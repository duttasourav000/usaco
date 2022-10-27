/*
ID: duttaso2
LANG: C++
TASK: ariprog
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;

int main(void) {
    FILE *in, *out;
    in = fopen("ariprog.in", "r");
    out = fopen("ariprog.out", "w");

    int n, m;
    fscanf(in, "%d", &n);
    fscanf(in, "%d", &m);

    int maxNum = m * m + m * m;
    vector<bool> isBiSquare(maxNum + 1, false);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            isBiSquare[i * i + j * j] = true;
        }
    }

    vector<int> biSquares;
    for (int i = 0; i < isBiSquare.size(); i++)
        if (isBiSquare[i]) {
            biSquares.push_back(i);
        }

    bool isFound = false;
    vector<pair<int, int>> diffStart;

    int start, end;
    int lastBisquare = biSquares[biSquares.size() - 1];

    int next;
    int dLimit = lastBisquare / 2;
    vector<int> lengthFromHere(lastBisquare + dLimit + 1, 0);
    for (int d = 1; d <= dLimit; d++) {
        for (int i = biSquares.size() - 1; i >= 0; i--) {
            start = biSquares[i];
            lengthFromHere[start] = 1 + lengthFromHere[start + d];

            if (lengthFromHere[start] >= n)
                diffStart.push_back({d, start});
        }
    }

    sort(diffStart.begin(), diffStart.end());
    for (auto& p: diffStart)
        fprintf(out, "%d %d\n", p.second, p.first);

    if (diffStart.size() == 0)
        fprintf(out, "NONE\n");

    fclose(in);
    fclose(out);

    return 0;
}