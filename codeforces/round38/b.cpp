#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main (int argc, char const* argv[]){
  
  int h, w, x;
  
  cin >> h >> w >> x;
  
  h = h - ((x-1) * 2);
  w = w - ((x-1) * 2);
  
  int p = h*2 + w*2 - 4;
  
  //cout << "p is " << p << endl;
  
  if(p == 0){
    cout << 1 << endl;
    return 0;
  }
  
  int s = (int)ceil((float)p/2.0);
  
  
  cout << s << endl;
  
  return 0;
}
