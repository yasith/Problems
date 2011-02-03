#include <iostream>

using namespace std;

int main (int argc, char const* argv[]){
  int n, m, a;
  cin >> n >> m >> a;
  
  int x = n%a ? n/a + 1 : n/a;
  int y = m%a ? m/a + 1 : m/a;
  
  long long ans = x*y;
  
  cout << ans << endl;
  
  return 0;
}
