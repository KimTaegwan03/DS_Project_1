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
        exit(-1);
    }
    
    char cmd[64];
    while(!fcmd.eof()){
        fcmd >> cmd;
        if(!strcmp(cmd,"LOAD")){
            if(!memq){
                memq = new MemberQueue;
                LOAD();
            }
            else{
                PrintErrorCode(100);
            }
        }
        else if(!strcmp(cmd,"ADD")){
            char name[21];
            char date[11];
            int age;
            int year,month,day;
            char term;

            fcmd >> name >> age >> date >> term;

            char* p = strtok(date,"-");
            if(p)
                year = atoi(p);
            else PrintErrorCode(200);
            strtok(NULL,"-");
            if(p)
                month = atoi(p);
            else PrintErrorCode(200);
            strtok(NULL,"-");
            if(p)
                day = atoi(p);
            else PrintErrorCode(200);

            if(!memq->full())
                memq->push(name,age,year,month,day,term);

        }
        else if(!strcmp(cmd,"QPOP")){
            
        }
        else if(cmd == "SEARCH"){

        }
        else if(cmd == "PRINT"){

        }
        else if(cmd == "DELETE"){

        }
        else if(cmd == "EXIT"){

        }
        else {
            this->PrintErrorCode(1000);
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

    char data_tmp[100];
    char name[21];
    char date[11];
    int age;
    int year,month,day;
    char term;

    while(!fdata.eof()){
        fdata >> name >> age >> date >> term;
        char* p = strtok(date,"-");
        if(p)
            year = atoi(p);
        else PrintErrorCode(200);
        strtok(NULL,"-");
        if(p)
            month = atoi(p);
        else PrintErrorCode(200);
        strtok(NULL,"-");
        if(p)
            day = atoi(p);
        else PrintErrorCode(200);
        if(!memq->full())
            memq->push(name,age,year,month,day,term);

        // fdata.getline(data_tmp,100);
        // strtok(p," ");
        // name = p;
        // strtok(NULL," ");

    }
}
// LOAD

// ADD

// QPOP

// SEARCH

// PRINT

// DELETE