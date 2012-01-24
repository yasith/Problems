#include <vector>
#include <list>
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


ifstream fin("a.in");

int n, k;
string map[50];
string answer;
bool R, B;

string itoa(int val) {stringstream ss;ss << val;return ss.str();}

void print(){
    for (int i = 0; i < n; i ++){
        cout << map[i] << endl;
    }
}

void found(char c){
    if(c == 'R')
        R = true;
    if(c == 'B')
        B = true;
}

void solve(){

    bool balls = true;
    int line = n;
    while (balls && line > 0){
        line --;
        int place = n-1;
        for (int i = n-1; i > -1; i --){
            if(map[line][i] != '.'){
                swap(map[line][i], map[line][place]);
                place --;
            }
        }
        if(place == n-1)
            balls = false;
    }
    
    //print();    

    char prev;

    // Check Down
    for (int j = 0; j < n; j ++){
        for (int i = 0; i < n; i ++){
            if(map[i][j] != '.'){
                prev = map[i][j];
                int counter = 0;
                while(i < n){
                    if(prev == map[i][j]){
                        counter ++;
                        i ++;
                        if(counter >= k)
                            found(prev);
                    }
                    else{
                        i --;
                        break;
                    }
                }
            }
        }
    }
    //cout << "Checked Down" << endl;
    
    // Check Right
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if(map[i][j] != '.'){
                prev = map[i][j];
                int counter = 0;
                while(j < n){
                    if(prev == map[i][j]){
                        counter ++;
                        j ++;
                        if(counter >= k)
                            found(prev);
                    }
                    else{
                        j --;
                        break;
                    }
                }
            }
        }
    }
    
    //cout << "Checked Right" << endl;
    
    // Check Right Up
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if(map[i][j] != '.'){
                prev = map[i][j];
                int counter = 0;
                int j1 = j;
                int i1 = i;
                while(i1 >= 0 && j1 < n){
                    if(prev == map[i1][j1]){
                        counter ++;
                        j1 ++;
                        i1 --;
                        if(counter >= k)
                            found(prev);
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    
    //cout << "Checked Right-Up" << endl;
    
    // Check Right Down
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            if(map[i][j] != '.'){
                prev = map[i][j];
                int counter = 0;
                int j1 = j;
                int i1 = i;
                while(i1 < n && j1 < n){
                    
                    if(prev == map[i1][j1]){
                        counter ++;
                        j1 ++;
                        i1 ++;
                        if(counter >= k)
                            found(prev);
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    
    //cout << "Checked Right-Down" << endl;
    
    return;
} 


int main(){

    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        cin >> n >> k;
        for (int j = 0; j < n; j ++){
            cin >> map[j];           
        }
        R = B = false;      
        solve();
        if(R && B) answer = "Both";
        else if(R) answer = "Red";
        else if(B) answer = "Blue";
        else answer = "Neither";
        cout << "Case #" << i+1 << ": " << answer << endl;
    }

    return 0;
}
