// COMSC-210 | Lab 12 | Mamadou Sissoko 
// IDE used: Visual Studio Code
// 
// Demonstrates basic std::array member functions: size, max_size, empty, front, back.

#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;

const int SIZE = 50; // array size

int main() {
    array<double, SIZE> numbers{}; // declare array to hold 50 numbers
    ifstream infile("fiftynumbers.txt");

    // Check if file opened successfully
    if (!infile) {
        cerr << "Error: could not open fiftynumbers.txt.\n";
        return 1;
    }

    // Read numbers from file into array
    for (int i = 0; i < SIZE; i++) {
        infile >> numbers.at(i); // safe access
    }
    infile.close(); // close file after reading

    // Display basic array info
    cout << "Array size: " << numbers.size() << endl;
    cout << "Max size: " << numbers.max_size() << endl;
    cout << "Is empty? " << (numbers.empty() ? "Yes" : "No") << endl;
    cout << "First element: " << numbers.front() << endl;
    cout << "Last element: " << numbers.back() << endl;

    // Demonstrates array statistics: average
    double avg = accumulate(numbers.begin(), numbers.end(), 0.0) / SIZE; // sum & divide
    cout << "\nAverage value: " << avg << endl;

    // Demonstrates finding min and max values
    auto [minIt, maxIt] = minmax_element(numbers.begin(), numbers.end()); // min & max
    cout << "Min value: " << *minIt << ", Max value: " << *maxIt << endl;

    return 0;
}
