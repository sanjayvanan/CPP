#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

int binaryToDecimal(const string& binaryString) {
    return std::bitset<64>(binaryString).to_ulong();
}

int main() {
    string str;
    cout << "Enter the AIS : ";
    cin >> str;
    vector<string> substrings;
    vector<string> binarySubstrings;
    string concatenatedBinary;
    stringstream ss(str);
    string item;


    while (getline(ss, item, ',')) {
        substrings.push_back(item);
    }


    if (substrings.size() >= 6) {
        const string& sixthElement = substrings[5];

    
        for (const auto& ch : sixthElement) {
            int asciiValue = static_cast<int>(ch) - 48;
            int truncatedValue = asciiValue & 0x3F;
            bitset<6> binary(truncatedValue);
            string binaryString = binary.to_string();
            std::reverse(binaryString.begin(), binaryString.end());

            binarySubstrings.push_back(binaryString);
            concatenatedBinary = binaryString + concatenatedBinary;
        }
    }


    std::reverse(concatenatedBinary.begin(), concatenatedBinary.end());


    vector<string> aisFields(17);

    struct FieldInfo {
        int length;
        string name;
    };

    vector<FieldInfo> fieldInfo = {
        {6, "Message Type"},
        {2, "Repeat Indicator"},
        {30, "MMSI"},
        {4, "Status Kapal"},
        {8, "Rate of Turn (ROT)"},
        {10, "Speed Over Ground (SOG)"},
        {1, "Position Accuracy"},
        {28, "Longitude"},
        {27, "Latitude"},
        {12, "Course Over Ground (COG)"},
        {9, "True Heading (HDG)"},
        {6, "Time Stamp"},
        {2, "Maneuver Indicator"},
        {3, "Spare"},
        {1, "RAIM Flag"},
        {19, "Radio Status"}
    };

    int startIndex = 0;

    for (size_t i = 0; i < fieldInfo.size(); ++i) {
        int len = fieldInfo[i].length;
        string fieldBinary = concatenatedBinary.substr(startIndex, len);
        aisFields[i] = fieldBinary;
        startIndex += len;
    }


    for (size_t i = 0; i < aisFields.size(); ++i) {
        if (i == 7 || i == 8) {
            double value = binaryToDecimal(aisFields[i]);
            if (i == 7) {
                value = (value / 600000.0);
            } else {
                value = (value / 600000.0);
            }
            cout << fieldInfo[i].name << ": " << fixed << setprecision(6) << value << endl;
        } else {
            cout << fieldInfo[i].name << ": " << binaryToDecimal(aisFields[i]) << endl;
        }
    }

    return 0;
}
