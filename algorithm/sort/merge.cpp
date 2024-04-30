#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& arr,int l,int mid,int r){
    int n=r-l+1;
    vector<int> temp(n);
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
        if(arr[i]<=arr[j])temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    while(i<=mid)temp[k++]=arr[i++];
    while(j<=r)temp[k++]=arr[j++];
    for(k=0;k<n;k++)arr[l+k]=temp[k];
}
void mergeSort(vector<int>& arr,int l,int r){
    if(l>=r)return;
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main(){
    vector<int> arr{4, 3, 12, 5, 1};
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    mergeSort(arr,0,arr.size()-1);
    cout<<endl;
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    return 0;
}