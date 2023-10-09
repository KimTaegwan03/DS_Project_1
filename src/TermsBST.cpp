#include "TermsBST.h"
using namespace std;

TermsBST::TermsBST() : root(nullptr)
{

}
TermsBST::~TermsBST()
{
	// Delete all node
	while(root){
		Delete(root);
	}
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

void TermsBST::Insert(TermsBSTNode* param){		// Insert parameter node to correct position
	TermsBSTNode* cur = root;

	if (!root) {
		root = param;
		return;
	}

	while(cur){
		if(compare_end_term(cur,param)>0){		// faster than cur node, go left
			if(!cur->getLeft()){
				cur->setLeft(param);
				break;
			}
			else{
				cur = cur->getLeft();
			}
		}
		else if(compare_end_term(cur,param)<=0){	// later than cur node, go right
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

// Print node info
void TermsBST::Print(ofstream& flog, TermsBSTNode* node){
	if(node){
		Print(flog,node->getLeft());
		flog << node->getName()<<'/'<<node->getAge()<<'/'<<node->getYear()<<'-'<<node->getMonth()<<'-'<<node->getDay()<<'/'<<node->getEndYear()<<'-'<<node->getEndMonth()<<'-'<<node->getEndDay()<<endl;
		Print(flog,node->getRight());
	}
}

// Delete function
void TermsBST::Delete(TermsBSTNode* find){
	TermsBSTNode* cur = root;
	TermsBSTNode* pre = nullptr;

	while (cur) {
		if (compare_end_term(cur, find) > 0) {	// faster than cur, go left
			pre = cur;
			cur = cur->getLeft();
		}
		else if (compare_end_term(cur, find) < 0) {	// later than cur, go right
			pre = cur;
			cur = cur->getRight();
		}
		else if (strcmp(cur->getName(),find->getName())==0) break;
		else{
			pre = cur;
			cur = cur->getRight();
		}
	}

	if (!cur) return;

	if (!cur->getLeft()&&!cur->getRight()) {	// leaf case
		if (!pre) {
			delete root;
			root = 0;
			return;
		}
		else if (pre->getLeft() == cur) pre->setLeft(nullptr);
		else pre->setRight(nullptr);
		delete cur;
		return;
	}
	else if (!cur->getLeft()) {		// exist only left node
		if (!pre) root = cur->getRight();
		else if (pre->getLeft() == cur) pre->setLeft(cur->getRight());
		else pre->setRight(cur->getRight());
		delete cur;
		return;
	}
	else if (!cur->getRight()) {	// exist only right node
		if (!pre) root = cur->getLeft();
		else if (pre->getLeft() == cur) pre->setLeft(cur->getLeft());
		else pre->setRight(cur->getLeft());
		delete cur;
		return;
	}
	else {	// exist both node
		TermsBSTNode* p2 = cur, * p1 = cur->getRight(), * p0 = cur->getRight()->getLeft();

		while (p0) {
			p2 = p1;
			p1 = p0;
			p0 = p0->getLeft();
		}

		cur->setInfo(p1);
		if (p2 == cur) p2->setRight(p1->getRight());
		else p2->setLeft(p1->getRight());
		delete p1;
		return;
	}
}

TermsBSTNode* TermsBST::Search(TermsBSTNode* find){
	TermsBSTNode* cur = root;
	while(cur){
		if(compare_end_term(cur,find)>0)
			cur = cur->getLeft();
		else if(compare_end_term(cur,find)<0)
			cur = cur->getRight();
		else if (strcmp(cur->getName(),find->getName())==0) break;
		else cur = cur->getRight();
	}
	return cur;

}


TermsBSTNode* TermsBST::SearchLesser(TermsBSTNode* find) {
	TermsBSTNode* cur = root;
	while (cur) {
		if (compare_end_term(cur, find) >= 0)
			cur = cur->getLeft();
		else if (compare_end_term(cur, find) < 0)
			break;
	}
	return cur;
}