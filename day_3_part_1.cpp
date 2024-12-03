#include <sstream>
#include <string>
#include <iostream>
#include <vector>

int main() {
    std::string line;
    int sum = 0;
    std::vector<std::string> ins;

    while (std::getline(std::cin, line)) {
        if (line == "END") break;

        size_t pos = 0;
        while ((pos = line.find("mul(", pos)) != std::string::npos) {
            size_t end = line.find(')', pos);
            if (end == std::string::npos) {
                pos++;
                continue;
            }

            std::string content = line.substr(pos + 4, end - (pos + 4));

            if (content.find("mul") != std::string::npos) {
                pos++;
                continue;
            }


            size_t comma = content.find(',');
            if (comma != std::string::npos) {
                std::string a = content.substr(0, comma);
                std::string b = content.substr(comma + 1);

                a.erase(remove_if(a.begin(), a.end(), isspace), a.end());
                b.erase(remove_if(b.begin(), b.end(), isspace), b.end());

                try {
                    if (a.find_first_not_of("0123456789") == std::string::npos &&
                        b.find_first_not_of("0123456789") == std::string::npos) {
                        int num1 = std::stoi(a);
                        int num2 = std::stoi(b);
                        sum += num1 * num2;
                    }
                } catch (const std::exception&) {
                    //skip
                }
            }
            pos = end + 1;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}