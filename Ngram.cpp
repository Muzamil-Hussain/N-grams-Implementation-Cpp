// Ngram.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Ngram.h"


int _tmain(int argc, _TCHAR* argv[])
{
	readInput("input.txt");
	//display();
	//cout<<endl;
	removePunctucationMarks();
	//display();
	//cout<<endl;
	removeSpacing();
	//display();
	//cout<<endl;
	insertDots();
	//display();
	//cout<<endl;
	cout<<getText()<<endl;
	generateUnigrams();
	generateBigrams();
    generateTrigrams();

	cout<<validateSentance("Sam I am")<<endl;
	//sentenceCreation(11);

	return 0;
}

