#include <iostream>

using namespace std;

bool flags[5000];
int answer = 0;

int main(){

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;

    if(x > n){
      answer += 1;
    }else{
      if(flags[x]){
        answer += 1;
      }else{
        flags[x] = true;
      }
    }
  }

  cout << answer << endl;

  return 0;
}
