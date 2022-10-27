/*
ID: duttaso2
LANG: C++
TASK: friday
*/

#include <cstdio>

int main(void)
{
    FILE *in, *out;
    in = fopen("friday.in", "r");
    out = fopen("friday.out", "w");

    int n;
    fscanf (in, "%d", &n);

    int ans[7] = {0};
    int days[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int curDay = 1;
    for (int i = 0; i < n; i++)
    {
        int y = 1900 + i, leap = 0;
        if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
        {
            leap = 1;
        }

        for (int j = 0; j < 12; j++)
        {
            for (int k = 0; k < days[leap][j]; k++)
            {
                curDay = (curDay + 1) % 7;
                if (k + 1 == 13)
                    ans[curDay] += 1;
            }
        }
    }

    for (int i = 0; i < 7; i++)
    if (i == 6)
        fprintf (out, "%d\n", ans[i]);
    else
        fprintf (out, "%d ", ans[i]);

    fclose(in);
    fclose(out);
    return 0;
}