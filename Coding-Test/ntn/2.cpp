#include <string>
#include <vector>
//효율성 0점 나오셨다!!!

int res=0;
int cnt;
void Search(int x, int y, vector<string> Mydrum){
    if(cnt>=2){
        if(x==Mydrum[0].size()){
            res++;
        }
        return;
    }
    if(x==Mydrum[0].size()){
        res++;
        return;
    }
    else if(Mydrum[x][y]=='#'){
        Search(x+1,y,Mydrum);
    }
    else if(Mydrum[x][y]=='<'){
        Search(x,y-1,Mydrum);
    }
    else if(Mydrum[x][y]=='>'){
        Search(x,y+1,Mydrum);
    }
    else if(Mydrum[x][y]=='*' && cnt<2){
        Search(x+1,y,Mydrum);
        cnt++;
    }
}



int Solution(vector<string> drum){

    for(int i=0;i<drum[0].size();i++){
        Search(0,i,drum);
    }

    return res;
}