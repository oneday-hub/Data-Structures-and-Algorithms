// rat in the maze : 4 direction 
#include<iostream>
#include<vector>
using namespace std;

int fourDirection (int sr, int sc, int er, int ec, string s){
    if(sr>er || sc>ec || sr<0, sc<0) return 0;

    if(sr == er && sc ==ec) {
        cout<<s<<endl;
        return 1;
    }
    

}
int main(){
    int rows = 3; 
    int cols = 3; 
    int count = fourDirection(0, 0, rows-1, cols-1, "");
    cout<<"total ways :"<<count<<endl;
    return 0;
}