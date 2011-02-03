#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;

int main (int argc, char const* argv[]){
 
  string s1, s2;
  cin >> s1 >> s2;
  
  if(s1.size() != s2.size()){
    cout << "NO" << endl;
    return 0;
  }
  
  for(int i = 0; i < s1.size(); i++){
    if(s1[i] != s2[s1.size()-1 - i]){
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "YES" << endl;
  
  return 0;
}
