// problem : rat in the maze
// this is 2 ways it means 2*2
#include<iostream>
using namespace std;
int maze(int startingr, int startingc, int endingr, int endingc){
    
    if(startingr > endingr || startingc > endingc) return 0;
    if(startingr == endingr && startingc == endingc) return 1;
    
    int downways = maze(startingr + 1, startingc, endingr, endingc);
    int rightways = maze(startingr, startingc + 1, endingr, endingc);

    int totalways = downways + rightways;
    return totalways;
}
int main(){
    int rows = 2;
    int cols = 2;
    int count = maze(1, 1, rows, cols);
    cout<<"total no of ways : "<<count<<endl;
    return 0;
}