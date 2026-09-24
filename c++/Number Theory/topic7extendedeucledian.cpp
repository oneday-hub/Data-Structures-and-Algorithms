// Extended Euclidean algorithms Explained with Bezout's identity
/*
2. Euclidean Algorithm

The Euclidean Algorithm repeatedly uses the division formula:
a=bq+r

The key property is:
gcd(a,b)=gcd(b,amodb)
	​
Example: Find GCD(18, 12)
Step 1:
18=12×1+6
Step 2:
12=6×2+0

When the remainder becomes zero, the last nonzero remainder is the GCD.
gcd(18,12)=6
	​
Key Idea

The Euclidean Algorithm calculates the GCD. The Extended Euclidean Algorithm goes 
one step further: it also finds coefficients that express the GCD as a linear 
combination of the original numbers.

3. Bézout's Identity

Definition
For any two integers a and b, not both zero, there exist integers x and y such that:

ax+by=gcd(a,b)
This equation is called Bézout's Identity.

Here:
Symbol      Meaning
a,b         Given integers
x,y         Bézout coefficients
gcd(a,b)    Greatest common divisor

The Extended Euclidean Algorithm finds the values of x and y.

*/
#include <bits/stdc++.h>
using namespace std;


// Extended gcd for two numbers (from previous implementation)


int extended_gcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1; 
		y = 0; 
		return a;
	}

	int x1, y1; 
	int gcd = extended_gcd(b, a%b, x1, y1);

	x = y1; 
	y = x1 - (a/b) * y1;

	return gcd;
}

// Extended gcd for three numbers

int extended_gcd_three(int a, int b, int &x, int &y, int &z){

	// step 1 : find gcd(a, b) and co efficients u, v

	int u, v; 
	int d = extended_gcd(a, b, u, b);

	// step 2 : find gcd(d, c) and co efficents X, Z

	int X, Z;
	int g = extended_gcd(d, c, X, Z);

	// step 3 : combine the results
	x = u * X; 
	y = v * X; 
	z = Z;

	return g;
}


int main() {
    
    
    return 0;
}