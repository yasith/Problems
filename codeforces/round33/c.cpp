#inlcude <iostream>

using namespace std;

int main (int argc, char const* argv[]){
  
  int n;
  int seq[100000];

  cin >> n;
  for (int_ i = 0; i < n; i += 1){
    cin >> seq[i];
  }
  
  // Prefix
  int best = 0;
  int best_pos = 0;
  
  int tsf = 0;
  for(int i = 0; i < n; i++){
    tsf += seq[i];
    if(tsf <= best){
      best = tsf;
      best_pos = i;
    }
  }
  
  for(int i = 0; i <= best; i++){
    seq[i] = -1 * seq[i];
  }
  
  // Suffix
  
  
  
  return 0;
}
