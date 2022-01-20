#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print1toN(int n)
{
    if(n<1) return;
    print1toN(n-1);
    cout << n << " ";
}

void printNto1(int n)
{
    if(n<1) return;
    cout << n << " ";
    printNto1(n-1);
}

int main()
{
    int n = 25;
    print1toN(n);
    cout << endl;
    printNto1(n);
    return 69;
}