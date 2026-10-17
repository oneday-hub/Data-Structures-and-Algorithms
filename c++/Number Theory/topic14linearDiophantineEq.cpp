// lecture 27 : Linear Diophantine Equation | Existence of Solutions + General Solution


#include <bits/stdc++.h>
using namespace std;

// Extended Euclidean Algorithm
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

// Finds one solution to ax + by = c
bool linear_Diophantine(int a, int b, int c,
                        int &x0, int &y0, int &g) {
    g = extended_gcd(abs(a), abs(b), x0, y0);

    if (c % g != 0) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;

    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;

    return true;
}

int main() {
    int a = 15, b = 25, c = 5;

    int x0, y0, g;

    if (linear_Diophantine(a, b, c, x0, y0, g)) {
        cout << "Solution exists!\n";
        cout << "gcd(a, b) = " << g << '\n';
        cout << "One solution: x = " << x0
             << ", y = " << y0 << '\n';

        cout << "Verification: "
             << a << "(" << x0 << ") + "
             << b << "(" << y0 << ") = "
             << a * x0 + b * y0 << '\n';
    } else {
        cout << "No integer solution exists.\n";
    }

    return 0;
}
