#pragma once
#include "TermsListNode.h"

class TermsLIST
{
private:
	TermsListNode* head;
	TermsListNode* tail;

public:
	TermsLIST();
	~TermsLIST();

	TermsListNode* getHead();

	void Insert(char* p_name,int p_age,int p_year,
	int p_month,int p_day,char p_term);

	TermsBSTNode* Search(int p_year,
	int p_month,int p_day,char p_term);

	void Delete(int p_year,
	int p_month,int p_day,char p_term);

	// insert
	// search
	// delete
};
