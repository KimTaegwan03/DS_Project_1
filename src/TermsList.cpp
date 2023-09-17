#include "TermsList.h"

TermsLIST::TermsLIST(): head(nullptr)
{

}
TermsLIST::~TermsLIST()
{
	TermsListNode* tmp;
	while(head){
		tmp = head->getNext();
		delete head;
		head = tmp;
	}
}

TermsListNode* TermsLIST::getHead()
{
	return head;
}

void TermsLIST::Insert(char* p_name,int p_age,int p_year, int p_month,int p_day,char p_term){
	TermsBSTNode* ptr = new TermsBSTNode(p_name,p_age,p_year,p_month,p_day,p_term);
	TermsListNode* cur = head;

	while(cur){
		if(cur->getTerm() == p_term)break;
		else cur = cur->getNext();
	}
	
	if(cur==0){
		TermsListNode* tmp = new TermsListNode(p_term);
		tail->setNext(tmp);
		tail = tmp;
		tmp->getBST()->Insert(ptr);
		tmp->increaseMem();
	}
	else{
		cur->getBST()->Insert(ptr);
		cur->increaseMem();
	}

}
// insert

// search

// delete