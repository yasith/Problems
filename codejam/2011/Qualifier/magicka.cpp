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

string itoa(int val) {stringstream ss;ss << val;return ss.str();} 

char combinations[26][26];
char oppositions[26];
vector<char> elements;

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        string s;
        cin >> s;
        int s1 = s[0]-'A';
        int s2 = s[1]-'A';
        
        combinations[s1][s2] = combinations[s2][s1] = s[2];
    }
    
    cin >> n;
    for (int i = 0; i < n; i ++){
        string s;
        cin >> s;
        int s1 = s[0]-'A';
        int s2 = s[1]-'A';
        
        oppositions[s1] = s[1];
        oppositions[s2] = s[0];
    }
    
    cin >> n;
    string spell;
    cin >> spell;
    elements.push_back(spell[0]);
    for (int i = 1; i < n; i ++){
        char a = elements.back();
        char b = spell[i];
        if(combinations[a-'A'][b-'A'] != '#'){
            elements.pop_back();
            elements.push_back(combinations[a-'A'][b-'A']);
            continue;
        } else{
            elements.push_back(b);
        }
        char opp = oppositions[b-'A'];
        if(opp != '#'){
            for (int j = 0; j < elements.size(); j ++){
                if(elements[j] == opp){
                    elements.clear();
                    if(i < n-1){
                        elements.push_back(spell[i+1]);
                        i++;
                    }
                }
            }
        }
    }
    return;
}

int main(){

    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        memset(combinations, '#', sizeof combinations);
        memset(oppositions, '#', sizeof oppositions);
        elements.clear();
        solve();
        cout << "Case #" << i+1 << ": [";
        if(elements.size() > 0){
            for (int j = 0; j < elements.size()-1; j ++){
                cout << elements[j] << ", ";
            }
            cout << elements.back();
        }
        cout << "]" << endl;
    }

    return 0;
}
