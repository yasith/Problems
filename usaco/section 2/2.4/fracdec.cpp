/*
ID: yasith.1
PROG: fracdec
LANG: C++
*/

#define p(x) cout << #x << ": " << x << endl

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

string itoa(int i){ stringstream ss; ss << i; string s; ss >> s; return s;}

int num, den, rem; // Numberator, Denominator and Remainder
string ans = "";

map<int, int> remainders; // Remainders, pointing to index  of the num in nums
vector<int> nums; // Numbers that comes after the decimal point

int main(){

  fin >> num >> den; 

  p(num);
  p(den);

  int x = num / den;
  rem = num % den;

  p(x);
  p(rem);

  ans += itoa(x) + ".";
  p(ans);

  map<int, int>::iterator it;

  // Repeating a remainder means, we have a repeating sequence of numbers
  // If remainder is 0, we have the decimal representation
  while(rem != 0 && !remainders.count(rem)){ 
    remainders[rem] = nums.size();

    num = rem * 10;
    p(num);
    cout << flush;
    while(num < den) num *= 10;
    x = num / den;
    rem = num % den;

    p("---");
    p(num);
    p(den);
    p(x);
    p(rem);
    
    nums.push_back(x);
    it = remainders.find(rem);
  }

  for (int i = 0; i < nums.size(); i++) {
    if(i == (*it).second && rem != 0) ans += "(";

    ans += itoa(nums[i]);
  }

  if(rem != 0) ans += ")";
  if(nums.size() == 0) ans += "0";

  for(int i = 76; i < ans.size(); i++){
    ans.insert(i, "\n");  
  }

  fout << ans << endl;
  cout << ans << endl;

  return 0;
}
