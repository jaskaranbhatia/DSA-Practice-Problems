#include<iostream>
#define MAX 10000
using namespace std;

void RadixSort (int a[], int n){
int i, m=0, exp=1, b[MAX];
    for (i=0; i<n; i++)
        if (a[i]>m)
            m=a[i];
    while (m/exp>0)
    {
        int bucket[10]={0};
        for (i=0; i<n; i++)
            bucket[9-a[i]/exp%10]++;      
        for (i=1; i<10; i++)
            bucket[i]+=bucket[i-1];
        for (i=n-1; i>=0; i--)
            b[--bucket[9-a[i]/exp%10]]=a[i];
        for (i=0; i<n;i++){
            a[i]=b[i];                  
        }
        exp*=10;
        for(int i=0;i<n;i++){
    		cout<<a[i]<<" ";
		}
		cout<<endl;
    }
}

int main() 
{ 
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    RadixSort(arr, n); 
    return 0; 
} 
