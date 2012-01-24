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

int main(){

    string c[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H",
                  "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H",
                  "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};

    string n[3];
    
    for (int i = 0; i < 3; i ++){
        cin >> n[i];
    }

    sort (n,n+3);

    do {
  
        int count = 0;
        int d[2];
        int p = 0;
    
        for (int i = 0; i < 100; i ++){
            count ++;
            if(p > 2) 
                break;
            if(c[i] == n[p]){
                if(p == 1)
                    d[0] = count;
                if(p == 2)
                    d[1] = count;
                
                count = 0;
                p++;
            }
        }
        
        //p(n[0]) p(n[1]) p(n[2])
        //p(d[0]) p(d[1])
        
        if(d[0]+d[1] == 7){
            if(d[0] == 3){
                cout << "minor" << endl;
                return 0;
            }else if(d[1] == 3){
                cout << "major" << endl;
                return 0;
            }
        }
    }while ( next_permutation (n, n+3) );

    cout << "strange" << endl;

    return 0;
}
