/*
ID: duttaso2
LANG: C++
TASK: skidesign
*/

// 22946

#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    FILE *in, *out;
    
    in = fopen("skidesign.in", "r");
    out = fopen("skidesign.out", "w");

    int n, temp;
    vector<int> heights;
    fscanf(in, "%d", &n);

    for (int i = 0; i < n; i++) {
        fscanf(in, "%d", &temp);
        heights.push_back(temp);
    }

    int minCost = INT_MAX, cost;
    int endLimit = 100 - 17, upperLimit;
    for (int i = 0; i <= endLimit; i++) {
        cost = 0;
        upperLimit = i + 17;
        for (int j = 0; j < n; j++) {
            if (heights[j] < i) {
                cost += pow(i - heights[j], 2);
            }
            else if (heights[j] > upperLimit) {
                cost += pow(heights[j] - upperLimit, 2);
            }
        }

        minCost = min(cost, minCost);
    }

    fprintf(out, "%d\n", minCost);
    fclose(in);
    fclose(out);
    return 0;
}