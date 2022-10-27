/*
ID: duttaso2
LANG: C++
TASK: ride
*/

#include <iostream>

using namespace std;

int getNum(char* s) {
    int res = 1;

    for (int i = 0; *(s + i) != '\0'; i++) {
        res *= *(s + i) - 64;
    }

    return res;
}

int main(void)
{
    FILE *in, *out;
    in = fopen("ride.in", "r");
    out = fopen("ride.out", "w");
    
    char a[7], b[7];
    
    fscanf(in, "%s\n%s", a, b);
    if ((getNum(a) % 47) == (getNum(b) % 47))
        fprintf(out, "GO\n");
    else
        fprintf(out, "STAY\n");

    fclose(in);
    fclose(out);
    return 0;
}