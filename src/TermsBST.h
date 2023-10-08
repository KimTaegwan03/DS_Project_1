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
	void setRoot(TermsBSTNode* p) { root = p; }
	void resetRoot() { root = 0; }

	int compare_end_term(TermsBSTNode* first,TermsBSTNode* second);

	void Insert(TermsBSTNode* param);

	void Print(std::ofstream& flog, TermsBSTNode* node);

	void Delete(TermsBSTNode* find);

	TermsBSTNode* Search(TermsBSTNode* find);
	TermsBSTNode* SearchLesser(TermsBSTNode* find);
};