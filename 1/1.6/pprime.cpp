/*
ID: duttaso2
LANG: C++
TASK: pprime
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n == 1)
        return false;
    int sq = floor(sqrt(n));
    for (int i = 2; i <= sq; i++)
        if (n % i == 0) {
            return false;
        }

    return true;
}

int getNum(string s) {
    int n = 0;
    for (auto c: s) {
        n = n * 10 + (c - '0');
    }

    return n;
}

void findPalindromes(string s, const int& a, const int& b, vector<int>& res) {
    if (s.size() > 8)
        return;

    int n = getNum(s);
    if (n > b)
        return;

    if (s[0] != '0') {
        if (n >= a && n <= b && isPrime(n))
            res.push_back(n);
    }

    for (char i = '0'; i <= '9'; i++) {
        findPalindromes(i + s + i, a, b, res);
    }
}

int main(void) {
    FILE *in, *out;
    in = fopen("pprime.in", "r");
    out = fopen("pprime.out", "w");

    int a, b, temp;
    fscanf(in, "%d %d", &a, &b);
    vector<int> res;

    for (int i = 0; i < 10; i++) {
        string s = to_string(i);
        findPalindromes(s, a, b, res);
    }

    for (int i = 0; i < 10; i++) {
        string s = to_string(i) + to_string(i);
        findPalindromes(s, a, b, res);
    }

    sort(res.begin(), res.end());
    for (auto& x: res)
        fprintf(out, "%d\n", x);

    fclose(in);
    fclose(out);

    return 0;
}