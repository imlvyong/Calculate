#ifndef __PARSER_H__
#define __PARSER_H__

class Node;
class Scanner;

enum STATUS
{
	STATUS_OK,
	STATUS_ERROR,
	STATUS_QUIT
};


class Parser
{
public:
	Parser(Scanner& scanner);
	void parse();
	Node* expr();
	Node* term();
	Node* factor();
	double calculate() const;
private:
	Scanner& scanner_;

	Node* tree_;
	STATUS status_;
};

#endif
