#include <iostream>
#include <fstream>
#include "SubstringFind.h"
#include "profile.h"

using namespace std;

string readFromFile(string name) {
    ifstream in(name);
    string text, s;
    while (getline(in, s)) {
        text += s + "\n";
    }
    return text;
}

int main()
{
    string text, s;
    for (int i = 10; i <= 1e3; i*=10) {
        text = readFromFile("text.txt");
        s = string(text.data(), i);
        LOG_DURATION("File - 25,2kb, word - " + to_string(i));
        auto res = getPosOfSubstrings(text, s);
    }
    for (int i = 10; i <= 1e3; i*=10) {
        text = readFromFile("text2.txt");
        s = string(text.data(), i);
        LOG_DURATION("File - 252kb, word - " + to_string(i));
        auto res = getPosOfSubstrings(text, s);
    }
    for (int i = 10; i <= 1e3; i*=10) {
        text = readFromFile("text3.txt");
        s = string(text.data(), i);
        LOG_DURATION("File - 2520kb, word - " + to_string(i));
        auto res = getPosOfSubstrings(text, s);
    }
    return 0;
}