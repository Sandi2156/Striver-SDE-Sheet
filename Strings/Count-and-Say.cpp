#include<bits/stdc++.h>
string writeAsYouSpeak(int n) 
{
	string res = "1";
    n--;
    while(n--)
    {
        string newStr = "";
        int i = 0, count = 0;
        char ch;
        while(i < res.length())
        {
            ch = res[i];
             count=0;
            while(i < res.length() && res[i] == ch) {
                i++;
                count++;
            }
            newStr += to_string(count) + ch;
           
        }
        
        res = newStr;
    }
    return res;
}
