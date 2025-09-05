#include<iostream>

using namespace std;

void swap(int arr[], int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int j=l;
    int i=l-1;
    for(;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);//swap elements less than pivot to left
        }

    }
    //now i is pointing to the last element less than pivot
    //correct position for pivot will be i+1
    swap(arr[i+1],arr[r]);
    return i+1;


  
}

void quickSort(int arr[],int l,int r){
    //base case
    if(l>=r){
        return;
    }
    if (l<r){
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main(){
    int arr[]={20,50,4,2,3,1};
     int n=sizeof(arr)/sizeof(arr[0]); //a bad practice
    //int n= size(arr); //best practice available after c++17
    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;

}