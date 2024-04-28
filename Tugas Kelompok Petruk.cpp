#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool isValidCell(int rows, int cols, int row, int col) {
    return (row >= 0 && row < rows && col >= 0 && col < cols);
}

bool searchWord(const vector<vector<char>>& matrix, const string& word, int row, int col, int dr, int dc) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (word.empty() || !isValidCell(rows, cols, row, col)) {
        return false;
    }

    if (tolower(matrix[row][col]) != tolower(word[0])) {
        return false;
    }

    if (word.length() == 1) {
        return true;
    }

    return searchWord(matrix, word.substr(1), row + dr, col + dc, dr, dc);
}

bool searchMatrix(const vector<vector<char>>& matrix, const string& word) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            for (int dr = -1; dr <= 1; ++dr) {
                for (int dc = -1; dc <= 1; ++dc) {
                    if (dr == 0 && dc == 0) {
                        continue;
                    }
                    if (searchWord(matrix, word, row, col, dr, dc)) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    int numWords;
    cin >> numWords;

    vector<string> words(numWords);
    for (int i = 0; i < numWords; ++i) {
        cin >> words[i];
    }

    vector<vector<char>> matrix = {
        {'A', 'A', 'F', 'L', 'K', 'H', 'P', 'F', 'S', 'S', 'U', 'F', 'I', 'C', 'I', 'C', 'L', 'E', 'S', 'G', 'N', 'N', 'H'},
	{'S', 'F', 'V', 'R', 'E', 'O', 'M', 'R', 'W', 'L', 'R', 'T', 'T', 'S', 'X', 'O', 'Q', 'Q', 'N', 'A', 'O', 'A', 'O'},
	{'Q', 'E', 'I', 'A', 'I', 'F', 'X', 'A', 'E', 'I', 'R', 'F', 'V', 'F', 'Y', 'S', 'X', 'I', 'M', 'I', 'N', 'J', 'I'},
	{'W', 'S', 'T', 'R', 'L', 'G', 'O', 'C', 'A', 'P', 'B', 'I', 'A', 'F', 'I', 'W', 'I', 'W', 'T', 'U', 'A', 'C', 'M'},
	{'F', 'E', 'Y', 'A', 'E', 'A', 'I', 'S', 'T', 'P', 'C', 'R', 'L', 'U', 'J', 'K', 'O', 'A', 'K', 'C', 'E', 'R', 'S'},
	{'R', 'V', 'D', 'A', 'K', 'P', 'N', 'D', 'E', 'E', 'H', 'D', 'E', 'M', 'S', 'N', 'C', 'K', 'K', 'F', 'O', 'A', 'H'},
	{'M', 'R', 'N', 'E', 'D', 'S', 'L', 'C', 'R', 'R', 'I', 'W', 'N', 'R', 'S', 'A', 'A', 'F', 'I', 'T', 'M', 'M', 'I'},
	{'Y', 'A', 'A', 'E', 'C', 'I', 'E', 'A', 'H', 'Y', 'M', 'O', 'T', 'A', 'V', 'H', 'R', 'S', 'S', 'T', 'I', 'S', 'B'},
	{'R', 'J', 'S', 'E', 'W', 'E', 'L', 'C', 'C', 'E', 'N', 'N', 'I', 'E', 'T', 'O', 'H', 'W', 'S', 'G', 'L', 'S', 'E'},
	{'U', 'T', 'E', 'N', 'E', 'W', 'E', 'B', 'H', 'M', 'Y', 'B', 'E', 'T', 'N', 'N', 'R', 'A', 'I', 'E', 'B', 'E', 'N'},
	{'R', 'C', 'L', 'K', 'U', 'T', 'E', 'A', 'E', 'Q', 'J', 'L', 'S', 'G', 'S', 'H', 'T', 'G', 'D', 'S', 'K', 'O', 'A'},
	{'B', 'H', 'O', 'I', 'C', 'A', 'T', 'N', 'R', 'R', 'S', 'D', 'D', 'E', 'C', 'E', 'H', 'O', 'O', 'L', 'G', 'I', 'T'},
	{'E', 'N', 'S', 'L', 'U', 'A', 'R', 'I', 'R', 'S', 'E', 'T', 'A', 'L', 'O', 'C', 'O', 'H', 'C', 'T', 'O', 'H', 'E'},
	{'F', 'Z', 'F', 'U', 'D', 'Q', 'J', 'Y', 'M', 'A', 'D', 'O', 'Y', 'I', 'O', 'Y', 'G', 'L', 'O', 'V', 'E', 'S', 'U'},
	{'T', 'E', 'K', 'A', 'L', 'F', 'W', 'O', 'N', 'S', 'N', 'A', 'E', 'B', 'M', 'I', 'E', 'J', 'T', 'Z', 'N', 'T', 'G'},
	{'E', 'S', 'W', 'P', 'O', 'S', 'J', 'X', 'E', 'U', 'T', 'U', 'Y', 'O', 'Z', 'U', 'W', 'A', 'K', 'E', 'Z', 'H', 'M'},
	{'K', 'Z', 'U', 'H', 'B', 'P', 'E', 'Z', 'E', 'E', 'R', 'F', 'L', 'M', 'S', 'N', 'O', 'W', 'B', 'A', 'L', 'L', 'H'},
	{'N', 'S', 'N', 'O', 'W', 'B', 'O', 'A', 'R', 'D', 'Y', 'T', 'V', 'W', 'Y', 'C', 'L', 'E', 'V', 'O', 'H', 'S', 'A'},
	{'A', 'C', 'O', 'C', 'R', 'Q', 'L', 'G', 'Z', 'I', 'Y', 'C', 'H', 'O', 'D', 'R', 'A', 'Z', 'Z', 'I', 'L', 'B', 'I'},
	{'L', 'B', 'V', 'K', 'K', 'W', 'A', 'N', 'Z', 'A', 'A', 'Q', 'I', 'N', 'W', 'O', 'L', 'P', 'W', 'O', 'N', 'S', 'L'},
	{'B', 'F', 'R', 'E', 'E', 'Z', 'I', 'N', 'G', 'R', 'A', 'I', 'N', 'S', 'L', 'I', 'L', 'G', 'T', 'M', 'E', 'L', 'T'},
	{'H', 'Q', 'P', 'Y', 'L', 'W', 'H', 'F', 'M', 'N', 'F', 'F', 'U', 'F', 'P', 'S', 'W', 'X', 'N', 'U', 'M', 'M', 'V'},
    };

    for (const string& word : words) {
        if (searchMatrix(matrix, word)) {
            cout << "Ada" << endl;
        } else {
            cout << "Tidak Ada" << endl;
        }
    }

    return 0;
}
