#include <bits/stdc++.h>
using namespace std;

int power(int x, int m) {
    int y = 1;
    if (m == 0) y = 1;
    else {
        y = power(x, m / 2);
        y = y * y;
        if (m & 1) y = y * x;
    }  
    return y;
}

int power2(int x, int m) {
    int y = 1;
    while (m > 0) {
        if (m & 1) y = y * x;
        x = x * x;
        m = m / 2;
    }
    return y;
}


int main() {
    cout << power(2, 10) << endl;
    cout << power2(2, 3) << endl;
}