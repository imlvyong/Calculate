
#include "Node.h"
#include "Parser.h"
#include "Scanner.h"

#include <iostream>

void test1()
{
	Node *node = new NumberNode(0.5);
	std::cout << "number node: " << node->Calc() << std::endl;
	delete node;

	UnaryNode *unode = new UminusNode(new NumberNode(5));
	std::cout << "Uminus node: " << unode->Calc() << std::endl;
	delete unode;

	BinaryNode *bnode1 = new AddNode(new NumberNode(3), new NumberNode(5));
	std::cout << "Add node:" << bnode1->Calc() << std::endl;
	delete bnode1;

	BinaryNode *bnode2 = new SubNode(new NumberNode(5), new NumberNode(3));
	std::cout << "Sub node:" << bnode2->Calc() << std::endl;
	delete bnode2;

	BinaryNode *bnode3 = new MultiplyNode(new NumberNode(3), new NumberNode(5));
	std::cout << "Mul node:" << bnode3->Calc() << std::endl;
	delete bnode3;

	BinaryNode *bnode4 = new DivideNode(new NumberNode(6), new NumberNode(3));
	std::cout << "Div node:" << bnode4->Calc() << std::endl;
	delete bnode4;
}

void test2()
{
	do
	{
		std::cout << ">";
		std::string buffer;
		std::getline(std::cin, buffer);//输入一行表达式放到buf当中
		Scanner scanner(buffer);
		Parser parser(scanner);
		parser.parse();//实际上计算表达式的值，就是计算这颗树的根节点的值
		std::cout << parser.calculate() << std::endl;
	} while (1);
}
int main(void)
{
	test1();
	test2();
	return 0;
}