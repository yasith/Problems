#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <fstream>

#define p(x) cout << #x << ":" << x << endl;

using namespace std;

string itoa(int val) {stringstream ss;ss << val;return ss.str();} 

struct card{
    int c, s, t;
    int id;
};

vector<card> hand;
vector<card> deck;

int n, m;
int answer;

int score;
int prescore;
int turns;

bool comp(card a, card b){
    return a.s > b.s;
}

void play1(){
    int tc = 0;
    for (int i = 0; i < hand.size(); i ++){
        if(hand[i].t > 0){
            tc = hand[i].c;
            turns += hand[i].t;
            prescore += hand[i].s;
            hand.erase(hand.begin() + i);
            
            int j = 0;
            while(!deck.empty() && j < tc){
                hand.push_back(deck.front());
                deck.erase(deck.begin());
                j ++;
            }
            
            i --;
            turns --;
        }
    }
}

void play(){
    if(turns == 0 || (hand.empty() && deck.empty())){
        //cout << "Returning " << score << endl;
        answer = max(answer, score);
        return;
    }
    turns --;
    card c;
    for (int i = 0; i < hand.size(); i ++){
        c = hand[i];
        
        //cout << c.id << ": " << c.c << " " << c.s << " " << c.t << endl;
        
        hand.erase(hand.begin()+i);
        score += c.s;
        turns += c.t;
        
        //p(score);
        //p(turns);
        
        int j = 0;
        while(!deck.empty() && j < c.c){
            hand.push_back(deck.front());
            deck.erase(deck.begin());
            j++;
        }
        
        play();
        
        for (int k = 0; k < j; k ++){
            card t = hand.back();
            hand.pop_back();
            deck.insert(deck.begin(), t);
        }
        
        turns -= c.t;
        score -= c.s;
        
        hand.insert(hand.begin()+i, c);
    }
    turns ++;
    return;
}

int main(){
        
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        hand.clear();
        deck.clear();
        prescore = score = answer = 0;
        
        turns = 1;
        cin >> n;
        for (int j = 0; j < n; j ++){
            card c;
            cin >> c.c >> c.s >> c.t;
            c.id = j+1;
            hand.push_back(c);
        }            
        cin >> m;
        for (int j = 0; j < m; j ++){
            card c;
            cin >> c.c >> c.s >> c.t;
            c.id = j+1+n;
            deck.push_back(c);
        }        
        
        play1();      
              
        play();
              
        cout << "Case #" << i+1 << ": " << answer+prescore << endl;
    }

    return 0;
} 
