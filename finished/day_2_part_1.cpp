#include <iostream>
#include <sstream>
#include <vector>
#include <cmath> // for abs()

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

        try {

            if (words.size() < 2) continue;

            bool up = false, valid = true;
            int first_diff = stoi(words[1]) - stoi(words[0]);
            
            if (first_diff > 0) up = true;
            else if (first_diff < 0) up = false;
            else valid = false;

            for (size_t i = 0; i < words.size() - 1 && valid; i++) {
                int diff = stoi(words[i + 1]) - stoi(words[i]);

                if ((up && diff <= 0) || (!up && diff >= 0) || abs(diff) < 1 || abs(diff) > 3) {
                    valid = false;
                }
            }

            if (valid) total++;
        } catch (const std::exception& e) {
            std::cerr << "Error processing input: " << e.what() << std::endl;
        }
    }

    std::cout << total << std::endl;
    return 0;
}