#define _CRT_SECURE_NO_WARNINGS
#include "Manager.h"

Manager::Manager()
{
    memq = nullptr;
    termlis = nullptr;
    nameBST = nullptr;
}


Manager::~Manager()
{
    if(memq) delete memq;
    if(termlis) delete termlis;
    if(nameBST) delete nameBST;
}

//run
void Manager::run(const char* command)
{
     // Open command & log file
    fcmd.open(command);
    flog.open("log.txt");
    if (!fcmd)
    {
        flog << "Fail to open command file" << endl;
        exit(-1);
    }
    
    char cmd[64];
    while(!fcmd.eof()){
        char* p = 0;
        
        // Read command
        fcmd.getline(cmd, 64);


        if (!strcmp(cmd, "")) break;

        p = strtok(cmd, " ");

        // LOAD command
        if(!strcmp(p,"LOAD")){

            // No Member Queue, Allocate Member Queue and LOAD
            if(!memq){
                memq = new MemberQueue;
                LOAD();
            }
            else{
                PrintErrorCode(100);
            }
        }
        // ADD command
        else if(!strcmp(p,"ADD")){
            p = strtok(NULL, "");

            // No Member Queue, Allocate Member Queue and ADD
            if(!memq){
                memq = new MemberQueue;
                ADD(p);
            }
            else{
                ADD(p);
            }

        }
        // QPOP command
        else if(!strcmp(p,"QPOP")){
            if(memq)
                QPOP();
            else
                PrintErrorCode(300);
        }
        //SEARCH command
        else if(!strcmp(p ,"SEARCH")){
            p = strtok(NULL, "");
            if(nameBST||termlis)
                SEARCH(p);
            else
                PrintErrorCode(400);
        }
        // PRINT command
        else if(!strcmp(p,"PRINT")){
            p = strtok(NULL, "");
            if(nameBST||termlis)
                PRINT(p);
            else   
                PrintErrorCode(500);
        }
        // DELETE command
        else if(!strcmp(p,"DELETE")){
            p = strtok(NULL,"");
            if(nameBST||termlis)
                DELETE(p);
            else
                PrintErrorCode(600);
        }
        // EXIT command
        else if(!strcmp(p,"EXIT")){
            if(memq) delete memq;
            if(nameBST) delete nameBST;
            if(termlis) delete termlis;
            memq = 0;
            nameBST = 0;
            termlis = 0;
            PrintSuccess("EXIT");
            fcmd.close();
            flog.close();
            return;
        }
        else {
            PrintErrorCode(1000);
        }
    }

    // Close file
    fcmd.close();
    flog.close();
    return;
}

void Manager::PrintSuccess(const char* cmd)
{
    flog << "===== " << cmd << " =====" << endl;
    flog << "Success" << endl;
    flog << "===============" << endl << endl;
}
void Manager::PrintErrorCode(int num)
{
    flog << "===== ERROR =====" << endl;
    flog << num << endl;
    flog << "===============" << endl << endl;
}

// LOAD function
void Manager::LOAD()
{
    ifstream fdata;

    // Open data.txt file
    fdata.open("data.txt");
    if(!fdata){
        PrintErrorCode(100);
        exit(-1);
    }

    char info[100];
    char name[21];
    char year_c[5];
    char month_c[3];
    char day_c[3];
    int age = 0;
    int year = 0,month = 0,day = 0;
    char term;

    flog<<"===== LOAD ====="<<endl;

    // Read data.txt
    while(!fdata.eof()){
        char* p = nullptr;

        fdata.getline(info,100);

        if (!strcmp(info, "")) break;

        // Get name
        p = strtok(info, " ");
        strcpy(name, p);

        // Get age
        p = strtok(NULL, " ");
        age = atoi(p);

        // Get date
        p = strtok(NULL, " ");
        for (int i = 0; i < 4; i++) {
            year_c[i] = p[i];
        }
        year_c[4] = '\0';

        month_c[0] = p[5];
        month_c[1] = p[6];
        month_c[2] = '\0';

        day_c[0] = p[8];
        day_c[1] = p[9];
        day_c[2] = '\0';

        year = atoi(year_c);
        month = atoi(month_c);
        day = atoi(day_c);

        // Get term
        p = strtok(NULL, " ");
        term = p[0];

        // Push
        if (!memq->full()) {
            memq->push(name, age, year, month, day, term);
            flog<<name<<'/'<<age<<'/'<<year_c<<'-'<<month_c<<'-'<<day_c<<'/'<<term<<endl;
        }
    }
    flog<<"==============="<<endl<<endl;
    fdata.close();
}

// ADD function
void Manager::ADD(char* info) {
    char name[21];
    int age = 0;
    char year_c[5];
    int year = 0;
    char month_c[3];
    int month = 0;
    char day_c[3];
    int day = 0;
    char term = 0;
    char* p = nullptr;

    // Detect Parameter Error
    int len = strlen(info);
    int blank = 0;
    for(int i = 0;i<len;i++){
        if(info[i] == ' ')
            blank++;
    }
    if(blank!=3){
        PrintErrorCode(200);
        return;
    }
    
    // Get name
    p = strtok(info, " ");
    strcpy(name, p);

    // Get age
    p = strtok(NULL, " ");
    age = atoi(p);

    // Get date
    p = strtok(NULL, " ");
    for (int i = 0; i < 4; i++) {
        year_c[i] = p[i];
    }
    year_c[4] = '\0';
    
    month_c[0] = p[5];
    month_c[1] = p[6];
    month_c[2] = '\0';

    day_c[0] = p[8];
    day_c[1] = p[9];
    day_c[2] = '\0';

    year = atoi(year_c);
    month = atoi(month_c);
    day = atoi(day_c);

    // Get term
    p = strtok(NULL, " ");
    term = p[0];

    // Push
    if (!memq->full()){
        memq->push(name, age, year, month, day, term);
        flog<<"===== ADD ====="<<endl;
        flog<<name<<'/'<<age<<'/'<<year_c<<'-'<<month_c<<'-'<<day_c<<'/'<<term<<endl;
        flog<<"==============="<<endl<<endl;
    }
}

// QPOP function
void Manager::QPOP() {

    // Work when memq exist
    if (memq) {
        while (!memq->empty()) {
            // No TermsList, Allocate new one
            if (!termlis){
                termlis = new TermsLIST;
            }

            // Insert front member of member queue to TermsList
            termlis->Insert(memq->front().getName(), memq->front().getAge(), memq->front().getYear(), memq->front().getMonth(), memq->front().getDay(), memq->front().getTerm());
            
            // Allocate NameBSTNode with front member of member queue
            NameBSTNode* nameNode = new NameBSTNode(memq->front().getName(), memq->front().getAge(), memq->front().getYear(), memq->front().getMonth(), memq->front().getDay(), memq->front().getTerm());
            
            // No NameBST, Allocate new one
            if (!nameBST)
                nameBST = new NameBST;
            
            // Insert the NameNode to NameBST
            nameBST->Insert(nameNode);

            // POP member queue
            memq->pop();
        }
        PrintSuccess("QPOP");
    }
}

// SEARCH function
void Manager::SEARCH(char* find) {
    // Allocate node for finding
    NameBSTNode* find_node = new NameBSTNode(find);

    // Get node from Search function of NameBST
    NameBSTNode* search_node = nameBST->Search(find_node);

    // If the node exist Print node info
    if (search_node) {
        flog << "===== SEARCH =====\n";
        flog << search_node->getName() << '/' << search_node->getAge() << '/' << search_node->getYear()<<'-'<< search_node->getMonth()<<'-'<< search_node->getDay()<<'/' << search_node->getEndYear() << '-' << search_node->getEndMonth() << '-' << search_node->getEndDay()<<endl;
        flog << "===============\n\n";
    }
    delete find_node;
}

// PRINT function
void Manager::PRINT(char* p){

    // Term print
    if(!strcmp(p,"A")||!strcmp(p,"B")||!strcmp(p,"C")||!strcmp(p,"D")){
        if(termlis){
            TermsListNode* cur = termlis->getHead();
            
            // Find same term node
            while(cur){
                if(p[0] == cur->getTerm()) break;
                else cur = cur->getNext();
            }
            
            // Print all node info of termBST
            if(cur){
                flog<<"===== PRINT ====="<<endl;
                flog<<"Terms_BST "<<p[0]<<endl;
                cur->getBST()->Print(flog,cur->getBST()->getRoot());
                flog<<"==============="<<endl<<endl;
            }
            else{
                PrintErrorCode(500);
            }
        }
        else{
            PrintErrorCode(500);
        }
    }
    // Name print
    else if(!strcmp(p,"NAME")){

        // Print all node info of NameBST
        if(nameBST){
            flog<<"===== PRINT ====="<<endl;
            flog<<"Name_BST "<<endl;
            nameBST->Print(flog,nameBST->getRoot());
            flog<<"==============="<<endl<<endl;
        }
        else{
            PrintErrorCode(500);
        }
    }
    else{
        PrintErrorCode(500);
    }
}

// DELETE function
void Manager::DELETE(char* param){
    char* p;
    p = strtok(param, " ");

    // Date Delete
    if(!strcmp(p,"DATE")){
        char year_c[5];
        char month_c[3];
        char day_c[3];
        int year,month,day;

        p = strtok(NULL," ");

        for (int i = 0; i < 4; i++) {
            year_c[i] = p[i];
        }
        year_c[4] = '\0';
        
        month_c[0] = p[5];
        month_c[1] = p[6];
        month_c[2] = '\0';

        day_c[0] = p[8];
        day_c[1] = p[9];
        day_c[2] = '\0';

        year = atoi(year_c);
        month = atoi(month_c);
        day = atoi(day_c);
        
        // Search node lesser than parameter date
        TermsBSTNode* search_node = termlis->SearchLesser(year, month, day);
        if (!search_node) {
            PrintErrorCode(600);
            return;
        }

        // Delete all lesser node
        while (search_node) {
            char delete_name[21];
            int s_year = search_node->getEndYear();
            int s_month = search_node->getEndMonth();
            int s_day = search_node->getEndDay();
            strcpy(delete_name, search_node->getName());
            termlis->Delete(delete_name, s_year, s_month, s_day, search_node->getTerm());
            NameBSTNode* find = new NameBSTNode(delete_name);
            nameBST->Delete(find);
            delete find;
            search_node = termlis->SearchLesser(year, month, day);
        }
        PrintSuccess("DELETE");
    }

    // Name Delete, Search node and delete the node
    else if(!strcmp(p,"NAME")){
        p = strtok(NULL," ");
        NameBSTNode* ptr = new NameBSTNode(p);
        NameBSTNode* search_node = nameBST->Search(ptr);
        if(search_node){
            char term;
            int year,month,day;
            term = search_node->getTerm();
            year = search_node->getEndYear();
            month = search_node->getEndMonth();
            day = search_node->getEndDay();
            nameBST->Delete(ptr);
            termlis->Delete(p,year,month,day,term);
            PrintSuccess("DELETE");
        }
        else{
            PrintErrorCode(600);
        }
        delete ptr;
    }
    else{
        PrintErrorCode(600);
    }
}
// DELETE