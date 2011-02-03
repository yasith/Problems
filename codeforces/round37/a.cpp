#include <iostream>

using namespace std;

int arr[10000];

int main (int argc, char const* argv[]){
  
  
  int n;
  cin >> n;
  
  int count = 0, highest = 0;
  
  for (int i = 0; i < n; i += 1){
    int len;
    cin >> len;
    if(arr[len] == 0){
      count ++;
    }
    arr[len] ++;
    highest = max(highest, arr[len]);
  }
  
  cout << highest << " " << count << endl;
  
  return 0;
}
