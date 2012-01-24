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

int n, d, g;

int main(){
        
    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        cin >> n >> d >> g;
        bool stat = false;
        
        for (int j = 1; j <= n; j ++){
            if((j*d)%100 == 0){
                stat = true;
                break;
            }
        }
        
        if(g == 100 && d != 100)
            stat = false;
        if(g == 0 && d != 0)
            stat = false;

        string answer = stat ? "Possible" : "Broken";
        
        cout << "Case #" << i+1 << ": " << answer << endl;
    }

    return 0;
} 
