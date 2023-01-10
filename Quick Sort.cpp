#include<iostream>
using namespace std;
void quickSort(int a[], int m,int l)
{
    int i,j,temp;
    if(m<l)
    {
        i=m+1;
        j=l;
        while(a[i]<a[m])
            i++;
        while(a[j]>a[m])
            j--;
        while(i<j)
        {
            temp = a[i];
            a[i]=a[j];
            a[j]=temp;
            while(a[i]<a[m])
                i++;
            while(a[j]>a[m])
                j--;
        }
        temp = a[j];
        a[j]=a[m];
        a[m]=temp;
        quickSort(a,m,j-1);
        quickSort(a,j+1,l);
    }
}
int main()
{

    int i,j;
    int arr[10] = {10,12,16,5,2,32,25,15,9,49};
    for(i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
       cout<<" "<<endl;
    quickSort(arr,0,10-1);
    for(i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
