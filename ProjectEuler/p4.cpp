#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <sstream>



#define p(x) cout << #x << ":" << x << endl;

using namespace std;

string itoa(int val) {stringstream ss;ss << val;return ss.str();} 


int main(){

    string pal;
    for (int i = 100; i < 1000; i ++){
        for (int j = i; j < 1000; j ++){
            int p = i*j;
            string s = itoa(p);
            string rev = "";
            for (int x = 0; x < s.size(); x ++){
                rev += s[s.size()-1-x];
            }
            if(s == rev && atoi(s.c_str()) > atoi(pal.c_str())){
                pal = s;
            }
        }
    }
    
    p(pal);

    return 0;
}
