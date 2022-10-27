/*
ID: duttaso2
LANG: C++
TASK: combo
*/

#include <iostream>
#include <vector>

using namespace std;

bool withinRange(vector<int>& comb, vector<int>& key, int n) {
    int ctr = 0;
    for (int i = 0; i < 3; i++) {
        if (abs(comb[i] - key[i]) <= 2 ||
            (n > 3 &&
                ((comb[i] > n - 2 && key[i] <= 2 - (n - comb[i])) || (comb[i] < 3 && key[i] >= n - 2 + comb[i]))
            ))
            ctr++;
    }

    return ctr == 3;
}

int main(void)
{
    FILE *in, *out;
    in = fopen("combo.in", "r");
    out = fopen("combo.out", "w");
    vector<int> comb(3, 0);
    vector<int> john(3, 0);
    vector<int> master(3, 0);
    int n, temp;

    fscanf(in, "%d", &n);
    for (int i = 0; i < 3; i++) {
        fscanf(in, "%d", &temp);
        john[i] = temp;
    }

    for (int i = 0; i < 3; i++) {
        fscanf(in, "%d", &temp);
        master[i] = temp;
    }

    int ctr = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)    
            for (int k = 1; k <= n; k++) {
                comb[0] = i;
                comb[1] = j;
                comb[2] = k;
                if (withinRange(comb, john, n) || withinRange(comb, master, n)) {
                    // cout << comb[0] << " " << comb[1] << " " << comb[2] << endl;
                    ctr++;
                }
            }

    fprintf(out, "%d\n", ctr);
    fclose(in);
    fclose(out);
    return 0;
}