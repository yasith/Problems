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

int nums[1000];
int answer;
int n;
vector<int> val;
bool zero;

bool comp(int a, int b){
    return a > b;
}

inline vector<int> tobinary(int num){
    vector<int> result;
    while(num != 1){
        result.push_back(num%2);
        num = num/2;
    }
    result.push_back(1);
    
    return result;
}

inline void print(vector<int> v){
for (int i = 0; i < v.size(); i ++){
        cout << v[i] << " ";
    }
    cout << endl;
}

inline void add(int num){
    vector<int> v1 = val;
    vector<int> v2 = tobinary(num);
    //cout << num << " -> "; print(v2);
    
    int len = max(v1.size(), v2.size());
    
    val.clear();
    
    zero = true;
    for (int i = 0; i < len; i ++){
        int a = v1.size() > i ? v1[i] : 0;
        int b = v2.size() > i ? v2[i] : 0;
        if(a == b){
            val.push_back(0);
        } else{
            zero = false;
            val.push_back(1);
        }
    }
    /*
    print(v1);
    print(v2);
    print(val);
    cout << "---" << endl;
    */
}

void solve(){
    cin >> n;
    answer = 0;
    for (int i = 0; i < n; i ++){
        cin >> nums[i];
        add(nums[i]);
    }
    if(!zero){
        return;    
    }
    sort(nums, nums+n, comp);
    for (int i = 0; i < n-1; i ++){
        answer += nums[i];
    }   
}

int main(){

    int t;
    cin >> t;
    for (int i = 0; i < t; i ++){
        val.clear();
        solve();
        cout << "Case #" << i+1 << ": ";
        if(answer == 0){
            cout << "NO" << endl;
        }else{
            cout << answer << endl;
        }
    }

    return 0;
}
