// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
using namespace std;


double calculateSum(vector<double> numbers);
double calculateAverage(vector<double> numbers);
double findMax(vector<double> numbers);
double findMin(vector<double> numbers);

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;

    if (n <= 0) {
        cout << "Errors: Please enter a positve number of values." << endl;
        return 1;
    }

    vector<double> numbers;
    for (int i = 0; i < n; i++) {
        double value;
        cout << "Enter number " << i + 1 << ": ";
        cin >> value;
        numbers.push_back(value);
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(numbers) << endl;
    cout << "Average: " << calculateAverage(numbers) << endl;
    cout << "Maximum: " << findMax(numbers) << endl;
    cout << "Minimum: " << findMin(numbers) << endl;

    return 0;
}

double calculateSum(vector<double> numbers) {
    double total = 0;
    for (int i = 0; i < numbers.size(); i++) {
        total += numbers[i];
    }
    return total;
}
double calculateAverage(vector<double> numbers) {
    double total = calculateSum(numbers);
    return total / numbers.size();
}
double findMax(vector<double> numbers) {
    double maxValue = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] > maxValue) {
            maxValue = numbers[i];
        }
    }
    return maxValue;
}
double findMin(vector<double> numbers) {
    double minValue = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] < minValue) {
            minValue = numbers[i];
        }
    }
    return minValue;
}
