#include<bits/stdc++.h>
bool isPallindrome(string &str){
    int i = 0, j = str.length()-1;
    while(i < j) {
        if(str[i++] != str[j--]) return false;
    }
    return true;
}
int minCharsforPalindrome(string str) {
	int n = str.length();
    
    vector<int> dp(n, 0);
    string tmp = "";
    for(int i = 0; i < n; i++) {
        tmp += str[i];
        if(isPallindrome(tmp)) dp[i] = 1;
    }
    for(int j = n-1; j >= 0; j--) {
        if(dp[j]) return n-j-1;
    }
	
}
