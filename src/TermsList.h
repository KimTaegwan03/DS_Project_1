#pragma once
#include "TermsListNode.h"

class TermsLIST
{
private:
	TermsListNode* head;


public:
	TermsLIST();
	~TermsLIST();

	TermsListNode* getHead();

	void Insert(char* p_name,int p_age,int p_year,
	int p_month,int p_day,char p_term);

	void Search(char* p_name);

	void Delete(char* p_name);

	// insert
	// search
	// delete
};
