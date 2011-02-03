#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int N;
int trees[100000];
bool tried[100000];

int mincount = INT_MAX;

int main (int argc, char const* argv[]){
    
    cin >> N;
    for(int i = 0; i < N; i ++){
        cin >> trees[i];
    }
    
    for(int i = 0; i < (N/2 + N%2); i ++){
        int counter = 0;
        if(tried[i])
            continue;
            
        int len = max(trees[i] - i, trees[i] - (N-1-i));
        
        if(len < 1)
            continue;
            
        for(int j = 0; j < (N/2 + N%2); j++){
            if(trees[j] == len){
                tried[j] = true;
            }else{
                counter ++;
            }
            
            if(trees[N-1-j] == len){
                tried[N-1-j] = true;
            }else if(j != N/2){
                counter ++;
            }
            
            len ++;
        }
        
        //cout << "Tree " << i << " Count " << counter << endl;
        mincount = min(mincount, counter);
    }
    
    cout << mincount << endl;
    
    return 0;
}
