#include<bits/stdc++.h>
int romanToInt(string s) {
    // Write your code here
    vector<int> ref(26);
    ref['I' - 'A'] = 1;
    ref['V' - 'A'] = 5;
    ref['X' - 'A'] = 10; ref['L' - 'A'] = 50; ref['C' - 'A'] = 100; ref['D' - 'A'] = 500; ref['M' - 'A'] = 1000;
    
    
    int res = 0, n = s.length();
    res += ref[s[n-1]- 'A'];
    int post = res;
    
    for(int i = n-2; i >= 0; i--)
    {
        int tmp = ref[s[i] -'A'];
        if(tmp < post) {
            res -= tmp;
        } else res += tmp;
        post = tmp;
    }
    
    
    return res;
    
}
