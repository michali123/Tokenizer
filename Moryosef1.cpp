#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> tokenizer(string line) {
 vector<string> words; // returns vector
 string word = "";
 bool found = false;
 for (int i = 0, len = line.length(); i < len; ++i) { // visit every char in line
 if (!isspace(line.at(i))) { // non-space char found
 found = true; // flag up for word found
 word += line.at(i); // constructing a word
 continue;
 }
 if (found) { // this matches right after the tail of the found word
 words.push_back(word); // accumulate a found word to return vector
 word = ""; // reset
 found = false; // flag down for a new word
 }
 }
 if (found) words.push_back(word);
 return words;
 }

void framePrint (int buf){
	while (true){
		if (buf > 10){
	cout << "---------+";
		buf -= 10;
		}
		else{
		for (int h = 0; h < buf; ++h){
			cout << "-";
			}
		cout << "+";
		}
	}
}

int main (){

	string line, margin;
	vector<string> storeWords;
	int width;

	// program gets new lines (paragraph)
	while (true){
		cout << "> " ;
		getline (cin, line);
		if (line == "") break;

	 vector<string> storeWords = tokenizer(line); //stores all the input in a one string vector.
	}
	// gets input until reads 0 as new width
	while ( width != 0){
	cout << "Enter left|right|center and paragraph width:";
	cin >> margin;
	cin >> width ;
	int remainder;
	int j=0;

	//printing top boundary
			int buffer = width;
			cout << "+" << framePrint(buffer) << "+" << endl;

			while ( storeWords.empty() == false ){

				if (margin == "left"){//printing tokenized lines
				cout << "|" ;
				remainder = width;
				while (( remainder > 0) && (remainder >= storeWords.at(j).size())){
					cout << storeWords.at(j);
					remainder = remainder - storeWords.at(j).size();
					if (remainder - 1 != 0)
						cout << " ";
					}
					j++;
				}
				cout << "|" << endl;
				remainder = width;

			}
			 if ( margin == "right"){
				string rightSpace;
				remainder = width;
				rightSpace = "|";
				while ((remainder > 0) && (remainder >= storeWords.at(j).size())){
					if (remainder == storeWords.at(j).size()){
						rightSpace = storeWords.at(j) ,"|";
						remainder -= storeWords.at(j).size();
				}
					if (remainder > storeWords.at(j).size()){
						rightSpace = storeWords.at(j) , " ";
						remainder = remainder - storeWords.at(j).size() - 1;
					}
					++j;
			}
				if (remainder == 0){
					cout << rightSpace << endl;
				}
					else{
						 for (int i = 0; i <= remainder; ++i ){
							 cout << " ";
					}
						 cout << rightSpace << endl;
				}
			 }
			 if (margin == 'center'){
				 string centerSpace;
				 remainder = width;
				 centerSpace = "|";
					while (remainder > 0) && (remainder >= storeWords.at(j).size()){
							if (remainder == storeWords.at(j).size()){
								centerSpace = storeWords.at(j);
								remainder -= storeWords.at(j).size();
						}
							if (remainder > storeWords.at(j).size()){
								centerSpace = storeWords.at(j) , " ";
								remainder = remainder - storeWords.at(j).size() - 1;
							}
							++j;
					}
						if (remainder == 0){
							cout << centerSpace << "|" << endl;
						}
							else{
								 for (int i = 0; i <= remainder/2 ; ++i ){
									 cout << " ";
							}
								 cout << centerSpace;
								 for (int i = 0; i <= remainder/2 ; ++i ){
									cout << " ";
								}
								 	 cout << "|" << endl;
						}

			 }

			//printing bottom boundary
					buffer = width;
								cout << "+" << framePrint(buffer) << "+" << endl;
		}

	return 0;

}
