#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string exp = "[{}()]";
    stack <char> S;
    bool pass = true;
    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            S.push(exp[i]);
            continue;
        }
        if(S.empty())
        {
            pass = false;
            break;
        }
        if(exp[i]==')')
        {
            if(S.top()=='{' || S.top() =='[')
            {
                pass = false;
                break;
            }
            S.pop();
        }
        if(exp[i]=='}')
        {
            if(S.top()=='(' || S.top() =='[')
            {
                pass = false;
                break;
            }
            S.pop();
        }
        if(exp[i]==']')
        {
            if(S.top()=='{' || S.top() ==')')
            {
                pass = false;
                break;
            }
            S.pop();
        }
    }
    if(S.empty() && pass) cout << "YES";
    else cout << "NO";
    return 69;
}