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
        if(last == 0) return 1;
        else return 0;
    }
    else return 0;
}

bool MemberQueue::full()
{
    if(head_idx == tail_idx) {
        if(last == 1) return 1;
        else return 0;
    }
    else return 0;
}

void MemberQueue::push(char* p_name,int p_age,int p_year,
	int p_month,int p_day,char p_term)
{
	if(!this->full()){
        tail_idx = (tail_idx+1)%100;
        Queue[tail_idx].setInfo(p_name,p_age,p_year,p_month,p_day,p_term);
        last = 1;
    }
}

MemberQueueNode MemberQueue::pop()
{
    if(!this->empty()){
        head_idx = (head_idx+1)%100;
        return Queue[head_idx];
        last = 0;
    }
}

MemberQueueNode MemberQueue::front()
{
    if(!empty())
        return Queue[head_idx];
}