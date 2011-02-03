#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>

#define p(x) cout << #x << ":" << x << endl;
#undef p
#define p(x) 

using namespace std;

int tools[500];
int n, m;
bool cons[500][500];
int grps[500][500];

void solve(){
    memset(grps, -1, sizeof grps);
    memset(cons, false, sizeof cons);
    cin >> n >> m;
    
    for (int i = 0; i < m; i ++){
        int s, d;
        cin >> s >> d;
        s--; d--;
        cons[s][d] = cons[d][s] = true;
    }
    
    int groups = 0;
    tools[0] = groups;
    grps[0][0] = 0;
    
    for (int i = 1; i < n; i ++){
        p(i)
        bool found = false;
        
        for (int j = 0; j < groups+1; j ++){
            p(j)
            int count = 0;
            bool canadd = true;
            while(grps[j][count] != -1){
                p(count);
                p(cons[grps[j][count]][i]);
                if(cons[grps[j][count]][i]){
                    canadd = false;
                    p(canadd);
                    break;
                }
                count ++;
            }
            if(canadd){
                grps[j][count] = i;
                tools[i] = j;
                found = true;
                p(found)
                break;
            }
        }
        if(!found){
            groups ++;
            grps[groups][0] = i;
            tools[i] = groups;
        }
    }
    
    for (int i = 0; i < n; i ++){
        cout << tools[i]+1 << " ";
    }
    cout << endl;
}

int main(){

    int testcases;
    cin >> testcases;
    
    for (int i = 0; i < testcases; i ++){
        solve();
    }

    return 0;
}
