#include "Solver.h"


bool Solver::Compute() {
	switch (StraightFlush()) {
	case 1: 
		return true;
	case 2: return false;
	case 3: break;
	}

	switch (FourKind()) {
	case 1: 
		return true;
	case 2: return false;
	case 3: break;
	}

	switch (FullHouse()) {
	case 1: 
		return true;
	case 2: return false;
	case 3: break;
	}

	switch (Flush()) {
	case 1: 
		return true;
	case 2: return false;
	case 3: break;
	}

	switch (Straight()) {
	case 1: 
		return true;
	case 2: return false;
	case 3: break;
	}

	switch (ThreeKind()) {
	case 1: 
		return true;
	case 2: return false;
	case 3: break;
	}

	switch (XKind()) {
	case 1: 
		return true;
	case 2: return false;
	case 3: break;
	}
}

int Solver::StraightFlush() {
	Value straight1;
	Value straight2;

	bool type1 = true;
	bool type2 = true;

	bool has1 = false;
	bool has2 = false;

	if (hand1[0].GetType() != hand1[1].GetType() ||
		hand1[1].GetType() != hand1[2].GetType() ||
		hand1[2].GetType() != hand1[3].GetType() ||
		hand1[3].GetType() != hand1[4].GetType()) {
		type1 = false;
	}
	if (hand2[0].GetType() != hand2[1].GetType() ||
		hand2[1].GetType() != hand2[2].GetType() ||
		hand2[2].GetType() != hand2[3].GetType() ||
		hand2[3].GetType() != hand2[4].GetType()) {
		type2 = false;
	}

	//No Flush
	if (!type1 && !type2) {
		return 3;
	}
		
	//Check flush -> check high card
	if (type1) {

		//Find straight in type 1
		Value val1[5] = { 
			hand1[0].GetValue(), hand1[1].GetValue(), hand1[2].GetValue(), hand1[3].GetValue(), hand1[4].GetValue()
		};
			
		std::sort(val1,val1 + 5);

		for (int i = 0; i < 10; i++) {
			if (val1[0] == straight[i][0] && val1[1] == straight[i][1] && val1[2] == straight[i][2] && val1[3] == straight[i][3] && val1[4] == straight[i][4]) {
				straight1 = val1[4];
				has1 = true;
				break;
			}
		}
	}
	if (type2) {

		//Find straight in type 2
		Value val2[5] = { 
			hand2[0].GetValue(), hand2[1].GetValue(), hand2[2].GetValue(), hand2[3].GetValue(), hand2[4].GetValue()
		};
			
		std::sort(val2,val2 + 5);

		for (int i = 0; i < 10; i++) {
			if (val2[0] == straight[i][0] && val2[1] == straight[i][1] && val2[2] == straight[i][2] &&
			val2[3] == straight[i][3] && val2[4] == straight[i][4]) {
				straight2 = val2[4];
				has2 = true;
				break;
			}
		}
	}

	if (type1 && type2 && has1 && has2) {
		if (straight1 > straight2) {
			return 1;
		}
		else {
			return 2;
		}
	}
	else if (type1 && has1) {
		return 1;
	}
	else if (type2 && has2) {
		return 2;
	}
	else {
		return 3;
	}
}

int Solver::FourKind() {
	Value player1 = Value::TWO;
	Value player2 = Value::TWO;

	Value val1[5] = { 
		hand1[0].GetValue(), hand1[1].GetValue(), hand1[2].GetValue(), hand1[3].GetValue(), hand1[4].GetValue()
	};
		
	Value val2[5] = { 
		hand2[0].GetValue(), hand2[1].GetValue(), hand2[2].GetValue(), hand2[3].GetValue(), hand2[4].GetValue()
	};

	std::sort(val1,val1 + 5);
	std::sort(val2,val2 + 5);

	//Check first
	if ((val1[0] == val1[1] && val1[1] == val1[2] && val1[2] == val1[3]) ||
		(val1[4] == val1[3] && val1[1] == val1[2] && val1[2] == val1[3])) {
		player1 = val1[3];
	}

	//Check second
	if ((val2[0] == val2[1] && val2[1] == val2[2] && val2[2] == val2[3]) ||
		(val2[4] == val2[3] && val2[1] == val2[2] && val2[2] == val2[3])) {
		player2 = val2[3];
	}

	if (player1 > player2) {
		return 1;
	}
	else if (player2 > player1) {
		return 2;
	}
	return 3;
}

int Solver::FullHouse() {
	Value player1 = Value::TWO;
	Value player2 = Value::TWO;

	bool first = false;
	bool second = false;

	Value val1[5] = { 
		hand1[0].GetValue(), hand1[1].GetValue(), hand1[2].GetValue(), hand1[3].GetValue(), hand1[4].GetValue()
	};
		
	Value val2[5] = { 
		hand2[0].GetValue(), hand2[1].GetValue(), hand2[2].GetValue(), hand2[3].GetValue(), hand2[4].GetValue()
	};

	std::sort(val1,val1 + 5);
	std::sort(val2,val2 + 5);

	//Check player 1
	bool fullhouse1 = (val1[0] == val1[1] && val1[1] == val1[2]) && (val1[3] == val1[4]);
	bool fullhouse2 = (val1[0] == val1[1]) && (val1[2] == val1[3] && val1[3] == val1[4]);

	if (fullhouse1 || fullhouse2) {
		first = true;
		if (fullhouse1) {
			player1 = val1[0];
		}
		else {
			player1 = val1[4];
		}
	}


	//Check player 2
	fullhouse1 = (val2[0] == val2[1] && val2[1] == val2[2]) && (val2[3] == val2[4]);
	fullhouse2 = (val2[0] == val2[1]) && (val2[2] == val2[3] && val2[3] == val2[4]);

	if (fullhouse1 || fullhouse2) {
		second = true;
		if (fullhouse1) {
			player2 = val2[0];
		}
		else {
			player2 = val2[4];
		}
	}

	//Check result
	if (first && second) {
		//Check high card
		if (player1  > player2) {
			return 1;
		}
		return 2;	
	}
	else if (first) {
		return 1;
	}
	else if (second) {
		return 2;
	}
	return 3;
}

int Solver::Flush() {
	Value flushH1;
	Value flushH2;

	bool type1 = true;
	bool type2 = true;

	bool has1 = false;
	bool has2 = false;

	Value val1[5] = { 
		hand1[0].GetValue(), hand1[1].GetValue(), hand1[2].GetValue(), hand1[3].GetValue(), hand1[4].GetValue()
	};
		
	Value val2[5] = { 
		hand2[0].GetValue(), hand2[1].GetValue(), hand2[2].GetValue(), hand2[3].GetValue(), hand2[4].GetValue()
	};

	std::sort(val1,val1 + 5);
	std::sort(val2,val2 + 5);

	if (hand1[0].GetType() != hand1[1].GetType() ||
		hand1[1].GetType() != hand1[2].GetType() ||
		hand1[2].GetType() != hand1[3].GetType() ||
		hand1[3].GetType() != hand1[4].GetType()) {
		type1 = false;
	}
	else {
		flushH1 = val1[4];
	}
	if (hand2[0].GetType() != hand2[1].GetType() ||
		hand2[1].GetType() != hand2[2].GetType() ||
		hand2[2].GetType() != hand2[3].GetType() ||
		hand2[3].GetType() != hand2[4].GetType()) {
		type2 = false;
	}
	else {
		flushH2 = val2[4];
	}

	//Flush Check
	if (type1 && type2) {
		if (flushH1 > flushH2) {
			return 1;
		}
		return 2;
	}
	else if (type1) {
		return 1;
	}
	else if (type2) {
		return 2;
	}
	return 3;
}

int Solver::Straight() {
	Value straight1;
	Value straight2;

	bool has1 = false;
	bool has2 = false;
		
	//Check flush -> check high card
		
	//Find straight in type 1
	Value val1[5] = { 
		hand1[0].GetValue(), hand1[1].GetValue(), hand1[2].GetValue(), hand1[3].GetValue(), hand1[4].GetValue()
	};
			
	std::sort(val1,val1 + 5);

	for (int i = 0; i < 10; i++) {
		if (val1[0] == straight[i][0] && val1[1] == straight[i][1] && val1[2] == straight[i][2] &&
			val1[3] == straight[i][3] && val1[4] == straight[i][4]) {
			straight1 = val1[4];
			has1 = true;
			break;
		}
	}
		
	//Find straight in type 2
	Value val2[5] = { 
		hand2[0].GetValue(), hand2[1].GetValue(), hand2[2].GetValue(), hand2[3].GetValue(), hand2[4].GetValue()
	};
			
	std::sort(val2,val2 + 5);

	for (int i = 0; i < 10; i++) {
		if (val2[0] == straight[i][0] && val2[1] == straight[i][1] && val2[2] == straight[i][2] &&
			val2[3] == straight[i][3] && val2[4] == straight[i][4]) {
			straight2 = val2[4];
			has2 = true;
			break;
		}
	}
		

	if (has1 && has2) {
		if (straight1 > straight2) {
			return 1;
		}
		else {
			return 2;
		}
	}
	else if (has1) {
		return 1;
	}
	else if (has2) {
		return 2;
	}
	else {
		return 3;
	}
}

int Solver::ThreeKind() {
	Value player1;
	Value player2;

	bool has1 = false;
	bool has2 = false;

	//First Array
	Value val1[5] = { 
		hand1[0].GetValue(), hand1[1].GetValue(), hand1[2].GetValue(), hand1[3].GetValue(), hand1[4].GetValue()
	};
			
	std::sort(val1,val1 + 5);
				
	//Second Array
	Value val2[5] = { 
		hand2[0].GetValue(), hand2[1].GetValue(), hand2[2].GetValue(), hand2[3].GetValue(), hand2[4].GetValue()
	};
			
	std::sort(val2,val2 + 5);


	//Check for three of a kind in 1 and 2
	for (int i = 0; i < 3; i++) {
		if (val1[i] == val1[i + 1] && val1[i + 1] == val1[i + 2]) {
			player1 = val1[i];
			has1 = true;
		}
		if (val2[i] == val2[i + 1] && val2[i + 1] == val2[i + 2]) {
			player2 = val1[i];
			has2 = true;
		}
	}

	if (has1 && has2) {
		if (player1 > player2) {
			return 1;
		}
		return 2;
	}
	else if (has1) {
		return 1;
	}
	else if (has2) {
		return 2;
	}
	return 3;
}

int Solver::XKind() {
	std::vector<Value> player1H;
	std::vector<Value> player2H;

	std::vector<Value> restCard1;
	std::vector<Value> restCard2;

	//First Array
	Value val1[5] = { 
		hand1[0].GetValue(), hand1[1].GetValue(), hand1[2].GetValue(), hand1[3].GetValue(), hand1[4].GetValue()
	};
			
	std::sort(val1,val1 + 5);
				
	//Second Array
	Value val2[5] = { 
		hand2[0].GetValue(), hand2[1].GetValue(), hand2[2].GetValue(), hand2[3].GetValue(), hand2[4].GetValue()
	};
			
	std::sort(val2,val2 + 5);

	//Add first hand to list
	for (int i = 0; i < 4; i++) {
		if (val1[i] == val1[i + 1]) {
			player1H.push_back(val1[i]);
			i++;
		}
		else {
			restCard1.push_back(val1[i]);
		}
	}
	if (player1H.size() > 0 && val1[3] != val1[4]) {
		restCard1.push_back(val1[4]);
	}

	//Add second hand to list
	for (int i = 0; i < 4; i++) {
		if (val2[i] == val2[i + 1]) {
			player2H.push_back(val2[i]);
			i++;
		}
		else {
			restCard2.push_back(val2[i]);
		}
	}
	if (player2H.size() > 0 && val2[3] != val2[4]) {
		restCard2.push_back(val2[4]);
	}

	//Nothing found return high card
	if (player1H.size() == 0 && player2H.size() == 0) {
		if (val1[4] > val2[4]) {
			return 1;
		}
		return 2;
	}

	//If one pair
	if (player1H.size() == 1 && player2H.size() == 1) {
		if (player1H[0] > player2H[0]) {
			return 1;
		}
		else if (player2H[0] > player1H[0]) {
			return 2;
		}
		else {
			//Check rest cards
			std::sort(restCard1.begin(), restCard1.end());
			std::sort(restCard2.begin(), restCard2.end());

			for (int i = restCard1.size(); i > 0; i--) {
				if (restCard1[i - 1] > restCard2[i - 1]) {
					return 1;
				}
				else if (restCard1[i - 1] < restCard2[i - 1]) {
					return 2;
				}
			}
		}
	}
	else if (player1H.size() == 1 && player2H.size() != 2) {
		return 1;
	}
	else if (player2H.size() == 1 && player1H.size() != 2) {
		return 2;
	}

	//If two pair
	if (player1H.size() == 2 && player2H.size() == 2) {
		if (player1H[0] > player2H[0]) {
			return 1;
		}
		else if (player2H[0] > player1H[0]) {
			return 2;
		}
		else {
			//Check rest cards
			std::sort(restCard1.begin(), restCard1.end());
			std::sort(restCard2.begin(), restCard2.end());

			for (int i = restCard1.size(); i > 0; i--) {
				if (restCard1[i] > restCard2[i]) {
					return 1;
				}
				else if (restCard1[i] < restCard2[i]) {
					return 2;
				}
			}
			return 3;
		}
	}
	else if (player2H.size() == 2) {
		return 2;
	}
	else if (player1H.size() == 2) {
		return 1;
	}
	return 3;
}