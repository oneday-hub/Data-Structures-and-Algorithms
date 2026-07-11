#include <iostream>
using namespace std;
int add(int num1, int num2){
int sum = num1 + num2;
return sum;
}
int add(int num1, int num2, int num3){
    int sum = num1+num2+num3;
    return sum;
}
float add(float num1, float num2){
    float sum = num1+num2;
    return sum;

}
    int main(){
        float a = 4.8;
        float b = 8.0;
        int  c = 98;
        cout<<add(a,b)<<endl;
        return 0;
    }