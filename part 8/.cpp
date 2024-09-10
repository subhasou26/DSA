#include <iostream>
#include <string>
#include <cctype> // For tolower() function
using namespace std;
int countVowels(const string& str) {
    int count = 0;

    // Iterate through each character in the string
    for (char ch : str) {
        // Convert the character to lowercase for case-insensitive matching
        ch = tolower(ch);

        // Check if the character is a vowel
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }

    return count;
}

int main() {
    string str1 = "Hello, World!";
    string str2 = "This is a test string.";
    string str3 = "AEIOUaeiou"; // All vowels

    cout << "Vowel count in \"" << str1 << "\": " << countVowels(str1) << std::endl;
    cout << "Vowel count in \"" << str2 << "\": " << countVowels(str2) << std::endl;
    cout << "Vowel count in \"" << str3 << "\": " << countVowels(str3) << std::endl;

    return 0;
}
