#include<stdio.h>
#include<vector>
using namespace std;
void merge(int arr1[],int n,int arr2[],int m,int arr3[])
{
    int i=0,j=0,k=0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }
    while(i<n)
    {
        arr3[k++]=arr1[i++];
    }
     while(j<n)
    {
        arr3[k++]=arr1[j++];
    }
}
void prnt(int arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //return 0;
}
int main(){
    int n=4,m=3;
  int arr1[4]={2,4,6,8};
  int arr2[3]={1,3,5};
  int arr3[7]={0};
  merge(arr1,n,arr2,m,arr3);
  prnt(arr3,7);
  return 0;
}
