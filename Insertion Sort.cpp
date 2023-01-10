#include<stdio.h>
#include<math.h>
void insertationsort(int ara[],int n)
{
    int ara2[n+2];
    ara2[0]=(pow(2,32)-1)*-1;
    int i,j;
    for(i=0;i<n;i++)
        ara2[i+1]=ara[i];

    for(j=1;j<=n;j++)
    {
        int temp=ara2[j];
        i=j-1;
        while(temp<ara2[i])
        {
            ara2[i+1]=ara2[i];
            i--;
        }
        ara2[i+1]=temp;
    }
    for(i=1;i<=n;i++)
        printf ("%d ",ara2[i]);
}
int main()
{
    int i,n;
    scanf ("%d",&n);
    int ara[n+1];
    for(i=0;i<n;i++)
        scanf ("%d",&ara[i]);
        insertationsort(ara,n);
}

