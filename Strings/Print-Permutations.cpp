void func(string &s, vector<int> &visited, vector<string> &res, string temp)
{
    bool flag = true;
    for(int i = 0; i < s.length(); i++) {
        if(!visited[i])
        {
            temp += s[i];
            visited[i] = 1;
            func(s, visited, res, temp);
            temp.pop_back();
            visited[i] = 0;
            flag = false;
        }
    }
    if(flag) res.push_back(temp);
    
}

vector<string> findPermutations(string &s) {
    vector<int> visited(s.length(), 0);
    vector<string> res;
    func(s, visited, res, "");
    return res;
}
