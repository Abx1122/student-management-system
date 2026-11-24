#include <iostream>
#include <numeric>
#include <algorithm>

// 1. Euclidean Algorithm (Recursive)
long long euclideanGCD(long long a, long long b) {
    if (b == 0)
        return a;
    return euclideanGCD(b, a % b);
}

// 2. Binary GCD (Stein's Algorithm) - Bitwise optimization
long long binaryGCD(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int shift = 0;
    while (((a | b) & 1) == 0) {
        a >>= 1;
        b >>= 1;
        shift++;
    }

    while ((a & 1) == 0)
        a >>= 1;

    do {
        while ((b & 1) == 0)
            b >>= 1;

        if (a > b)
            std::swap(a, b);

        b = (b - a);
    } while (b != 0);

    return a << shift;
}

int main() {
    long long num1 = 48, num2 = 18;

    std::cout << "Computing GCD for " << num1 << " and " << num2 << ":\n";
    std::cout << "Euclidean GCD: " << euclideanGCD(num1, num2) << "\n";
    std::cout << "Binary GCD:    " << binaryGCD(num1, num2) << "\n";

    return 0;
}
