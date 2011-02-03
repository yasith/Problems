#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main (int argc, char const* argv[]){
    
    string s;
    cin >> s;
    
    string h = "hello";
    int c = 0;
    for(int i = 0; i < s.size(); i++){
        //cout << s[i] << " " << h[c] << endl;
        if(s[i] == h[c]){
          //  cout << "yes" << endl;
            c++;
        }else{
            //cout << "no" << endl;
        }
    }
    if(c == 5){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
    return 0;
}
