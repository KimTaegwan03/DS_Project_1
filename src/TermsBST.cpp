#include "TermsBST.h"
using namespace std;

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

int TermsBST::compare_end_term(TermsBSTNode* first,TermsBSTNode* second){
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
	while(cur){
		if(compare_end_term(cur,param)>0){
			if(cur->getLeft()==0){
				cur->setLeft(param);
			}
			else{
				cur = cur->getLeft();
			}
		}
		else if(compare_end_term(cur,param)<=0){
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
		ofstream flog;
		Print(node->getLeft());
		flog.open("log.txt",ios::app);
		flog << node->getName()<<'/'<<node->getAge()<<'/'<<node->getYear()<<'-'<<node->getMonth()<<'-'<<node->getDay()<<'/'<<node->getEndYear()<<'-'<<node->getEndMonth()<<'-'<<node->getEndDay()<<endl;
		Print(node->getRight());
	}
}

TermsBSTNode* TermsBST::Delete(TermsBSTNode* cur,TermsBSTNode* find){
	if(!cur) return cur;
	if(compare_end_term(cur,find)<0)
		cur->setLeft(Delete(cur->getLeft(),find));
		

}

TermsBSTNode* TermsBST::Find_Node(TermsBSTNode* cur,TermsBSTNode* find){
	TermsBSTNode* out = nullptr;
	if(cur != 0){
		if(!compare_end_term(cur,find)) return cur;
		if(out = Find_Node(cur->getLeft(),find)) return out;
		if(out = Find_Node(cur->getRight(),find)) return out;
	}
	return out;
}
// insert

// print

// delete