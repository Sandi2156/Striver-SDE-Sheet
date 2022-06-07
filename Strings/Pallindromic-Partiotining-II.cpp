int func(int i, string &str, vector<vector<int>> &isPallin, vector<int> &dp)
{
    if(i == str.length()) return 0;
    if(dp[i] != -1) return dp[i];
    int minCut = INT_MAX;
    for(int k = i; k < str.length(); k++) {
        int cut = INT_MAX;
        if(isPallin[i][k]) {
            int tmp = func(k+1, str, isPallin, dp);
            if(tmp != INT_MAX) cut = tmp + (k == str.length()-1 ? 0 : 1);
        }
        minCut = min(minCut, cut);
    }
    return dp[i] = minCut;
}
int palindromePartitioning(string str) {
    int n = str.length();
    vector<vector<int>> isPallin(n, vector<int>(n, 0));
    for(int k = 0; k < n; k++)
    {
        int i = 0, j = k;
        while(j < n)
        {
            if(k == 0) isPallin[i][j] = 1;
            else if(k == 1) isPallin[i][j] = (str[i] == str[j]);
            else{
                if(str[i] == str[j]) isPallin[i][j] = isPallin[i+1][j-1];
            }
            i++;
            j++;
        }
    }
    vector<int> dp(n, -1);
    return func(0, str, isPallin, dp);
    
}
