#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;

int rates[2001];

int main (int argc, char const* argv[]){
  
  int days, money, dollars = 0;
  
  cin >> days >> money;
  
  for(int i = 0; i < days; i++){
    cin >> rates[i];
  }
  
  for(int i = 0; i < days; i++){
    if(rates[i+1] > rates[i]){
      dollars = money/rates[i];
      money = money%rates[i];  
    } else{
      money += dollars * rates[i];
      dollars = 0;
    }
  }
  
  cout << money << endl;
  
  return 0;
}
