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

void Manager::run(const char* command)
{
     // Open command & log file
    fcmd.open(command);
    flog.open("log.txt");
    if (!fcmd)
    {
        flog << "Fail to open command file" << endl;
        exit(-2);
    }
    
    char cmd[64];
    while(!fcmd.eof()){
        //fcmd >> cmd;
        char* p = 0;

        fcmd.getline(cmd, 64);

        if (!strcmp(cmd, "")) break;

        p = strtok(cmd, " ");

        if(!strcmp(p,"LOAD")){
            if(!memq){
                memq = new MemberQueue;
                LOAD();
            }
            else{
                PrintErrorCode(100);
            }
        }
        else if(!strcmp(p,"ADD")){
            p = strtok(NULL, "");
            ADD(p);

        }
        else if(!strcmp(p,"QPOP")){
            QPOP();
        }
        else if(!strcmp(p ,"SEARCH")){
            p = strtok(NULL, "");
            SEARCH(p);
        }
        else if(!strcmp(p,"PRINT")){
            p = strtok(NULL, "");
            PRINT(p);
        }
        else if(!strcmp(p,"DELETE")){
            p = strtok(NULL,"");
            DELETE(p);
        }
        else if(!strcmp(p,"EXIT")){
            if(memq) delete memq;
            if(nameBST) delete nameBST;
            if(termlis) delete termlis;
            fcmd.close();
            flog.close();
            return;
        }
        else {
            PrintErrorCode(1000);
        }
    }
    // Run command


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

void Manager::LOAD()
{
    ifstream fdata;
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

    while(!fdata.eof()){
        char* p = nullptr;

        fdata.getline(info,100);

        if (!strcmp(info, "")) break;

        p = strtok(info, " ");
        strcpy(name, p);

        //  2004-06-05
        p = strtok(NULL, " ");
        age = atoi(p);

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

        p = strtok(NULL, " ");
        term = p[0];

        if (!memq->full()) {
            memq->push(name, age, year, month, day, term);
            flog<<name<<'/'<<age<<'/'<<year_c<<'-'<<month_c<<'-'<<day_c<<'/'<<term<<endl;
        }

        // fdata.getline(data_tmp,100);
        // strtok(p," ");
        // name = p;
        // strtok(NULL," ");

    }
    flog<<"==============="<<endl<<endl;
    fdata.close();
}
// LOAD
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

    p = strtok(info, " ");
    strcpy(name, p);

    //  2004-06-05
    p = strtok(NULL, " ");
    age = atoi(p);

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

    p = strtok(NULL, " ");
    term = p[0];

    if (!memq->full()){
        memq->push(name, age, year, month, day, term);
        flog<<"===== ADD ====="<<endl;
        flog<<name<<'/'<<age<<'/'<<year_c<<'-'<<month_c<<'-'<<day_c<<'/'<<term<<endl;
        flog<<"==============="<<endl<<endl;
    }

}
// ADD

void Manager::QPOP() {
    if (memq) {
        while (!memq->empty()) {
            if (!termlis)
                termlis = new TermsLIST;

            termlis->Insert(memq->front().getName(), memq->front().getAge(), memq->front().getYear(), memq->front().getMonth(), memq->front().getDay(), memq->front().getTerm());
            
            NameBSTNode* nameNode = new NameBSTNode(memq->front().getName(), memq->front().getAge(), memq->front().getYear(), memq->front().getMonth(), memq->front().getDay(), memq->front().getTerm());
            
            if (!nameBST)
                nameBST = new NameBST;
            
            nameBST->Insert(nameNode);
            memq->pop();
        }
        PrintSuccess("QPOP");
    }
}
// QPOP

void Manager::SEARCH(char* find) {
    NameBSTNode* find_node = new NameBSTNode(find);
    NameBSTNode* search_node = nameBST->Search(find_node);
    if (search_node) {
        flog << "===== SEARCH =====\n";
        flog << search_node->getName() << '/' << search_node->getAge() << '/' << search_node->getYear()<<'-'<< search_node->getMonth()<<'-'<< search_node->getDay()<<'/' << search_node->getEndYear() << '-' << search_node->getEndMonth() << '-' << search_node->getEndDay()<<endl;
        flog << "===============\n\n";
    }
    delete find_node;
}
// SEARCH

void Manager::PRINT(char* p){
    if(!strcmp(p,"A")||!strcmp(p,"B")||!strcmp(p,"C")||!strcmp(p,"D")){
        if(termlis){
            TermsListNode* cur = termlis->getHead();
            
            while(cur){
                if(p[0] == cur->getTerm()) break;
                else cur = cur->getNext();
            }

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
    else if(!strcmp(p,"NAME")){
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
// PRINT
void Manager::DELETE(char* param){
    char* p = param;
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
        
        TermsBSTNode* search_node = termlis->Search(year,month,day);
        if(search_node){
            char delete_name[21];
            strcpy(delete_name,search_node->getName());
            termlis->Delete(year,month,day,search_node->getTerm());
            NameBSTNode* find = new NameBSTNode(delete_name);
            nameBST->Delete(nameBST->getRoot(),find);
            delete find;
        }
        else{
            PrintErrorCode(600);
        }
    }
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
            nameBST->Delete(nameBST->getRoot(),ptr);
            termlis->Delete(year,month,day,term);
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