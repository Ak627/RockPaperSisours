#include<iostream>
#include<string>
using namespace std;


string gestures[] = { "rock", "paper", "scissors", "lizard", "spock" };


int winloss[5][5] = {
	2,0,1,1,0,
	1,2,0,0,1,
	0,1,2,1,0,
	0,1,0,2,1,
	1,0,1,0,2
};

void print_greeting() {
	cout << "Welcome to Rock-Paper-Scissors-Lizard-Spock! Fun family game for all!" << endl;
}

void gesture() {
	cout << "Choices are: " << endl;
	cout << "(0)Rock, (1)Paper, (2)Scissors, (3)Lizard, (4)Spock" << endl;
}


int input_throw(string t, string o) {
	cout << "It is " << t << "'s turn" << endl;
	cout << o << " no peeking" << endl;


	cout << t << " What is your throw?" << endl;
	gesture();
	int the_throw;
	cin >> the_throw;


	while (the_throw < 0 || the_throw >= sizeof(gestures) / sizeof(gestures[0])) {
		cout << "Invalid choice: try again." << endl;
		cout << t << " what is your throw" << endl;
		cin >> the_throw;
	}

	cout << t << " throws " << gestures[the_throw] << endl;

	return the_throw;
}

int calc_winner(int t1, int t2) {
	return winloss[t1][t2];
}

int main() {
	print_greeting();

	cout << "Enter player 1 name" << endl;
	string name1;
	string name2;
	getline(cin, name1);
	cout << "So your name is " << name1 << endl;

	cout << "Enter player 2 name" << endl;
	getline(cin, name2);
	cout << "So your name is " << name2 << endl;


	int throw1 = input_throw(name1, name2);
	int throw2 = input_throw(name2, name1);


	int winner = calc_winner(throw1, throw2);

	while (winner == 2) {
		cout << "It's a tie; both players will throw again." << endl;
		throw1 = input_throw(name1, name2);
		throw2 = input_throw(name2, name1);
		winner = calc_winner(throw1, throw2);


	}

	if (winner == 1) {
		cout << gestures[throw1] << " beats " << gestures[throw2] << endl;
		cout << name1 << " beats " << name2 << endl;
	}
	else {
		cout << gestures[throw2] << " beats " << gestures[throw1] << endl;
		cout << name2 << " beats " << name1 << endl;
	}
}
