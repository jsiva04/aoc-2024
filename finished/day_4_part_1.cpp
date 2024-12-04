#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    int total = 0;

    std::vector<std::string> puzzle;

    while (std::getline(std::cin, line)) {
        if (line == "END") {
            break;
        }

        puzzle.push_back(line);
    }

    for (int i = 0; i < puzzle.size(); i++) {
        for (int j = 0; j < puzzle[i].length(); j++) {
            if (puzzle[i][j] == 'X') {
                // N
                if (i > 2) {
                    if ((puzzle[i - 1][j] == 'M') && (puzzle[i - 2][j] == 'A') && (puzzle[i - 3][j] == 'S')) total++;
                }
                // S
                if (i < 137) {
                    if ((puzzle[i + 1][j] == 'M') && (puzzle[i + 2][j] == 'A') && (puzzle[i + 3][j] == 'S')) total++;
                }
                // E
                if (j < 137) {
                    if ((puzzle[i][j + 1] == 'M') && (puzzle[i][j + 2] == 'A') && (puzzle[i][j + 3] == 'S')) total++;
                }
                // W
                if (j > 2) {
                    if ((puzzle[i][j - 1] == 'M') && (puzzle[i][j - 2] == 'A') && (puzzle[i][j - 3] == 'S')) total++;
                }
                // NE
                if (i > 2 && j < 137) {
                    if ((puzzle[i - 1][j + 1] == 'M') && (puzzle[i - 2][j + 2] == 'A') && (puzzle[i - 3][j + 3] == 'S')) total++;
                }
                // SE
                if (i < 137 && j < 137) {
                    if ((puzzle[i + 1][j + 1] == 'M') && (puzzle[i + 2][j + 2] == 'A') && (puzzle[i + 3][j + 3] == 'S')) total++;
                }
                // SW
                if (i < 137 && j > 2) {
                    if ((puzzle[i + 1][j - 1] == 'M') && (puzzle[i + 2][j - 2] == 'A') && (puzzle[i + 3][j - 3] == 'S')) total++;
                }
                // NW
                if (i > 2 && j > 2) {
                    if ((puzzle[i - 1][j - 1] == 'M') && (puzzle[i - 2][j - 2] == 'A') && (puzzle[i - 3][j - 3] == 'S')) total++;
                }
            }
        }
    }

    std::cout << total << std::endl;

    return 0;
}
