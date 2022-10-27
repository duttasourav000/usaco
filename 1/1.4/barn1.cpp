/*
ID: duttaso2
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    FILE *in, *out;
    in = fopen("barn1.in", "r");
    out = fopen("barn1.out", "w");
    
    int m, s, c, temp;
    vector<int> occupied;
    vector<int> dist;
    
    fscanf(in, "%d %d %d", &m, &s, &c);
    for (int i = 0; i < c; i++) {
        fscanf(in, "%d", &temp);
        occupied.push_back(temp);
    }

    sort(occupied.begin(), occupied.end());
    for (int i = 1; i < occupied.size(); i++)
        dist.push_back(occupied[i] - occupied[i - 1] - 1);

    sort(dist.begin(), dist.end());

    int ans = (int)occupied.size();
    int blocks = (int)occupied.size();

    for (int i = 0; i < dist.size(); i++) {
        // cout << blocks << " " << ans << endl;
        if (blocks <= m)
            break;
        ans += dist[i];
        blocks -= 1;
    }

    fprintf(out, "%d\n", ans);

    fclose(in);
    fclose(out);
    return 0;
}