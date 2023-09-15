#pragma once
#include "MemberQueueNode.h"

class MemberQueue
{
private:
	MemberQueueNode Queue[100];
	int head_idx,tail_idx;
	bool last; //0 = pop, 1 = push

public:
	MemberQueue();
	~MemberQueue();

	bool empty();
	bool full();
	void push(char* p_name,int p_age,int p_year,
	int p_month,int p_day,char p_term);
	MemberQueueNode pop();
	MemberQueueNode front();
};

