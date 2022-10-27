/*
ID: duttaso2
LANG: C++
TASK: milk
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    FILE *in, *out;
    in = fopen("milk.in", "r");
    out = fopen("milk.out", "w");
    
    int n, m, c, q;
    vector<pair<int, int>> costQuant;
    
    fscanf(in, "%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        fscanf(in, "%d %d", &c, &q);
        costQuant.push_back({c, q});
    }

    sort(costQuant.begin(), costQuant.end());
    int cost = 0;
    for (int i = 0; i < m; i++) {
        cost += min(n, costQuant[i].second) * costQuant[i].first;
        n -= min(n, costQuant[i].second);
    }

    fprintf(out, "%d\n", cost);

    fclose(in);
    fclose(out);
    return 0;
}