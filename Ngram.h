#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;
char *arr;
int size=0;
void readInput(const char* Path){
	ifstream in(Path);
	string line;
	if (in.is_open()){	
			line="";
			getline(in,line,'\0');
			for (int i=0;i<line.length();i++){
				size++;
			}		
	}
	in.seekg(0,ios::beg);
	size=size+1;
	arr=new char[size];
	
		getline(in,line,'\0');
		
		for (int j=0,i=0;j<line.length();j++,i++){
			arr[i]=line[j];
		}
		arr[size-1]='\0';		
}
void removePunctucationMarks(){
	for (int i=0;i<size;i++){
		if (((int(arr[i])<97 || int(arr[i])>122) && (int(arr[i])<65 || int(arr[i])>90) && (int(arr[i])<48 || int(arr[i])>57) && arr[i]!='.' ) || (arr[i]=='\n')){
			arr[i]=' ';
		}
	}
	int noOfSpacesCount=0;
	int iterator=0;
	while (iterator<size){
		if (arr[iterator]==' ' && arr[iterator+1]==' '){
			noOfSpacesCount++;
		}
		iterator++;
	}
	int storeWithoutExtraSpacesCount=size-noOfSpacesCount;
	char *storeWithoutExtraSpaces=new char [storeWithoutExtraSpacesCount];
	int originalArrayIndex=0;
	int storeWithoutExtraSpacesIndex=0;
	while (originalArrayIndex<size)
	{
		if (arr[originalArrayIndex]==' ' && arr[originalArrayIndex+1]==' '){
		}
		else{
			storeWithoutExtraSpaces[storeWithoutExtraSpacesIndex]=arr[originalArrayIndex];
			storeWithoutExtraSpacesIndex++;
		}
		originalArrayIndex++;
	}
	storeWithoutExtraSpaces[storeWithoutExtraSpacesIndex-1]='\0';
	delete [] arr;
	size=storeWithoutExtraSpacesCount;
	arr=new char [size];
	for (int i=0;i<size;i++){
		arr[i]=storeWithoutExtraSpaces[i];
	}
	delete []storeWithoutExtraSpaces;
}
void removeSpacing(){
	for (int i=0;i<size;i++){
		if (arr[i]=='.' && arr[i+1]==' '){
			char *tempArr=new char [size-1];
			int j=0;
			for (;j<i+1;j++){
				tempArr[j]=arr[j];
			}
			for (int k=j+1;j<size;j++,k++){
				tempArr[j]=arr[k];
			}
			delete [] arr;
			size=size-1;
			arr= new char[size];
			for (int k=0;k<size;k++){
				arr[k]=tempArr[k];
			}
			arr[size-1]='\0';
			delete []tempArr;
			i--;
		}
	}
}
template <typename T,typename U>
bool isPresent(T ch,U index)
{
	if (arr[index]==ch)
	{
		return false;
	}
	return true;
}
void insertDots(){
	if (isPresent<char,int>('.',0)==true){
	char *tempArr=new char [size+1];
	tempArr[0]='.';
	for (int iterator=1,j=0;iterator<size+1;iterator++,j++){
		tempArr[iterator]=arr[j];
	}
	delete []arr;
	size=size+1;
	arr= new char [size];
	for (int i=0;i<size;i++){
		arr[i]=tempArr[i];
	}
	delete []tempArr;
	}
	if (isPresent<char,int>('.',size-2)==true){
		char *tempArr=new char [size+1];
		for (int i=0;i<size-1;i++){
			tempArr[i]=arr[i];
		}
		tempArr[size-1]='.';
		tempArr[size]=arr[size-1];

		delete []arr;
		size=size+1;

		arr=new char [size];
		for (int i=0;i<size;i++){
			arr[i]=tempArr[i];
		}
		delete[]tempArr;
	}
	for (int i=0;i<size;i++){
		if (arr[i]=='.' && arr[i+1]!='.' && arr[i-1]!='.'){
			char *tempArr=new char [size+1];
			int j=0;
			for (;j<i+1;j++){
				tempArr[j]=arr[j];
			}
			int k=j;
			tempArr[j]='.';
			k++;
			for (;j<size;j++,k++){
				tempArr[k]=arr[j];
			}
			delete[]arr;
			size=size+1;
			arr=new char[size];
			for(int it=0;it<size;it++){
				arr[it]=tempArr[it];
			}
			delete[]tempArr;
			i++;
		}
	}
}

char * getText(){
	return arr;
}
template <typename T, typename U>
bool isUnique(T *uniqueWords,T word, U uniqueWordsSize){
	for (U i=0;i<uniqueWordsSize;i++){
		if (uniqueWords[i]==word)
		{
			return false;
		}
	}
	return true;
}
template<typename T, typename U>
int getWordIndex(T *uniqueWords,T word,U uniqueWordsSize){
	for (U i=0;i<uniqueWordsSize;i++){
		if (uniqueWords[i].compare(word)==0){
			return i;
		}
	}
	return -1;
}
template <typename T,typename U>
void appendWordsArray(T *&uniqueWords,U *&counts,T word,U &uniqueWordsSize){
		uniqueWordsSize++;
		uniqueWords[uniqueWordsSize-1]=word;
		counts[uniqueWordsSize-1]=1;
}
int getNoOfWords(){
	int noOfWords=0;
	for (int i=0;i<size-2;i++){
		if (arr[i]=='.' ){
			if (arr[i]=='.' && arr[i-1]!='.'){
				noOfWords+=2;
			}
			else{
				noOfWords++;
			}
		} else if(arr[i] == ' ') {
			noOfWords++;
		}
	}
	return noOfWords;
}
void generateUnigrams(){
	int noOfWords=getNoOfWords();
	string *uniqueWords=new string [noOfWords];
	int *counts=new int [noOfWords];
	int uniqueWordsSize=0;
	string word="";
	int i=0;
	while (arr[i]!='\0'){
		if (arr[i]=='.'){
			if (word.length()==0){
				if (isUnique<string,int>(uniqueWords,".",uniqueWordsSize)){
					appendWordsArray<string,int>(uniqueWords,counts,".",uniqueWordsSize);
					word="";
				}
				else{
					int index=getWordIndex<string,int>(uniqueWords,".",uniqueWordsSize);
					counts[index]+=1;
					word="";
				}
			}
			else{
				if (isUnique<string,int>(uniqueWords,word,uniqueWordsSize)){
					appendWordsArray<string,int>(uniqueWords,counts,word,uniqueWordsSize);
					word="";
				}
				else{
					int index=getWordIndex<string,int>(uniqueWords,word,uniqueWordsSize);
					counts[index]+=1;
					word="";
				}
				i--;
			}
		}
		else if (arr[i]!=' '){
			word+=arr[i];
		}
		else{
			if (isUnique<string,int>(uniqueWords,word,uniqueWordsSize)){
				appendWordsArray<string,int>(uniqueWords,counts,word,uniqueWordsSize);
				word="";
			}
			else{
				int index=getWordIndex<string,int>(uniqueWords,word,uniqueWordsSize);
				counts[index]+=1;
				word="";
			}
		}
		i++;
	}
	ofstream shift("unigram.txt");
	for (int it=0;it<uniqueWordsSize;it++){
		shift<<uniqueWords[it]<<" "<<counts[it]<<endl;
	}
	shift.close();
	delete []uniqueWords;
	delete counts;
}
template <typename  T>
void generateNgrams(T n, string nameOfFile){
	int noOfWords=getNoOfWords();
	int indexPointer=0;
	int count=0;
	string *uniqueWords=new string[noOfWords];
	int *counts=new int[noOfWords];
	int uniqueWordsSize=0;
	string word="";
	int i=0;
	while (arr[i]!='\0'){
		if (arr[i]=='.'){
			if (word.length()==0){
				word+=arr[i];
				word+=' ';
				count++;
				if (count==1){
					indexPointer=i;
				}
			}
			else{
				count++;
				word+=arr[i];
				word+=' ';
				if (count==1){
					indexPointer=i;
				}
			}
		}
		else if (arr[i]!=' '){
			word+=arr[i];
			if (arr[i+1]=='.'){
				word+=' ';
				count++;
				if (count==1){
					indexPointer=i;
				}
			}
			if (arr[i+1]==' '){
				word+=' ';
			}
		}
		else{
			count++;
				if (count==1){
					indexPointer=i;
				}
		}
		if (count==n){
			
			if (isUnique<string,int>(uniqueWords,word,uniqueWordsSize)){
				appendWordsArray<string,int>(uniqueWords,counts,word,uniqueWordsSize);
				word="";
				count=0;
				i=indexPointer;
			}
			else{
				int index=getWordIndex<string,int>(uniqueWords,word,uniqueWordsSize);
				counts[index]+=1;
				word="";
				count=0;
				i=indexPointer;
			}
		}
		i++;
	}
	if (n==2){
	ofstream shift(nameOfFile);
	for (int it=0;it<uniqueWordsSize;it++){
		shift<<uniqueWords[it]<<counts[it]<<endl;
	}
	shift.close();
	}
	else if (n==3){
		ofstream shift(nameOfFile);
		for (int it=0;it<uniqueWordsSize;it++){
			shift<<uniqueWords[it]<<counts[it]<<endl;
		}
		shift.close();
	}
	delete []uniqueWords;
	delete counts;
}
void generateBigrams(){
	generateNgrams<int>(2,"bigram.txt");
}
void generateTrigrams(){
	generateNgrams<int>(3,"trigram.txt");
}
double validateSentance(string str){
	int rootArrayCopySize=size;
	char * rootArrayCopy=new char [rootArrayCopySize];

	strcpy(rootArrayCopy,arr);
	delete [] arr;
	size=str.length()+1;
	arr=new char[size];
	for (int i=0;i<size-1;i++)
		arr[i]=str[i];
	arr[size-1]='\0';
	removePunctucationMarks();
	removeSpacing();
	insertDots();
	generateNgrams<int>(2,"tempBigrams.txt");
	generateNgrams<int>(3,"tempTrigrams.txt");
	ifstream tempBigramsFile("tempBigrams.txt");
	ifstream tempTrigramsFile("tempTrigrams.txt");
	int storeBigramCounts=0;
	int storeTrigramCounts=0;
	while (!tempBigramsFile.eof()){
		string line="";
		getline(tempBigramsFile,line);
		storeBigramCounts++;
	}
	while (!tempTrigramsFile.eof()){
		string line="";
		getline(tempTrigramsFile,line);
		storeTrigramCounts++;
	}
	int MatchedBigramsCountsArraySize=storeBigramCounts-1;
	int MatchedTrigramsCountsArraySize=storeTrigramCounts-1;
	int MatchedBigramArrayTrack=0;
	int MatchedTrigramArrayTrack=0;
	double *storeMatchedBigrams=new double [MatchedBigramsCountsArraySize];
	double *storeMatchedTrigrams=new double [MatchedTrigramsCountsArraySize];
	for (int iterator=0;iterator<MatchedBigramsCountsArraySize;iterator++)
		storeMatchedBigrams[iterator]=-1.00;
	for (int iterator=0;iterator<MatchedTrigramsCountsArraySize;iterator++)
		storeMatchedTrigrams[iterator]=-1.00;
	tempBigramsFile.seekg(0,ios::beg);
	tempTrigramsFile.seekg(0,ios::beg);
	ifstream originalBigramsFile("bigram.txt");
	ifstream originalTrigramsFile("trigram.txt");
	tempBigramsFile.close();
	tempTrigramsFile.close();
	tempBigramsFile.open("tempBigrams.txt");
	tempTrigramsFile.open("tempTrigrams.txt");

	string tempBiGram="";
	while (getline(tempBigramsFile,tempBiGram,'\n')){
		int tempBigramPopBack=tempBiGram.length()-1;
		while (tempBiGram[tempBigramPopBack]!=' '){
			tempBiGram.pop_back();
			tempBigramPopBack--;
		}
		string originalBiGram="";
		while (getline(originalBigramsFile,originalBiGram,'\n')){
			string currentBiGramCount="";
			int iterator=originalBiGram.length()-1;
			while (originalBiGram[iterator]!=' '){
				currentBiGramCount+=originalBiGram[iterator];
				iterator--;
			}
			int originalBigramPopBack=originalBiGram.length()-1;
			while(originalBiGram[originalBigramPopBack]!=' '){
				originalBiGram.pop_back();
				originalBigramPopBack--;
			}
			if (originalBiGram==tempBiGram){
				storeMatchedBigrams[MatchedBigramArrayTrack]=double(stoi(currentBiGramCount));
				MatchedBigramArrayTrack++;
				originalBigramsFile.seekg(0);
				break;
			}
		}
		tempBiGram="";
	}

	string tempTriGram="";
	while (!tempTrigramsFile.eof()){
		getline(tempTrigramsFile,tempTriGram,'\n');
		if(tempTriGram.length()>0){
		int tempTrigramPopBack=tempTriGram.length()-1;
		while (tempTriGram[tempTrigramPopBack]!=' '){
			tempTriGram.pop_back();
			tempTrigramPopBack--;
		}
		string originalTriGram="";
		while (!originalTrigramsFile.eof()){
			getline(originalTrigramsFile,originalTriGram,'\n');
			string currentTriGramCount="";
			if(originalTriGram.length()>0){
			int iterator=originalTriGram.length()-1;
			while (originalTriGram[iterator]!=' '){
				currentTriGramCount+=originalTriGram[iterator];
				iterator--;
			}
			int originalTrigramPopBack=originalTriGram.length()-1;
			while(originalTriGram[originalTrigramPopBack]!=' '){
				originalTriGram.pop_back();
				originalTrigramPopBack--;
			}
			if (originalTriGram==tempTriGram){
				storeMatchedTrigrams[MatchedTrigramArrayTrack]=double(stoi(currentTriGramCount));
				MatchedTrigramArrayTrack++;
				originalTrigramsFile.seekg(0);
				break;
			}
		}
		}
		}
		else{
			if(storeMatchedTrigrams[MatchedTrigramArrayTrack]==-1)
				break;
		}
	}
	double Prob=0,count=0;
	for (int i=0;i<MatchedTrigramsCountsArraySize;i++){
		if(storeMatchedBigrams[i]!=-1 && storeMatchedTrigrams[i]!=-1){
			count=storeMatchedTrigrams[i]/storeMatchedBigrams[i];
			Prob+=log(count);
		}
		else{
			return 1;
		}
	}
	return Prob;
}
