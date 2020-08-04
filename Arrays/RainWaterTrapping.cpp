#include<bits/stdc++.h>
using namespace std;

int findWater(int arr[],int n){
	int left_max = 0, right_max = 0;
	int res = 0;
	int l = 0, h = n-1;
	while(l <= h){
		if(arr[l] < arr[h]){
			if(arr[l] > left_max){
				left_max = arr[l];
			}
			else{
				res += left_max - arr[l];
			}
			l++;
		}
		else{
			if(arr[h] > right_max){
				right_max = arr[h];
			}
			else{
				res += right_max - arr[h];
			}
			h--;
		}
	}
	return res;
}

int main(){
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Maximum water that can be accumulated is "
         << findWater(arr, n);
}
