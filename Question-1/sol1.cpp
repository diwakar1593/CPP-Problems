#include<bits/stdc++.h>
using namespace std;

int firstOcc(vector<int>& arr,int n,int key){
    int s=0,e=n-1;
    int mid= s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else if(key<arr[mid]){
             e=mid-1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr,int n,int key){
    int s=0,e=n-1;
    int mid= s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(arr[mid]==key){
            ans=mid;
            s=mid+1;
        }
        else if(key>arr[mid]){
            s=mid+1;
        }
        else if(key<arr[mid]){
             e=mid-1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>sol;
       int n= nums.size();
    int f= firstOcc(nums,n,target);
        int l=lastOcc(nums,n,target);
   sol.push_back(f);
   sol.push_back(l);

        return sol ;
    }
};