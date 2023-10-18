//time ./a.out

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;



//fragment 1

int main() {

    auto start = high_resolution_clock::now();

    int n = 100;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i); j++) {
            sum = sum + i + j;
        }
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;


}



int main() {

    //fragment 2

    auto start = high_resolution_clock::now();

    int n = 2000;
    int sum = 0;
    
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 2 * i; j++) {
            sum = sum + i + j;
        }
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;


}



//problem 3

int main (){

    int sum = 0;
    int xi = 1;
    int n;
    int x;
    int a[0];

    for (int i = 0; i < n; i++){

        if (i == 0){
            xi = 1;
        }else{
            for (int j = 0; j<i; j++){
                xi *= x;
            }
        }

        sum += a[i] * xi;

    }

}
