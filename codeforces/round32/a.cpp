#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int main (int argc, char const* argv[]){
  int n, d;
  int answer = 0;
  
  cin >> n >> d;
  
  int heights[1000];
  
  for (int i = 0; i < n; i += 1){
    cin >> heights[i];
  }
  
  sort(heights, heights+n);
  
  for (int i = 0; i < n; i += 1){
    for (int j = 0; j < n; j += 1){
      if(i == j)
        continue;
      if(abs(heights[i] - heights[j]) <= d){
        answer ++;
        //cout << i << " " << j << endl;
      }
    }
  }
  
  cout << answer << endl;
  
  return 0;
}
