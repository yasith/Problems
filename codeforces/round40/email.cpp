#include <iostream>
#include <string>

using namespace std;

int main (int argc, char const* argv[]){
  
  string email;
  string at = "at";
  string dot = "dot";
  
  cin >> email;
  
  char end = email[email.size()-1];
  char begin = email[0];
  email[0] = email[email.size()-1] = '*';
  
  size_t foundat = email.find(at);
  email.replace(foundat, 2, "@");
  
  size_t founddot = email.find(dot);
  
  while(founddot != string::npos){
    email.replace(founddot, 3, ".");
    founddot = email.find(dot, founddot + 1);
  }
  
  email[0] = begin;
  email[email.size()-1] = end;
  
  cout << email << endl;
  
  return 0;
}
