#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
    vector<int> Players(numOfAllPlayers);
    vector<char> nameOfAllPlayers(numOfAllPlayers);
    int lenOfGames = sizeof(numOfMovesPerGame)/sizeof(numOfMovesPerGame[0]);
    int pos = numOfAllPlayers;

    Players[numOfAllPlayers] = 1;
    nameOfAllPlayers[numOfAllPlayers] = 0;

    for(int i=1;i<numOfAllPlayers;i++){
        Players[i] = 0;
        nameOfAllPlayers[i] = i;
    }

    while(numOfGames){
        for(int i=0;i<lenOfGames;i++){
            if((numOfMovesPerGame[i]+pos)>numOfAllPlayers){
                if((pos - numOfMovesPerGame[i] + 65) == namesOfQuickPlayers[i]) Players[pos]++;
                else{
                    Players[pos]++;

                    int temp = pos-numOfMovesPerGame[i];
                    nameOfAllPlayers[temp] = pos;
                    nameOfAllPlayers[pos] = temp;
                }
            }
            else if((numOfMovesPerGame[i]+pos)<numOfAllPlayers){
                if((pos + numOfMovesPerGame[i] + 65) == namesOfQuickPlayers[i]) Players[pos]++;
                else{
                    Players[pos]++;
                    int temp = pos+numOfMovesPerGame[i];
                    nameOfAllPlayers[temp] = pos;
                    nameOfAllPlayers[pos] = temp;
                }
            }
        }
        numOfGames--;
    }


    for(int i=1;i<numOfAllPlayers;i++){
        printf("%s %d\n",&nameOfAllPlayers[i]+65,&Players[nameOfAllPlayers[i]]);
    }
}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}