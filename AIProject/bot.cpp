#include "stdafx.h"
#include "bot.h"
#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

bot::bot()
{
}
bot::~bot()
{
}


char responses[MAX_KEYWORDS][MAX_RESPONSES + 1][MAX_RESPONSE_LENGTH] = { 
{ "unknown", "I don't understand.", "I'm confused!", "Do you even english?" },
{ "open", "So, why am I doing this for you?", "There you go.", "Hope that helps!" },
{ "hi", "Hello", "Good Morning.", "Good Afternoon." },
{ "you", "I am an AI.","I am a chatbot AI.", "Thats enough of me, lets talk about you." },
{"hello","Hi.","Good Morning.","Good Afternoon."},
{ "exit", "Good Bye!", "Nice Chatting to you.", "Talk to you again soon." },
{ "quit", "Good Bye!", "Nice Chatting to you.", "Talk to you again soon." },
{ "jarvis", "Yes?", "What do you want now?", "What can I do for you?" },
{ "open and wait for", "Your app has now closed.", "All done.", "You took your time." }
};

char *bot::respond(char human_input[], int length){
	char input[MAX_RESPONSE_LENGTH];
	for (int i = 0; i < length; i++){
		input[i] = tolower(*(human_input + i));
	}
	input[length] = '\0';

	int Response = 0;
	int Keyword = 1;

	int OpenCommand = 0;

	for (int i = 0; i < MAX_KEYWORDS; i++){
		char *match = strstr(input, responses[i][0]);
		if (match != 0){
			Keyword = i;
			break;
		}
		else{
			Keyword = 0;
		}
	}

	/*
	char *match = strstr(input, responses[1][0]);
	int Response = 0;
	int Keyword = 1;
	if (match != 0){
		Keyword = 1;
	}
	else{
		Keyword = 0;
	}
	*/

	if (Keyword == 1){
		OpenCommand = 1;
		char app[MAX_RESPONSE_LENGTH] = {};
		for (int i = 0; *(input + i) != '\0'; i++){
			app[i] = *(input + i + 5);
		}
		app[strlen(input)] = '\0';
		open(app, strlen(app));
	}

	srand((unsigned)time(NULL));
	Response = (rand() % (MAX_RESPONSES))+1;
	char output[MAX_RESPONSE_LENGTH];
	int ResponseLength = strlen(responses[Keyword][Response]);
	for (int i = 0; i < ResponseLength; i++){
		output[i] = responses[Keyword][Response][i];
	}
	output[ResponseLength] = '\0';
	char *outputPtr;
	outputPtr = output;
	return outputPtr;
}


int bot::openWait(char input[], int length){

	char *command = input;
	char commandToSend[262] = {};
	strcat_s(commandToSend, "Exec ");
	strcat_s(commandToSend, command);
	//FILE *file = _popen(command, "r");
	//char line[256] = {};
	//fgets(line, MAX_RESPONSE_LENGTH, file);
	//while (fgets(line, 256, file));
	//_pclose(file);

	system(command);

	return 0;
}

int bot::open(char input[], int length){
	
	char app[] = "exec_vb.exe ";
	char command[256] = {};
	strcat_s(command, app);
	strcat_s(command, input);
	FILE *file;
	file = _popen(command, "r");
	char line[256] = {};
	char cline[256] = {};
	/*
	while (fgets(line, MAX_RESPONSE_LENGTH, file)){
		cout << line << endl;
	}
	*/
	fgets(line, MAX_RESPONSE_LENGTH, file);
	strcat_s(cline, line);
	cout << cline << endl;
	readOutLoud(line);
	while (fgets(line, MAX_RESPONSE_LENGTH, file));
	_pclose(file);
	
	return 0;


}


int bot::readOutLoud(char toRead[]){
	char *command = "espeak -ven+mf4 ";
	char command_to_send[256] = {};
	strcat_s(command_to_send, command);
	strcat_s(command_to_send, "\"");
	strcat_s(command_to_send, toRead);
	strcat_s(command_to_send, "\"");
	command_to_send[strlen(command_to_send)] = '\0';
	FILE *file = _popen(command_to_send, "r");
	_pclose(file);
	return 0;
}
