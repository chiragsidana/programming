#include<bits/stdc++.h>
using namespace std;
int findpeakelement(int arr[],int low,int high,int n){
    int mid=low+(high-low)/2;
    if((mid==1 or arr[mid-1]<=arr[mid]) and (mid==n-1 or arr[mid+1]<=arr[mid])){
        return mid;

    }
    else if(mid>0 and arr[mid-1]>arr[mid]){
        return findpeakelement(arr,low,mid-1,n);
    }
    else{
        return findpeakelement(arr,mid+1,high,n);
    }
}
int main(){
int arr[]={0,6,8,5,7,9};
int n=6;
cout<<findpeakelement(arr,0,n-1,n)<<endl;

return 0;
}