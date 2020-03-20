// Ngram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ngram.h"



int _tmain(int zargc, _TCHAR* argv[]){


	
	readInput("input.txt");
	
	removePunctucationMarks();
	
	removeSpacing();
	
	

	
	insertDots();
	
	
	cout<<"UNIGRAMS:"<<endl;
	generateUnigrams();
	cout<<"BIGRAMS:"<<endl;
	generateBigrams();
	cout<<"TRIGRAMS:"<<endl;
	generateTrigrams();
	
	cout<<endl<<endl;
	return 0;
	
}

