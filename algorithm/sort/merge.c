#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int l,int mid,int r){
    int size=r-l+1;
    int *temp=(int *)malloc(size*sizeof(int));
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
        if(arr[i]<=arr[j])temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    while(i<=mid)temp[k++]=arr[i++];
    while(j<=r)temp[k++]=arr[j++];
    for(k=0;k<size;k++)arr[l+k]=temp[k];
    free(temp);
}
void mergeSort(int arr[],int l,int r){
    if(l>=r)return;
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
int main(){
    int arr[]={64, 34, 25, 12, 22, 11, 90};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}