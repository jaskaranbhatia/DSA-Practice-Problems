#include <bits/stdc++.h>
using namespace std;

string name = "A1";

void printParanthesis(int i, int j, int n, vector< vector<int> > bracket)
{
    if (i == j)
    {
        cout << name;
        name[1]++;
        return;
    }
    cout << "(";
    printParanthesis(i, bracket[i][j], n, bracket);
    printParanthesis(bracket[i][j] + 1, j, n, bracket);
    cout << ")";
}

int matrixChainMul(int dims[], int n){
    vector< vector<int> > dp(n + 1, vector<int>(n + 1));
    vector< vector<int> > bracket(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            int ans = INT_MAX;
            for (int k = i; j < n && k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < ans)
                {
                    ans = cost;
                    bracket[i][j] = k;
                }
            }
            dp[i][j] = ans;
        }
    }
    cout << "Optimal Paranthesis for multiplication are : ";
    printParanthesis(1, n - 1, n, bracket);
    cout << endl;
    return dp[1][n - 1];
}

int main()
{
    /*
        A1 = 5 X 4
        A2 = 4 X 6
        A3 = 6 X 2
        A4 = 2 X 7
    */
    int dims[] = {20,15,30,5};
    int n = sizeof(dims) / sizeof(dims[0]);
    cout << "Minimum cost of multiplication is : " << matrixChainMul(dims, n) << endl;
    return 0;
}
