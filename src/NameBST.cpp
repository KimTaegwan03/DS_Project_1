#include "NameBST.h"
using namespace std;

NameBST::NameBST() : root(nullptr)
{

}
NameBST::~NameBST()
{
	if(root) delete root;
}

NameBSTNode* NameBST::getRoot()
{
	return root;
}

void NameBST::Insert(NameBSTNode* param){
	NameBSTNode* cur = root;

	if (!root) {
		root = param;
		return;
	}
	while(cur){
		if(strcmp(cur->getName(),param->getName())>0){
			if(!cur->getLeft()){
				cur->setLeft(param);
				return;
			}
			else{
				cur = cur->getLeft();
			}
		}
		else if(strcmp(cur->getName(),param->getName())<=0){
			if(!cur->getRight()){
				cur->setRight(param);
				return;
			}
			else{
				cur = cur->getRight();
			}
		}
	}
}

void NameBST::Print(ofstream& flog, NameBSTNode* node){
	if(!node){
		ofstream flog;
		Print(flog,node->getLeft());
		flog << node->getName()<<'/'<<node->getAge()<<'/'<<node->getYear()<<'-'<<node->getMonth()<<'-'<<node->getDay()<<'/'<<node->getEndYear()<<'-'<<node->getEndMonth()<<'-'<<node->getEndDay()<<endl;
		Print(flog,node->getRight());
	}
}

NameBSTNode* NameBST::Delete(NameBSTNode* cur, NameBSTNode* find){
	if(!cur) return cur;
	if(strcmp(cur->getName(),find->getName())>0)
		cur->setLeft(Delete(cur->getLeft(),find));
	else if(strcmp(cur->getName(),find->getName())<0)
		cur->setRight(Delete(cur->getRight(),find));
	else{
		if(!cur->getLeft()){
			NameBSTNode* tmp = cur->getRight();
			delete cur;
			return tmp;
		}
		else if(!cur->getRight()){
			NameBSTNode* tmp = cur->getLeft();
			delete cur;
			return tmp;
		}

		NameBSTNode* tmp = Find_Min_Node(cur->getRight());
		cur->setInfo(tmp);
		cur->setRight(Delete(cur->getRight(),tmp));
	}
	return cur;
}

NameBSTNode* NameBST::Find_Min_Node(NameBSTNode* cur){
	NameBSTNode* ptr = cur;
	while(ptr->getLeft()){
		ptr = ptr->getLeft();
	}
	return ptr;
}

NameBSTNode* NameBST::Search(NameBSTNode* find){
	NameBSTNode* cur = root;
	while(cur){
		if(strcmp(cur->getName(),find->getName())>0)
			cur = cur->getLeft();
		else if(strcmp(cur->getName(),find->getName())<0)
			cur = cur->getRight();
		else break;
	}
	return cur;
}

// insert

// search

// print

// delete