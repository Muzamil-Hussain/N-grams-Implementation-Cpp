#include<iostream>
#include<fstream>
#include<string>
using namespace std;

char * text;
char ** Ngram;
int * NgramCount;
int NumOfWords;
int NumOfNgrams;
int endOfNgrams;
int sizeOfText;
int* startingPoints;
int* indecesOfDotsForInserting;
int incReqInsertDot=0;

	textFile.open(Path);
	getline(textFile,fileContainer,'\0');