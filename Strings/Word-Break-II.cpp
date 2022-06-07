#include<bits/stdc++.h>

void func(int i, string &s, unordered_set<string> &st, string carry, vector<string> &res)
{
    if(i == s.length()) {
        carry.pop_back();
        res.push_back(carry);
        return;
    }
    string tmp = "";
    for(int k = i; k < s.length(); k++) {
        tmp += s[k];
        if(st.find(tmp) != st.end()) {
            func(k+1, s, st, carry+tmp+' ', res);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    unordered_set<string> st;
    for(auto &it: dictionary) st.insert(it);
    vector<string> res;
    func(0, s, st, "", res);
    return res;

}
