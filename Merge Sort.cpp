#include<stdio.h>
#include<math.h>
void MergeSort(int array[],int p,int q,int r )
{
    int n1,n2;
    n1=q-p+1;
    n2=r-q;
    int L[n1+1],R[n2+1];

    int i,j;
    for(i=0;i<n1;i++)
    {
        L[i]=array[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=array[q+1+j];
    }
    L[i]=INFINITY;
    R[j]=INFINITY;

    i=0,j=0;
    int k;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            array[k]=L[i];
            i++;
        }
        else
        {
            array[k]=R[j];
            j++;
        }
    }

}
void MergeSort(int array[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        MergeSort(array,p,q);
        MergeSort(array,q+1,r);
        MergeSort(array,p,q,r);
    }
}
int main()
{
    int n,i;
    printf("Enter the number:");
    scanf("%d",&n);
    int array[n];
    for(i=0;i<n;i++)
    scanf("%d",&array[i]);

    int p=0,r=n-1;

    MergeSort(array,p,r);

    printf("\nThe merge sort is \n:");
    for(i=0;i<n;i++)
    printf("%d\n",array[i]);
}
