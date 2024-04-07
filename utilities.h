#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <algorithm>
#include <cctype> //not necessary for "toUpper", iostream probably handles it



// Function to display a bigger line
void displaySeparator();

// Function to display a smaller line
void displayUnderline();

// Function to display a header
void displayHeader(const std::string& header);

// Function to display a Subheader
void displaySubHeader(const std::string& header);

// Function to convert a string to uppercase
std::string toUpper(const std::string& str);

#endif
