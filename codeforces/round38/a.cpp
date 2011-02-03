#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main (int argc, char const* argv[]){
  
  double x ,y;
  cin >> x >> y;
  
  if(fmod(sqrt(x*x + y*y), 1.0) == 0){
    cout << "black" << endl;
    return 0;
  }
  
  bool black = true;
  
  if((int)floor(sqrt(x*x + y*y)) % 2){
    black = false;
  }
  
  if((x > 0 && y < 0) || (x < 0 && y > 0)){
    black = !black;
  }
  
  
  if(black)
    cout << "black" << endl;
  if(!black)
    cout << "white" << endl;
  
  return 0;
}
