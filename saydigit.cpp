#include<iostream>
using namespace std;
void sd(string arr[],int n)
{
    if(n==0)
    {
        return;
    }
    int c=n%10;
    n=n/10;
    sd(arr,n);
    cout<<arr[c]<<" ";

}
int main()
{
    int n;
    cout<<"enter any  no ";
    cin>>n;
    string ar[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    sd(ar,n);
}
