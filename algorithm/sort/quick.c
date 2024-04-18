#include<stdio.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quickSort(int arr[],int l,int r){
    if(l>=r)return;
    int temp=arr[l],i=l,j=r;
    while(i!=j){
        while(i<j&&arr[j]>=temp)j--;
        swap(&arr[i],&arr[j]);
        while(i<j&&arr[i]<=temp)i++;
        swap(&arr[i],&arr[j]);
    }
    quickSort(arr,l,i-1);
    quickSort(arr,i+1,r);
}
int main(){
    int arr[]={64, 34, 25, 12, 22, 11, 90};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)printf("%d ",arr[i]);
    return 0;
}
