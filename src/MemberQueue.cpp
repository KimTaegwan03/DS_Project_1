#include "MemberQueue.h"

MemberQueue::MemberQueue()
{
    head_idx = -1;
    tail_idx = -1;
    last = 0;
}

MemberQueue::~MemberQueue()
{

}

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

bool MemberQueue::full()
{
    if(head_idx == tail_idx) {
        if(last == 1) return true;
        else return false;
    }
    else return false;
}

void MemberQueue::push(char* p_name,int p_age,int p_year,
	int p_month,int p_day,char p_term)
{
	if(!this->full()){
        tail_idx = (tail_idx+1)%100;
        last = 1;
        Queue[tail_idx].setInfo(p_name,p_age,p_year,p_month,p_day,p_term);
    }
}

MemberQueueNode MemberQueue::pop()
{
    if(!this->empty()){
        head_idx = (head_idx+1)%100;
        last = 0;
        return Queue[head_idx];
    }
}

MemberQueueNode MemberQueue::front()
{
    if(!empty())
        return Queue[(head_idx+1)%100];
}