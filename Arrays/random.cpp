#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a 10-digit number starting with 1
long long generateRandomNumber() {
    long long min = 1000000000; // Smallest 10-digit number starting with 1
    long long max = 1999999999; // Largest 10-digit number starting with 1
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(0)); // Seed for random number generation
    
    cout << "10 random 10-digit numbers starting with 1:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << generateRandomNumber() << endl;
    }
    
    return 0;
}
