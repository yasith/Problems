#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main (int argc, char const* argv[]){

  int N, x, M, y;
  
  cin >> N >> x >> M >> y;
  
  int dist = abs(x - y);
  
  int parts = 1 + N + M;
  
  for(int i = 1; i <= M; i++){
    bool first = true;
    for(int j = 1; j <= N; j++){
      if(i + j > dist && j < dist+i){
        if(!first){
          parts ++;
        }
        first = false;
        parts ++;
      }
    }
  }  
  
  
  cout << parts << endl;
  
  return 0;
}
