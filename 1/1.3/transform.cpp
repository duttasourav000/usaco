/*
ID: duttaso2
LANG: C++
TASK: transform
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printMatrix(vector < string >& matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << matrix[i] << endl;
    }

    cout << endl;
}

void rotate90(vector < string >& matrix)
{
    char c;
    for (int i = 0; i < matrix.size() / 2; i++)
    {
        for (int j = i; j < matrix.size() - i - 1; j++)
        {
            // cout << i << " " << j << endl;
            c = matrix[i][j];
            matrix[i][j] = matrix[matrix.size() - j - 1][i];
            matrix[matrix.size() - j - 1][i] = matrix[matrix.size() - i - 1][matrix.size() - j - 1];
            matrix[matrix.size() - i - 1][matrix.size() - j - 1]  = matrix[j][matrix.size() - i - 1];
            matrix[j][matrix.size() - i - 1] = c;
            
        }
    }

    // printMatrix(matrix);
}

void reflection(vector < string >& matrix)
{
    char c;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size() / 2; j++)
        {
            // cout << i << " " << j << endl;
            c = matrix[i][j];
            matrix[i][j] = matrix[i][matrix.size() - j - 1];
            matrix[i][matrix.size() - j - 1] = c;
        }
    }

    // printMatrix(matrix);
}

bool areEqual(vector < string >& mat1, vector < string >& mat2)
{
    for (int i = 0; i < mat1.size(); i++)
        for (int j = 0; j < mat1[i].size(); j++)
            if (mat1[i][j] != mat2[i][j])
                return false;

    return true;
}
int main(void)
{
    FILE *in, *out;

    in = fopen("transform.in", "r");
    out = fopen("transform.out", "w");

    int n;
    fscanf (in, "%d", &n);
    char wC[11];
    vector < string > matrix;
    vector < string > pattern;
    for (int i = 0; i < n; i++)
    {
        fscanf (in, "%s", wC);
        string s(wC);
        matrix.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        fscanf (in, "%s", wC);
        string s(wC);
        pattern.push_back(s);
    }

    // printMatrix(matrix);
    // rotate90(matrix);
    // printMatrix(matrix);

    bool isNotDone = true;

    rotate90(matrix);
    if (isNotDone && areEqual(matrix, pattern))
    {
        isNotDone = false;
        fprintf (out, "1\n");
    }

    rotate90(matrix);
    if (isNotDone && areEqual(matrix, pattern))
    {
        isNotDone = false;
        fprintf (out, "2\n");
    }

    rotate90(matrix);
    if (isNotDone && areEqual(matrix, pattern))
    {
        isNotDone = false;
        fprintf (out, "3\n");
    }

    rotate90(matrix);
    reflection(matrix);
    if (isNotDone && areEqual(matrix, pattern))
    {
        isNotDone = false;
        fprintf (out, "4\n");
    }

    rotate90(matrix);
    if (isNotDone && areEqual(matrix, pattern))
    {
        isNotDone = false;
        fprintf (out, "5\n");
    }

    rotate90(matrix);
    if (isNotDone && areEqual(matrix, pattern))
    {
        isNotDone = false;
        fprintf (out, "5\n");
    }

    rotate90(matrix);
    if (isNotDone && areEqual(matrix, pattern))
    {
        isNotDone = false;
        fprintf (out, "5\n");
    }

    rotate90(matrix);
    reflection(matrix);
    if (isNotDone && areEqual(matrix, pattern))
    {
        isNotDone = false;
        fprintf (out, "6\n");
    }

    rotate90(matrix);
    if (isNotDone)
        fprintf (out, "7\n");

    fclose(in);
    fclose(out);
    return 0;
}