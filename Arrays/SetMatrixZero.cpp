#include<bits/stdc++.h>
using namespace std;

void setColZero(vector<vector<int>>& matrix,int rows,int col) {
	for(int i=0;i<rows;i++){
		matrix[i][col] = 0;
	}
}

void setRowZero(vector<vector<int>>& matrix,int row,int cols) {
	for(int i=0;i<cols;i++){
		matrix[row][i] = 0;
	}
}

void setZeroes(vector<vector<int>>& matrix) {
	vector<pair<int,int>> p;
	int rows = matrix.size();
	int cols = matrix[0].size();
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(matrix[i][j] == 0){
				p.push_back(make_pair(i,j));
			}
		}
	}
	for(auto pp:p){
		int row = pp.first;
		int col = pp.second;
		setColZero(matrix,rows,col);
		setRowZero(matrix,row,cols);
	}
}

void print(vector<vector<int>>& matrix){
	int rows = matrix.size();
	int cols = matrix[0].size();
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> matrix(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>matrix[i][j];
		}
	}
	setZeroes(matrix);
	print(matrix);
}

