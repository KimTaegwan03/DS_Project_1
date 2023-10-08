#pragma once
#include "NameBSTNode.h"
#include <fstream>

class NameBST
{
private:
	NameBSTNode* root;

public:
	NameBST();
	~NameBST();

	NameBSTNode* getRoot();

	void Insert(NameBSTNode* param);

	void Print(std::ofstream& flog, NameBSTNode* node);

	void Delete(NameBSTNode* find);

	NameBSTNode* Search(NameBSTNode* find);
};