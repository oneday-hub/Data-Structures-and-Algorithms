#include <iostream>
using namespace std;
int main(){
int marks;
cin>>marks; 
if(marks>80){
    cout<<"grade A";
}
    else if (marks<70){
cout<<"grade B";
 }
else if (marks<60){
    cout<<"Grade C";

}
else if (marks<50){
    cout<<"Grade D";
}
else 
cout<<"E";
return 0;
}
