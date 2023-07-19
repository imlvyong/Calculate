### 类图
![image](//www.plantuml.com/plantuml/png/ZLLVJzi-57tFf_1JbG91lsT-NGLZJ48Q2AajUwmSnoqMZXFPDzqOspxxSkDGtwG9zAMAVV-VUtfywO1Rg78TyTI1vGAOqDmvTbzayZKwtQdQoZLJxjiZrvMCfqmKna6mx0gLiJf2RKsS5LMgvJGO_GMxvbgyHR9FxB_Wy1VhnDFeJnIrTQiybRQjFXGV9MsUrcQQW3Lcw8tmMHbkNtogf1deX6cvWVN-PDNs2OP2Lo5oh0cVGJmfdGrbkAiqg5BBjho3xE9Y9mKKTjP4pdseM__VDQP5eUUiB9m2jPDetaFpoAtYgK_9nXexPPW1zxNhxcjWKQnscKQ9XxCoQ94PKmQOoX2aHTqGtye9S_vZ7NfPLFaxy0I_1rjabO2ZV5UvCfKRduxwVgsC05MOen9VDKEthYEUKLDtzZl9YXyc8JJi6WAf-eRLo3qbGiz45nf58NFm29r7D4zmm3sCMmdwqUemkmTyp4eXtgzTS6EaVTtJIGXPGbp_uxj_HqAxcsNnB0q3_2NN3USTM6MsR2jXyPAdXJvayKrUmaiyxTr-AKnWTk9RSS-g_Fwae3Ri9O8MIQiDShf3Sr7PXyBXDUqIpprnIJgfNDCitj8kruJrt3gFqc9vjLmjM8aN25Ch6_9dQSaHfCt9SSDH2YYgWcjHQGvqwdON4-RyHv0ri5BYgItkW4FLJ8cadpJ9IBCU-YKI4Jlk0CIpB3w04lN0Jlkk6sL6VRiQ9BJaEDq82UvvBkEU6eMfcv2SbpCIUzRfPCuoXSH5HWzj_3QZmtjbU-tr5gXsQnICTUDZ4AHhF7C3CG5pmY3LOOSue7z2ty_cHjpE61NjKFe8vuJH5yPRvan8hHjM73u_oYXmwqErnRa2LkWrEF03s3e21tuB79-P6XeEg5yo7bWtzJjhAypPfhw-uoLf5IcEp_q1DtsZxpEq7yUp3yA217mqQN8yAkJbHM__xMMDe8qgj4nHXRhhOPlsXCQGglE6Hwrsi5chzLwm8WIFdVWxMeiQzXdfPQ-7YFOvEqUFypPisDQDlfGcgtBz3m00)

### plant类图代码

```plantuml
@startuml

abstract class Node{
+virtual isLValue() const
+virtual void assign(double)
+virtual double Calc() const = 0
+virtual ~Node()
}

class NumberNode{
+ double Calc() const
- const double number_
}

abstract class BinaryNode{
- Node* left_
- Node* right_
}

abstract class UnaryNode{
+ double Calc() const
- Node* child_
}

abstract class MultipleNode{
-std::vector<Node*> childs_;
-std::vector<bool> positives_;
}

class VariableNode {
+ double Calc() const
+ bool isLvalue() const
+ void assign(double val)
-const unsigned int id_
- Storage& storage_
}

class SumNode{
+ double Calc() const
}

class ProductNode{
+ double Calc() const
}

class UminusNode {
+ double Calc() const
}

class FunctionNode{
+ double Calc() const
}

class AssignNode{
+double Calc() const
}


Node <|-down- NumberNode
Node <|-down- BinaryNode
Node <|-down- UnaryNode
Node <|-down- MultipleNode
Node <|-down- VariableNode

BinaryNode <|-down- AssignNode
MultipleNode <|-down- SumNode
MultipleNode <|-down- ProductNode
UnaryNode <|-down- UminusNode
UnaryNode <|-down- FunctionNode

class Scanner{
+ void accept()
+ double number() const
+ EToken token() const
+ std::string getSymbol() const
+ bool isEmpty()const
+ bool isDone() const
- void skipWhite()
- const std::string buf_
- unsigned int curPos_
- EToken token_
- double number_
- std::string symbol_
- bool isEmpty_
}

class Parser{
+ STATUS parse()
+ Node* expr()
+ Node* term()
+ Node* factor()
+ double calculate() const
- Scanner& scanner_
- Node* tree_
- STATUS status_
- Calc& calc_
}

class SymbolTable{
+ unsigned int add(const std::string& str)
+ unsigned int find(const std::string& str) const
+ void clear()
+ std::string getSymbolName(unsigned int id) const
- std::map<std::string, unsigned int> dictionary_
- unsigned int curId_
}

class Storage{
+ void clear()
+ bool isInit(unsigned int id) const
+ void addConstant(SymbolTable& tbl)
+ double getValue(unsigned int id) const
+ void setValue(unsigned int id, double val)
+ void addValue(unsigned int id, double val)
- std::vector<double> cells_
- std::vector<bool> inits_
}

class FunctionTable{
+ void init(SymbolTable& tbl)
+ PtrFun getFunction(unsigned int id) const
+ unsigned int getSize() const
- std::map<unsigned int, PtrFun> funsMap_
}

class Calc{
- unsigned int findSymbol(const std::string& str) const
- unsigned int addSymbol(const std::string& str)
- bool isFunction(unsigned int id) const
- PtrFun getFunction(unsigned int id) const
- Storage& getStorage()
- SymbolTable symTbl_
- FunctionTable functionTbl_
- Storage storage_
}


Scanner <-down- Parser
Calc *-down- SymbolTable
Calc *-down- Storage
Calc *-down- FunctionTable
SymbolTable <.down. Storage
SymbolTable <.down. FunctionTable
@enduml
```