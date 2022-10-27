/*
ID: duttaso2
LANG: C++
TASK: palsquare
*/

#include <iostream>
#include <string>
#include <algorithm>

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
    in = fopen("palsquare.in", "r");
    out = fopen("palsquare.out", "w");
    
    int b, iSq;
    string iSqInBaseB, iInBaseB;
    
    fscanf(in, "%d", &b);
    for (int i = 1; i <= 300; i++) {
        iSq = i * i;
        iSqInBaseB = getNumInBase(iSq, b);
        if (isPalindrome(iSqInBaseB)) {
            iInBaseB = getNumInBase(i, b);
            fprintf (out, "%s %s\n", iInBaseB.c_str(), iSqInBaseB.c_str());
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}