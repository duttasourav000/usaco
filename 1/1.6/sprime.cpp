/*
ID: duttaso2
LANG: C++
TASK: sprime
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool isPrime(int n) {
    int nCopy = n;
    if (n == 1)
        return false;
    int sq = floor(sqrt(n));
    for (int i = 2; i <= sq; i++)
        if (n % i == 0) {
            return false;
        }

    return true;
}

void recurse(int n, int l, int maxL, FILE *out) {
    if (l == maxL) {
        fprintf(out, "%d\n", n);
        return;
    }

    for (int i = 1; i < 10; i += 2) {
        int temp = n * 10 + i;
        if (isPrime(temp))
            recurse(temp, l + 1, maxL, out);
    }
}

int main(void) {
    FILE *in, *out;
    in = fopen("sprime.in", "r");
    out = fopen("sprime.out", "w");

    int maxL;
    fscanf(in, "%d", &maxL);

    recurse(2, 1, maxL, out);
    recurse(3, 1, maxL, out);
    recurse(5, 1, maxL, out);
    recurse(7, 1, maxL, out);

    fclose(in);
    fclose(out);

    return 0;
}