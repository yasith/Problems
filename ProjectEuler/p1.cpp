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

    int count = 0;
    for (int i = 0; i < 1000; i ++){
        if(i%3 == 0 || i%5 == 0){
            count += i;
        }
        //p(count);
    }
    cout << count << endl;  

    return 0;
}
