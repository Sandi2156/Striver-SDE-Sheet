#include<bits/stdc++.h>
string reverseString(string str)
{
    string res = "", temp = "";
    for(int i = str.length()-1; i >= 0; i--)
    {
        if(str[i] == ' ')
        {
            if(temp.length() > 0){
                reverse(temp.begin(), temp.end());
                res += temp;
                res += ' ';
                temp = "";
            }
        }
        else temp += str[i];
    }
    if(temp.length() > 0){
        reverse(temp.begin(), temp.end());
        res += temp;
     }
    return res;
}
