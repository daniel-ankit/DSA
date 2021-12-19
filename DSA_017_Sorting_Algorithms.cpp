#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*    THEORY

╔═════════════════════╤══════════════╤══════════════╤════════════╤════════════╤════════════╗
║      ALGORITHM      │      Best    │    Average   │    Worst   │   Memory   │   Stable   ║
╠═════════════════════╪══════════════╪══════════════╪════════════╪════════════╪════════════╣
║     Bubble Sort     │     Ω(n)     │     Ө(n²)    │    O(n²)   │    O(1)    │     Yes    ║
╟─────────────────────┼──────────────┼──────────────┼────────────┼────────────┼────────────╢
║    Selection Sort   │     Ω(n²)    │     Ө(n²)    │    O(n²)   │    O(1)    │     No     ║
╟─────────────────────┼──────────────┼──────────────┼────────────┼────────────┼────────────╢
║    Insertion Sort   │     Ω(n)     │     Ө(n²)    │    O(n²)   │    O(1)    │     Yes    ║
╟─────────────────────┼──────────────┼──────────────┼────────────┼────────────┼────────────╢
║     Merge Sort      │   Ω(n.logn)  │   Ө(n.logn)  │  O(n.logn) │    O(n)    │     Yes    ║
╟─────────────────────┼──────────────┼──────────────┼────────────┼────────────┼────────────╢
║     Quick Sort      │   Ω(n.logn)  │   Ө(n.logn)  │    O(n²)   │   O(logn)  │     No     ║
╟─────────────────────┼──────────────┼──────────────┼────────────┼────────────┼────────────╢
║     Count Sort      │   Ω(n.logn)  │   Ө(n.logn)  │  O(n.logn) │    O(k)    │     Yes    ║
╟─────────────────────┼──────────────┼──────────────┼────────────┼────────────┼────────────╢
║      Heap Sort      │   Ω(n.logn)  │   Ө(n.logn)  │  O(n.logn) │    O(1)    │     No     ║
╚═════════════════════╧══════════════╧══════════════╧════════════╧════════════╧════════════╝

*/

void print(vector<int> &V)
{
    for(auto x : V)
        cout << x << " ";
    cout << endl;
}

void bubblesort(vector<int> &V)
{
    /*

    Individually taking elements to its sorted position 
        O(n²) Time Complexity
        O(1) Auxiliary Space
    
    */
    for(int i=0; i<V.size()-1; i++)
    {
        bool swapp = false;
        for(int j=0; j<V.size()-i; j++)
        {
            if(V[j+1] < V[j])
            {
                swap(V[j+1], V[j]);
                swapp = 1;
            }
        }
        if(swapp==0) break;
    }
    return;
}

void selectionsort(vector<int> &V)
{
    /*

    Compare with the remainning array and swap with the smallest
        O(n²) Time Complexity
        O(1) Auxiliary Space
        O(n) Swaps

    */
    int index, i, j;
    for(i=0; i<V.size()-1; i++)
    {
        index = i;
        for(j=i+1; j<V.size(); j++)
            if(V[j] < V[index]) index = j;
        swap(V[i], V[index]);
    }
    return;
}

void insertionsort(vector<int> &V)
{
    /*

    Pick elements and insert them in the right place of the sorted array by replacing all the elements greater to it in the sorted array.
        O(n²) Time Complexity
        O(1) Auxiliary Space

    */

    for(int i=1; i<V.size(); i++)
    {
        int val = V[i], j;
        for(j=i-1; j>=0; j--)
        {
            if(V[j]>val) V[j+1] = V[j];
            else break;
        }
        V[j+1] = val;
    }
    return;
}

void merger(vector<int> &V, int S, int M, int E)
{
    int i=S, j=M+1;
    vector<int> V2;
    while(i<=M and j<=E)
    {
        if(V[i]<=V[j])
        {
            V2.push_back(V[i]);
            i++;
        }
        else
        {
            V2.push_back(V[j]);
            j++;
        }
    }
    while(i<=M)
    {
        V2.push_back(V[i]);
        i++;
    }
    while(j<=E)
    {
        V2.push_back(V[j]);
        j++;
    }
    for(int i=S; i<=E; i++)
        V[i]=V2[i-S];
}

void mergesort(vector<int> &V, int S, int E)
{
    /*

    Recursive calls giving starting and ending positions for an array, array is divided into two parts, (start to mid) and (mid to end) where mid = (start + end)/2.
    The only return conditon for the loops is that the array get divided and starting and end ending point becomes same, (size of subarray = 1).
    Then a merger funcion is called for each division that inserts the elements in the array in their increasing order.
        Divide and Conquere
        Stable - Preserves relative order of records with same key
        O(n) Auxiliary Space
        O(n²) Time Complexity

    */
    if(S<E)
    {
        int M = (S+E)/2;
        mergesort(V, S, M);
        mergesort(V, M+1, E);
        merger(V, S, M, E);
    }
}

int partition(vector<int> &V, int S, int E)
{
    int pivot = V[E];
    int index = S-1;
    for(int i=S; i<=E; i++)
    {
        if(V[i]<pivot)
        {
            index++;
            swap(V[i], V[index]);
        }
    }
    index++;
    swap(V[index], V[E]);
    return index;
}

void quicksort(vector<int> &V, int S, int E)
{
    /*
    Fix the last element as pivot and place all the elements lesser than pivot in first half and elements greater than pivot on second half, using index as another pointer.
    after exchange the position of index with pivot and return the position of patition.
    */
    E-=1;
    if(S<E)
    {
        int pivot = partition(V, S, E);
        quicksort(V, S, pivot);
        quicksort(V, pivot+1, E+1);
    }
}

void countsort(vector<int> &V)
{
    int MAX = *max_element(V.begin(), V.end());
    int MIN = *min_element(V.begin(), V.end());
    int S[MAX-MIN+1] = {0}, j=0;
    for(int i=0; i<V.size(); i++)
        S[V[i]-MIN]++;

    for(int i=0; i<=MAX-MIN; i++)
    {
        int val = S[i];
        while(S[i]--)
        {
            V[j] = MIN+i;
            j++;
        }
    }
    return;
}

int main()
{
    int Sample[6] = {15, 20, 10, 0, 5, -5};
    vector<int> V;
    for(int i=0; i<6; i++)
        V.push_back(Sample[i]);
    // bubblesort(V);
    // selectionsort(V);
    // mergesort(V, 0, V.size());
    // quicksort(V, 0, V.size());
    countsort(V);
    print(V);
    return 69;
}