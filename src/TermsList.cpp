#include "TermsList.h"

TermsLIST::TermsLIST()
{
	head = 0;
	tail = 0;
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

	while(cur){	//find same term tree
		if(cur->getTerm() == p_term)break;
		else cur = cur->getNext();
	}
	
	if(cur==0){	//if there is no tree, make new tree and insert
		if (!head) {
			TermsListNode* tmp = new TermsListNode(p_term);
			head = tail = tmp;
			tmp->getBST()->Insert(ptr);
			tmp->increaseMem();
		}
		else {
			TermsListNode* tmp = new TermsListNode(p_term);
			tail->setNext(tmp);
			tail = tmp;
			tmp->getBST()->Insert(ptr);
			tmp->increaseMem();
		}
	}
	else{	//insert tree node to tree, increase member
		cur->getBST()->Insert(ptr);
		cur->increaseMem();
	}

}
// insert

TermsBSTNode* TermsLIST::Search(int p_year,
	int p_month,int p_day,char p_term){
	TermsListNode* cur = head;
	while(cur){
		if(cur->getTerm()==p_term) break;
		else cur = cur->getNext();
	}

	if(cur){	//if find same term tree, search in tree
		TermsBSTNode* ptr = new TermsBSTNode(p_year,p_month,p_day);
		TermsBSTNode* out = cur->getBST()->Search(ptr);
		delete ptr;
		return out;
	}	//else return nullptr
	else return nullptr;

}

// search


void TermsLIST::Delete(int p_year, int p_month,int p_day,char p_term){
	TermsListNode* cur = head;
	TermsListNode* pre = nullptr;
	while(cur){
		if(cur->getTerm()==p_term) break;
		else {
			pre = cur;
			cur = cur->getNext();
		}
	}

	if(cur){
		TermsBSTNode* ptr = new TermsBSTNode(p_year,p_month,p_day);
		cur->getBST()->Delete(cur->getBST()->getRoot(),ptr);
		cur->decreaseMem();
		if(cur->getMem()==0){
			if(pre){
				if(cur==tail){
					tail = pre;
				}
				pre->setNext(cur->getNext());
			}
			else{
				head = cur->getNext();
			}
		}
		delete ptr;
	}
}
// delete