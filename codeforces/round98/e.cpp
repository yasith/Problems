#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define p(x) cout << #x << ":" << x << endl;

using namespace std;

struct Node {
  int sum;
  int start, end;
  Node *left;
  Node *right;

  void init(int _start, int _end){
    start = _start;
    end = _end;

    left = NULL;
    right = NULL;
  }
} tree;

string str;
string vowels = "aeiouAEIOU";
bool mstr[200000];

int dp[20000][20000];

void rec(Node *n){

  if (n->end - n->start == 1) {
    n->sum = int(mstr[n->start]);
    //cout << n->start << ":" << n->sum << " ";
    return;
  }

  int mid = (n->start + n->end) / 2;

  //cout << n->start << "," << n->end << ":" << n->start << "," << mid << "," << n->end << endl;

  Node *n1 = new Node;
  n1->init(n->start, mid);
  rec(n1);

  Node *n2 = new Node;
  n2->init(mid, n->end);
  rec(n2); 

  n->left = n1;
  n->right = n2;
  n->sum = n1->sum + n2->sum;


}

void print_tree(Node *n){

  if(n->end - n->start == 1){
    //p(n->start)
    //p(n->end)
    //p(n->sum)

    return;
  }

  print_tree(n->left);
  print_tree(n->right);
}

int get_count(Node *n, int s, int e){
  ////p(n->start) //p(s)
  ////p(n->end) //p(e)
  int sum = 0;

  if(dp[s][e] != -1){
    return dp[s][e];
  }
  
  if(n->start == s && n->end == e){
    //cout << "Have a match" << endl;
    ////p(n->start)
    ////p(n->end)
    ////p(n->sum)

    sum = n->sum;
  }else{

    //cout << "No match" << endl;
    int lsum = 0, rsum = 0;
    int mid = (n->start + n->end) / 2;

    if(s < mid){
      //cout << "Go left" << endl;
      //cout << s << "," << mid << endl;
      lsum = get_count(n->left, s, min(e, mid));
    }
    if(e > mid){ 
      //cout << "Go right" << endl; 
      //cout << mid << "," << e << endl;
      rsum = get_count(n->right, max(mid, s), e);
    }
    
    //cout << s << "," << mid << "," << e << endl;
    //cout << n->start << "," << mid << "," << n->end << endl;
    ////p(lsum)
    ////p(rsum)
    ////p(lsum + rsum)
    sum = lsum + rsum;
  }

  //cout << endl;
  
  dp[s][e] = sum;
  return sum;
}

int main(){
  
  memset(dp, -1, sizeof dp);
  cin >> str;

  for (int i = 0; i < str.length(); i++) {
    bool v = false;
    for (int j = 0; j < vowels.length(); j++) {
      if(str[i] == vowels[j]){
        v = true;
        break;
      }
    }
    if (v) {
      mstr[i] = true;
    }   
  }

  /*
  for (int i = 0; i < str.length(); i++) {
    cout << str[i] << ":";
    cout << int(mstr[i]) << " ";
  }
  cout << endl;
  */

  tree.init(0, str.length());

  rec(&tree);

  //print_tree(&tree);
  //cout << get_count(&tree, 3, 21) << endl;
  //cout << get_count(&tree, 2, 8) << endl;
  
  //p(str.length())

  int count = 0;
  int size = 0;
  for (int sz = str.length(); sz > 0; sz--) {
    bool found = false;
    for (int pos = 0; pos < str.length() - sz + 1; pos++) {
      //p(pos)
      //p(pos + sz)
      //p(sz)
      int v = get_count(&tree, pos, pos+sz);
      //p(v)
      if(3 * v <= 2 * sz){
        found = true;
        size = sz;
        count ++;
      }
    }
    if(found)
      break;
  }
  
  if(size == 0){
    cout << "No solution" << endl;
  }else{
    cout << size << " " << count << endl;
  }
  return 0;
}


