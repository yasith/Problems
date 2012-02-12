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


int main(){
    
    int num = 2520;
    while(true){
        num ++;
        bool flag = true;
        for (int i = 2; i < 21; i ++){
            if(num % i){
                flag = false;
            }
        }
        if(flag){
            p(num);
            break;
        }
    }

    return 0;
}

