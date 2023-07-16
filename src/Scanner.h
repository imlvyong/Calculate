#ifndef __SCANNER_H__
#define __SCANNER_H__

#include <string>

enum EToken
{
	TOKEN_END,
	TOKEN_ERROR,
	TOKEN_NUMBER,
	TOKEN_ADD,
	TOKEN_MINUS,
	TOKEN_MULTIPLY,
	TOKEN_DIVIDE,
	TOKEN_LPARENTHESIS,
	TOKEN_RPARENTHESIS,
	TOKEN_IDENTIFIER,
	TOKEN_ASSIGN//eg:a=5
};

class Scanner
{
public:
	Scanner(const std::string& buf);
	void accept();
	double number() const;
	EToken token() const;
private:
	void skipWhite();
	const std::string buf_;
	unsigned int curPos_;
	EToken token_;//返回状态
	double number_;//返回数字
};

#endif



