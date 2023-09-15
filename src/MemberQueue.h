#pragma once
#include "MemberQueueNode.h"

class MemberQueue
{
private:
	MemberQueueNode *head, *tail;
	int cur;

public:
	MemberQueue();
	~MemberQueue();

	bool empty();
	bool full();
	void push(MemberQueueNode* p_node);
	MemberQueueNode* pop();
	MemberQueueNode* front();
};

