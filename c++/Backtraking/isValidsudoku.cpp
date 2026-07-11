// question  : check the sudoku is valid 
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
bool isValid(vector<vector<char>>& board){
    vector<unordered_set<char>> rows(9), cols(9), boxes(9);
    
    int n = board.size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            char num = board[i][j];
            if(num == '.') continue; 

            // here we are not writing check function for the row and cols seprately
            // only go with the boxes conditions 

            int boxindex = (i/3)*3+(j/3);

            // now check the duplicates
            if(rows[i].count(num) || cols[j].count(num) || boxes[boxindex].count(num)){
                return false;
            }
            rows[i].insert(num);
            cols[j].insert(num);
            boxes[boxindex].insert(num);
        }
    }
    return  true;
}
int main(){
    return 0;
}