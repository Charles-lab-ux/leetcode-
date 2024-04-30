#include<iostream>
#include <vector>
using namespace std;
void quickSort(vector<int>& arr,int l,int r){
    if(l>=r)return;
    int pivot=arr[l],i=l,j=r;
    while(i<j){
        while(i<j&&arr[j]>=pivot)j--;
        swap(arr[i],arr[j]);
        while(i<j&&arr[i]<pivot)i++;
        swap(arr[i],arr[j]);
    }
    quickSort(arr, l,i-1);
    quickSort(arr,i+1,r);
}
int main(){
    vector<int> arr{4, 3, 12, 5, 1, 100};
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    quickSort(arr,0,arr.size()-1);
    cout<<endl;
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    return 0;
}