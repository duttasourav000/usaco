/*
ID: duttaso2
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <vector>

using namespace std;

bool isValid(int prod, vector<int>& digitsVec, int low, int high) {
    if (prod >= low && prod <= high) {
        while (prod > 0) {
            if (digitsVec[prod % 10] == 0)
                break;
            prod /= 10;
        }

        if (prod == 0) {
            return true;
        }
    }

    return false;
}

int main(void)
{
    FILE *in, *out;
    in = fopen("crypt1.in", "r");
    out = fopen("crypt1.out", "w");
    vector<int> digitsVec(10, 0);
    vector<int>digits;
    int n, temp;

    fscanf(in, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(in, "%d", &temp);
        digits.push_back(temp);
        digitsVec[temp] = 1;
    }

    vector<int> a;
    vector<int> b;
    for (int i = 0; i < digits.size(); i++)
        for (int j = 0; j < digits.size(); j++)    
            for (int k = 0; k < digits.size(); k++) {
                a.push_back(digits[i] * 100 + digits[j] * 10 + digits[k]);
                // cout << a[a.size() - 1] << endl;
            }

    for (int j = 0; j < digits.size(); j++)    
        for (int k = 0; k < digits.size(); k++)
            b.push_back(digits[j] * 10 + digits[k]);

    int ctr = 0, prod;
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++) {
            if (isValid(a[i] * b[j], digitsVec, 1000, 9999) &&
                isValid(a[i] * (b[j] / 10), digitsVec, 100, 999) &&
                isValid(a[i] * (b[j] % 10), digitsVec, 100, 999))
                ctr++;
        }

    fprintf(out, "%d\n", ctr);

    fclose(in);
    fclose(out);
    return 0;
}