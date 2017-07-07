#include <iostream>
#include <string>
using namespace std;

string hide_msg(string input);

int main() {
	string msg;
	string hidden_msg;
	int failures = 0;
	
	cout << "HANGMAN by Tolby Lam \n";
	cout << "Player 1, type a word or phrase... \n";
	//figure out how to hide the word/phrase...
	getline(cin, (msg));
	hidden_msg = hide_msg(msg);
	
	do {
		char input;
		bool success = false;
		cout << hidden_msg << endl;
		cout << "Player 2, guess a character... " << endl; //
		cin >> input;
		for(int i = 0; i < msg.size(); i++) { //this could be a method...
			if(input == msg.at(i)) {
				hidden_msg.at(i) = input;
				success = true;
			}
		}
		if(!success)
			failures++;
	} while(hidden_msg != msg || failures < 6);
	
	if(failures < 6)
		cout << "You did it! \n";
	else
		cout << "You failed. \n";
	
	return 0;
}

string hide_msg(string s) {
    string hidden_msg;
    
    for(char c : s) {
        if(isalpha(c))
            hidden_msg.push_back('_');
        else if(isspace(c))
            hidden_msg.push_back(' ');
        else //add more cases eventually, but this is sufficient for now
            continue;
    }
    
    return hidden_msg;
}