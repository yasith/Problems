#include <iostream>
#include <list>

using namespace std;

int seq[100];
int len[100];
int prev[100];
  
int N;

void printass(int pos, int length){
  list<int> printlist;
  
  int next = pos;
  for (int i = 0; i < length; i += 1){
    printlist.push_front(2001 + next);
    next = prev[next];
  }
  
  for (int i = 0; i < length; i += 1){
    cout << printlist.front() << " ";
    printlist.pop_front();
  }
  cout << endl;
}

void longestass(){

  for (int i = 0; i < N; i += 1){
    if(seq[i] <= 0){
      len[i] = 0;
      continue;
    }
    
    bool found = false;
    for (int j = i-1; j > 0; j --){
      if(seq[i] > seq[j] && len[i] <= len[j]){
        len[i] = len[j] + 1;
        prev[i] = j;
        found = true;
      }
    }
    
    if(! found){
      len[i] = 1;
    }
  }  
  
  int asslength = 0;
  int asspos;
  for (int i = 0; i < N; i += 1){
    if(asslength < len[i]){
      asslength = len[i];
      asspos = i;
    }
  }
  
  cout << asslength << endl;
  printass(asspos, asslength);

}

int main (int argc, char const* argv[]){
  cin >> N;
  
  for (int i = 0; i < N; i += 1){
    cin >> seq[i];
  }
  
  longestass();
  
  return 0;
}
