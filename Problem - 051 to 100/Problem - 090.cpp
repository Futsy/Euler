/**
 * Run time solution
 * 0.002001 seconds
 */
#include <iostream>
#include <vector>


class Solver {
public:
	Solver() {
		GenerateSet();
	}

	bool Check(const std::vector<int>& first, const std::vector<int>& second) {
		if (first[0] != 0) {
			return false;
		}

		// Numbers: 49, 64 - Most likely
		if (!(HasMember(first, 4) && (HasMember(second, 6) || HasMember(second, 9))) 
			&& (!(HasMember(second, 4) && (HasMember(first, 6)|| HasMember(first, 9))))) {				
			return false;
		}

		// Number: 09
		if (!HasMember(second, 6) && !HasMember(second, 9) && (!(HasMember(second, 0) 
			&& (HasMember(first, 6) || HasMember(first, 9))))) {
			return false;
		}

		// Number: 16
		if (!(HasMember(first, 1) && (HasMember(second, 6) || HasMember(second, 9))) 
			&& (!(HasMember(second, 1) && (HasMember(first, 6) || HasMember(first, 9))))) {
			return false;
		}

		// Number: 36
		if (!(HasMember(first, 3) && (HasMember(second, 6) || HasMember(second, 9))) 
			&& (!(HasMember(second, 3) && (HasMember(first, 6) || HasMember(first, 9))))) {
			return false;
		}

		// Number: 01
		if (!HasMember(second, 1) && (!(HasMember(second, 0) && HasMember(first, 1)))) {
			return false;
		}

		// Number: 04
		if (!HasMember(second, 4) && (!(HasMember(second, 0) && HasMember(first, 4)))) {
			return false;
		}

		// Number: 25
		if (!(HasMember(first, 2) && HasMember(second, 5)) && (!(HasMember(second, 2) && HasMember(first, 5)))) {
			return false;
		}

		// Number: 81
		return !(!(HasMember(first, 8) && HasMember(second, 1)) 
			 && (!(HasMember(second, 8) && HasMember(first, 1))));
	}

private:
	bool HasMember(const std::vector<int>& numbers, int value) {
		for(const auto& e : numbers) {
			if(e == value) {
				return true;
			}
			else if(e > value) {
				return false;
			}
		}
		return false;
	}
	
	void GenerateSet(int amount = 0, int last = -1) {
		if(amount > 5) {
			entries.push_back(vals);
			return;
		}
		for(int i = last + 1; i <= amount + 4; i++) {
			vals.push_back(i);
			GenerateSet(amount + 1, i);
			vals.pop_back();
		}
	}

private: // Member variables
	std::vector<std::vector<int>> entries;
	std::vector<int> vals;

public:
	auto Start() -> decltype(entries.begin()) {
		return entries.begin();
	}

	auto End() -> decltype(entries.end()) {
		return entries.end();
	}

};


int main() {
    int solution = 0;

    Solver solver;
	std::vector<std::vector<int>> first(solver.Start(), solver.End() - 1);
	std::vector<std::vector<int>> second(first.size());

	int i = 1;
	for(const auto& e : first) {
		second.assign(solver.Start() + i, solver.End());
		for(const auto& f : second) {
			if(solver.Check(e, f)) {
				solution++;
			}
		}
		++i;
	}

	std::cout << "Solution: " << solution << std::endl;
}