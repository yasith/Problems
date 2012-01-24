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

ifstream fin("c.in");

string itoa(int val) {stringstream ss;ss << val;return ss.str();} 

#define SIZELIM 10000

bool dp[SIZELIM][SIZELIM];
bool used[SIZELIM][SIZELIM];

bool play(int a, int b){
    if(a == b)
        return false;
        
    //p(a)p(b)
    if(used[a][b])
        return dp[a][b];
        
    // move 1
    int k = 1;
    while(a-(k*b) > 0){
        bool opwin = play(a-(k*b), b);
        if(opwin){
            used[a][b] = used[b][a] = true;
            dp[a][b] = dp[b][a] = false;
            return false;
        }
        k++;
    }
    
    // move 2
    k = 1;
    while(b-(k*a) > 0){
        bool opwin = play(a, b-(k*a));
        if(opwin){
            used[a][b] = used[b][a] = true;
            dp[a][b] = dp[b][a] = false;
            return false;
        }
        k++;
    }
    
    used[a][b] = used[b][a] = true;
    dp[a][b] = dp[b][a] = true;
    return true;
}

int main(){

    int t;
    fin >> t;
    //cin >> t;
    
    for (int i = 0; i < t; i ++){
        int a1, a2, b1, b2;
        fin >> a1 >> a2 >> b1 >> b2;
        //cin >> a1 >> a2 >> b1 >> b2;
        
        int answer = 0;
        
        for (int a = a1; a < a2+1; a ++){
            for (int b = b1; b < b2+1; b ++){
                if(play(a, b))
                    answer ++;
            }
        }
        
        cout << "Case #" << i+1 << ": " << answer << endl;
    }

    return 0;
}
