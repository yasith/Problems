#include <iostream>


using namespace std;

int main (int argc, char const* argv[]){
  int h, f, m;
  cin >> h >> f >> m;
  
  int jumps[100], pos[100];
  int frogs[100];
  int mini = m, count = 0;
  
  for (int i = 0; i < f; i += 1){
    cin >> jumps[i];
  }
  
  for (int i = 0; i < m; i += 1){
    cin >> pos[i];
  }
  
  for (int i = 0; i < f; i += 1){
    frogs[i] = 0;
    for (int j = 0; j < m; j += 1){
      if(pos[j] % jumps[i] == 0){
        frogs[i] ++;
      }
    }
    if(frogs[i] < mini){
      count = 0;
      mini = frogs[i];
    }
    if(frogs[i] == mini)
      count ++;
  }
  
  cout << count << endl;
  for (int i = 0; i < f; i += 1){
    if(frogs[i] == mini)
      cout << i+1 << " ";
  }
  
  cout << endl;
  
  return 0;
}
