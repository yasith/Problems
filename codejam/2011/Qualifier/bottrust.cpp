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

#define p(x) cout << #x << ":" << x << endl;

using namespace std;

string itoa(int val) {stringstream ss;ss << val;return ss.str();} 

int seq[100];
int bot[100];
int n;
int pos[2];
int timer;

void solve(){
    cin >> n;
    
    for (int i = 0; i < n; i ++){
        int pos;
        char x;
        cin >> x >> pos;
        seq[i] = pos;
        bot[i] = x == 'O' ? 0:1;
    }
    
    int cur = 0;
    while(cur < n){
        timer ++;
        int b1 = bot[cur];
        int b2 = !b1;
        if(seq[cur] == pos[b1]){
            cur ++;
        }else{
            if(pos[b1] < seq[cur]){
                pos[b1] ++;
            }else{
                pos[b1] --;
            }
        }
        int np;
        for (int i = cur; i < n; i ++){
            if(bot[i] == b2){
                np = seq[i];
                break;
            }
        }
        if(pos[b2] == np)
            continue;
        if(pos[b2] < np){
            pos[b2] ++;
        } else{
            pos[b2] --;
        }
        
    }
}

int main(){

    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        pos[0] = pos[1] = 1;
        timer = 0;
        solve();
        cout << "Case #" << i+1 << ": " << timer << endl;
    }

    return 0;
}
