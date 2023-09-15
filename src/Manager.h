#pragma once
#include "MemberQueue.h"
#include "TermsList.h"
#include "TermsBST.h"
#include "NameBST.h"
#include <fstream>
#include <cstring>
using namespace std;

class Manager
{
private:

	ifstream	fcmd;
	ofstream	flog;

	MemberQueue* memq;
	TermsLIST* termlis;
	NameBST* nameBST;


public:
	Manager();
	~Manager();

	void run(const char* command);
	
	void PrintSuccess(const char* cmd);
	void PrintErrorCode(int num);

	void LOAD();
	// LOAD
	// ADD
	// QPOP
	// SEARCH
	// PRINT
	// DELETE
};
