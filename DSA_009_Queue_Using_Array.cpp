#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Queue
{
    public:
    int first;
    int last;
    int SIZE;
    int *array;
    Queue(int n)
    {
        SIZE = n;
        first=0;
        last=0;
        array = new int;
    }
    ~Queue()
    {
        delete[] array;
    }
    bool isEmpty()
    {
        return (last==0);
    }
    bool isFull()
    {
        return (last==SIZE-1);
    }
    void enqueue(int A)
    {
        if(last==SIZE-1) return;
        array[last]=A;
        last++;
    }
    int peek()
    {
        if(isEmpty()) return -1;
        return array[first];
    }
    void dequeue()
    {
        if(isEmpty()) return;
        for(int i=0; i<last-1; i++)
            array[i]=array[i+1];
        last--;
    }
    int peekat(int index)
    {
        if(isEmpty()) return -1;
        return array[index-1];
    }
    int size()
    {
        return last;
    }
};

class CircularQueue
{
    public:
    int first;
    int last;
    int *array;
    int SIZE;
    CircularQueue(int size)
    {
        first=0;
        last=0;
        array = new int;
        SIZE = size+1;
    }
    ~CircularQueue()
    {
        delete[] array;
    }
    bool isEmpty()
    {
        return (first==0 && last==0);
    }
    bool isFull()
    {
        return ((last+1)%SIZE==first);
    }
    void enqueue(int A)
    {
        if(isFull())
        {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if(first==0 && last==0)
        {
            first++;
            array[first]=A;
            last++;
            return;
        }
        last=(last+1)%SIZE;
        array[last]=A;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue Underlow!" << endl;
            return;
        }
        if(first==1 && last==1)
        {
            first--;
            last--;
        }
        first = (first+1)%SIZE;
    }
};

int main()
{
    Queue Q(7);
    cout << Q.isEmpty() << endl;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);
    Q.enqueue(60);
    Q.enqueue(70);
    cout << Q.isEmpty() << endl;
    cout << Q.size() << endl;
    Q.dequeue();
    cout << Q.size() << endl;
    cout  << Q.peek() << endl;
    cout << Q.peekat(4) << endl;
    cout << Q.size()<< endl;

    CircularQueue Q(5);
    cout << Q.isEmpty() << endl;
    cout << Q.isFull() << endl;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    cout << Q.isEmpty() << endl;
    cout << Q.isFull() << endl;;
    Q.enqueue(40);
    Q.enqueue(50);
    Q.enqueue(60);
    cout << Q.isEmpty() << endl;
    cout << Q.isFull() << endl;
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    cout << Q.isEmpty() << endl;
    cout << Q.isFull() << endl;
    
    return 69;
}