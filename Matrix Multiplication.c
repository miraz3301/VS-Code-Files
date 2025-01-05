#include<stdio.h>
int main()
{
    printf("1st one:\n");
    int n,m;
    scanf("%d %d",&n,&m);
    int arr1[n][m];
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
 
            scanf("%d",&arr1[i][j]);
 
        }
    }
    printf("2nd one:\n");
    int p,q;
    scanf("%d %d",&p,&q);
    if(m!=p)
    {
        printf("Moron!! not possible");
        return 0;
    }
    int arr2[p][q],mul[n][q];
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
 
            scanf("%d",&arr2[i][j]);
 
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<q;j++)
        {
           int sum=0;
           for(int x=0;x<m;x++)
           {
               sum+=arr1[i][x]*arr2[x][j];
           }
           mul[i][j]=sum;
        }
    }
    printf("After MULtiplication :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<q;j++)
        {
            printf("%d ",mul[i][j]);
        }
        printf("\n");
    }
}