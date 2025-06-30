#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// A map to store the mapping of characters to digits
map<char, int> char_to_digit;
vector<int> assigned_digits(10, 0); // Marks which digits are assigned
string unique_chars;                // To store unique characters in the puzzle

// Get the numeric value of a word based on the character-to-digit mapping
long getValue(const string& word) {
    long value = 0;
    for (char c : word) {
        value = value * 10 + char_to_digit[c];
    }
    return value;
}

// Function to check if the current digit assignment solves the equation
bool solve(const vector<string>& words, const string& result, int index) {
    // If we've assigned digits to all characters, check if the equation holds
    if (index == unique_chars.length()) {
        long sum = 0;
        for (const string& word : words) {
            sum += getValue(word);
        }
        if (sum == getValue(result)) {
            return true;
        }
        return false;
    }

    // Try assigning digits to the current character
    for (int d = 0; d <= 9; ++d) {
        if (!assigned_digits[d]) {
            char ch = unique_chars[index];

            // No leading zero for any word
            if ((ch == words[0][0] || ch == words[1][0] || ch == result[0]) && d == 0)
                continue;

            assigned_digits[d] = 1;
            char_to_digit[ch] = d;

            // Recursively assign digits to the next character
            if (solve(words, result, index + 1)) return true;

            // Backtrack
            assigned_digits[d] = 0;
        }
    }
    return false;
}

int main() {
    // Input the puzzle
    cout << "Enter the number of words in the equation: ";
    int num_words;
    cin >> num_words;
    cin.ignore(); // To ignore the newline after the integer input

    vector<string> words(num_words);
    cout << "Enter the words in the equation (one word per line):\n";
    for (int i = 0; i < num_words; ++i) {
    	cout << "Enter word "<<i+1<<" : ";
        cin >> words[i];
    }

    cout << "Enter the result word: ";
    string result;
    cin >> result;

    // Convert all letters to uppercase for uniformity
    for (auto& word : words) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
    }
    transform(result.begin(), result.end(), result.begin(), ::toupper);

    // Collect unique characters
    unordered_set<char> seen;
    string combined = result;
    for (const string& word : words) {
        combined += word;
    }

    for (char c : combined) {
        if (!seen.count(c)) {
            seen.insert(c);
            unique_chars += c;
        }
    }

    // Check if the unique characters exceed 10
    if (unique_chars.length() > 10) {
        cout << "Warning: More than 10 unique letters. This may not have a valid solution.\n";
        cout << "Would you like to continue (Y/N)? ";
        char choice;
        cin >> choice;
        if (choice == 'N' || choice == 'n') {
            return 0;
        }
    }

    // Solve the equation using the Branch and Bound technique
    if (solve(words, result, 0)) {
        cout << "\n? Solution Found:\n";
        for (char c : unique_chars) {
            cout << c << " = " << char_to_digit[c] << endl;
        }
        // Display the results
        for (const string& word : words) {
            cout << word << " = " << getValue(word) << endl;
        }
        cout << result << " = " << getValue(result) << endl;
    } else {
        cout << "\n? No valid solution found.\n";
    }

    return 0;
}


/*
SEND + MORE = MONEY
BASE + BALL = GAMES
CROSS + ROADS = DANGER
TWO + TWO = FOUR
MATH + HELP = SIMPLE
FIRE + HOUSE = STORM
TWO + TEN = NINE
DOG + CAT = PETS
*/

