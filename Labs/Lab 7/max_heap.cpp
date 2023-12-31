// A C++ program to demonstrate common Binary Max-Heap Operations

#include<iostream>
#include <assert.h>
using namespace std;

// implement this function to insert the element x into the heap
void insert(int heap[], int& n, int x)
{
    int i = n;
    heap[i] = x;
    n++;

    while (i > 0 && heap[(i-1)/2] < heap[i]) {
        int temp = heap[(i-1)/2];
        heap[(i-1)/2] = heap[i];
        heap[i] = temp;
        i = (i-1)/2;
    }
}

// implement this function to remove the root
void remove(int heap[], int& n)
{
    if (n == 0) return;

    heap[0] = heap[n-1];
    n--;

    int i = 0;

    while (2*i+1 < n) {
        int left = 2*i+1;
        int right = 2*i+2;
        int maxIndex = i;

        if (heap[left] > heap[maxIndex])
            maxIndex = left;
        if (right < n && heap[right] > heap[maxIndex])
            maxIndex = right;

        if (maxIndex == i) break;

        int temp = heap[i];
        heap[i] = heap[maxIndex];
        heap[maxIndex] = temp;

        i = maxIndex;
    }
}


int main() 
{
    int heap[100]; // The array to store the max-heap
    int n = 0;  // keep track the number of elements in the heap

    insert(heap, n, 1);
    insert(heap, n, 2);
    insert(heap, n, 4);
    insert(heap, n, 6); 
    insert(heap, n, 10);
    insert(heap, n, 11);
    insert(heap, n, 13);
    insert(heap, n, 15);

    assert(n==8);
    int sol1[] = {15, 13, 11, 6, 4, 2, 10, 1};
    int i = 0;

    for (i = 0; i < 8; i++)
        assert(heap[i]==sol1[i]);

    cout << "Test case 1 passed. " << endl;

    remove(heap, n);
    remove(heap, n);

    int sol2[] = {11, 6, 10, 1, 4, 2};
    for (i = 0; i < 6; i++)
        assert(heap[i]==sol2[i]);

    cout << "Test case 2 passed. " << endl;
    return 0;
}



/*   int lastEl = heap[n-1];
    heap[0] = lastEl;
    n -= 1;
    */