#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solve(){

  int n, s, p;
  cin >> n >> s >> p;

  int surprised = 0;
  int normal = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    bool sf = false; //surprise
    bool nf = false; //normal

    for (int a = 0; a < 11; a++) {
      for (int b = 0; b < 11; b++) {
        for (int c = 0; c < 11; c++) {
          if(a+b+c == x && max(a, max(b,c)) >= p){
            if(abs(a-b) < 2 && abs(a-c) < 2 && abs(b-c) < 2){
              nf = true;
            }else if(abs(a-b) <= 2 && abs(a-c) <= 2 && abs(b-c) <= 2){
              sf = true;
            }
          }
          if(nf) break;
        }
        if(nf) break;
      }
      if(nf) break;
    }

    if(nf){
      normal ++;
    }else if(sf){
      surprised ++;
    }
  }

  return normal + min(surprised, s);

}

int main(){

  int T;
  cin >> T;

  for(int i = 0; i < T; i++){
    cout << "Case #" << i+1 << ": " << solve() << endl;
  }

}
