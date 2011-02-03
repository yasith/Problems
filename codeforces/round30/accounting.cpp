#include <iostream>
#include <cmath>

using namespace std;

int findRoot(int num, int root){
    int newNum = (int)abs((float)num);
//    cout << "Finding root " << root << " for " << newNum << endl;
    for(int i = 2; i <= newNum/root; i++){
        int val = i;
//        cout << "Trying for " << i << endl;
        for(int j = 0; j < root-1; j++){
            val *= i;
        }
//        cout << "val is " << val << endl;
        if(val == newNum){
            if(num < 0 && (root % 2)){
                return (-i);
            } else 
                return i;
        }
        if(val > num)
            return 0;
    }
}

int main (int argc, char const* argv[]){
    int A, B, n;
    
    cin >> A >> B >> n;
 
    if(A == 0 || B == 0){
        cout << 1 << endl;
        return 0;
    }
    
    int x = findRoot(B/A, n);
    
    if(x){
        cout << x << endl;
    } else{
        cout << "No solution" << endl;
    }
    return 0;
}
