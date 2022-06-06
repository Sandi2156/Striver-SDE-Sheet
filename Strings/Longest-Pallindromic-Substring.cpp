#include<bits/stdc++.h>
string longestPalinSubstring(string str)
{
    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int maxi = INT_MIN;
    
    for(int k = 0; k < n; k++)
    {
        int i = 0, j = k;
        while(j < n)
        {
            if(k == 0) dp[i][j] = 1;
            else if(k == 1) dp[i][j] = (str[i] == str[j]);
            else {
                if(str[i] == str[j]) dp[i][j] = dp[i+1][j-1];
            }
            if(dp[i][j]) maxi = max(maxi, j-i+1);
            i++;
            j++;
            
        }
    }
    
    for(int k = n-1; k >= 0; k--)
    {
        int i = 0, j = k;
        while(j < n){
            if(dp[i][j] && j-i+1 == maxi) {
                return str.substr(i, j-i+1);
            }
            i++;
            j++;
        }
    }
}
