/*
ID: duttaso2
LANG: C++
TASK: milk3
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

struct Buckets {
    int a, b, c, id;
    Buckets(int aIn, int bIn, int cIn) : a(aIn), b(bIn), c(cIn), id(aIn * 10000 + bIn * 100 + cIn) {}

    bool operator==(const Buckets& that) const {
        return this->id == that.id;
    }
};

class BucketsHash { 
public: 
    size_t operator()(const Buckets& b) const
    { 
        return b.id; 
    } 
}; 
  

void findAllComb(int a, int b, int c, int ca, int cb, int cc, unordered_set<Buckets, BucketsHash>& visited, set<int>& cMilks) {
    Buckets buck(ca, cb, cc);
    if (visited.find(buck) != visited.end()) {
        return;
    }

    if (buck.a == 0)
        cMilks.insert(buck.c);
    Buckets copyBuck = buck;
    visited.insert(copyBuck);

    int temp;
    temp = min(ca, b - cb);
    findAllComb(a, b, c, ca - temp, cb + temp, cc, visited, cMilks);

    temp = min(ca, c - cc);
    findAllComb(a, b, c, ca - temp, cb, cc + temp, visited, cMilks);

    temp = min(cb, a - ca);
    findAllComb(a, b, c, ca + temp, cb - temp, cc, visited, cMilks);

    temp = min(cb, c - cc);
    findAllComb(a, b, c, ca, cb - temp, cc + temp, visited, cMilks);

    temp = min(cc, a - ca);
    findAllComb(a, b, c, ca + temp, cb, cc - temp, visited, cMilks);

    temp = min (cc, b - cb);
    findAllComb(a, b, c, ca, cb + temp, cc - temp, visited, cMilks);
}

int main(void) {
    FILE *in, *out;
    in = fopen("milk3.in", "r");
    out = fopen("milk3.out", "w");

    int a, b, c;
    fscanf(in, "%d %d %d", &a, &b, &c);

    int ca = 0, cb = 0, cc = c;
    Buckets buck(0, 0, c);
    unordered_set<Buckets, BucketsHash> visited;
    set<int> cMilks;
    findAllComb(a, b, c, ca, cb, cc, visited, cMilks);

    for (auto it = cMilks.begin(); it != cMilks.end(); it++)
        if (it == cMilks.begin())
            fprintf(out, "%d", *it);
        else
            fprintf(out, " %d", *it);
    fprintf(out, "\n");

    fclose(in);
    fclose(out);

    return 0;
}