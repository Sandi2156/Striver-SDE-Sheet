#include<bits/stdc++.h>
struct Node {
    Node* links[26];
    int count;
    void createLink(char ch) {
        links[ch - 'a'] = new Node();
    }
};

class Trie {
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(string str)
        {
            Node* temp = root;
            for(auto &it : str) {
                if(!temp->links[it - 'a'])
                    temp->createLink(it);
                temp = temp->links[it - 'a'];
                temp->count++;
            }
        
        }
        string findLongestPrefix(string str, int n) {
            Node* temp = root;
            string res = "";
            for(auto &it : str) {
                temp = temp->links[it - 'a'];
                if(temp->count == n){
                    res += it;
                }else return res;
            }
            return res;
        }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
//     Trie trie;
//     for(auto &str : arr) {
//         trie.insert(str);
//     }
//     return trie.findLongestPrefix(arr[0], n);
    
    string res = "";
    string str = arr[0];
    for(int i = 0; i < str.length(); i++)
    {
        bool flag = true;
        for(int j = 1; j < n; j++) {
            if(i == arr[j].length()) {
                flag = false;
                break;
            }
            
            if(str[i] != arr[j][i]){
                flag = false;
                break;
            }
        }
        if(flag) res += str[i];
        else break;
    }
    return res;
}


