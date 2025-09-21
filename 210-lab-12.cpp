// COMSC-210 | Lab 12 | Mamadou Sissoko 
// IDE used: Visual Studio Code

#include <iostream>
#include <fstream>
#include <array>
using namespace std;

const int SIZE = 50;

int main() {
    array<double, SIZE> numbers{};
    ifstream infile("fiftynumbers.txt");

    if (!infile) {
        cerr << "Error: could not open fiftynumbers.txt" << endl;
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        infile >> numbers.at(i); // safe access
    }
    infile.close();

    cout << SIZE << " numbers successfully loaded into std::array.\n";
    return 0;
}
