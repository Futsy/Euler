#pragma once

enum class Type { 
	SPADE, HEART, DIAMOND, CLUB 
};

enum class Value { 
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE 
};

class Card {
public:
	Card(const std::string& card);
	const Type& GetType() {
		return type;
	}
	const Value& GetValue() {
		return value;
	}
private:
	Type type;
	Value value;
};

Card::Card(const std::string& card) {
	char first = card[0];
	char second = card[1];

	switch (first) {
	case '2': value = Value::TWO;
		break;
	case '3': value = Value::THREE;
		break;
	case '4': value = Value::FOUR;
		break;
	case '5': value = Value::FIVE;
		break;
	case '6': value = Value::SIX;
		break;
	case '7': value = Value::SEVEN;
		break;
	case '8': value = Value::EIGHT;
		break;
	case '9': value = Value::NINE;
		break;
	case 'T': value = Value::TEN;
		break;
	case 'J': value = Value::JACK;
		break;
	case 'Q': value = Value::QUEEN;
		break;
	case 'K': value = Value::KING;
		break;
	case 'A': value = Value::ACE;
		break;
	}
	switch (second) {
	case 'S': type = Type::SPADE;
		break;
	case 'H': type = Type::HEART;
		break;
	case 'D': type = Type::DIAMOND;
		break;
	case 'C': type = Type::CLUB;
		break;
	}
}
