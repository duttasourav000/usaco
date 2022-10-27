/*
ID: duttaso2
LANG: C++
TASK: beads
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    FILE *in, *out;
    in = fopen("beads.in", "r");
    out = fopen("beads.out", "w");

    int n;
    char str[351];
    fscanf (in, "%d", &n);
    fscanf (in, "%s", str);

    string beads(str);
    beads = beads + beads + beads;
    // cout << beads << endl;
    int m = 0;
    for (int i = n + 1; i < n + n; i++)
    {
        char c = beads[i - 1];
        int cnt = 1, j = i - 1;
        while (j >= 0 && cnt < n && (beads[j] == c || beads[j] == 'w' || c == 'w'))
        {
            if (c == 'w' & beads[j] != 'w')
                c = beads[j];

            j -= 1;
            cnt += 1;
        }

        c = beads[i];
        j = i + 1;
        while (j < beads.size() && cnt < n && (beads[j] == c || beads[j] == 'w' || c == 'w'))
        {
            if (c == 'w' & beads[j] != 'w')
                c = beads[j];

            j += 1;
            cnt += 1;
        }

        if (cnt > m)
        {
            // printf ("%d %d\n", i - n - 1, cnt);
            m = cnt;
        }
    }

    fprintf (out, "%d\n", m);

    fclose (in);
    fclose (out);
    return 0;
}