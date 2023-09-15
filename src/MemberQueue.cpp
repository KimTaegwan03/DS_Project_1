#include "MemberQueue.h"

MemberQueue::MemberQueue()
{
    head = nullptr;
    tail = nullptr;
    cur = 0;
}

MemberQueue::~MemberQueue()
{
	MemberQueueNode* del;
    while(head){
        del = head->getNext();
        delete head;
        head = del;
    }
}

bool MemberQueue::empty()
{
    if(cur == 0) return 1;
    else return 0;
}

bool MemberQueue::full()
{
    if(cur == 100) return 1;
    else return 0;
}

void MemberQueue::push(MemberQueueNode* p_node)
{
	if(!this->full()){
        cur++;
        tail->setNext(p_node);
        tail = p_node;
    }
}

MemberQueueNode* MemberQueue::pop()
{
    if(!this->empty()){
        MemberQueueNode* out = head;
        head = head->getNext();
        cur--;
        return out;
    }
}

MemberQueueNode* MemberQueue::front()
{
    return head;
}