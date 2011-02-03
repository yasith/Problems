#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

int main (int argc, char const* argv[]){
  
  int teeth, rows, vals;
  cin >> teeth >> rows >> vals;
  
  int row[20000];
  for(int i = 0; i < rows+1; i ++){
    row[i] = 999999999;
  }
  
  for (int i = 0; i < teeth; i += 1){
    int rn, mn;
    cin >> rn >> mn;
    row[rn] = min(mn, row[rn]);
    //cout << "Row " << rn << " " << row[rn] << endl;
  }
  
  int answer = 0;
  
  for(int i = 1; i < rows+1; i++){
    answer += row[i];
  }
  
  //cout << "Answer " << answer << endl;
  
  answer = min(answer, vals);
  
  cout << answer << endl;
  
  
  return 0;
}
