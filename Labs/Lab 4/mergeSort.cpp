#include <iostream>
#include <assert.h>
using namespace std;


// TODO (student): sort the numbers into nonincreasing order using a merge sort
// TODO (student): implement the following two functions
void merge(int* A, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = A[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;


    while (i < n1 && j < n2) {
        if (L[i] >= M[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = M[j];
        j++;
        k++;
    }

}


void mergeSort(int* A, int p, int r) {

    if (p < r) {
    
    int m = p + (r - p) / 2;

    mergeSort(A, p, m);
    mergeSort(A, m + 1, r);
    merge(A, p, m, r);
  }
}

int main() {
    // Don't modify the main function
    int test[] = {100, 3, 45, 7, 45, 57, 34, 12, 10};
    int sol[] = {100, 57, 45, 45, 34, 12, 10, 7, 3};
    mergeSort(test, 0, 8);

    for (int i = 0; i < 9; i++){
        assert(test[i]==sol[i]);
    }

    cout << "Test passed." << endl;

    return 0;
}
