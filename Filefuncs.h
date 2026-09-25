#pragma once
#include <fstream>
#include "Utilities.h"
void writetofile(string event) {
ofstream logfile("test_results.txt");
if (logfile.is_open()) {
	logfile << event << endl;
}
logfile.close();
}
void appendtolog(string event) {
	ofstream logfile("test_results.txt", ios::app);
	if (logfile.is_open()) {
		logfile << event << endl;
		logfile.close();
	}
}
void appendtolog(int event) {
	ofstream logfile("test_results.txt", ios::app);
	if (logfile.is_open()) {
		logfile << event << endl;
		logfile.close();
	}
}
bool fileexists(string filename) {
	ifstream file(filename);
	return file.is_open();
}
void fileop(string log) {
	if (fileexists("test_results.txt")) {
		appendtolog(log);
	}
	else
		writetofile(log);
}
void firsthighscore(int event) {
	ofstream logfile("highscore.txt");
	if (logfile.is_open()) {
		logfile << event << endl;
	}
	logfile.close();
}
void newhighscore(int event) {
	ifstream datafile("highscore.txt");
	int highscore = 0;
	if (datafile.is_open()) {
		datafile >> highscore;
		datafile.close();
	}
	ofstream logfile("highscore.txt");
	if (logfile.is_open()) {
		if (event > highscore) {
			logfile << event << endl;
		}
		else {
			logfile << highscore << endl;
		}

		logfile.close();
	}
}
void highscorefile(int score) {
	if (fileexists("highscore.txt")) {
		newhighscore(score);
	}
	else
		firsthighscore(score);
}
int printhighscore() {
	ifstream datafile("highscore.txt");
	int highscore = 0;
	if (datafile.is_open()) {
		datafile >> highscore;
		datafile.close();
	}
	return highscore;
}