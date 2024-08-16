#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm> // For std::reverse

using namespace std;

int main() {
    string str = "!AIVDM,1,1,,A,15?:4d001D7LE:R0fF8::89L00S;,0*59";
    vector<string> substrings;
    vector<string> binarySubstrings;
    string concatenatedBinary;
    stringstream ss(str);
    string item;

    // Splitting the string based on comma
    while (getline(ss, item, ',')) {
        substrings.push_back(item);
    }

    // Check if there is a 6th element
    if (substrings.size() >= 6) {
        // Get the 6th element (0-based index is 5)
        const string& sixthElement = substrings[5];

        // Convert the 6th element to binary and store it
        for (const auto& ch : sixthElement) {
            // Convert each character to its ASCII value and then to binary
            int asciiValue = static_cast<int>(ch) - '0';
            int truncatedValue = asciiValue & 0x3F; // 6-bit mask
            bitset<6> binary(truncatedValue);
            string binaryString = binary.to_string();
            std::reverse(binaryString.begin(), binaryString.end()); // Reverse the binary string

            // Store in the vector and concatenate the string
            binarySubstrings.push_back(binaryString);
            concatenatedBinary = binaryString + concatenatedBinary;
        }
    }

    // Displaying the reversed binary substrings
    cout << "Binary Substrings: ";
    for (const auto& bin : binarySubstrings) {
        cout << bin << " ";
    }
    cout << endl;

    // Displaying the concatenated binary string
    cout << "Concatenated Binary String: " << concatenatedBinary << endl;

    return 0;
}
