#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

string hide_msg(string input);

int main() {
	string msg;
	string hidden_msg;
	int failures = 0;
	
	cout << "HANGMAN by Tolby Lam \n";
	cout << "Player 1, type a word or phrase... \n";
	getline(cin, (msg));
	hidden_msg = hide_msg(msg);
	
	//print blank lines to clear screen...
	for(int i = 0; i < 20; i++)
		cout << "\n";
	
	do {
		char input;
		bool success = false;
		cout << hidden_msg << endl;
		cout << "Player 2, guess a character... " << endl; //
		cin >> input;
		for(int i = 0; i < msg.size(); i++) { //check if letter is in word/phrase
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
