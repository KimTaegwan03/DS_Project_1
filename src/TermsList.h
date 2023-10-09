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
	int p_month,int p_day);
	TermsBSTNode* SearchLesser(int p_year,
	int p_month,int p_day);

	void Delete(char* p_name, int p_year,
	int p_month,int p_day,char p_term);
};
