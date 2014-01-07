// Telephone Words
// PROBLEM People in the United States often give others their telephone number as a word representing the seven-digit number after the area code. For example, if my telephone number were 866-2665, I could tell people my number is “TOOCOOL,” instead of the hard-to-remember seven-digit number. Note that many other possibilities (most of which are nonsensical) can represent 866-2665. You can see how letters correspond to numbers on a telephone keypad in Figure 7-2.
// prints out all of the possible “words” or combinations of letters that can represent the given number. Because the 0 and 1 keys have no letters on them, you should change only the digits 2– 9 to letters. You’ll be passed an array of seven integers, with each element being one digit in the number. You may assume that only valid phone numbers will be passed to your function. You can use the helper function
// char getCharKey( int telephoneKey, int place )
// which takes a telephone key (0– 9) and a place of either 1, 2, 3 and returns the character corresponding to the letter in that position on the specified key. For example, GetCharKey( 3,2) will return ‘E’ because the telephone key 3 has the letters “DEF” on it and ‘E’ is the second letter.
// Mongan, John (2012-11-14). Programming Interviews Exposed: Secrets to Landing Your Next Job (Kindle Locations 3242-3248). Wiley. Kindle Edition. 

#include <iostream>
#include <cassert>
using namespace std;

char get_char_key(char key, int place) {
    assert(place >= 1 && place <= 3);
    assert(key >= '2' && key <= '9');
    return (key - '2') * 3 + (place - 1) + 'a';
}

void print_words_internal(const char * number, char * words, int index) {
    if (number[index] == '\0') {
        for (int i = 0; i < index; ++i) {
            cout << words[i];
        }
        cout << endl;
        return;
    }
    if (number[index] == '-') {
        print_words_internal(number, words, index + 1);
        return;
    }
    if (number[index] == '0' || number[index] == '1') {
        words[index] = number[index];
        print_words_internal(number, words, index + 1);
    }
    else {
        for (int j = 1; j <= 3; ++j) {
            words[index] = get_char_key(number[index], j);
            print_words_internal(number, words, index + 1);
        }
    }
}

void print_words(const char * number) {
    char * words = new char[strlen(number)];
    print_words_internal(number, words, 0);
    delete[] words;
}

int main(int argc, const char ** argv) {
    print_words("497-1117");
    return 0;
}
