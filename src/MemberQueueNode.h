#pragma once
#include <iostream>
#include <cstring>

class MemberQueueNode
{
private:
	char name[21];
	int age;
	int year;
	int month;
	int day;
	char term;

public:
	MemberQueueNode() {
	}
	~MemberQueueNode() {}

	char* getName() {return name;};
	int getAge() {return age;}
	int getYear() {return year;}
	int getMonth() {return month;}
	int getDay() {return day;}
	char getTerm() {return term;}

	void setInfo(char* p_name,int p_age,int p_year,
	int p_month,int p_day,char p_term){
		strcpy(name,p_name);
		age = p_age;
		year = p_year;
		month = p_month;
		day = p_day;
		term = p_term;
	}
};