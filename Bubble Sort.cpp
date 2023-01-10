#include <stdio.h>
#include<math.h>
void bubblesort(int ara[],int n)
{
    int i,j,k=n;
    while(k!=0)
    {
        int t=0;
        for(j=0;j<k;j++)
        {
            if(ara[j]>ara[j+1])
            {
                int temp=ara[j+1];
                ara[j+1]=ara[j];
                ara[j]=temp;
                t=j;
            }
        }
        k=t;
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
        bubblesort(ara,n);
}
