
#include "utilities.h"
using namespace std;


// Function to display a bigger line
void displaySeparator() {
    cout << "=========================================" << endl;
}
// Function to display a smaller line
void displayUnderline() {
    cout << "----------------------------" << endl;
}

// Function to display a header
void displayHeader(const string& header) {
    cout << endl;
    cout << endl;
    displaySeparator();
    cout << "------   " << header << "   ------" << endl;
    displaySeparator();
}
// Function to display a Subheader
void displaySubHeader(const string& header) {
    cout << endl;
    cout << endl;
    displayUnderline();
    cout << " -  " << header << "  - " << endl;
    displayUnderline();
}

// Function to convert a string to uppercase
    string toUpper(const string& str) {
    string upperStr = str;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    return upperStr;
}