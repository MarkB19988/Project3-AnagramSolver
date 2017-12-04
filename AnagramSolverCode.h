#include <iostream>  // Inlucded libraries 
#include <fstream>  // --
#include <string>  // --
#include <cstdlib> // --
#include <map> // --

using namespace std; // Makes functions with the same names within different libraries distinguishable

string answer;

int lastScore; // Creates int called lastScore
  
void solution(string a, string w){ 

   if (  answer.length() > w.length()) return; // returns the string for the user if the solution is retrieved. 
   
		int currentScore = 0;  // sets currentScore to 0
		map<char, int> reapeatedChars; // stores the score to the values and searches for them when they are retrieved
  
		for(unsigned i=0; i < a.length(); i++) {  // for the score, each letter is worth 1
		
		for(unsigned j=0; j < w.length(); j++) { //  if letter is found in anagram that is in dictionary, gives one point 
			
			if(a[i] == w[j]){ // if a character [i] = w character [j] 
				
				reapeatedChars[w[j]]++; 
					
					if(reapeatedChars[w[j]] == 1){ 
					
					currentScore++;
				}
			}
		}
	}
	
	if(currentScore > lastScore){  // currentScore is bigger lastScore, give answer
     
		answer = w; // answer refered to as 'w'
		lastScore = currentScore; // gets the answer 
	}
}
  
  
  
int main() { // main function
	
	string filename = "Words.csv";	// points to the file to read

  
    string userin;
		
		do {
			
			cout << "Please enter 3 letters: "; // asks the user to enter 3 letters
			getline(cin, userin); 
		}
  
		while(userin.length() > 3); // makes sure the length of the word is 3 characters (wont procede if longer)
		
		// ---Read from the file---
  
		ifstream fin(filename.c_str());  // This section of code will read the file 
			
			if (!fin) { // the "fin" in the code is the file being opened and '!' allows the file to be true or false.
				
				cout << "error file not able to retrieve"; // this error message will display if the file can't be found
				abort(); // closes if the file can't be found
			}
			
			string line; 
    
			while (fin >> line) {  
    
				if(userin.length() >= line.length()){  // checks the lenght of the line.
				
				solution(userin, line);
			}
		}
    
	fin.close();  // close the file and unlinks it from the program
	cout << "Best Solution: " << answer << endl; // prints out best solution out of 3 letters.
	
	return 0;
}