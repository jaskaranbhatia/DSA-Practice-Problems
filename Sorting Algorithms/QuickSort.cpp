#include<iostream>
using namespace std;

int partition(int arr[],int l, int r){
	int pivot = arr[r];
	int i = l-1;
	for(int j=l;j<r;j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return (i+1);	
}

int partition1(int arr[],int l,int e)
{
	int pivot=arr[l];
	int j=l+1;
	for(int i=l+1;i<=e;i++){
		if(arr[i]<pivot){
        	if(i!=j){  
            	swap(arr[j],arr[i]);
      		}    
			j++;
    	}
	}
    arr[l]=arr[j-1];
    arr[j-1]=pivot;
	return j-1;
}

void quickSort(int arr[],int l,int r){
	if(l<r){
		int p = partition1(arr,l,r);
		quickSort(arr,l,p-1);
		quickSort(arr,p+1,r);
	}
}

void print(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int arr[] = {5,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Unsorted Array is : ";
	print(arr,n);
	quickSort(arr,0,n-1);
	cout<<"Sorted Array is : ";
	print(arr,n);
	return 0;
}
