#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

#include "Card.h"

std::vector<std::vector<Card>> hands1;
std::vector<std::vector<Card>> hands2;

void ParseInput() {
	std::ifstream t("input.txt");
	std::stringstream buffer;
	buffer << t.rdbuf();

	std::string input = buffer.str();

	std::vector<Card> hand1;
	std::vector<Card> hand2;

	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '\n') {
			hands1.push_back(hand1);
			hands2.push_back(hand2);
			hand1.clear();
			hand2.clear();
			continue;
		}

		if (input[i] == ' ') {
			continue;
		}

		//Add untill 5 in hand 1
		std::string card = "";
		card += input[i];
		card += input[i + 1];

		Card c(card);

		if (hand1.size() != 5) {
			hand1.push_back(c);
		}
		else {
			hand2.push_back(c);
		}
		++i;
	}
}

int main() {
	int solution = 0;

	ParseInput();
	for (int i = 0; i < hands1.size(); i++) {
		std::vector<Card> hand1 = hands1[i];
		std::vector<Card> hand2 = hands2[i];

		//Loop through the possibilities here
	}
	

	


	std::cout << "Solution: " << solution << std::endl;
	std::cin.get();
}

