#include "Manager.h"

Manager::Manager()
{
    memq = nullptr;
    termlis = nullptr;
    termBST = nullptr;
    nameBST = nullptr;
}
Manager::~Manager()
{
    if(memq) delete memq;
    if(termlis) delete termlis;
    if(termBST) delete termBST;
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
    
    string cmd;
    while(!fcmd.eof()){
        getline(fcmd,cmd);
        if(cmd == "LOAD"){
            if(!memq){
                memq = new MemberQueue;
                LOAD();
            }
            else{
                PrintErrorCode(100);
            }
        }
        else if(cmd == "ADD"){

        }
        else if(cmd == "QPOP"){

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

    char name[21];
    int age;
    char date[11];
    char term;

    while(!fdata.eof()){
        fdata >> name >> age >> date >> term;
        //if( )
    }
}
// LOAD

// ADD

// QPOP

// SEARCH

// PRINT

// DELETE