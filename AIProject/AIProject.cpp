// AIProject.cpp : Defines the entry point for the console application.
//

// SOP: to create a command line chatbot. Further functionality can be added through the use of pipe, for different applications.
// Could be done in VB,c++,c# or maybe java.

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>
#include "bot.h"

using namespace std;

// Entry point for the AI application
int main(int argc, char* argv[])
{

	bot chatterBot;
	char input[256] = {};
	bool running = true;

	cout << "Jone's chatterbot application. No more than 256 characters allowed." << endl;
	cout << "-------------------------------------------------------------------" << endl << endl;

	while (running){

		cout << ">";
		cin >> input;

		char *botOut;
		botOut = chatterBot.respond(input, strlen(input));

		int counter = 0;
		for (int i = 0; i != -1; i++){
			if (*(botOut + i) == '\0'){
				counter = i;
				break;
			}
		}
		for (int i = 0; i < counter; i++){
			cout << *(botOut + i);
		}
		

		cout << endl << endl;

	}

	return 0;
}


