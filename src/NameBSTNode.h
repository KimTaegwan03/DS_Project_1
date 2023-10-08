#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class NameBSTNode
{
private:
	char name[21];
	int age;
	int year;
	int month;
	int day;
	int end_year, end_month, end_day;
	char term;
	NameBSTNode*	left;
	NameBSTNode*	right;
	

public:
	NameBSTNode(char* p_name, int p_age, int p_year,
		int p_month, int p_day, char p_term) {
		strcpy(name,p_name);
		age = p_age;
		year = p_year;
		month = p_month;
		day = p_day;
		end_year = p_year;
		end_month = p_month;
		end_day = p_day;
		term = p_term;

		// Calculate end date
		if (p_term == 'A') {
			end_month += 6;
			if (end_month > 12) {
				end_year++;
				end_month -= 12;
			}
		}
		else if (p_term == 'B') {
			end_year++;
		}
		else if (p_term == 'C') {
			end_year+=2;
		}
		else if (p_term == 'D') {
			end_year+=3;
		}
		left = nullptr;
		right = nullptr;
	}
	NameBSTNode(char* p_name){
		strcpy(name,p_name);
		left = nullptr;
		right = nullptr;
	}
	~NameBSTNode() {}

	NameBSTNode*	getLeft()			{ return left; }
	NameBSTNode*	getRight()			{ return right; }

	char* getName(){return name;};
	int getAge(){return age;}
	int getYear(){return year;}
	int getMonth(){return month;}
	int getDay(){return day;}
	int getEndYear(){return end_year;}
	int getEndMonth(){return end_month;}
	int getEndDay(){return end_day;}
	char getTerm(){return term;}

	void setInfo(NameBSTNode* param){
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

	void setLeft(NameBSTNode* left)		{ this->left = left; }
	void setRight(NameBSTNode* right)	{ this->right = right; }
};