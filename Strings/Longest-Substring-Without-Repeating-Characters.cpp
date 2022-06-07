#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int i = 0, j = 0, n = input.length();
    map<char, int> mp;
    int res = INT_MIN;
    
    while(j < n)
    {
        mp[input[j]]++;
        while(i < j && mp[input[j]] > 1)
        {
            mp[input[i]]--;
            i++;
        }
        res = max(res, j - i + 1);
        j++;
    }
    return res;
}
