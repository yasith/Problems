#include <iostream>
#include <algorithm>

using namespace std;

struct event{
  int start, end;
} events[100000];

int n;

bool cmp(event a, event b){
  return a.start < b.start;
}

int main(){

  cin >> n;

  for(int i = 0; i < n; i ++){
    cin >> events[i].start >> events[i].end;
  }

  sort(events, events + n, cmp);


  // for(int i = 0; i < n; i ++){
  //   cout << events[i].start << " " << events[i].end << endl;
  // }
 
  int answer = 0;
  int maxend = events[0].end;

  for(int i = 1; i < n; i ++){
    if(events[i].end < maxend){
      answer ++;
    }else{
      maxend = events[i].end;
    }
  }

  cout << answer << endl;

  return 0;
}
