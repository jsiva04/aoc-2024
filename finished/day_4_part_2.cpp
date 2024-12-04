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

            if (j < puzzle[i].length() - 1 && i < puzzle.size() - 1) {
                // M   S
                //   A  
                // M   S

                if (puzzle[i][j] == 'M') {
                    if (puzzle[i][j + 2] == 'S' && puzzle[i + 1][j + 1] == 'A' && puzzle[i + 2][j] == 'M' && puzzle[i + 2][j + 2] == 'S') total++;
                }

                // M   M
                //   A  
                // S   S

                if (puzzle[i][j] == 'M') {
                    if (puzzle[i][j + 2] == 'M' && puzzle[i + 1][j + 1] == 'A' && puzzle[i + 2][j] == 'S' && puzzle[i + 2][j + 2] == 'S') total++;
                }

                // S   M
                //   A  
                // S   M

                if (puzzle[i][j] == 'S') {
                    if (puzzle[i][j + 2] == 'M' && puzzle[i + 1][j + 1] == 'A' && puzzle[i + 2][j] == 'S' && puzzle[i + 2][j + 2] == 'M') total++;
                }

                // S   S
                //   A  
                // M   M

                if (puzzle[i][j] == 'S') {
                    if (puzzle[i][j + 2] == 'S' && puzzle[i + 1][j + 1] == 'A' && puzzle[i + 2][j] == 'M' && puzzle[i + 2][j + 2] == 'M') total++;
                }
            }

        }
    }

    std::cout << total << std::endl;

    return 0;
}
