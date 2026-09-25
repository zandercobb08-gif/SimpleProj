#pragma once
#include <iostream>
using namespace std;
void spacing() {
	cout << "  " << endl;
	cout << "  " << endl;
	cout << "  " << endl;
}
int Length(string word) {
	int length = word.length();
    return length;
}
char CharacterAt( int index, string word) {
    char desiredchar = '\0';
    if (index != string::npos)
        char desiredchar = word.find(index);
    return desiredchar;
}
bool EqualTo(string str1, string str2 ) {
    if (str1.length() == str2.length())
        return true;
}
string Append(string str, string addition) {
    str += addition;
    return str;
}
string Prepend(string str, string addition) {
    addition += str;
    return addition;
}




string ToLower(string word) {


    
    for (char &c : word) {
        c = tolower(static_cast<unsigned char>(c));
    }

    return word;
}

string ToUpper(string word) {
    for (char& c : word) {
        c = toupper(static_cast<unsigned char>(c));
    }

    return word;
}

int Find(string findString, string word) {
    size_t position = word.find(findString);
    if (position != string::npos) {
        return position;
    }
    else {
        return -1;
    }


}


string Replace(string word, string findString, string replaceString) {
    size_t pos = Find(findString, word);
    if (pos != string::npos) {
        word.replace(pos, findString.length(), replaceString);
    }
    return word;
}



void WriteToConsole(string word) {
	cout << word << endl;
}

bool EqualityOperator(string word, string desiredword) {
    if (word == desiredword)
        return true;
}

char Subscriptoperator(string word, int pos) {
    char desiredchar = 'a';
    if (pos != string::npos)
        char desiredchar = word.find(pos);
    return desiredchar;
}

string AssignmentOperator(string word, string desiredword) {
    word = desiredword;
    return word;
}

bool LessThanOperator(string word1, string word2) {
    if (word1 < word2)
        return true;
}
