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

int n, l, h;
int of[100];

bool valid[1000];

int freq = -1;

void solve(){

    for (int i = l; i < h+1; i ++){
        //p(i);
        bool val = true;
        for (int j = 0; j < n; j ++){
            int x = of[j];
            if(x%i != 0 && i%x != 0){
                val = false;
                break;
            }
        }
        if(val){
            freq = i;
            return;
        }
    }
    return;
}

int main(){
        
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        
        cin >> n >> l >> h;
        
        freq = -1;
  
        for (int j = 0; j < n; j ++){
            cin >> of[j];
        }            
        
        solve();
        if(freq == -1){
            cout << "Case #" << i+1 << ": NO" << endl;
        }else{
            cout << "Case #" << i+1 << ": " << freq << endl;
        }
    }

    return 0;
} 
