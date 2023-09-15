#pragma once

class MemberQueueNode
{
private:
	char name[21];
	int age;
	int year;
	int month;
	int day;
	char term;
	MemberQueueNode* next;

public:
	MemberQueueNode(char* p_name,int p_age,int p_year,
	int p_month,int p_day,char p_term) {
		memcpy(name,p_name,21);
		age = p_age;
		year = p_year;
		month = p_month;
		day = p_day;
		term = p_term;
		next = nullptr;
	}
	~MemberQueueNode() {}

	void setNext(MemberQueueNode* param){
		next = param;
	}

	MemberQueueNode* getNext() const {
		return next;
	}
};