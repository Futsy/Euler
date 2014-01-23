#pragma once

#include "Card.h"

class Solver {
public:
	const Value straight[10][5] = {
		{ Value::TWO, Value::THREE, Value::FOUR, Value::FIVE, Value::ACE },
		{ Value::TWO, Value::THREE, Value::FOUR, Value::FIVE, Value::SIX },
		{ Value::THREE, Value::FOUR, Value::FIVE, Value::SIX, Value::SEVEN },
		{ Value::FOUR, Value::FIVE, Value::SIX, Value::SEVEN, Value::EIGHT },
		{ Value::FIVE, Value::SIX, Value::SEVEN, Value::EIGHT, Value::NINE },
		{ Value::SIX, Value::SEVEN, Value::EIGHT, Value::NINE, Value::TEN },
		{ Value::SEVEN, Value::EIGHT, Value::NINE, Value::TEN, Value::JACK },
		{ Value::EIGHT, Value::NINE, Value::TEN, Value::JACK, Value::QUEEN },
		{ Value::NINE, Value::TEN, Value::JACK, Value::QUEEN, Value::KING },
		{ Value::TEN, Value::JACK, Value::QUEEN, Value::KING, Value::ACE }
	};
private:
	std::vector<Card> hand1;
	std::vector<Card> hand2;
public:
	Solver(std::vector<Card>& hnd1, std::vector<Card>& hnd2) {
		hand1 = hnd1;
		hand2 = hnd2;
	}
	bool Compute();
private:
	//1 = p1 won
	//2 = p2 won
	//3 = no result
	int StraightFlush();
	int FourKind();
	int FullHouse();
	int Flush();
	int Straight();
	int ThreeKind();
	int XKind();
};
