/**/

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

// Define logistic regression function
double logisticRegression(double x, double a, double b) {
    return 1.0 / (1.0 + exp(-a * x - b));
}

string ArrayChallenge(double arr[]) {
    // Learning rate
    double learningRate = 1.0;

    // Define OCG (Output for Gradient Calculation)
    double varOcg = 0.0; // _define-ocg_

    // Input values
    double x = arr[0];
    double y = arr[1];

    // Parameters
    double a = arr[2];
    double b = arr[3];

    // Calculate current output
    double output = logisticRegression(x, a, b);

    // Calculate gradient for parameter a
    double gradient_a = (y - output) * output * (1.0 - output) * x;

    // Calculate gradient for parameter b
    double gradient_b = (y - output) * output * (1.0 - output);

    // Update parameters using gradient descent
    a += learningRate * gradient_a;
    b += learningRate * gradient_b;

    // Return updated parameters
    return to_string(round(a * 1000.0) / 1000.0) + ", " + to_string(round(b * 1000.0) / 1000.0);
}

int main(void) {
    // Input array
    double A[] = {2.2, 0.0, 5.1, 5.7};

    // Output updated parameters
    cout << ArrayChallenge(A) << endl;

    return 0;
}
