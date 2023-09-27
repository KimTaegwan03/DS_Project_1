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

	void Print(NameBSTNode* node);

	NameBSTNode* Delete(NameBSTNode* cur, NameBSTNode* find);

	NameBSTNode* Find_Min_Node(NameBSTNode* cur);

	NameBSTNode* Search(NameBSTNode* find);

	// insert
	// search
	// print
	// delete
};