#pragma once
#include <iostream>
using namespace std;
void spacing() {
	cout << "  " << endl;
	cout << "  " << endl;
	cout << "  " << endl;
}
int Length() {
	void;
}
char CharacterAt( int index, string word) {
	void;
}
bool EqualTo(string str) {

}
void Append(string str) {

}
void Prepend(string str) {

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
    if (position != std::string::npos) {
        return position;
    }
    else {
        return -1;
    }


}


void Replace(string word, string findString, string replaceString) {
    size_t pos = Find(findString, word);
    if (pos != std::string::npos) {
        word.replace(pos, findString.length(), replaceString);
    }
}

string ReadFromConsole() {

}

void WriteToConsole(string word) {
	cout << word << endl;
}

bool EqualityOperator() {

}

char Subscriptoperator() {

}

void AssignmentOperator() {

}

bool LessThanOperator() {

}
