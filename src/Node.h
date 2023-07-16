#ifndef __NODE_H__
#define __NODE_H__

#include "Noncopyable.h"

class Node : private Noncopyable
{
public:
	virtual ~Node(){}

	//每个节点都有一个计算的纯虚函数
	//类Node用于多态，派生类都要实现Calc
	//Calc声明为const的，因为Calc不会改变类的成员
	virtual double Calc() const = 0;

};

//NumerNode要实现这个纯虚函数Calc，为具体类；若没实现，还是抽象类
class NumberNode : public Node
{
public:
	NumberNode(double number) : number_(number) {}
	double Calc() const;
private:
	const double number_;//加const的原因：因为number_初始化后就不会改变
};

//BinaryNode节点有2个子节点
//BinaryNode类没有实现Calc方法，BinaryNode类仍然是抽象类，只有它的派生类，加、减、乘、除节点才知道该如何计算
class BinaryNode : public Node
{
public:
	BinaryNode(Node* left, Node* right)
		: left_(left), right_(right) {}
	~BinaryNode();//记得要释放left_和right_节点
protected:
	Node* const left_;//const的作用：指针不能改变（即指针不能指向其它的节点），而不是指针所指向的内容不能改变
	Node* const right_;
};

//于BinaryNode相比，它只有1个孩子
//UnaryNod也是抽象类，因为它没有实现Calc方法
class UnaryNode : public Node
{
public:
	UnaryNode(Node* child)
		: child_(child) {}
	~UnaryNode();
protected:
	Node* child_;
};

//加法运算节点AddNode
class AddNode : public BinaryNode
{
public:
	//构造函数初始化，要调用基类部分的构造函数
	AddNode(Node* left, Node* right)
		: BinaryNode(left, right) {}
	//要实现Calc方法，AddNode类是具体类
	double Calc() const;
};

class SubNode : public BinaryNode
{
public:
	SubNode(Node* left, Node* right)
		: BinaryNode(left, right) {}
	double Calc() const;
};

class MultiplyNode : public BinaryNode
{
public:
	MultiplyNode(Node* left, Node* right)
		: BinaryNode(left, right) {}
	double Calc() const;
};

class DivideNode : public BinaryNode
{
public:
	DivideNode(Node* left, Node* right)
		: BinaryNode(left, right) {}
	double Calc() const;
};

class UminusNode : public UnaryNode
{
public:
	UminusNode(Node* child)
		: UnaryNode(child) {}
	double Calc() const;
};


#endif // !__NODE_H__




