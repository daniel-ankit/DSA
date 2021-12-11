#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  THEORY

    Traversal - Visiting each element of the Array.
    Insertion - Inserting elements in an Array.
    Deletion and
    Searching
        (a.)Sorted
        (b.)Unsorted

*/

int S=0;

void assign(int A[], int N)
{
    for(int i=1; i<=N; i++)
        A[i-1]=i;
    S+=N;
}

void show(int A[], int N)
{
    for(int i=0; i<N; i++)
        cout << A[i] << " ";
    cout << endl;
}

void insert(int A[], int N, int M)
{
    A[N]=M;
    S++;
}

void insertsorted(int A[], int N, int M)
{
    A[N]=M;
    for(int i=N-1; ;i--)
    {
        if(A[i]>A[i+1]) swap(A[i], A[i+1]);
        else break;
    }
    S++;
}

void delindex(int A[], int N, int M)
{
    if(M>N || M<0)
        return;
    for(int i=M-1; i<N; i++)
    {
        A[i]=A[i+1];
    }
    S--;
}

void delele(int A[], int N, int M)
{
    for(int i=0; i<N; i++)
    {
        if(A[i]==M)
        {
            delindex(A, N, i+1);
        }
    }
}

bool linear_search(int A[], int N, int M)
{
    for(int i=0; i<N; i++)
        if(A[i]==M) return 1;
    return 0;
}

bool binary_search(int A[], int N, int M)
{
    sort(A, A+N);
    int i=0, j=N;
    while(i<j)
    {
        int m=(i+j)/2;
        if(A[m]==M)
            return 1;
        else if(A[m]>M) j=m-1;
        else i=m+1;
    }
    return 0;
}

int main()
{
    int A[100001]={0};
    assign(A, 10);
    show(A, S);
    insert(A, S, 12);
    show(A, S);
    insertsorted(A, S, 7);
    show(A, S);
    delindex(A, S, 7);
    show(A, S);
    delele(A, S, 12);
    show(A, S);
    cout << linear_search(A, S, 11) << endl;
    cout << binary_search(A, S, 10);
    return 69;
}