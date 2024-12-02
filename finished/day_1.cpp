#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int occurrences(int num, std::vector<int> &col) {
    int sum = 0;

    // Find the first occurrence of 2
    auto it = find(col.begin(), col.end(), num);

    // Check if the element was found
    while (it != col.end()) {
        sum++;

        // Search for the next occurrence of val
        it = find(it + 1, col.end(), num);
    }

    return sum;
}

int main() {
    std::string line;
    std::vector<int> col1;
    std::vector<int> col2;

    while (std::getline(std::cin, line)) {
        if (line == "END") {
            break;
        }

        std::istringstream iss(line);
        int firstNum, secondNum;
        if (iss >> firstNum >> secondNum) {
            col1.push_back(firstNum);
            col2.push_back(secondNum);
        } else {
            std::cerr << "Invalid input: " << line << std::endl;
        }
    }

    std::sort(col1.begin(), col1.end());
    std::sort(col2.begin(), col2.end());

    int sim_score = 0;

    for (int i = 0; i < col1.size(); i++) {
        sim_score += occurrences(col1[i], col2) * col1[i];
    }

    std::cout << sim_score << std::endl;

    return 0;
}