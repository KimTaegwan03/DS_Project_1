#pragma once

class TermsListNode
{
private:
	TermsBST* bst;
	char term;
	int member;
	TermsListNode* next;


public:
	TermsListNode(char p_term) {term = p_term;}
	~TermsListNode() {delete bst;}

	TermsListNode*	getNext()		 { return next; }

	void setNext(TermsListNode* next)	 { this->next = next; }
};