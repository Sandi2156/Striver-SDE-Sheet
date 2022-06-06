#include<bits/stdc++.h>
bool isValidParenthesis(string expression)
{
    stack<char> stk;
    for(auto &ch: expression) {
        if(ch == '{' || ch == '[' || ch == '(')
            stk.push(ch);
        else if(ch == '}' || ch == ']' || ch == ')') {
            if(stk.empty()) return false;
            if(ch == '}' && stk.top() == '{') stk.pop();
            else if(ch == ']' && stk.top() == '[') stk.pop();
            else if(ch == ')' && stk.top() == '(') stk.pop();
            else{
                 break;
            }
        }
    }
    if(stk.empty()) return true;
    else {return false;}
}
