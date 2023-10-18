#include <iostream>
#include <assert.h>
using namespace std;


// TODO (student): implement binary search
// return -1 is key is not present in the subarray A[p...r]
// return the index if key is present in the subarray A[p...r]


/* Analysis of binary search
 
 
If A[mid] != key then the recurive loop will continue. It will then continue on
until the search interval is empty where log2n iterations is taken due to the 
the search interval lessening by a factor of 2. In order to find constant k 
and n0 such that T(n) <= klogn for all n >= n0. Therefore, k = C and n0 = 1
is good since logn >= 0 for all n > 0 and T(n) <= Clog2n <= Clogn for all n>=1. 
This then leads to the worst case time of this binary algorithm method to be 
O(log n). 


*/

int binarySearch(int* A, int p, int r, int key) {

    if (r >= p) {

        int mid = p + (r - p) / 2;
 
        
        if (A[mid] == key)
            return mid;
 
       
        if (A[mid] > key)
            return binarySearch(A, p, mid - 1, key);
 
       
        return binarySearch(A, mid + 1, r, key);
    }
 
    return -1;

}

int main() {
    // Don't modify the main function
    int test[] = {3, 7, 10, 12, 34, 45, 45, 57, 100};
    int index = 0;
    for(int i = 0; i < 9; i++)
    {
        index = binarySearch(test, 0, 8, test[i]);
        assert(test[index] == test[i]);
    }
    index = binarySearch(test, 0, 8, -10);
    assert(index == -1);
    
    cout << "Tests passed." << endl;

    return 0;
}

