#include <iostream>
#include <algorithm>  // For std::gcd
#include <numeric>    // For std::lcm in C++17 or later

using namespace std;

// Function to compute the Least Common Multiple (LCM) using GCD
long long lcm(long long x, long long y) {
    return (x * y) / __gcd(x, y);
}

// Function to count how many numbers <= X are divisible by exactly two of a, b, c
long long rif(long long X, long long a, long long b, long long c) {
    long long lcab = lcm(a, b);
    long long lcbc = lcm(b, c);
    long long lcac = lcm(a, c);
    long long lcabc = lcm(lcab, c);

    // Count numbers divisible by exactly two of the three numbers
    long long cnt = (X / lcab) + (X / lcbc) + (X / lcac);
    cnt -= 3 * (X / lcabc);  // Subtract numbers divisible by all three
    return cnt;
}

// Binary search to find the n-th valid number
long long nvalid(long long a, long long b, long long c, long long n) {
    long long l = 1, h = 1e18, result = -1;
    while (l <= h) {
        long long mid = (l + h) / 2;
        if (rif(mid, a, b, c) >= n) {
            result = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return (result <= 1e18) ? result : -1;
}

int main() {
    long long a, b, c, n;
    cin >> a >> b >> c;
    cin >> n;

    // Find and print the n-th valid number
    cout << nvalid(a, b, c, n) << endl;

    return 0;
}
