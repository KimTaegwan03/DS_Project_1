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
	TermsBSTNode(char* p_name, int p_age, int p_year,
		int p_month, int p_day, char p_term) {
		strcpy(name, p_name);
		age = p_age;
		year = p_year;
		month = p_month;
		day = p_day;
		end_year = p_year;
		end_month = p_month;
		end_day = p_day;
		term = p_term;

		left = nullptr;
		right = nullptr;
		
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
	}
	TermsBSTNode(int p_year, int p_month, int p_day) {
		end_year = p_year;
		end_month = p_month;
		end_day = p_day;
	}
	~TermsBSTNode() {
	}

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