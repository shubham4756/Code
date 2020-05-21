/*
Link:https://leetcode.com/problems/uncrossed-lines/
solution is same as find logest common subsequence from given two string
Editorial:https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& X, vector<int>& Y) {
        int m=X.size(),n=Y.size();
    int L[m + 1][n + 1];  
    int i, j;  
    for (i = 0; i <= m; i++)  
    {  
        for (j = 0; j <= n; j++)  
        {  
        if (i == 0 || j == 0)  
            L[i][j] = 0;  
      
        else if (X[i - 1] == Y[j - 1])  
            L[i][j] = L[i - 1][j - 1] + 1;  
      
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
    return L[m][n];  
    }
};
