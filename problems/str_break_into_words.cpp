// write a program that breaks up a string of words with no spaces into a string with the appropriate spaces.
// https://sites.google.com/site/coachingsessions1/home

#include <string>
#include <set>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

bool starts_with(const char * str, const char * word) {
    while (word[0] != '\0') {
        if (str[0] != word[0]) {
            return false;
        }
        str++;
        word++;
    }
    return true;
}

bool break_into_words(const char * str, set<const char *> & words, int index, stack<int> & indices) {
    if (str[index] == '\0') {
        return true;
    }
    for (set<const char *>::iterator it = words.begin(); it != words.end(); it++) {
        if (starts_with(str + index, *it)) {
            indices.push(index);
            int next_index = index + strlen(*it);
            bool success = break_into_words(str, words, next_index, indices);
            if (success) {
                return true;
            }
            indices.pop();
        }
    }
    return false;
}

char * insert_spaces(const char * str, set<const char *> & words) {
    int n = strlen(str);
    stack<int> indices;
    bool success = break_into_words(str, words, 0, indices);
    if (!success) {
        return NULL;
    }
    stack<int> reversed_indices;
    while (!indices.empty()) {
        reversed_indices.push(indices.top());
        indices.pop();
    }
    assert(reversed_indices.top() == 0);
    char * ret = new char[n + reversed_indices.size()];
    char * ret_copy = ret;
    for (int i = 0; i < n; ++i) {
        if (i != 0 && !reversed_indices.empty() && reversed_indices.top() == i) {
            ret_copy[0] = ' ';
            ret_copy++;
        }
        ret_copy[0] = str[0];
        ret_copy++;
        str++;
        if (!reversed_indices.empty() && reversed_indices.top() == i) {
            reversed_indices.pop();
        }
    }
    ret_copy[0] = '\0';
    return ret;
}

int main(int argc, const char ** argv) {
    const char * str = "helloworldmyname";
    set<const char *> words;
    words.insert("hell");
    words.insert("hello");
    words.insert("world");
    words.insert("war");
    words.insert("my");
    words.insert("name");

    const char * ret = insert_spaces(str, words);
    if (ret != NULL) {
        cout << ret << endl;
        // delete[] ret;
    }
    return 0;
}