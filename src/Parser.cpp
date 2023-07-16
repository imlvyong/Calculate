#include "Parser.h"
#include "Node.h"
#include "Scanner.h"

#include <iostream>

//引用的初始化只能才初始化列表中进行初始化
Parser::Parser(Scanner& scanner) : scanner_(scanner), tree_(nullptr)
{

}

void Parser::parse()
{
	tree_ = expr();
}

//注意：带const的成员函数与不带const的成员函数可以构成重载
double Parser::calculate() const
{
	return tree_->Calc();
}

Node* Parser::expr()
{
	Node* node = term();
	EToken token = scanner_.token();
	if (token == TOKEN_ADD)//扫描到+
	{
		scanner_.accept();//accept+号，扫描下一个字符，看看是不是一个Expression
		Node* nodeRight = expr();
		node = new AddNode(node, nodeRight);//返回的是加法节点，（左节点，右节点），Expression is Term + Expression
	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.accept();
		Node* nodeRight = expr();
		node = new SubNode(node, nodeRight);//Expression is Term - Expression
	}

	return node;//Expression is Term
}
Node* Parser::term()
{
	Node* node = factor();
	EToken token = scanner_.token();
	if (token == TOKEN_MULTIPLY)
	{
		scanner_.accept();
		Node* nodeRight = term();
		node = new MultiplyNode(node, nodeRight);//Term is Factory * Term
	}
	else if (token == TOKEN_DIVIDE)
	{
		scanner_.accept();
		Node* nodeRight = term();
		node = new DivideNode(node, nodeRight);//Term is Factory / Term
	}

	return node;//Expression is Factory
}
Node* Parser::factor()
{
	//or (Expression)
	Node* node = 0;
	EToken token = scanner_.token();
	if (token == TOKEN_LPARENTHESIS)
	{
		scanner_.accept(); //accept '('
		node = expr();//先解析表达式，右边应该有个右括号
		if (scanner_.token() == TOKEN_RPARENTHESIS)
		{
			scanner_.accept(); //accept ')'
		}
		else
		{
			status_ = STATUS_ERROR;
			//to do:抛出异常
			std::cout << "missing parenthesis" << std::endl;
			node = 0;
		}
	}
	else if (token == TOKEN_NUMBER)
	{
		node = new NumberNode(scanner_.number());//新建一个数字节点
		scanner_.accept();
	}
	else if (token == TOKEN_MINUS)
	{
		scanner_.accept();//接受一个负号，目的是指针偏移到下一个字符，让下一次的解析做准备
		node = new UminusNode(factor());//传递一个子节点进去，这个子节点就是因式
	}
	else
	{
		status_ = STATUS_ERROR;
		//to do:抛出异常
		std::cout << "Not a valid expression" << std::endl;
		node = 0;
	}

	return node;
}
