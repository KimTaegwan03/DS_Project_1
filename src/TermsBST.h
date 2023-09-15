#pragma once
#include "TermsBSTNode.h"

class TermsBST
{
private:
	TermsBSTNode* root;

public:
	TermsBST();
	~TermsBST();

	TermsBSTNode* getRoot();

	int compare_term(TermsBSTNode* first,TermsBSTNode* second);

	void Insert(TermsBSTNode* param);

	void Print(TermsBSTNode* node);

	void Delete(int p_year,int p_month,int p_day);

	// insert
	// print
	// delete
};