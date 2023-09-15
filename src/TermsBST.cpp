#include "TermsBST.h"

TermsBST::TermsBST() : root(nullptr)
{

}
TermsBST::~TermsBST()
{

}


TermsBSTNode* TermsBST::getRoot()
{
	return root;
}

int TermsBST::compare_term(TermsBSTNode* first,TermsBSTNode* second){
	if(first->getEndYear()>second->getEndYear()) return 1;
	else if(first->getEndYear()<second->getEndYear()) return -1;
	else{
		if(first->getEndMonth()>second->getEndMonth()) return 1;
		else if(first->getEndMonth()<second->getEndMonth()) return -1;
		else{
			if(first->getEndDay()>second->getEndDay()) return 1;
			else if(first->getEndDay()<second->getEndDay()) return -1;
			else return 0;
		}
	}
}

void TermsBST::Insert(TermsBSTNode* param){
	TermsBSTNode* cur = root;
	TermsBSTNode* pre;
	while(cur){
		if(compare_term(cur,param)>0){
			if(cur->getLeft()==0){
				cur->setLeft(param);
			}
			else{
				cur = cur->getLeft();
			}
		}
		else if(compare_term(cur,param)<=0){
			if(cur->getRight()==0){
				cur->setRight(param);
			}
			else{
				cur = cur->getRight();
			}
		}
	}
	

}

void TermsBST::Print(TermsBSTNode* node){
	if(node != 0){
		Print(node->getLeft());
		
	}
}

void TermsBST::Delete(int p_year,int p_month,int p_day){

}

// insert

// print

// delete