#pragma once
#include <iostream>
#include <cstring>

class TermsBSTNode
{
private:
	char name[21];
	int age;
	int year;
	int month;
	int day;
	int end_year, end_month, end_day;
	char term;
	TermsBSTNode*	left;
	TermsBSTNode*	right;


public:
	TermsBSTNode() {}
	~TermsBSTNode() {}

	TermsBSTNode*	getLeft()			{ return left; }
	TermsBSTNode*	getRight()			{ return right; }
	
	char* getName(){return name;};
	int getAge(){return age;}
	int getYear(){return year;}
	int getMonth(){return month;}
	int getDay(){return day;}
	int getEndYear(){return end_year;}
	int getEndMonth(){return end_month;}
	int getEndDay(){return end_day;}
	char getTerm(){return term;}


	void setInfo(TermsBSTNode* param){
		strcpy(name,param->getName());
		age = param->getAge();
		year = param->getYear();
		month = param->getMonth();
		day = param->getDay();
		end_year = param->getEndYear();
		end_month = param->getEndMonth();
		end_day = param->getEndDay();
		term = param->getTerm();
	}
	void setLeft (TermsBSTNode* left)	{ this->left = left; }
	void setRight(TermsBSTNode* right)	{ this->right = right; }
};