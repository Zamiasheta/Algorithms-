#include<stdio.h>
#include<math.h>
void selectionsort(int ara[],int n)
{
    int i,j,t;
    for(i=n-1;i>=0;i--)
    {
        int t=0;
        for(j=1;j<=i;j++)
        {
            if(ara[t]<ara[j])
                t=j;
        }
        int temp=ara[t];
        ara[t]=ara[i];
        ara[i]=temp;
    }
    for(i=0;i<n;i++)
        printf ("%d ",ara[i]);
}
int main()
{
    int i,n;
    scanf ("%d",&n);
    int ara[n+1];
    for(i=0;i<n;i++)
        scanf ("%d",&ara[i]);
        selectionsort(ara,n);
}

