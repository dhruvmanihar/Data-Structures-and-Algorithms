#include <iostream>
#include <assert.h>
using namespace std;


// TODO (student): sort the numbers into nonincreasing order using a selection
// sort (5 points)

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int* arr, int size) {

    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (arr[i] > arr[min_idx])
                min_idx = i;
        }

    swap(&arr[min_idx], &arr[step]);
  }

}

int main() {
    // Don't modify the main function
    int test1[] = {1, 3, 5, 7};
    int test2[] = {7, 5, 3, 1};
    int test3[] = {1, 7, 3, 7};

    selectionSort(test1, 4);
    assert(test1[0]==7);
    assert(test1[1]==5);
    assert(test1[2]==3);
    assert(test1[3]==1);
    cout << "Test 1 passed. " << endl;

    selectionSort(test2, 4);
    assert(test2[0]==7);
    assert(test2[1]==5);
    assert(test2[2]==3);
    assert(test2[3]==1);
    cout << "Test 2 passed. " << endl;

    selectionSort(test3, 4);
    assert(test3[0]==7);
    assert(test3[1]==7);
    assert(test3[2]==3);
    assert(test3[3]==1);
    cout << "Test 3 passed. " << endl;

    return 0;
}
