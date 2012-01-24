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

#define p(x) 
//cout << #x << ":" << x << endl;

using namespace std;

string itoa(int val) {stringstream ss;ss << val;return ss.str();} 

int d[1000];
int td[1000];
int t;
int n;
int c;
int l;

int fs = 0;
int ss = 0;

int fd, sd;

void solve(){

    for (int i = 0; i < n; i ++){
        int efd = 0;
        if(i == 0 && (td[i] < t)){
            continue;
        }else if(i == 0 && (td[i] > t)){
            efd = td[i] - t;
        }else if(td[i-1] < t){
            efd = td[i]-t;
        }else{
            efd = d[i]*2;
        }
        
        if(efd >= fd){
            sd = fd;
            ss = fs;
            fd = efd;
            fs = i;
            p(fd);
            p(sd);
        }
    }
        
}

void printd(){
    for (int i = 0; i < n; i ++){
        cout << d[i] << " ";
    }
    cout << endl;
}


void printtd(){
    for (int i = 0; i < n; i ++){
        cout << td[i] << " ";
    }
    cout << endl;
}


int main(){
        
    int T;
    cin >> T;
    for (int i = 0; i < T; i ++){
        
        cin >> l >> t >> n >> c;
        
        memset(d, 0, sizeof d);
        memset(td, 0, sizeof td);
        
        fd = 0; sd = 0;
        
        for (int j = 0; j < c; j ++){
            int a;
            cin >> a;
            for (int k = 0; (k*c) + j < n; k ++){
                //if((k*c) + j < n){
                    d[(k*c) + j] = a;
                //}
            }
        }
        
        //cout << "done" << endl;
        
        int total = 0;
        for (int j = 0; j < n; j ++){
            total += d[j]*2;
            td[j] = total;
        }
        
        //printd();
        //printtd();
        
        solve();
        
        p(total)
        int answer = total - (fd/2);
        
        p(answer)
        if(l == 2) answer -= (sd/2);
        p(answer)
        cout << "Case #" << i+1 << ": " << answer << endl;
    }

    return 0;
} 
