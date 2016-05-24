#include "stdafx.h"
#include "bot.h"
#include <iostream>
#include <ctime>

using namespace std;

bot::bot()
{
}
bot::~bot()
{
}


char responses[MAX_KEYWORDS][MAX_RESPONSES + 1][MAX_RESPONSE_LENGTH] = { 
{ "unknown", "I don't understand.", "I'm confused!", "Do you even english?" },
{ "hi", "Hello", "Good Morning.", "Good Afternoon." },
{ "you", "I am an AI.","I am a chatbot AI.", "Thats enough of me, lets talk about you." },
{"hello","Hi.","Good Morning.","Good Afternoon."},
{ "exit", "Good Bye!", "Nice Chatting to you.", "Talk to you again soon." },
{ "quit", "Good Bye!", "Nice Chatting to you.", "Talk to you again soon." },
{"open", "Open What?","Open What?","Open What?"}
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

	if (Keyword == 6){
		OpenCommand = 1;
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


int bot::open(char input[], int length){

	char *command = input;
	FILE *file = _popen(command, "r");
	char line[256] = {};
	while (fgets(line, 256, file));
	_pclose(file);

	return 0;
}
