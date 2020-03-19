#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str,int low,int high){
	while(low < high){
		if(str[low] != str[high]){
			return false;
		}
		low++;
		high--;
	}
	return true;
}

void allPalUtil(vector<vector<string>> &allParts, vector<string> &currPart, int start,int n,string str){
	if(start >= n){
		allParts.push_back(currPart);
		return;
	}
	for(int i=start;i<n;i++){
		if(isPalindrome(str,start,i)){
			currPart.push_back(str.substr(start,i-start+1));
			allPalUtil(allParts,currPart,i+1,n,str);
			currPart.pop_back();
		}
	}
}

void allPalPartitions(string str){
	int n = str.length();
	vector<vector<string>> allPart;
	vector<string> currPart;
	allPalUtil(allPart,currPart,0,n,str);
	for(int i=0;i<allPart.size();i++){
		for(int j=0;j<allPart[i].size();j++){
			cout<<allPart[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	string str = "nitin";
	allPalPartitions(str);
	return 0;
}

