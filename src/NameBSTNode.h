#pragma once

class NameBSTNode
{
private:
	char name[21];
	int age;
	int year;
	int month;
	int day;
	char term;
	NameBSTNode*	left;
	NameBSTNode*	right;
	

public:
	NameBSTNode() {}
	~NameBSTNode() {}

	NameBSTNode*	getLeft()			{ return left; }
	NameBSTNode*	getRight()			{ return right; }

	void setLeft(NameBSTNode* left)						{ this->left = left; }
	void setRight(NameBSTNode* right)					{ this->right = right; }
};