#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& str) {
        string s="";
        int n = str.size();
        if(n == 0){
            return ""; 
        }
        for(int j=0;j<str[0].length();j++){
            char comp=str[0][j];
            for(int i=1;i<n;i++){
                if(comp!=str[i][j]){
                    return s;
                }
            }
            s.push_back(comp); 
        }
        return s; 
    }

int main(){
	int n;
	cin>>n;
	vector<string> strs;
	for(int i=0;i<n;i++){
		string data;
		cin>>data;
		strs.push_back(data);
	}
	cout<<longestCommonPrefix(strs);
}
