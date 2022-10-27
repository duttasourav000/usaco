/*
ID: duttaso2
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main(void)
{
    FILE *in, *out;
    int n;
	char name[1000];  /* bigger than necessary, room for newline */
    unordered_map < string , int > nameMoney;
    vector < string > names;

	in = fopen("gift1.in", "r");
	out = fopen("gift1.out", "w");

    fscanf (in, "%d", &n);
    // cout << n << endl;
    for (int i =0; i < n; i++)
    {
	    // fgets(name, sizeof name, in);
        fscanf (in, "%s", name);
        string s(name);
        names.push_back(s);
        nameMoney[s] = 0;

        // cout << s << endl;
    }

    int v, d;
    // fgets(name, sizeof name, in);
    while (!feof(in))
    {
        fscanf (in, "%s", name);
        string payer(name);
        fscanf (in, "%d %d", &v, &d);
        // cout << name << " " << v << " " << d << endl;
        int value = d == 0 ? 0 : v / d;
        int rem = d == 0 ? v : v % d;
        
        nameMoney[payer] -= v;
        nameMoney[payer] += rem;

        for (int i = 0; i < d; i++)
        {
            // fgets(name, sizeof name, in);
            fscanf (in, "%s", name);
            string rec(name);
            nameMoney[rec] += value;
            // cout << rec << endl;
        }
    }
    
    for (int i = 0; i < names.size(); i++)
        fprintf (out, "%s %d\n", names[i].c_str(), nameMoney[names[i]]);

    fclose (in);
    fclose (out);

    exit(0);
    // return 0;
}