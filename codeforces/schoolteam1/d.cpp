#include <iostream>

using namespace std;

int main (int argc, char const* argv[]){

  int x, y, z;
  cin >> x >> y >> z;
  
  int x1, y1, z1;
  cin >> x1 >> y1 >> z1;
  
  if(x == x1 || y == y1 || z == z1){
    cout << "YES" << endl;
  } else{
    cout << "NO" << endl;
  }
  return 0;
}
