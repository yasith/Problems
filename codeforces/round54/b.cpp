#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int maxdenoms;
vector<int> maxvals;

#undef debug

void find(int den, int count, vector<int> vals){
    
    #ifdef debug
    cout << "Finding for " << den << " at " << count << endl;
    #endif
    
    if(den == 1){
        if(maxdenoms < count){
            maxdenoms = count;
            maxvals = vals;
        }
        return;
    }
    
    #ifdef debug
    cout << "Squareroot " << sqrt(den) << endl;
    #endif
    
    bool found = false;
    for(int i = 2; i <= sqrt(den); i++){
        if(den % i == 0){
            found = true;
            vals.push_back(den/i);
            find(den/i, count+1, vals);
        }
    }
    if(!found){
        vals.push_back(1);
        find(1, count+1, vals);
    }
    return;
}

int main (int argc, char const* argv[]){
    
    cin >> N;
    
    vector<int> vals;
    vals.push_back(N);
    find(N, 1, vals);
    
    //cout << maxdenoms << endl;
    for(int i = 0; i < maxdenoms; i++){
        cout << maxvals[i] << " ";
    }
    cout << endl;
       
    return 0;
}
