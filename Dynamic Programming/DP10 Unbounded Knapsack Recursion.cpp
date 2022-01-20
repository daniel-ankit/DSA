#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Unbounded_Knapsack(vector<int> price, vector<int> length, int L, int n)
{
    if(n-1<0 || L<=0) return 0;
    if(length[n-1]<=L)
        return max(price[n-1] + Unbounded_Knapsack(price, length, L-length[n-1], n), Unbounded_Knapsack(price, length, L, n-1));
    else
        return Unbounded_Knapsack(price, length, L, n-1);
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 7, 20};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = price.size();
    int L = 8;
    cout << Unbounded_Knapsack(price, length, L, n);
    return 69;
}