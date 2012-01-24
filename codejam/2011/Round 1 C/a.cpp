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

int c, r;

string answer;
string pic[50];

bool possible = true;


void solve(){

    for (int i = 0; i < r-1; i ++){
        for (int j = 0; j < c-1; j ++){
          if(pic[i][j] == '#'){
            char p, q, r, s;
            p = pic[i][j];
            q = pic[i][j+1];
            r = pic[i+1][j];
            s = pic[i+1][j+1];
            
            if((r != '#' || s != '#') || (p != q || r != s)){
                possible = false;
                return;
            }
            
            if((p == q && q == r) && r == s){
                pic[i][j] = '/';
                pic[i][j+1] = '\\';
                pic[i+1][j] = '\\';
                pic[i+1][j+1] = '/';
            }
          }
        }
    }
    
    return;

}

void printpic(){
    for (int i = 0; i < r; i ++){
        cout << pic[i] << endl;
    }
}

int main(){
        
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        
        possible = true;
        
        
        cin >> r >> c;
        int bcount = 0;
        for (int j = 0; j < r; j ++){
            cin >> pic[j];
            for (int k = 0; k < c; k ++){
                if(pic[j][k] == '#')
                    bcount ++;
            }
        }
        
        
        cout << "Case #" << i+1 << ":" << endl;
        
        
        if(bcount == 0){
            printpic();
            continue;
        }
        if(bcount % 4 != 0){
            cout << "Impossible" << endl;
            continue;
        }
        
        solve();  
        if(possible){
            printpic();
        } else{
            cout << "Impossible" << endl;
        }
        
    }

    return 0;
} 
