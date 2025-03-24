#include <iostream>
using namespace std;

void printSubarrays(string &s, int start, int end) {
    // Base case: If start index reaches or exceeds the length of the string, stop recursion
    if (start >= s.length())
        return;
    
    // If end index reaches the length of the string, reset end and increment start
    if (end > s.length()) {
        printSubarrays(s, start + 1, start + 1);
        return;
    }
    
    // Print the current substring
    cout << s.substr(start, end - start) << endl;
    
    // Recur for next substring by increasing end index
    printSubarrays(s, start, end + 1);
}

int main() {
    string s = "abcd";
    cout << "All subarrays (substrings) of the given string are:\n";
    printSubarrays(s, 0, 1);
    return 0;
}