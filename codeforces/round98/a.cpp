#include <iostream>

#define p(x) 
//cout << #x << ":" << x << endl;

using namespace std;

int main(){

  string cards;
  cin >> cards;


  int answer = 0;
  int i;
  char prev = cards[0];
  int total = 1;
  for (i = 1; i < cards.length(); i++) {
    if(cards[i] != prev){
      p(i)
      p(total)
       
      answer += (total + 4) / 5;
      total = 1;
      prev = cards[i];
    }else{
      total += 1;
    }
  }

  answer += (total + 4) / 5;

  cout << answer << endl;

  return 0;
}
