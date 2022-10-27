/*
ID: duttaso2
LANG: C++
TASK: milk2
*/

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct MilkTime
{
    int time;
    bool isStart;

    MilkTime (int t, bool isS): time(t), isStart(isS) {};
};

bool timeSort(const MilkTime *a, const MilkTime *b)
{
    if (a->time == b->time)
        return a->isStart;

    return a->time < b->time;
}

int main(void)
{
    vector < MilkTime* > milkTimes;

    FILE *in, *out;
    in = fopen("milk2.in", "r");
    out = fopen("milk2.out", "w");

    int n, a, b;
    fscanf (in, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf (in, "%d %d", &a, &b);
        milkTimes.push_back(new MilkTime(a, true));
        milkTimes.push_back(new MilkTime(b, false));
    }

    sort (milkTimes.begin(), milkTimes.end(), timeSort);

    // for (int i = 0; i < milkTimes.size(); i++)
    //     cout << milkTimes[i]->time << " " << milkTimes[i]->isStart << endl;

    int lastStartTime = 0, lastEndTime = 0, started = 0;
    int longestMilkTime = 0, longestNotMilkTime = 0;
    for (int i = 0; i < milkTimes.size(); i++)
    {
        if (milkTimes[i]->isStart)
        {
            if (started == 0)
            {
                lastStartTime = milkTimes[i]->time;
                longestNotMilkTime = i == 0 ? 0 : max(longestNotMilkTime, milkTimes[i]->time - lastEndTime);
            }
            
            started += 1;
        }
        else
        {
            if (started == 1)
            {
                longestMilkTime = max(longestMilkTime, milkTimes[i]->time - lastStartTime);
                lastEndTime = milkTimes[i]->time;
            }

            started -= 1;
        }
    }

    fprintf (out, "%d %d\n", longestMilkTime, longestNotMilkTime);
    fclose(in);
    fclose(out);

    return 0;
}