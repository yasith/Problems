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

int main(){

    long count = 2;
    
    int i1 = 1;
    int i2 = 2;
    
    while(i2 < 4000000){
        int fib = i1+i2;
        i1 = i2;
        i2 = fib;
        if(fib % 2 == 0){
            count += fib;
        }
    }
    
    p(count);

    return 0;
}
