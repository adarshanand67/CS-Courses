#include <iostream>
#include <string>
using namespace std;

int ArrayChallenge(int arr[], int arrLength) {

    // code goes here
    return arr[0];
}

int main(void) {

    // keep this function call here
    int A[] = coderbyteInternalStdinFunction(stdin);
    int arrLength = sizeof(A) / sizeof(*A);
    cout << ArrayChallenge(A, arrLength);
    return 0;
}