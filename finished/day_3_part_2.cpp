#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string line;
    int sum = 0;
    bool mul_enabled = true;

    while (std::getline(std::cin, line)) {
        if (line == "END") break;

        size_t pos = 0;
        while (pos < line.length()) {
            // Check for don't() instruction
            if (pos + 6 <= line.length() && line.substr(pos, 6) == "don't(") {
                mul_enabled = false;
                pos += 6; // Move past the instruction
                continue;
            }

            // Check for do() instruction
            if (pos + 4 <= line.length() && line.substr(pos, 4) == "do()") {
                mul_enabled = true;
                pos += 4; // Move past the instruction
                continue;
            }

            // Check for mul() instruction
            if (pos + 4 <= line.length() && line.substr(pos, 4) == "mul(") {
                size_t startPos = pos + 4;
                size_t end = line.find(')', startPos);

                if (end == std::string::npos) {
                    pos++;
                    continue;
                }

                if (mul_enabled) {
                    // Extract and process the numbers inside mul()
                    std::string content = line.substr(startPos, end - startPos);
                    size_t comma = content.find(',');

                    if (comma != std::string::npos) {
                        std::string a = content.substr(0, comma);
                        std::string b = content.substr(comma + 1);

                        // Clean whitespace
                        a.erase(remove_if(a.begin(), a.end(), isspace), a.end());
                        b.erase(remove_if(b.begin(), b.end(), isspace), b.end());

                        if (!a.empty() && !b.empty() &&
                            a.find_first_not_of("0123456789") == std::string::npos &&
                            b.find_first_not_of("0123456789") == std::string::npos) {
                            try {
                                int num1 = std::stoi(a);
                                int num2 = std::stoi(b);
                                sum += num1 * num2;
                            } catch (const std::exception&) {
                                // Ignore invalid numbers
                            }
                        }
                    }
                }
                pos = end + 1; // Move past the mul() instruction
            } else {
                pos++;
            }
        }
    }

    std::cout << sum << std::endl;
    return 0;
}