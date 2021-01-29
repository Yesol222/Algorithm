#include <iostream>
#include <sstream>

using namespace std;

void solution(int day, int width, int **blocks) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
  int middle = abs(width/2), i=0,k=0,lpos=0 , rpos=width, sum=0;
  int *block;

  for(i=0;i<width;i++){
      block[i]=0;
  }

  while(day){
      for(i=0;i<width;i++){
          block[i]+=blocks[k][i];
      }
      for(int j=1;j<middle;j++){
          if(block[lpos]>block[j]){
              block[j] = block[lpos];
              sum += block[lpos]-block[j];
          }
          else{
             lpos = j;
          }
      }

      for(int j=width-1;j>=middle;j--){
          if(block[rpos]>block[j]){
              block[j] = block[rpos];
              sum += block[rpos]-block[j];
          }
          else{
             rpos = j;
          }
      }
      i++;
      day--;
  }
  printf("%d",sum);
}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}