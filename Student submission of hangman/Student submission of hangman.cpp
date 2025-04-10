#include <fstream>
#include <iostream>
#include <random>
#include <string>

using std::cin;
using std::cout;
using std::ifstream;
using std::getline;
using std::string;
using std::vector;

// @param wordList -> a vector of words Fills vector with contents of words.txt, referred to when selecting a random word and determining size of file
void generateWordList(vector<string>& wordList) { 
	ifstream fin;
	fin.open("words.txt");
	string fileLine;
	while (getline(fin, fileLine)) {
		wordList.push_back(fileLine);
	}
}



int getWordPosition(const vector<string>& wordList) { // Used to randomly select a word from vector filled in generateWordList()
	std::mt19937 mt{ std::random_device{}()};
	std::uniform_int_distribution<> randomWordPosition{ 1, (int)(wordList.size()) }; // Compiler yelled at me if I didn't use static_cast, not 100% sure why but already spent too much time optimizing this already so I just listened
	return randomWordPosition(mt);
}

void checkAnswer(const char guessedLetter, const string& answer, string& guessedAnswer) {
	bool correctGuess = false;
	bool reusedGuess = false;
	for (int i = 0; i < guessedAnswer.length(); i++) {
		if (guessedAnswer[i] == guessedLetter) {
			reusedGuess = true;
			break;
		}
		else if (answer[i] == guessedLetter) {
			guessedAnswer[i] = guessedLetter;
			correctGuess = true;
		}
	}
	if (reusedGuess) {
		cout << "Letter already guessed! Try again.";
	}
	else if (correctGuess) {
		cout << "You guessed a correct letter!\n";
	}
	else {
		cout << "Letter not found! Try again.\n";
	}
}

int main() {
	vector<string> wordList;
	generateWordList(wordList);
	string answer = wordList[getWordPosition(wordList)];
	cout << answer;
	string guessedAnswer(answer.length(), '*');
	char guessedLetter;
	while (guessedAnswer != answer) {
		cout << "\nGuess a letter from the following word:\t" << guessedAnswer << '\n';
		cin >> guessedLetter;
		checkAnswer(guessedLetter, answer, guessedAnswer);
	}
	cout << "You guessed the word! Good job!";
}