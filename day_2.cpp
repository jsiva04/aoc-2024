#include <iostream>
#include <sstream>
#include <vector>

void split(std::string& line, std::vector<std::string>& words, char delim) {
    std::stringstream ss(line);
    std::string word;
    while (std::getline(ss, word, delim)) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }
}

int main() {
    std::string line;

    int total = 0;

    while (std::getline(std::cin, line)) {
        if (line == "END") {
            break;
        }

        std::vector<std::string> words;

        split(line, words, ' ');

        // std::cout << std::to_string(stoi(words[0]) + stoi(words[1])) << std::endl;

        try {
            bool up;

            if (stoi(words[0]) > stoi(words[1])) {
                up = false;
            } else if (stoi(words[0]) == stoi(words[1])) {
                total++;
                continue;
            } else {
                up = true;
            }
                
            for (size_t i = 1; i < words.size() - 1; i++) {
                if (up == true && stoi(words[i]) > stoi(words[i + 1])) {
                    total++;
                    break;
                }

                if (up == false && stoi(words[i]) < stoi(words[i + 1])) {
                    total++;
                    break;
                }

                if (abs(stoi(words[i + 1]) - stoi(words[i])) > 3 || abs(stoi(words[i + 1]) - stoi(words[i])) < 1) {
                    total++;
                    break;
                }
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid number format in input: " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Number out of range in input: " << e.what() << std::endl;
        }
    }

    std::cout << std::to_string(total) << std::endl;

    return total;
}