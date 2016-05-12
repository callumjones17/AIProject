#pragma once

#define MAX_KEYWORDS 4
#define MAX_RESPONSES 3
#define MAX_RESPONSE_LENGTH 256

class bot
{
public:
	bot();
	~bot();

	// Send over input from user and get response from chatbot.
	char *respond(char input[], int length);

private:
	//char responses[1][4];
};

