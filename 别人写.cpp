#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

#include <math.h>
using namespace std;
const int N = 100000 + 10;
bool vis[N];
int prime[N];
int cnt;
int hs[N];
void makePrimeTable()
{
    for (int i = 3; i < 320; ++i)
    {
        if (!vis[i])
        for (int j = i*i; j < N; j += 2 * i)
            vis[j] = true;
    }
    prime[cnt++] = 2;
    for (int i = 3; i < N; ++i)
    if ((i & 1) == 1 && !vis[i])
        prime[cnt++] = i;
}
int main()
{
    int n;
    makePrimeTable();
    for (int i = 0; i < cnt; ++i)
    for (int j = i + 1; prime[i] + prime[j]<=100000 && j < cnt; ++j)
    {
        hs[prime[i] + prime[j]]++;
    }
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", hs[n]);
    }
    return 0;
}
