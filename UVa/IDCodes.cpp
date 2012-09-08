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
      cout << "No successor" << endl;
    }
    cin >> str;
  }
  return 0;
}
