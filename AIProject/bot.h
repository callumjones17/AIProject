#pragma once
class bot
{
public:
	bot();
	~bot();
	// Send over input from user and get response from chatbot.
	void respond(char input[]);

	// Grab some input from the user and store in in output.
	void getInput(char output[]);
};

