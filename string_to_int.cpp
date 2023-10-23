#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s) {
        bool flag=false,temp=false;
        int i=0;
        while(i<s.length()){
            if(s[i]==' ')
            i++;
            else break;
        }
        s=s.substr(i);
        i=0;
        int sign=+1;
        if(s[0]=='-')
        sign=-1;
        long ans=0;
        i=(s[0]=='-'||s[0]=='+') ?1:0;        
        while(i<s.length()){
            if(s[i]==' '||!isdigit(s[i]))
            break;
            ans=ans*10+s[i]-'0';
            if(sign==-1&&-1*ans<INT_MIN)return INT_MIN;
            if(sign==1&&ans>INT_MAX)return INT_MAX;
            i++;
        }
        return (int)(ans*sign);
    }
int main(){
  string s;
  cin>>s;
  int int_of_s=myAtoi(s);
  cout<<"integer of s= "<<int_of_s<<endl;
  return 0;
}
