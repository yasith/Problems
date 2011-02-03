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

using namespace std;

bool e[500][500];
char dishes[500];

int n, m;
bool found;

void rec(int dish){
    if(dish == n){
        for (int i = 0; i < n; i ++){
            cout << (int)dishes[i] <<  " ";
        }
        cout << endl;
        found = true;
        return;
    }
    bool avail[4];
    avail[1] = avail[2] = avail[3] = true;
    for (int i = 0; i < n; i ++){
        if(e[dish][i] == true){
            avail[dishes[i]] = false;
        }
    }
    for (int i = 1; i < 4; i ++){
        if(avail[i]){
            dishes[dish] = i;
            rec(dish+1);
            dishes[dish] = 0;
        }
        if(found){
            return;
        }
    }
}

int main(){

    int tests;
    cin >> tests;
    
    for (int i = 0; i < tests; i ++){

        memset(dishes, 0, sizeof dishes);
        memset(e, false, sizeof e);
        
        cin >> n >> m;
        for (int j = 0; j < m; j ++){
            int s, d;
            cin >> s >> d;
            s--; d--;
            e[s][d] = e[d][s] = true;
        }
        found = false;
        rec(0);
    }
    

    return 0;
}
