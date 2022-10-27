/*
ID: duttaso2
LANG: C++
TASK: numtri
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    FILE *in, *out;
    in = fopen("numtri.in", "r");
    out = fopen("numtri.out", "w");

    int n;
    fscanf(in, "%d", &n);

    vector<int> prev, now;
    int ctr = 1, temp, up, left;
    for (int i = 0; i < n; i++) {
        now.clear();
        for (int j = 0; j < ctr; j++) {
            fscanf(in, "%d", &temp);
            up = j;
            left = j - 1;
            now.push_back(
                max(
                    temp + (up >= 0 && up < prev.size() ? prev[up] : 0),
                    temp + (left >= 0 && left < prev.size() ? prev[left] : 0)
                )
            );
        }

        // for (auto x: now)
        //     cout << x << " ";
        // cout << endl;

        ctr++;
        prev = now;
    }

    int res = *max_element(prev.begin(), prev.end());
    fprintf(out, "%d\n", res);

    fclose(in);
    fclose(out);

    return 0;
}