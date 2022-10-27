/*
ID: duttaso2
LANG: C++
TASK: namenum
*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

void check(int pos, string& num, string& word, vector < string >& numMap, set < string >& dict, vector < string >& ans)
{
    if (pos >= num.size())
    {
        if (dict.find(word) != dict.end())
            ans.push_back(word);
        return;
    }

    // cout << num[pos] << " " << numMap[num[pos] - 48 - 2] << endl;
    for (int i = 0; i < numMap[num[pos] - 48 - 2].size(); i++)
    {
        word[pos] = numMap[num[pos] - 48 - 2][i];
        // cout << word << endl;

        check(pos + 1, num, word, numMap, dict, ans);
    }
}

int main(void)
{
    vector < string > numMap {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
    set < string > dict;

    FILE *d;
    char dC[15];
    d = fopen("dict.txt", "r");
    while (fscanf(d, "%s", dC) != EOF)
    {
        string dS(dC);
        dict.insert(dS);
    }

    fclose(d);

    FILE *in, *out;
    in = fopen("namenum.in", "r");
    out = fopen("namenum.out", "w");

    char numC[13];
    fscanf(in, "%s", numC);
    string num(numC);

    string word = num;
    for (int i = 0; i < word.size(); i++)
        word[i] = '1';

    vector < string > ans;
    check(0, num, word, numMap, dict, ans);

    // cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        fprintf (out, "%s\n", ans[i].c_str());

    if (ans.size() == 0)
        fprintf (out, "NONE\n");

    fclose(in);
    fclose(out);
    return 0;
}