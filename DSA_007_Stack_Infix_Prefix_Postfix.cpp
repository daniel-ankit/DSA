#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

bool isOperator(char C)
{
    if (C == '^' || C == '/' || C == '*' || C == '+' || C == '-')
        return 1;
    return 0;
}

bool isOpearnd(char C)
{
    if ((C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z') || (C >= '0' && C <= '9'))
        return 1;
    return 0;
}

int precedance(char C)
{
    if (C == '^')
        return 3;
    if (C == '/' || C == '*')
        return 2;
    if (C == '+' || C == '-')
        return 1;
    return 0;
}

string toPostfix(string exp)
{
    stack<char> S;
    string ans;
    exp = '(' + exp + ')';
    for (int i = 0; i < exp.length(); i++)
    {
        if (isOpearnd(exp[i]))
            ans += exp[i];
        else if (exp[i] == '(')
            S.push('(');
        else if (exp[i] == ')')
        {
            while (S.top() != '(')
            {
                ans += S.top();
                S.pop();
            }
            S.pop();
        }
        else if(isOperator(exp[i]))
        {
            while (!S.empty() && precedance(exp[i]) <= precedance(S.top()))
            {
                ans += S.top();
                S.pop();
            }
            S.push(exp[i]);
        }
    }
    while (!S.empty())
    {
        ans += S.top();
        S.pop();
    }
    return ans;
}

string toPrefix(string exp)
{
    reverse(exp.begin(), exp.end());
    for(int i=0; i<exp.length();i++)
    {
        if(exp[i]=='(') exp[i]=')';
        if(exp[i]==')') exp[i]='(';
    }
    string ans = toPostfix(exp);
    reverse(ans.begin(), ans.end());
    return ans;
}

// int main()
// {
//     string s = "A+B^C^D*E";
//     stack<char> S;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (!isOperator(s[i]))
//             cout << s[i];
//         else
//         {
//             if (S.empty())
//             {
//                 S.push(s[i]);
//                 continue;
//             }
//             else if (precedance(s[i]) > precedance(S.top()))
//                 S.push(s[i]);
//             else if (precedance(s[i]) == precedance(S.top()))
//                 cout << s[i];
//             else if(precedance(s[i]) < precedance(S.top()))
//             {
//                 cout << S.top();
//                 S.pop();
//                 S.push(s[i]);
//             }
//             else
//             {
//                 while (!S.empty())
//                 {
//                     cout << S.top();
//                     S.pop();
//                 }
//             }
//         }
//     }
//     while (!S.empty())
//     {
//         cout << S.top();
//         S.pop();
//     }
//     return 69;
// }

int main()
{
    string exp = "((a+b)*c-d)*e";
    string postexp = toPostfix(exp);
    cout << postexp << endl;
    string preexp = toPrefix(exp);
    cout << preexp;
    return 69;
}