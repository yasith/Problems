#include <iostream>
#include <string>

using namespace std;

int main (int argc, char const* argv[]){
  
  string str;
  int number[500], place = 0;
  
  cin >> str;
  
  for (int i = 0; i < str.size(); i += 1){
    if(str[i] == '.'){
      number[place] = 0;
      place ++;
    }
    if(str[i] == '-' && str[i+1] == '.'){
      number[place] = 1;
      place ++;
      ++ i;
    }
    if(str[i] == '-' && str[i+1] == '-'){
      number[place] = 2;
      place ++;
      ++ i;
    }
  }
  
  for (int i = 0; i < place; i += 1){
    cout << number[i];
  }
  cout << endl;
  
  return 0;
}
