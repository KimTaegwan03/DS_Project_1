#include "MemberQueue.h"

MemberQueue::MemberQueue()
{
    head_idx = 0;
    tail_idx = 0;
    last = 0;
}

MemberQueue::~MemberQueue()
{   

}

// empty function, if queue is empty return true
bool MemberQueue::empty()
{
    if(head_idx == tail_idx) {
        if(last == 0) 
            return true;
        else 
            return false;
    }
    else 
        return false;
}

// full function, if queue is full return true
bool MemberQueue::full()
{
    if(head_idx == tail_idx) {
        if(last == 1) return true;
        else return false;
    }
    else return false;
}

// push function
void MemberQueue::push(char* p_name,int p_age,int p_year,
	int p_month,int p_day,char p_term)
{
	if(!this->full()){
        last = 1;
        Queue[tail_idx].setInfo(p_name,p_age,p_year,p_month,p_day,p_term);
        tail_idx = (tail_idx+1)%100;
    }
}

// pop function
MemberQueueNode MemberQueue::pop()
{
    if(!this->empty()){
        MemberQueueNode* out = &Queue[head_idx];
        head_idx = (head_idx+1)%100;
        last = 0;
        return *out;
    }
}

// front function, return front member node
MemberQueueNode MemberQueue::front()
{
    if(!empty())
        return Queue[(head_idx+1)%100];
}