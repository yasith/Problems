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

int GCD(int a, int b) {if(b == 0) return a; return GCD(b, a%b);}

int LCM(int a, int b) {return (a*b)/GCD(a, b);}

struct coord{
    int x, y;
};

int n, m;
float lim;
int dp[26];
vector<coord> shifts;
bool key[26];
string keyboard[30];

float dist(coord a, coord b){
    float dx = abs(a.x - b.x);
    float dy = abs(a.y - b.y);
    
    float d = sqrt((dx*dx) + (dy*dy));
    
    return d;
}

int type(char c){
    if(dp[c-'a'] != -1){
        return dp[c-'a'];
    }
    bool result = true;
    
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if(keyboard[i][j] == c){
                for (int k = 0; k < shifts.size(); k ++){
                    coord cd;
                    cd.y = i;
                    cd.x = j;
                    float d = dist(shifts[k], cd);
                    //p(d); p(c);
                    if(d <= lim){
                        result = false;
                        dp[c-'a'] = 0;
                        return 0;
                    }    
                }
            }
        }
    }
    
    dp[c-'a'] = result;
    return result;
}

int main(){

    cin >> n >> m >> lim;
    
    for (int i = 0; i < n; i ++){
        string s;
        cin >> s;
        keyboard[i] = s;
        for (int j = 0; j < m; j ++){
            if(s[j] == 'S'){
                coord c;
                c.x = j;
                c.y = i;
                
                shifts.push_back(c);
            }else{
                key[s[j] - 'a'] = true;
            }
        }
    }   
    
    memset(dp, -1, sizeof(dp)); 
    
    int count = 0;
    
    int t;
    cin >> t;
    
    int cs = 0;
    char TEMP = cin.get();
    while(cin.good()){
        cs++;
        char c;
        if(cin.good())
            c = cin.get();
        
        if(cs > t) break;
        
        //p(c);
        
        if(c >= 'A' && c <= 'Z'){
            if(shifts.size() < 1 || !key[c-'A']){
                cout << -1 << endl;
                return 0;
            }else{
                count += type(tolower(c));
            }
        }else if(!key[c-'a']){
            cout << -1 << endl;
            return 0;
        }
        
    }
    
    cout << count << endl;

    return 0;
}
