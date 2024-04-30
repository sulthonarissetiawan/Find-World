


int main() {
  int numWords;
  cin >> numWords;

  vector<string> words(numWords);
  for (int i = 0; i < numWords; ++i) {
    cin >> words[i];
    // Convert words to lowercase for case-insensitive search
    transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
  }

  vector<vector<char>> matrix = {
    // ... (same matrix content as before) ...
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
