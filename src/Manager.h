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
	void ADD(char* info);
	// ADD

	void QPOP();
	// QPOP
	void SEARCH(char* find);
	// SEARCH

	void PRINT(char* p);
	// PRINT

	void DELETE(char* param);
	// DELETE
};
