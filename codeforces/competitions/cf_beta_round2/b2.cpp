#include <iostream>
#include<stdio.h>
#include <algorithm>
using namespace std;
 
int dv[1100][1100][2];
int sln[1100][1100][2];
void show(int i, int j, int k)
  {
    if (i && sln[i][j][k]==dv[i][j][k]+sln[i-1][j][k])
      {
        show(i-1, j, k);
        printf("D");
      }
    else if (j)
      {
        show(i, j-1, k);
        printf("R");
      }
  }
int main()
  {
    int n, a;
    scanf("%d", &n);
    int ps=1;
    int ii, jj;
    for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < n; ++j)
          {
            scanf("%d", &a);
            if (a)
              {
                while (a%2==0)
                  {
                    a/=2;
                    dv[i][j][0]++;
                  }
                while (a%5==0)
                  {
                    a/=5;
                    dv[i][j][1]++;
                  }
              }
            else
              {
                dv[i][j][0]=dv[i][j][1]=100000;
                ps=0;
                ii=i;
                jj=j;
              }
            sln[i][j][0]=sln[i][j][1]=1000000000;
            if (i==0 && j==0)
              sln[i][j][0]=sln[i][j][1]=0;
            for (int k = 0; k < 2; ++k)
              {
                if (i)
                  sln[i][j][k]=min(sln[i][j][k], sln[i-1][j][k]);
                if (j)
                  sln[i][j][k]=min(sln[i][j][k], sln[i][j-1][k]);
                sln[i][j][k]+=dv[i][j][k];
              }
          }
      }
 
    int ans= min(sln[n-1][n-1][0], sln[n-1][n-1][1]);
    if (ans>1 && ps==0)
      {
        ans=1;
        printf("%d\n", ans);
        for (int i = 0; i < ii; ++i)
          {
            printf("D");
          }
        for (int j = 0; j < n-1; ++j)
          {
            printf("R");
          }
        for (int i = ii; i < n-1; ++i)
          {
            printf("D");
          }
      }
    else
      {
        printf("%d\n", ans);
        if (sln[n-1][n-1][0]<sln[n-1][n-1][1])
          show(n-1, n-1, 0);
        else
          show(n-1, n-1, 1);
      }
    puts("");
    return 0;
  }
