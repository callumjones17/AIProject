// Together.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#define MAX_RESPONSE_LENGTH 256

using namespace std;

char *espeakCommand = "espeak - ven + mf4";
char *vbSpeakCommand = "ai_speak ";


char *getAIResponse(char *stimuli){//, int &func){
	char *command = "AIProject.exe ";
	char command_to_send[256] = {};
	strcat_s(command_to_send, command);
	strcat_s(command_to_send, "\"");
	strcat_s(command_to_send, stimuli);
	strcat_s(command_to_send, "\"");
	command_to_send[strlen(command_to_send)] = '\0';
	//cout << command_to_send << endl;
	char line[MAX_RESPONSE_LENGTH] = {};
	//char otherLine[MAX_RESPONSE_LENGTH] = {};
	//system(command_to_send);
	FILE *file = _popen(command_to_send, "r");
	fgets(line, MAX_RESPONSE_LENGTH, file);
	//while (fgets(otherLine, MAX_RESPONSE_LENGTH, file));
	//if (otherLine[0] == 'O' && otherLine[1] == 'p'){
	//	func = 1;
	//}
	_pclose(file);
	//somehow get text that system returns
	return line;
}

char* getVoiceInput(){
	char line[MAX_RESPONSE_LENGTH] = {};
	char lin2[MAX_RESPONSE_LENGTH] = {};
	char* command_to_send = "get_speech.exe";
	FILE *file = _popen(command_to_send, "r");
	fgets(line, MAX_RESPONSE_LENGTH,file);
	while (fgets(lin2, MAX_RESPONSE_LENGTH, file));
	_pclose(file);
	return line;
}

void readOutLoud(char *toRead){
	//char *command = "espeak -ven+mf4 ";
	//char *command = espeakCommand;
	char *command = vbSpeakCommand;
	char command_to_send[256] = {};
	strcat_s(command_to_send, command);
	strcat_s(command_to_send, "\"");
	strcat_s(command_to_send, toRead);
	strcat_s(command_to_send, "\"");
	command_to_send[strlen(command_to_send)] = '\0';
	FILE *file = _popen(command_to_send, "r");
	_pclose(file);
	return;
}

char* GetVoiceInput2ndAttempt(){
	char *command = "get_speech_diag";
	char line[MAX_RESPONSE_LENGTH] = {};
	FILE *file = _popen(command, "r");
	fgets(line, MAX_RESPONSE_LENGTH, file);
	_pclose(file);
	//readOutLoud(line);	// Debugging Only
	return line;
}




int main(int argc, char* argv[])
{
	char input[256];
	//char firstWord[256];									// comment this out for voice.
	char toSend[600] = {};

	cout << "Hi"<< endl;

	while (1){


		/*													This is the original texting version of the app.
		cout << ">  ";
		cin >> firstWord;
		cin.getline(input, MAX_RESPONSE_LENGTH);
		*/

		char *firstWord = GetVoiceInput2ndAttempt();


		char toSend[256] = {};
		strcat_s(toSend, firstWord);
		//strcat_s(toSend, input);						// Don't Know why this was causing issues.  //Needed for Texting though

		char *output = getAIResponse(toSend);
		char output_s[MAX_RESPONSE_LENGTH] = {};
		for (int i = 0; i < strlen(output); i++){
			output_s[i] = *(output + i);
		}
		output_s[strlen(output)] = '\0';

		cout << output_s << endl;
		readOutLoud(output_s);

	}

	return 0;
}

