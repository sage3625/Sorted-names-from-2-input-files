// Sorted names from 2 input files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// Function to read names from a file into a vector of strings
std::vector<std::string> readNamesFromFile(const std::string& filename) {
    std::vector<std::string> names;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }
    std::string name;
    while (std::getline(file, name)) {
        if (!name.empty()) { // Avoid adding empty lines
            names.push_back(name);
        }
    }
    file.close();
    return names;
}

// Function to write names to a file and display them
void writeNamesToFileAndDisplay(const std::string& filename, const std::vector<std::string>& names) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }
    for (const auto& name : names) {
        std::cout << name << std::endl; // Display the name
        file << name << std::endl; // Write the name to file
    }
    file.close();
}

int main() {
    // Input file names
    std::string inputFileName1 = "file_1.txt";
    std::string inputFileName2 = "file_2.txt";

    // Read names from input files
    std::vector<std::string> names1 = readNamesFromFile(inputFileName1);
    std::vector<std::string> names2 = readNamesFromFile(inputFileName2);

    // Merge the names
    std::vector<std::string> mergedNames;
    mergedNames.reserve(names1.size() + names2.size());
    mergedNames.insert(mergedNames.end(), names1.begin(), names1.end());
    mergedNames.insert(mergedNames.end(), names2.begin(), names2.end());

    // Sort the merged names alphabetically
    std::sort(mergedNames.begin(), mergedNames.end());

    // Write sorted names to output file and display them
    std::string outputFileName = "sorted.txt";
    writeNamesToFileAndDisplay(outputFileName, mergedNames);

    std::cout << "Merged and sorted names written to " << outputFileName << std::endl;

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
