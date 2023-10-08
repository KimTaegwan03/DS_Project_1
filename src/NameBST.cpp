#include "NameBST.h"
using namespace std;

NameBST::NameBST() : root(nullptr)
{

}
NameBST::~NameBST()
{
	// Delete all node
	while(root){
		Delete(root);
	}
}

NameBSTNode* NameBST::getRoot()
{
	return root;
}

void NameBST::Insert(NameBSTNode* param){		// Find correct position, and insert new node
	NameBSTNode* cur = root;

	if (!root) {
		root = param;
		return;
	}
	while(cur){
		if(strcmp(cur->getName(),param->getName())>0){	//smaller than cur, go left
			if(!cur->getLeft()){
				cur->setLeft(param);
				return;
			}
			else{
				cur = cur->getLeft();
			}
		}
		else if(strcmp(cur->getName(),param->getName())<=0){	//bigger than cur, go right
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

// Print function, Print node info
void NameBST::Print(ofstream& flog, NameBSTNode* node){
	if(node){
		Print(flog,node->getLeft());
		flog << node->getName()<<'/'<<node->getAge()<<'/'<<node->getYear()<<'-'<<node->getMonth()<<'-'<<node->getDay()<<'/'<<node->getEndYear()<<'-'<<node->getEndMonth()<<'-'<<node->getEndDay()<<endl;
		Print(flog,node->getRight());
	}
}

// Delete function, Find node and delete the node
void NameBST::Delete(NameBSTNode* find){
	NameBSTNode* cur = root;
	NameBSTNode* pre = nullptr;

	// Find node
	while (cur) {
		if (strcmp(cur->getName(), find->getName()) > 0) {		// smaller than cur, go left
			pre = cur;
			cur = cur->getLeft();
		}
		else if (strcmp(cur->getName(), find->getName()) < 0) {	// bigger than cur, go right
			pre = cur;
			cur = cur->getRight();
		}
		else break;
	}

	if (!cur) return ;

	// Delete node
	if (!cur->getLeft() && !cur->getRight()) {		// leaf case
		if (!pre) {
			delete root;
			root = 0;
			return;
		}
		else if (pre->getLeft() == cur) pre->setLeft(nullptr);
		else pre->setRight(nullptr);
		delete cur;
		return ;
	}
	else if (!cur->getLeft()) {		// exist only right node case
		if (!pre) root = cur->getRight();
		else if (pre->getLeft() == cur) pre->setLeft(cur->getRight());
		else pre->setRight(cur->getRight());
		delete cur;
		return ;
	}
	else if (!cur->getRight()) {	// exist only left node case
		if (!pre) root = cur->getLeft();
		else if (pre->getLeft() == cur) pre->setLeft(cur->getLeft());
		else pre->setRight(cur->getLeft());
		delete cur;
		return ;
	}
	else {		// exist both node case
		NameBSTNode* p2 = cur, * p1 = cur->getRight(), * p0 = cur->getRight()->getLeft();

		while (p0) {
			p2 = p1;
			p1 = p0;
			p0 = p0->getLeft();
		}

		cur->setInfo(p1);
		if (p2 == cur) 
			p2->setRight(p1->getRight());
		else 
			p2->setLeft(p1->getRight());
		delete p1;
	}
}

// Search function, Find node and return the node
NameBSTNode* NameBST::Search(NameBSTNode* find){
	NameBSTNode* cur = root;
	while(cur){
		if(strcmp(cur->getName(),find->getName())<0)
			cur = cur->getLeft();
		else if(strcmp(cur->getName(),find->getName())>0)
			cur = cur->getRight();
		else break;
	}
	return cur;
}