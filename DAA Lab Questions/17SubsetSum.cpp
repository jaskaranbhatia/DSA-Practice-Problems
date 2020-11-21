#include <bits/stdc++.h>
using namespace std;


void subsetsum_Backtracking(int Set[], int pos, int sum, int tmpsum, int size, bool &found, vector<int> &temp, vector< vector<int> > &subsets)
{
    if (sum == tmpsum){
        found = true;
        subsets.push_back(temp);
        return;
    }
    for (int i = pos; i < size; i++){
        if (tmpsum + Set[i] <= sum){
            tmpsum += Set[i];
            temp.push_back(Set[i]);
            subsetsum_Backtracking(Set, i + 1, sum, tmpsum, size, found, temp, subsets);
            // Backtracking
            temp.pop_back();
            tmpsum -= Set[i];
        }
    }
}


int main()
{
    int i, n, sum;
    cout << "Enter the number of elements in the set" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the values" << endl;
    for (i = 0; i < n; i++) cin >> a[i];
    cout << "Enter the value of sum" << endl;
    cin >> sum;
    bool f = false;
    vector<int> temp;
    vector< vector<int> > subsets;
    subsetsum_Backtracking(a, 0, sum, 0, n, f, temp, subsets);
    if (f) {
        cout << "subset with the given sum found" << endl;
        int n = subsets.size();
        for (int i = 0; i < n; i++)
        {
            int m = subsets[i].size();
            for (int j = 0; j < m; j++)
            {
                cout << subsets[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "no required subset found" << endl;
    }
    return 0;
}
