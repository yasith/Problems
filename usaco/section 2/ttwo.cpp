/*
ID: yasith.1
PROG: ttwo
LANG: C++
*/

#include <iostream>
#include <fstream>

#define MAX_MINS 10000

using namespace std;

ifstream fin ("ttwo.in");
ofstream fout("ttwo.out");

char map[11][11];

struct movement{
    int i, j;
}move[4];

struct tracker{
    int i, j;
    int mid;
    movement m;  
} cows, farmer;

int main(){

    move[0].i = -1; // NORTH
    move[0].j = 0;
    move[1].i = 0; // EAST
    move[1].j = 1;
    move[2].i = 1; // SOUTH
    move[2].j = 0;
    move[3].i = 0; // WEST
    move[3].j = -1;

    for(int i = 0; i < 10; i ++){
        fin >> map[i];
        for(int j = 0; j < 10; j ++){
            if(map[i][j] == 'C'){
                map[i][j] = '.';
                cows.i = i;
                cows.j = j;
                cows.mid = 0;
                cows.m = move[cows.mid];
            }
            if(map[i][j] == 'F'){
                map[i][j] = '.';
                farmer.i = i;
                farmer.j = j;
                farmer.mid = 0;
                farmer.m = move[farmer.mid];
            }
        }
    }   
    
    int mins = 0;
    
    while((cows.i != farmer.i) || (cows.j != farmer.j)){
        
        //#define debug
        #ifdef debug
        cout << "Going " << mins << endl;
        cout << "Farm " << farmer.i << " " << farmer.j << endl;
        cout << "Cows " << cows.i << " " <<  cows.j << endl;
        #endif
        
        if(mins > MAX_MINS){
            cout << 0 << endl;
            fout << 0 << endl;
            return 0;
        }
        mins ++;
        
        //COWS
        int di = cows.i+cows.m.i;
        int dj = cows.j+cows.m.j;
        if((map[di][dj] == '*') || 
                !((di >= 0 && di < 10) && 
                (dj >= 0 && dj < 10)) ){
            cows.mid = (cows.mid+1)%4;
            cows.m = move[cows.mid];
            di = cows.i+cows.m.i;
            dj = cows.j+cows.m.j;
        }else{
            cows.i = di;
            cows.j = dj;
        }
        
        //FARMER
        di = farmer.i+farmer.m.i;
        dj = farmer.j+farmer.m.j;
        if((map[di][dj] == '*') || 
                !((di >= 0 && di < 10) && 
                (dj >= 0 && dj < 10)) ){
            farmer.mid = (farmer.mid+1)%4;
            farmer.m = move[farmer.mid];
            di = farmer.i+farmer.m.i;
            dj = farmer.j+farmer.m.j;
        }else{
            farmer.i = di;
            farmer.j = dj;
        }
    }
    
    cout << mins << endl;
    fout << mins << endl;

    return 0;
}
