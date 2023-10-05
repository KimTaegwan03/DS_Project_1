#include "TermsBST.h"
using namespace std;

TermsBST::TermsBST() : root(nullptr)
{

}
TermsBST::~TermsBST()
{
	if(root) delete root;
}


TermsBSTNode* TermsBST::getRoot()
{
	return root;
}

int TermsBST::compare_end_term(TermsBSTNode* first,TermsBSTNode* second){	// return 1, when first is later
	if(first->getEndYear()>second->getEndYear()) return 1;					// return -1, when first is faster
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

	if (!root) {
		root = param;
		return;
	}

	while(cur){
		if(compare_end_term(cur,param)>0){
			if(!cur->getLeft()){
				cur->setLeft(param);
				break;
			}
			else{
				cur = cur->getLeft();
			}
		}
		else if(compare_end_term(cur,param)<=0){
			if(!cur->getRight()){
				cur->setRight(param);
				break;
			}
			else{
				cur = cur->getRight();
			}
		}
	}
	

}

void TermsBST::Print(ofstream& flog, TermsBSTNode* node){
	if(node){
		Print(flog,node->getLeft());
		flog << node->getName()<<'/'<<node->getAge()<<'/'<<node->getYear()<<'-'<<node->getMonth()<<'-'<<node->getDay()<<'/'<<node->getEndYear()<<'-'<<node->getEndMonth()<<'-'<<node->getEndDay()<<endl;
		Print(flog,node->getRight());
	}
}

TermsBSTNode* TermsBST::Delete(TermsBSTNode* cur,TermsBSTNode* find){
	if(!cur) return cur;
	if(compare_end_term(cur,find)>0)
		cur->setLeft(Delete(cur->getLeft(),find));
	else if(compare_end_term(cur,find)<0)
		cur->setRight(Delete(cur->getRight(),find));
	else{	//find
		if(cur->getLeft()==0){
			TermsBSTNode* tmp = cur->getRight();
			delete cur;
			return tmp;
		}
		else if(cur->getRight()==0){
			TermsBSTNode* tmp = cur->getLeft();
			delete cur;
			return tmp;
		}

		TermsBSTNode* tmp = Find_Min_Node(cur->getRight());
		cur->setInfo(tmp);
		cur->setRight(Delete(cur->getRight(),tmp));
	}
	return cur;
		

}

TermsBSTNode* TermsBST::Find_Min_Node(TermsBSTNode* cur){
	TermsBSTNode* ptr = cur;
	while(ptr->getLeft()){
		ptr = ptr->getLeft();
	}
	return ptr;
}
// insert

// print

// delete
TermsBSTNode* TermsBST::Search(TermsBSTNode* find){
	TermsBSTNode* cur = root;
	while(cur){
		if(compare_end_term(cur,find)>0)
			cur = cur->getLeft();
		else if(compare_end_term(cur,find)<0)
			cur = cur->getRight();
		else break;
	}
	return cur;

}