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

int k, n;
string board[50];
string answer;
int lr, lc;
bool fr, fb;

void print(){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cout << board[i][j];
        }
        cout << endl;
    }
}

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n; i ++){
        cin >> board[i];
    }
    bool empty = false;
    
    int row = n-1;
    while(!empty){
        int pos = n-1;
        for (int i = n-1; i >= 0; i --){
            if(board[row][i] != '.'){
                board[row][pos] = board[row][i];
                if(pos != i)
                    board[row][i] = '.';
                lc = min(lc, pos);
                pos --;
            }
        }
        if(pos == n-1 || row == 0)
            empty = true;
        lr = row;
        row --;
    }
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if(board[i][j] != '.'){
                char c = board[i][j];
                int found = 0;
                //if(!fr && c == 'R'){
                    int d;
                    for (d = 0; d < k; d ++){
                        if(j+d >= n)
                            break;
                        if(board[i][j+k] != c)
                            break;
                    }
                    found = max(found, d);
                    for (d = 0; d < k;  d++){
                        if(i+d >= n)
                            break;
                        if(board[i+d][j] != c)
                            break;
                    }
                    found = max(found, d);
                    for (d = 0; d < k;  d++){
                        if(i+d >= n || j+d >= n)
                            break;
                        if(board[i+d][j+d] != c)
                            break;
                    }
                    found = max(found, d);
                    for (d = 0; d < k;  d++){
                        if(i+d >= n || j-d <= 0)
                            break;
                        if(board[i+d][j-d] != c)
                            break;
                    }
                    found = max(found, d);
                    
                    if(found >= k){
                        fr = (c == 'R');
                        fb = (c == 'B');
                        p(c)
                        p(i) p(j)
                        p("--")
                        print();
                    }
                    if(fr && fb)
                        return;
                //}
            }
        }
    }
    
    //print();
}

int main(){

    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        //clr(board, '.');
        fr = fb = false;
        answer = "Neither";
        solve();
        answer = fr && fb ? "Both" : (fr ? "Red" : "Blue");
        cout << "Case #" << i+1 << ": " << answer << endl;
    }

    return 0;
}
