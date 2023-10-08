#include "TermsList.h"

TermsLIST::TermsLIST()
{
	head = 0;
	tail = 0;
}
TermsLIST::~TermsLIST()
{
	// Delete all node
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

// Insert function, Allocate new node and insert to correct position
void TermsLIST::Insert(char* p_name,int p_age,int p_year, int p_month,int p_day,char p_term){
	TermsBSTNode* ptr = new TermsBSTNode(p_name,p_age,p_year,p_month,p_day,p_term);
	TermsListNode* cur = head;

	while(cur){	//find same term tree
		if(cur->getTerm() == p_term)break;
		else cur = cur->getNext();
	}
	
	if(!cur){	//if there is no tree, make new tree and insert
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

// Search same node and return the node
TermsBSTNode* TermsLIST::Search(int p_year,
	int p_month,int p_day){
	TermsListNode* cur = head;

	// Repeat while search node complete
	while(cur){
		TermsBSTNode* ptr = new TermsBSTNode(p_year,p_month,p_day);
		TermsBSTNode* out = cur->getBST()->Search(ptr);
		delete ptr;
		if(out)
			return out;
		else
			cur = cur->getNext();
	}
	return nullptr;
}

// Delete same node
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
		cur->getBST()->Delete(ptr);
		cur->decreaseMem();
		if(cur->getMem()==0){	// if member is 0, delete list node
			if(pre){
				if(cur==tail){
					tail = pre;
				}
				pre->setNext(cur->getNext());
			}
			else{
				head = cur->getNext();
			}
			delete cur;
		}
		delete ptr;
	}
}

// Search faster node than parameter date
TermsBSTNode* TermsLIST::SearchLesser(int p_year, int p_month, int p_day) {
	TermsListNode* cur = head;
	while (cur) {
		TermsBSTNode* ptr = new TermsBSTNode(p_year, p_month, p_day);
		TermsBSTNode* out = cur->getBST()->SearchLesser(ptr);
		delete ptr;
		if (out)
			return out;
		else
			cur = cur->getNext();
	}
	return nullptr;
}