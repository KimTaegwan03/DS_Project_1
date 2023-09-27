#pragma once
#include "TermsBSTNode.h"
#include <fstream>

class TermsBST
{
private:
	TermsBSTNode* root;

public:
	TermsBST();
	~TermsBST();

	TermsBSTNode* getRoot();

	int compare_end_term(TermsBSTNode* first,TermsBSTNode* second);

	int compare_term(TermsBSTNode* first,TermsBSTNode* second);

	void Insert(TermsBSTNode* param);

	void Print(TermsBSTNode* node);

	TermsBSTNode* Delete(TermsBSTNode* cur,TermsBSTNode* find);

	TermsBSTNode* Find_Min_Node(TermsBSTNode* cur);
	// insert
	// print
	// delete
	TermsBSTNode* Search(TermsBSTNode* find);
};