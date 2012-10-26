// http://uva.onlinejudge.org/external/1/146.html

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main() {

  char* seq;
  string str;

  cin >> str;
  while(str != "#"){
    seq = new char [str.size()+1];
    strcpy(seq, str.c_str());

    if(next_permutation(seq, seq + str.size() )){
      cout << seq << endl;
    } else {
      cout << "No Successor" << endl;
    }
    cin >> str;
  }
  return 0;
}
