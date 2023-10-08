#pragma once
#include <iostream>
#include "TermsBST.h"

class TermsListNode
{
private:
	TermsBST* bst;
	char term;
	int member;
	TermsListNode* next;


public:
	TermsListNode(char p_term) {
		term = p_term;
		member = 0;
		bst = new TermsBST;
		next = 0;
	}
	~TermsListNode() {delete bst;}

	TermsListNode*	getNext()		 { return next; }
	char getTerm(){return term;}
	TermsBST* getBST(){return bst;}
	int getMem() {return member;}

	void increaseMem() {member++;}
	void decreaseMem() {member--;}

	void setNext(TermsListNode* next)	 { this->next = next; }
};