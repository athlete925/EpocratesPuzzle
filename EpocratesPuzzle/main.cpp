/*
Presish Chand
6/16/14

This program takes in a word and determines its rank in all words
that can be alphabetically generated. This program does not accept
lowercase words, 2-letter words with same letter, and words greater
than 25 letters long. 
*/

#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;

int rankWord(string w);									//determines alphabetic rank of word
void checkword(string inputw);							//determines if word all caps

bool allcaps = false;
string sortedword;								//used to hold alphabetized word

void main(){
	string word;

	int rank;
	
	do{
		do{
			cout << "Please enter a word only in caps: ";
			cin >> word;
			cout << endl << endl;

			checkword(word);								
		}while(allcaps == false);						//loop until word entered is all caps

		sortedword = word;
		rank = rankWord(word);

		cout << "Rank of the word " <<word << " is: " << rank << endl;
		cin.get();

		cout << "alphabetized is: " << sortedword <<endl <<endl;
		cin.get();cin.get();

		cout << "if you would like to exit? enter 'yes' in lowercase letter: ";
		cin >> word;
		cin.get();cin.get();

	}while(word != "yes");
}

void checkword(string inputw){
	int inputwLength = inputw.size();					//returns length of variable... sizeof() returns size in bytes
	
	for(int i = 0; i < inputwLength; i++){
		
		char lettercheck = inputw[i];

		if(int(lettercheck) >= 97){						//ASCII value where lowercase letters start
			allcaps = false;
		}
		else if(inputwLength == 2){	
			if(char(inputw[0]) == char(inputw[1])){	
				allcaps = false;						//return false if first two letters are not different
			}
			else{
				allcaps = true;							//return true if first two letters are different
			}		
		}
		else if(inputwLength > 25){
			allcaps = false;
		}
		else{
			allcaps = true;
		}

	}
}

int rankWord(string w){
	int ranked=1;										//if word is sent to function already alphabetized, it is automatically ranked 1
	int inputwLength = w.size();						//returns length of variable... sizeof() returns size in bytes

	for(int i = 0; i<inputwLength-1;i++){

		for(int j = i+1; j<inputwLength; j++){
			if(int(w[i]) > int(w[j])){
				swap(w[i],w[j]);
			}
			else{
				
			}
		}
	}

	sortedword = w;
	

	return ranked;
}