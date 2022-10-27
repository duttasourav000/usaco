/*
ID: duttaso2
LANG: C++
TASK: dualpal
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left <= right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    
    return true;
}

string getNumInBase(int n, int b) {
    string numInBase = "";
    int rem;
    while (n > 0) {
        rem = n % b;
        if (rem >= 10)
            numInBase += 'A' + (rem - 10);
        else
            numInBase += rem + '0';
        n /= b;
    }

    reverse(numInBase.begin(), numInBase.end());
    return numInBase;
}

int main(void)
{
    FILE *in, *out;
    in = fopen("dualpal.in", "r");
    out = fopen("dualpal.out", "w");
    
    int n, s, ctr = 0, p;
    string iInBaseB;
    
    fscanf(in, "%d %d", &n, &s);
    for (int i = s + 1; i <= INT_MAX && ctr < n; i++) {
        p = 0;
        for (int b = 2; b <= 10; b++) {
            iInBaseB = getNumInBase(i, b);
            if (isPalindrome(iInBaseB))
                p++;
            if (p == 2)
                break;
        }

        if (p == 2) {
            fprintf (out, "%d\n", i);
            ctr++;
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}