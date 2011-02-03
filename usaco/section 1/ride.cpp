/*
ID: yasith.1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("ride.in");
ofstream fout("ride.out");

int main(){

    string comet, group;
    fin >> comet >> group;
    
    int comval, grpval;
    comval = grpval = 1;
    
    for(int i = 0; i < comet.size(); i++){
        comval = (comet[i] - 'A' + 1) * comval;
    }
    
    for(int i = 0; i < group.size(); i++){
        grpval = (group[i] - 'A' + 1) * grpval;
    }
    
    if(comval % 47 == grpval % 47)
        fout << "GO";
    else
        fout << "STAY";
        
    fout << endl;

    return 0;
}
