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

#define p(x) 
//cout << #x << ":" << x << endl;

using namespace std;

string itoa(int val) {stringstream ss;ss << val;return ss.str();} 

int map[100][100];
float wp[100];
int gp[100];
int gw[100];
float owp[100][100];
float aowp[100];
float aoowp[100];

float rpi[100];

int n;

void printOwp(){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cout << owp[i][j];
        }
        cout << endl;
    }
}

float getOwp(int team){

    float totOwp = 0.0f;
    
    p(team)
    
    for (int i = 0; i < n; i ++){
        int res = map[team][i];
        if(res != -1){
        
            //cout << "found "; p(i);
        
            int gw1 = gw[i];
            if(res == 0){
                gw1 --;
            }
            p(gw1) p(gp[i]-1)
            owp[team][i] = (float) ((float)gw1/(float)(gp[i]-1));
            p(owp[team][i])
            totOwp += owp[team][i];
        }
    }
    
    aowp[team] = (float)(totOwp/gp[team]);
    p(aowp[team]);
    return aowp[team];
}

void calculate(int team){
    float WP = wp[team];
    float OWP = aowp[team];
    
    float totOwp = 0.0f;
    for (int i = 0; i < n; i ++){
        if(map[team][i] != -1){
            totOwp += aowp[i];
        }
    }
    
    float OOWP = (float) totOwp/gp[team];
    
    p(team) p(WP) p(OWP) p(OOWP)
    
    rpi[team] = (float) (0.25f * WP + 0.5f * OWP + 0.25f * OOWP);
}

int main(){
        
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        
        memset(map, -1, sizeof map);
        
        cin >> n;
        string s;
        for (int j = 0; j < n; j ++){
            cin >> s;
            float gw1 = 0.0f;
            float gp1 = 0.0f;
            for (int k = 0; k < n; k ++){
                if(s[k] == '1'){
                    map[j][k] = 1;
                    gw1 += 1.0f;
                    gp1 += 1.0f;
                }
                if(s[k] == '0'){
                    map[j][k] = 0;
                    gp1 += 1.0f;
                }
            }
            gp[j] = (int) gp1;
            gw[j] = (int) gw1;
            wp[j] = gw1/gp1;
            
            //p(j)
            //p(wp[j])
        }      
        
        for(int j = 0; j < n; j ++)
            getOwp(j);
        
        //printOwp();
        for (int j = 0; j < n; j ++){
            calculate(j);
        }
        
        cout << "Case #" << i+1 << ":" << endl;
        
        for (int j = 0; j < n; j ++){
            cout << setprecision(10) << rpi[j] << endl;
        }
    }

    return 0;
} 
