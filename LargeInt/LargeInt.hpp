/**
 * The MIT License (MIT)
 * 
 * Copyright (c) 2016 Floris Velleman
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <sstream>

#include <algorithm>
#include <cmath>
#include <cstring>
#include <type_traits>

// If Qt is defined the class will have some overloads for QString
#ifdef QT_CORE_LIB
#include <QString>
#endif


class LargeInt
{
	using ContainerType = std::vector<int>;

public: // Constructors
	explicit LargeInt();
	
	explicit LargeInt(int number);
	explicit LargeInt(double number);
	explicit LargeInt(const std::string& number);
	// Default copy/move is fine for LargeInt

public: // Assignment and Unary
	const LargeInt& operator=(int number);
	const LargeInt& operator=(double number);
	const LargeInt& operator=(const std::string& number);
	// Default assign/move is fine for LargeInt

	const LargeInt& operator++();
	const LargeInt& operator--();
	LargeInt operator++(int);
	LargeInt operator--(int);

public: // Operators +-*/%
	const LargeInt& operator+=(int rhs);
	const LargeInt& operator+=(double rhs);
	const LargeInt& operator+=(const std::string& rhs);
	const LargeInt& operator+=(const LargeInt& rhs);
	
	const LargeInt& operator-=(int rhs);
	const LargeInt& operator-=(double rhs);
	const LargeInt& operator-=(const std::string& rhs);
	const LargeInt& operator-=(const LargeInt& rhs);
	
	const LargeInt& operator*=(int rhs);
	const LargeInt& operator*=(double rhs);
	const LargeInt& operator*=(const std::string& rhs);
	const LargeInt& operator*=(const LargeInt& rhs);
	
	const LargeInt& operator/=(int rhs);
	const LargeInt& operator/=(double rhs);
	const LargeInt& operator/=(const std::string& rhs);
	const LargeInt& operator/=(const LargeInt& rhs);
	
	const LargeInt& operator%=(int rhs);
	const LargeInt& operator%=(double rhs);
	const LargeInt& operator%=(const std::string& rhs);
	const LargeInt& operator%=(const LargeInt& rhs);

	LargeInt operator-() const;
	
	LargeInt operator+(int rhs) const;
	LargeInt operator+(double rhs) const;
	LargeInt operator+(const std::string& rhs) const;
	LargeInt operator+(const LargeInt& rhs) const;
	
	LargeInt operator-(int rhs) const;
	LargeInt operator-(double rhs) const;
	LargeInt operator-(const std::string& rhs) const;
	LargeInt operator-(const LargeInt& rhs) const;
	
	LargeInt operator*(int rhs) const;
	LargeInt operator*(double rhs) const;
	LargeInt operator*(const std::string& rhs) const;
	LargeInt operator*(const LargeInt& rhs) const;
	
	LargeInt operator/(int rhs) const;
	LargeInt operator/(double rhs) const;
	LargeInt operator/(const std::string& rhs) const;
	LargeInt operator/(const LargeInt& rhs) const;
	
	LargeInt operator%(int rhs) const;
	LargeInt operator%(double rhs) const;
	LargeInt operator%(const std::string& rhs) const;
	LargeInt operator%(const LargeInt& rhs) const;

public: // Logical operators
	bool operator==(int rhs) const;
	bool operator==(double rhs) const;
	bool operator==(const std::string& rhs) const;
	bool operator==(const LargeInt& rhs) const;
	
	bool operator!=(int rhs) const;
	bool operator!=(double rhs) const;
	bool operator!=(const std::string& rhs) const;
	bool operator!=(const LargeInt& rhs) const;
	
	bool operator<(int rhs) const;
	bool operator<(double rhs) const;
	bool operator<(const std::string& rhs) const;
	bool operator<(const LargeInt& rhs) const;

	bool operator<=(int rhs) const;
	bool operator<=(double rhs) const;
	bool operator<=(const std::string& rhs) const;
	bool operator<=(const LargeInt& rhs) const;

	bool operator>(int rhs) const;
	bool operator>(double rhs) const;
	bool operator>(const std::string& rhs) const;
	bool operator>(const LargeInt& rhs) const;

	bool operator>=(int rhs) const;
	bool operator>=(double rhs) const;
	bool operator>=(const std::string& rhs) const;
	bool operator>=(const LargeInt& rhs) const;

public: // Utility
	std::string toStdString() const;
	int toInteger() const;
	double toDouble() const;
	float toFloat() const;

public:	// Mathematical functions
	void power(int pow);
	void power(double pow);
	void power(const std::string& pow);
	void power(const LargeInt& pow);
	
public: // Interface hard coded values
	static const LargeInt zero;
	static const LargeInt one;
	static const LargeInt two;

private: // Helper functions
	static int findD(const LargeInt& R, const LargeInt& D);
	static void digitIncrement(int factor, std::vector<int>& val);

	void stringToLargeInt(const std::string& str);

	template <typename T>
	void convertNumber(T t);
	void remake(bool lead = false, bool vsign = false);

	bool determineSize();
	void truncateToBase();

private:
	//Output overloads
	friend std::ostream& operator<<(std::ostream &s, const LargeInt& n);
	friend std::istream& operator>>(std::istream &s, LargeInt& n);

#ifdef QT_CORE_LIB
public: // Qt specific code
	explicit LargeInt(const QString& number);

	const LargeInt& operator=(const QString& number);

	const LargeInt& operator+=(const QString& rhs);
	const LargeInt& operator-=(const QString& rhs);
	const LargeInt& operator*=(const QString& rhs);
	const LargeInt& operator/=(const QString& rhs);
	const LargeInt& operator%=(const QString& rhs);

	LargeInt operator+(const QString& rhs) const;
	LargeInt operator-(const QString& rhs) const;
	LargeInt operator*(const QString& rhs) const;
	LargeInt operator/(const QString& rhs) const;
	LargeInt operator%(const QString& rhs) const;

	bool operator==(const QString& rhs) const;
	bool operator!=(const QString& rhs) const;
	bool operator<(const QString& rhs) const;
	bool operator<=(const QString& rhs) const;
	bool operator>(const QString& rhs) const;
	bool operator>=(const QString& rhs) const;

	QString toQString() const;
	void power(const QString& pow);

	void qstringToLargeInt(const QString& str);
#endif

private:
	ContainerType number;
	bool sign; // True means >= 0, False means < 0

};

/**
 * Initialize the static variables
 */
const LargeInt LargeInt::zero = LargeInt(0);
const LargeInt LargeInt::one = LargeInt(1);
const LargeInt LargeInt::two = LargeInt(2);

/**
 * Default constructor that adds a 0.
 */
LargeInt::LargeInt() : sign(true) 
{
	number.push_back(0);
}

/**
 * Sets the number as the LargeInt value
 */
LargeInt::LargeInt(int number)
{
	convertNumber<int>(number);
}

/**
 * Sets the number as the LargeInt value
 * rounds the double and casts to int
 */
LargeInt::LargeInt(double number)
{
	convertNumber<int>(std::round(number));
}

/**
 * Turns an std::string into a LargeInt
 * will give LargeInt(0) on any parse error
 */
LargeInt::LargeInt(const std::string& number) 
{
	stringToLargeInt(number);
}

/**
 * Turns the number into a LargeInt and returns itself
 */
inline
const LargeInt& LargeInt::operator=(int number) 
{
	convertNumber<int>(number);
	return *this;
}

/**
 * Turns the number into a LargeInt and returns itself
 * rounds the double and casts to int
 */
inline
const LargeInt& LargeInt::operator=(double number) 
{
	convertNumber<int>(std::round(number));
	return *this;
}

/**
 * Turns the std::string into a LargeInt and returns itself
 * will give LargeInt(0) on any parse error
 */
inline
const LargeInt& LargeInt::operator=(const std::string& str) 
{
	stringToLargeInt(str);
	return *this;
}

/**
 * Post-increments the number by 1
 */
inline
const LargeInt& LargeInt::operator++() 
{
	number[0] += (sign ? 1 : -1);
	remake(false, true);
	return *this;
}

/**
 * Post-decrements the number by 1
 */
inline
const LargeInt& LargeInt::operator--() 
{
	number[0] -= (sign ? 1 : -1);
	remake(false, true);
	return *this;
}

/**
 * Pre-increments the number by 1
 */
inline
LargeInt LargeInt::operator++(int) 
{
	LargeInt result = *this;
	number[0] += (sign ? 1 : -1);
	remake(false, true);
	return result;
}

/**
 * Pre-decrements the number by 1
 */
inline
LargeInt LargeInt::operator--(int) 
{
	LargeInt result = *this;
	number[0] -= (sign ? 1 : -1);
	remake(false, true);
	return result;
}

/**
 * Increments the LargeInt by the rhs int
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator+=(int rhs) 
{
	*this += LargeInt(rhs);
	return *this;
}

/**
 * Increments the LargeInt by the rhs double
 * rounds the double and casts to int
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator+=(double rhs) 
{
	*this += LargeInt(rhs);
	return *this;
}

/**
 * Increments the LargeInt by the rhs std::string
 * if parsing fails will increment by LargeInt(0).
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator+=(const std::string& rhs) 
{
	*this += LargeInt(rhs);
	return *this;
}

/**
 * Increments the LargeInt by using division
 * returns the result of adding the two
 */
const LargeInt& LargeInt::operator+=(const LargeInt& rhs) 
{
	const int nSize = number.size();
	const int rnSize = rhs.number.size();

	// Small optimization
	if (rnSize > nSize)
		number.resize(rnSize, 0);
	
	for (int i = 0; i < nSize; ++i) {
		const int rem = (i < rnSize ? 
			(rhs.sign ? rhs.number[i] : -rhs.number[i]) : 0);
		const int sig = (sign ? number[i] : -number[i]);
		number[i] = sig + rem;
	}
	remake();
	return *this;
}

/**
 * Decrements the LargeInt by the rhs int
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator-=(int rhs)
{
	*this -= LargeInt(rhs);
	return *this;
}

/**
 * Decrements the LargeInt by the rhs double
 * rounds the double and casts to int
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator-=(double rhs)
{
	*this -= LargeInt(rhs);
	return *this;
}

/**
 * Decrements the LargeInt by the rhs std::string
 * if parsing fails will decrement by LargeInt(0).
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator-=(const std::string& rhs)
{
	*this -= LargeInt(rhs);
	return *this;
}

/**
 * Decrements the LargeInt by using division
 */
const LargeInt& LargeInt::operator-=(const LargeInt& rhs) 
{
	const int nSize = number.size();
	const int rnSize = rhs.number.size();

	if (rnSize > nSize) {
		number.resize(rnSize, 0);
	}
	for (int i = 0; i < nSize; ++i) {
		const int rem = (i < rnSize ? 
			(rhs.sign ? rhs.number[i] : -rhs.number[i]) : 0);
		const int seg = (sign ? number[i] : -number[i]);
		number[i] = seg - rem;
	}
	remake();
	return *this;
}

/**
 * Multiplies the LargeInt by the rhs int
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator*=(int rhs)
{
	*this *= LargeInt(rhs);
	return *this;
}

/**
 * Multiplies the LargeInt by the rhs double
 * rounds the double and casts to int
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator*=(double rhs)
{
	*this *= LargeInt(rhs);
	return *this;
}

/**
 * Decrements the LargeInt by the rhs std::string
 * if parsing fails will multiply by LargeInt(0).
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator*=(const std::string& rhs)
{
	*this *= LargeInt(rhs);
	return *this;
}

/**
 * Multiplies the LargeInt by using the digit increment
 */
const LargeInt& LargeInt::operator*=(const LargeInt& rhs) 
{
	int factor = rhs < LargeInt::zero ? (-rhs).toInteger() : rhs.toInteger();
	bool oSign = sign;
	digitIncrement(factor, number);
	remake();
	sign = (number.size() == 1 && number[0] == 0) ? 
		true : (oSign == (rhs >= 0));
	return *this;
}

/**
 * Divides the LargeInt by the rhs int
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator/=(int rhs)
{
	*this /= LargeInt(rhs);
	return *this;
}

/**
 * Divides the LargeInt by the rhs double
 * rounds the double and casts to int
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator/=(double rhs)
{
	*this /= LargeInt(rhs);
	return *this;
}

/**
 * Divides the LargeInt by the rhs std::string
 * if parsing fails will not divide.
 * if dividing by zero will return the number and 
 * log an error to cerr.
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator/=(const std::string& rhs)
{
	*this /= LargeInt(rhs);
	return *this;
}

/**
 * Divides the LargeInt 
 * \todo: might need a small speedup
 */
const LargeInt& LargeInt::operator/=(const LargeInt& rhs) 
{
	if (rhs == zero) {
		std::cerr << "Division by zero!" << std::endl;
		return *this;
	}
	LargeInt R;
	LargeInt D = (rhs.sign ? rhs : -rhs);
	LargeInt N = (sign ? *this : -*this);

	bool oSign = sign;
	number.clear();
	number.resize(N.number.size(), 0);

	int i = static_cast<int>(N.number.size()) - 1;
	for (; i >= 0; --i) {
		R.number.insert(R.number.begin(), 0);
		R.number[0] = N.number[i];
		R.remake(true);
		int cnt = findD(R, D);
		R -= D * cnt;
		number[i] += cnt;
	}
	remake();
	sign = (number.size() == 1 && number[0] == 0) ? 
		true : (oSign == rhs.sign);
	return *this;
}

/**
 * Divides the LargeInt by the rhs int 
 * and returns the remainder
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator%=(int rhs)
{
	*this %= LargeInt(rhs);
	return *this;
}

/**
 * Divides the LargeInt by the rhs double 
 * and returns the remainder
 * rounds the double and casts to int
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator%=(double rhs)
{
	*this %= LargeInt(rhs);
	return *this;
}

/**
 * Divides the LargeInt by the rhs std::string 
 * and returns the remainder
 * if parsing fails will not divide.
 * if dividing by zero will return the number 
 * and log an error to cerr.
 * \todo: this is a bit lazy
 */
inline
const LargeInt& LargeInt::operator%=(const std::string& rhs)
{
	*this %= LargeInt(rhs);
	return *this;
}

/**
 * Divides the LargeInt by the rhs LargeInt
 * and returns the remainder.
 * \todo: might need a small speedup 
 */
const LargeInt& LargeInt::operator%=(const LargeInt& rhs) 
{
	if (rhs == zero) {
		std::cerr << "Division by zero!" << std::endl;
		return zero;
	}
	LargeInt D = (rhs.sign ? rhs : -rhs);
	LargeInt N = (sign ? *this : -*this);

	bool oSign = sign;
	number.clear();

	int i = static_cast<int>(N.number.size()) - 1;
	for (; i >= 0; --i) {
		number.insert(number.begin(), 0);
		number[0] = N.number[i];
		remake(true);
		*this -= D * findD(*this, D);
	}
	remake();
	sign = (number.size() == 1 && number[0] == 0) ? true : oSign;
	return *this;
}

/**
 * This is for prefixing -, which flips the sign
 */
LargeInt LargeInt::operator-() const 
{
	LargeInt result = *this;
	result.sign = !sign;
	return result;
}

/**
 * Adds the LargeInt to the rhs int
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator+(int rhs) const
{
	return *this + LargeInt(rhs);
}

/**
 * Adds the LargeInt to the rhs double
 * rounds the double and casts to int
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator+(double rhs) const
{
	return *this + LargeInt(rhs);
}

/**
 * Adds the LargeInt to the rhs std::string
 * if parsing fails will increment by LargeInt(0).
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator+(const std::string& rhs) const
{
	return *this + LargeInt(rhs);
}

/**
 * Adds the LargeInt to the rhs LargeInt
 * resizes to largest and adds.
 */
LargeInt LargeInt::operator+(const LargeInt& rhs) const 
{
	const auto nSize = number.size();
	const auto rnSize = rhs.number.size();
	LargeInt result;

	result.number.resize(nSize > rnSize ? nSize : rnSize, 0);
	for (unsigned int i = 0; i < nSize || i < rnSize; ++i) {
		result.number[i] = (i < nSize ? 
			(sign ? number[i] : -number[i]) : 0) 
			+ (i < rnSize ? 
			(rhs.sign ? rhs.number[i] : -rhs.number[i]) : 0);
	}
	result.remake();
	return result;
}

/**
 * Decrements the LargeInt by the rhs int
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator-(int rhs) const
{
	return *this - LargeInt(rhs);
}

/**
 * Decrements the LargeInt by the rhs double
 * rounds the double and casts to int
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator-(double rhs) const
{
	return *this - LargeInt(rhs);
}

/**
 * Decrements the LargeInt by the rhs std::string
 * if parsing fails will increment by LargeInt(0).
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator-(const std::string& rhs) const
{
	return *this - LargeInt(rhs);
}

/**
 * Decrements the LargeInt by the rhs LargeInt
 * resizes to largest and decrements.
 */
LargeInt LargeInt::operator-(const LargeInt& rhs) const 
{
	const auto nSize = number.size();
	const auto rnSize = rhs.number.size();
	LargeInt result;

	result.number.resize(nSize > rnSize ? nSize : rnSize, 0);
	for (unsigned int i = 0; i < nSize || i < rnSize; ++i) {
		result.number[i] = (i < nSize ? 
			(sign ? number[i] : -number[i]) : 0) 
			- (i < rnSize ?
			(rhs.sign ? rhs.number[i] : -rhs.number[i]) : 0);
	}
	result.remake();
	return result;
}

/**
 * Multiplies the LargeInt by the rhs int
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator*(int rhs) const
{
	return *this * LargeInt(rhs);
}

/**
 * Multiplies the LargeInt by the rhs double
 * rounds the double and casts to int
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator*(double rhs) const
{
	return *this * LargeInt(rhs);
}

/**
 * Multiplies the LargeInt by the rhs std::string
 * if parsing fails will increment by LargeInt(0).
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator*(const std::string& rhs) const
{
	return *this * LargeInt(rhs);
}

/**
 * Multiplies the LargeInt by the rhs LargeInt
 * \todo: This does not win a beauty contest, but it is pretty fast.
 */
LargeInt LargeInt::operator*(const LargeInt& rhs) const 
{
	const int nSize = number.size();
	const int rnSize = rhs.number.size();
	const int baseDivisor = static_cast<int>(std::pow(10, 9));

	LargeInt result;
	result.number.resize(nSize + rnSize, 0);
	long long carry = 0;
	auto digit = 0;

	for (;; ++digit) {
		long long oldcarry = carry;
		carry /= baseDivisor;
		result.number[digit] = static_cast<int>(oldcarry - carry * baseDivisor);

		bool found = false;
		for (int i = digit < rnSize ? 0 : digit - rnSize + 1; i < nSize && i <= digit; ++i) {
			long long pval = result.number[digit] + number[i] 
				* static_cast<long long>(rhs.number[digit - i]);

			if (pval >= baseDivisor || pval <= -baseDivisor) {
				long long quot = pval / baseDivisor;
				carry += quot;
				pval -= quot * baseDivisor;
			}
			result.number[digit] = static_cast<int>(pval);
			found = true;
		}
		if (!found)
			break;
	}
	for (; carry > 0; ++digit) {
		result.number[digit] = static_cast<int>(carry % baseDivisor);
		carry /= baseDivisor;
	}
	result.remake();
	result.sign = (result.number.size() == 1 && result.number[0] == 0)
		? true : (sign == rhs.sign);
	return result;
}

/**
 * Divides the LargeInt by the rhs int
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator/(int rhs) const
{
	return *this / LargeInt(rhs);
}

/**
 * Divides the LargeInt by the rhs double
 * rounds the double and casts to int
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator/(double rhs) const
{
	return *this / LargeInt(rhs);
}

/**
 * Divides the LargeInt by the rhs std::string
 * if parsing fails will not divide.
 * if dividing by zero will return the number and
 * log an error to cerr.
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator/(const std::string& rhs) const
{
	return *this / LargeInt(rhs);
}

/**
 * Divides the LargeInt
 * \todo: might need a small speedup
 */
LargeInt LargeInt::operator/(const LargeInt& rhs) const 
{
	if (rhs == zero) {
		std::cerr << "Division by zero!" << std::endl;
		return zero;
	}
	LargeInt Q;
	LargeInt R;
	LargeInt D = (rhs.sign ? rhs : -rhs);
	LargeInt N = (sign ? *this : -*this);

	Q.number.resize(N.number.size(), 0);
	for (int i = static_cast<int>(N.number.size()) - 1; i >= 0; --i) {
		R.number.insert(R.number.begin(), 0);
		R.number[0] = N.number[i];
		R.remake(true);
		int cnt = findD(R, D);
		R -= D * cnt;
		Q.number[i] += cnt;
	}
	Q.remake();
	Q.sign = (Q.number.size() == 1 && Q.number[0] == 0) ? true : (sign == rhs.sign);
	return Q;
}

/**
 * Divides the LargeInt by the rhs int
 * and returns the remainder
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator%(int rhs) const
{
	return *this % LargeInt(rhs);
}

/**
 * Divides the LargeInt by the rhs double
 * and returns the remainder
 * rounds the double and casts to int
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator%(double rhs) const
{
	return *this % LargeInt(rhs);
}

/**
 * Divides the LargeInt by the rhs std::string
 * and returns the remainder
 * if parsing fails will not divide.
 * if dividing by zero will return the number
 * and log an error to cerr.
 * \todo: this is a bit lazy
 */
inline
LargeInt LargeInt::operator%(const std::string& rhs) const
{
	return *this % LargeInt(rhs);
}

/**
 * Divides the LargeInt by the rhs LargeInt
 * and returns the remainder.
 * \todo: might need a small speedup
 */
LargeInt LargeInt::operator%(const LargeInt& rhs) const 
{
	if (rhs == zero) {
		std::cerr << "Division by zero!" << std::endl;
		return zero;
	}
	LargeInt R;
	LargeInt D = (rhs.sign ? rhs : -rhs);
	LargeInt N = (sign ? *this : -*this);

	for (int i = static_cast<int>(N.number.size()) - 1; i >= 0; --i) {
		R.number.insert(R.number.begin(), 0);
		R.number[0] = N.number[i];
		R.remake(true);
		R -= D * findD(R, D);
	}

	R.remake();
	R.sign = (R.number.size() == 1 && R.number[0] == 0) ? true : sign;
	return R;
}

/**
 * Logical
 */
inline
bool LargeInt::operator==(int rhs) const 
{
	return *this == LargeInt(rhs);
}

/**
 * rounds the double and casts to int
 */
inline
bool LargeInt::operator==(double rhs) const 
{
	return *this == LargeInt(rhs);
}

/**
 * if parsing fails will compare with LargeInt(0)
 */
inline
bool LargeInt::operator==(const std::string& rhs) const 
{
	return *this == LargeInt(rhs);
}

bool LargeInt::operator==(const LargeInt& rhs) const 
{
	const int nSize = number.size();
	const int rnSize = rhs.number.size();

	if (sign != rhs.sign || nSize != rnSize) 
		return false;
	
	for (int i = nSize - 1; i >= 0; --i) {
		if (number[i] != rhs.number[i]) 
			return false;
	}
	return true;
}

inline
bool LargeInt::operator!=(int rhs) const 
{
	return *this != LargeInt(rhs);
}

/**
 * rounds the double and casts to int
 */
inline
bool LargeInt::operator!=(double rhs) const 
{
	return *this != LargeInt(rhs);
}

/**
 * if parsing fails will compare with LargeInt(0)
 */
inline
bool LargeInt::operator!=(const std::string& rhs) const 
{
	return *this != LargeInt(rhs);
}

inline
bool LargeInt::operator!=(const LargeInt& rhs) const 
{
	return !(*this == rhs);
}

inline
bool LargeInt::operator<(int rhs) const 
{
	return *this < LargeInt(rhs);
}

/**
 * rounds the double and casts to int
 */
inline
bool LargeInt::operator<(double rhs) const 
{
	return *this < LargeInt(rhs);
}

/**
 * if parsing fails will compare with LargeInt(0)
 */
inline
bool LargeInt::operator<(const std::string& rhs) const 
{
	return *this < LargeInt(rhs);
}

bool LargeInt::operator<(const LargeInt& rhs) const 
{
	const int nSize = number.size();
	const int rnSize = rhs.number.size();

	if (sign && !rhs.sign)
		return false;
	if (!sign && rhs.sign)
		return true;
	if (nSize > rnSize)
		return !sign;
	if (nSize < rnSize)
		return sign;
	
	for (int i = nSize - 1; i >= 0; --i) {
		if (number[i] < rhs.number[i])
			return sign;
		if (number[i] > rhs.number[i])
			return !sign;
	}
	return false;
}

inline
bool LargeInt::operator<=(int rhs) const 
{
	return *this < LargeInt(rhs);
}

/**
 * rounds the double and casts to int
 */
inline
bool LargeInt::operator<=(double rhs) const 
{
	return *this < LargeInt(rhs);
}

/**
 * if parsing fails will compare with LargeInt(0)
 */
inline
bool LargeInt::operator<=(const std::string& rhs) const 
{
	return *this < LargeInt(rhs);
}

bool LargeInt::operator<=(const LargeInt& rhs) const 
{
	return (*this < rhs);
}

inline
bool LargeInt::operator>(int rhs) const 
{
	return *this < LargeInt(rhs);
}

/**
 * rounds the double and casts to int
 */
inline
bool LargeInt::operator>(double rhs) const 
{
	return *this < LargeInt(rhs);
}

/**
 * if parsing fails will compare with LargeInt(0)
 */
inline
bool LargeInt::operator>(const std::string& rhs) const 
{
	return *this < LargeInt(rhs);
}

bool LargeInt::operator>(const LargeInt& rhs) const 
{
	return !(*this < rhs);
}

inline
bool LargeInt::operator>=(int rhs) const 
{
	return *this < LargeInt(rhs);
}

/**
 * rounds the double and casts to int
 */
inline
bool LargeInt::operator>=(double rhs) const 
{
	return *this < LargeInt(rhs);
}

/**
 * if parsing fails will compare with LargeInt(0)
 */
inline
bool LargeInt::operator>=(const std::string& rhs) const 
{
	return *this < LargeInt(rhs);
}

bool LargeInt::operator>=(const LargeInt& rhs) const 
{
	return !(*this < rhs);
}

/**
 * Turns the LargeInt into an std::string
 */
std::string LargeInt::toStdString() const 
{
	std::string str = "";
	std::for_each(std::begin(number), std::end(number), [&](int e) { str += std::to_string(e); });
	return str;
}

/**
 * Turns the LargeInt into an int
 * returns 0 if std::stoi throws
 */
int LargeInt::toInteger() const 
{
	std::string str = "";
	std::for_each(std::begin(number), std::end(number), [&](int e) { str += std::to_string(e); });
	try {
		return std::stoi(str);
	}
	catch (...) {
		return 0;
	}
}

/**
 * Turns the LargeInt into a double
 * returns 0 if std::stod throws
 */
double LargeInt::toDouble() const 
{
	std::string str = "";
	std::for_each(std::begin(number), std::end(number), [&](int e) { str += std::to_string(e); });
	try {
		return std::stod(str);
	}
	catch (...) {
		return 0.0;
	}
}

/**
 * Turns the LargeInt into a float
 * returns 0 if std::stof throws
 */
float LargeInt::toFloat() const 
{
	std::string str = "";
	std::for_each(std::begin(number), std::end(number), [&](int e) { str += std::to_string(e); });
	try {
		return std::stof(str);
	}
	catch (...) {
		return 0.0;
	}
}

/**
 * Transforms into this^pow
 */
void LargeInt::power(int pow) 
{
	for (int i = 0; i < pow; i++) 
		*this *= *this;
}

/**
 * Transforms into this^pow
 * Rounds the double and casts it to an int
 */
void LargeInt::power(double pow) 
{
	for (int i = 0; i < std::round(pow); i++) 
		*this *= *this;
}

/**
 * Transforms into this^pow
 * if parsing fails will compare will return this
 */
void LargeInt::power(const std::string& pow) 
{
	auto num = LargeInt(pow);
	if (num == LargeInt::zero) {
		*this = LargeInt::one;
		return;
	}

	for (int i = 0; i < num.toInteger(); i++) 
		*this *= *this;
}

/**
 * Transforms into this^pow
 */
void LargeInt::power(const LargeInt& pow) 
{
	for (int i = 0; i < pow.toInteger(); i++) 
		*this *= *this;
}

/**
 * Find D utility function
 */
int LargeInt::findD(const LargeInt& R, const LargeInt& D) 
{
	int min = 0;
	int max = 999999999;

	while (max - min > 0) {
		int avg = max + min;
		int havg = avg / 2;

		avg = avg - havg * 2 ? (havg + 1) : havg;
		LargeInt prod = D * avg;

		if (R == prod) {
			return avg;
		}
		else if (R > prod) {
			min = avg;
		}
		else {
			max = avg - 1;
		}
	}

	return min;
}

/**
 * Used for multiplication
 */
void LargeInt::digitIncrement(int factor, std::vector<int>& val) 
{
	const int baseDivisor = static_cast<int>(std::pow(10, 9));

	int carry = 0;
	for (unsigned int i = 0; i < val.size(); ++i) {
		long long pval = val[i] * static_cast<long long>(factor)+carry;

		if (pval >= baseDivisor || pval <= -baseDivisor) {

			carry = static_cast<int>(pval / baseDivisor);
			pval -= carry * baseDivisor;
		}
		else {
			carry = 0;
		}
		val[i] = static_cast<int>(pval);
	}
	if (carry > 0) 
		val.push_back(carry);
}

/**
 * Transforms a string to a LargeInteger
 * will return 0 if it has the wrong format
 */
void LargeInt::stringToLargeInt(const std::string &str) {
	sign = true;
	number.clear();

	number.reserve(str.size() / 9 + 1);
	int i = static_cast<int>(str.size()) - 9;

	for (; i >= 0; i -= 9)
		number.push_back(std::stoi(str.substr(i, 9)));

	if (i > -9) {
		std::string strs = str.substr(0, i + 9);

		if (strs.size() == 1 && strs[0] == '-') {
			sign = false;
		}
		else {
			int val;
			try {
				val = std::stoi(strs);
			}
			catch (...) {
				number.clear();
				sign = true;
				return;
			}
			number.push_back(val);
		}
	}
	if (number.back() < 0) {
		number.back() = -number.back();
		sign = false;
	}
	remake(true);
}

/**
 * Changes a number into a LargeInt
 * also sets the sign
 */
template <typename T>
void LargeInt::convertNumber(T t) {
	sign = (t >= 0);

	const int baseDivisor = static_cast<int>(std::pow(10, 9));

	if (!sign)
		t = -t;

	do {
		std::div_t divR = div(t, baseDivisor);
		number.push_back(divR.rem);
		t = divR.quot;
	} while (t > 0);
}

/**
 * Rebuilds the LargeInt because digits fall out of: 0 < x < 9
 */
void LargeInt::remake(bool lead, bool vsign) {
	if (!lead) {
		truncateToBase();

		if (determineSize()) {
			sign = ((number.size() == 1 && number[0] == 0) || !vsign) ? true : sign;
		}
		else {
			sign = vsign ? !sign : false;
			for (unsigned int i = 0; i < number.size(); ++i) 
				number[i] = std::abs(number[i]);
		}
	}
	for (int i = static_cast<int>(number.size()) - 1; i > 0; --i) {
		if (number[i] != 0) {
			break;
		}
		else {
			number.erase(number.begin() + i);
		}
	}
}

bool LargeInt::determineSize() {
	bool isPositive = true;
	int i = static_cast<int>((number.size())) - 1;
	const int baseDivisor = static_cast<int>(std::pow(10, 9));
	const int max = 999999999;

	for (; i >= 0; --i) {
		if (number[i] != 0) {
			isPositive = number[i--] > 0;
			break;
		}
	}

	if (isPositive) {
		for (; i >= 0; --i) {
			if (number[i] < 0) {
				int k = 0, index = i + 1;

				for (; static_cast<size_t>(index) < number.size() && number[index] == 0; ++k, ++index); {
					number[index] -= 1;
					number[i] += baseDivisor;

					for (; k > 0; --k) {
						number[i + k] = max;
					}
				}
			}
		}
	}
	else {
		for (; i >= 0; --i) {
			if (number[i] > 0) {
				int k = 0, index = i + 1;
				for (; static_cast<size_t>(index) < number.size() && number[index] == 0; ++k, ++index); {
					number[index] += 1;
					number[i] -= baseDivisor;

					for (; k > 0; --k) {
						number[i + k] = -max;
					}
				}
			}
		}
	}

	return isPositive;
}

void LargeInt::truncateToBase()
{
	const int baseDivisor = static_cast<int>(std::pow(10, 9));

	for (unsigned int i = 0; i < number.size(); ++i) {
		if (number[i] >= baseDivisor || number[i] <= -baseDivisor) {
			div_t dt = div(number[i], baseDivisor);
			number[i] = dt.rem;

			if (i + 1 >= number.size()) {
				number.push_back(dt.quot);
			}
			else {
				number[i + 1] += dt.quot;
			}
		}
	}
}

/**
* Output overload for istream
*/
inline
std::istream& operator>>(std::istream& s, LargeInt& n)
{
	std::string str;
	s >> str;
	n.stringToLargeInt(str);
	return s;
}

/**
* Overloads the << operator for LargeInt so you can print the numbers.
* This will add a `-` if it is a negative number.
*/
inline
std::ostream& operator<<(std::ostream& s, const LargeInt& n)
{
	if (!n.sign)
		s << '-';

	const int start = static_cast<int>(n.number.size()) - 1;
	if (start >= 0) {
		s << n.number[start];
	}
	for (int i = start - 1; i >= 0; --i) {
		s << std::setfill('0') << std::setw(9) << n.number[i];
	}
	return s;
}

#ifdef QT_CORE_LIB
// Qt specific code
//\todo: comments
LargeInt::LargeInt(const QString& number)
{
	qstringToLargeInt(number);
}

inline
const LargeInt& LargeInt::operator=(const QString& number)
{
	qstringToLargeInt(number);
	return *this;
}

inline
const LargeInt& LargeInt::operator+=(const QString& rhs)
{
	*this += LargeInt(rhs);
	return *this;
}

inline
const LargeInt& LargeInt::operator-=(const QString& rhs)
{
	*this -= LargeInt(rhs);
	return *this;
}

inline
const LargeInt& LargeInt::operator*=(const QString& rhs)
{
	*this *= LargeInt(rhs);
	return *this;
}

inline
const LargeInt& LargeInt::operator/=(const QString& rhs)
{
	*this /= LargeInt(rhs);
	return *this;
}

inline
const LargeInt& LargeInt::operator%=(const QString& rhs)
{
	*this %= LargeInt(rhs);
	return *this;
}

inline
LargeInt LargeInt::operator+(const QString& rhs) const
{
	return *this + LargeInt(rhs);
}

inline
LargeInt LargeInt::operator-(const QString& rhs) const
{
	return *this - LargeInt(rhs);
}

inline
LargeInt LargeInt::operator*(const QString& rhs) const
{
	return *this * LargeInt(rhs);
}

inline
LargeInt LargeInt::operator/(const QString& rhs) const
{
	return *this / LargeInt(rhs);
}

inline
LargeInt LargeInt::operator%(const QString& rhs) const
{
	return *this % LargeInt(rhs);
}

inline
bool LargeInt::operator==(const QString& rhs) const
{
	return *this == LargeInt(rhs);
}

inline
bool LargeInt::operator!=(const QString& rhs) const
{
	return *this != LargeInt(rhs);
}

inline
bool LargeInt::operator<(const QString& rhs) const
{
	return *this < LargeInt(rhs);
}

inline
bool LargeInt::operator<=(const QString& rhs) const
{
	return *this <= LargeInt(rhs);
}

inline
bool LargeInt::operator>(const QString& rhs) const
{
	return *this > LargeInt(rhs);
}

inline
bool LargeInt::operator>=(const QString& rhs) const
{
	return *this >= LargeInt(rhs);
}

QString LargeInt::toQString() const
{
	QString str = "";
	std::for_each(std::begin(number), std::end(number), [&](int e) { str += QString::number(e); });
	return str;
}

void LargeInt::power(const QString& pow)
{
	auto num = LargeInt(pow);
	if (num == LargeInt::zero) {
		*this = LargeInt::one;
		return;
	}

	for (int i = 0; i < num.toInteger(); i++)
		*this *= *this;
}


void LargeInt::qstringToLargeInt(const QString& str)
{
	stringToLargeInt(str.toStdString());
}
#endif
