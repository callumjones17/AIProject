#pragma once

#define MAX_KEYWORDS 7
#define MAX_RESPONSES 3
#define MAX_RESPONSE_LENGTH 256

class bot
{
public:
	bot();
	~bot();

	// Send over input from user and get response from chatbot.
	char *respond(char input[], int length);

	// Open an application specified by the user.
	// Will return numbers, when I get round to it. Error Checking.
	int open(char input[], int length);

private:
	//char responses[1][4];
};

