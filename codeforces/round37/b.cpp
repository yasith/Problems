#include <iostream>
#include <algorithm>

using namespace std;

struct scroll{
  int dmg, num, turn;
  double pow;
} scrolls[1000];

bool comp(scroll a, scroll b){
  return a.dmg > b.dmg;
}

bool comp2(scroll a, scroll b){
  return a.turn < b.turn;
}

int N, hp, reg;

int getScroll(int health){
  int selected = -1;
  int dmg = 0;
  
  double percentage = ((double)health/(double)hp) * 100;
  
  for(int i = 0; i < N; i++){
    if(percentage <= scrolls[i].pow && dmg < scrolls[i].dmg && scrolls[i].turn == -1){
      selected = i;
      dmg = scrolls[i].dmg;
    }
  }
  
  return selected;
}

int main (int argc, char const* argv[]){
  
  cin >> N >> hp >> reg;
  
  for(int i = 0; i < N; i++){
    cin >> scrolls[i].pow >> scrolls[i].dmg;
    scrolls[i].num = i+1;
    scrolls[i].turn = -1;
  }
  
  //sort(scrolls, scrolls+N, comp);
  
  int health = hp;
  int used = 0;
  int turn = -1;

  while(health > 0){
    turn ++;
    
    health += reg;
    health = min(hp, health);
    if(health <= 0)
      break;
    
    int cur_scroll = getScroll(health);
    
    if(cur_scroll != -1){
      reg -= scrolls[cur_scroll].dmg;
      scrolls[cur_scroll].turn = turn;
    
      used ++;
    }
    
    //cout << turn << " " << health << " " << reg << endl;
  
    if(reg >= 0)
      break;
  }
  
  sort(scrolls, scrolls + N, comp2);

  if(health > 0){
    cout << "NO" << endl;
    return 0;
  }else{
    cout << "YES" << endl;
  }
  
  cout << turn << " " << used << endl;
    
  for(int i = 0; i < used; i++){
    cout << scrolls[i].turn << " " << scrolls[i].num << endl;
  }
  
  return 0;
}
