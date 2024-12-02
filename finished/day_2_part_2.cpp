#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

void split(std::string& line, std::vector<std::string>& words, char delim) {
    std::stringstream ss(line);
    std::string word;
    while (std::getline(ss, word, delim)) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }
}


bool is_safe(const std::vector<int>& levels) {
    if (levels.size() < 2) return true;

    bool up = levels[1] > levels[0];
    for (size_t i = 0; i < levels.size() - 1; i++) {
        int diff = levels[i + 1] - levels[i];
        if ((up && diff <= 0) || (!up && diff >= 0) || abs(diff) < 1 || abs(diff) > 3) {
            return false;
        }
    }
    return true;
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

        try {
            if (words.empty()) continue;


            std::vector<int> levels;
            for (const std::string& word : words) {
                levels.push_back(std::stoi(word));
            }


            if (is_safe(levels)) {
                total++;
                continue;
            }

            bool safe_with_dampener = false;
            for (size_t i = 0; i < levels.size(); i++) {
                std::vector<int> modified_levels = levels;
                modified_levels.erase(modified_levels.begin() + i);
                if (is_safe(modified_levels)) {
                    safe_with_dampener = true;
                    break;
                }
            }

            if (safe_with_dampener) {
                total++;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error processing input: " << e.what() << std::endl;
        }
    }

    std::cout << total << std::endl;
    return 0;
}