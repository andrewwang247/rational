/**
 * @file rational.cpp
 * @author Andrew Wang (siweiw9@gmail.com)
 * @brief Implementation for exact representation of rational numbers.
 * @version 0.1
 * @date 2022-02-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "rational.h"

#include <cstdlib>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <utility>
using integer = std::int64_t;
using std::abs;
using std::gcd;
using std::invalid_argument;
using std::ostream;

void rational::simplify() {
  const auto div = gcd(num, denom);
  num /= div;
  denom /= div;
  if ((num < 0) ^ (denom < 0)) {
    num = -abs(num);
    denom = abs(denom);
  } else if ((num < 0) && (denom < 0)) {
    num = -num;
    denom = -denom;
  }
}

rational::rational(integer_t value) : num(value), denom(1) {}

rational::rational(integer_t numerator, integer_t denominator)
    : num(numerator), denom(denominator) {
  if (denom == 0) {
    throw invalid_argument("Denominator must be non-zero.");
  }
  simplify();
}

rational::rational(const rational& other)
    : num(other.num), denom(other.denom) {}

rational& rational::operator=(const rational& other) {
  num = other.num;
  denom = other.denom;
  return *this;
}

integer rational::numerator() const { return num; }

integer rational::denominator() const { return denom; }

double rational::value() const {
  return static_cast<double>(num) / static_cast<double>(denom);
}

rational rational::operator+() const { return rational(abs(num), abs(denom)); }

rational rational::operator-() const { return rational(-num, denom); }

rational& rational::operator+=(const rational& other) {
  num = num * other.denom + denom * other.num;
  denom *= other.denom;
  simplify();
  return *this;
}

rational operator+(rational left, const rational& right) {
  left += right;
  return left;
}

rational& rational::operator-=(const rational& other) {
  num = num * other.denom - denom * other.num;
  denom *= other.denom;
  simplify();
  return *this;
}

rational operator-(rational left, const rational& right) {
  left -= right;
  return left;
}

rational& rational::operator*=(const rational& other) {
  num *= other.num;
  denom *= other.denom;
  simplify();
  return *this;
}

rational operator*(rational left, const rational& right) {
  left *= right;
  return left;
}

rational& rational::operator/=(const rational& other) {
  if (other.num == 0) {
    throw invalid_argument("Cannot divide by zero.");
  }
  num *= other.denom;
  denom *= other.num;
  simplify();
  return *this;
}

rational operator/(rational left, const rational& right) {
  left /= right;
  return left;
}

rational& rational::operator++() {
  num += abs(denom);
  return *this;
}

rational rational::operator++(int) {
  auto old = *this;
  operator++();
  return old;
}

rational& rational::operator--() {
  num -= abs(denom);
  return *this;
}

rational rational::operator--(int) {
  auto old = *this;
  operator--();
  return old;
}

bool operator==(const rational& left, const rational& right) {
  const auto left_neg = (left.num < 0) ^ (left.denom < 0);
  const auto right_neg = (right.num < 0) ^ (right.denom < 0);
  if (left_neg != right_neg) return false;
  const auto left_crit = abs(left.num * right.denom);
  const auto right_crit = abs(left.denom * right.num);
  return left_crit == right_crit;
}

bool operator!=(const rational& left, const rational& right) {
  return !(left == right);
}

bool operator<(const rational& left, const rational& right) {
  const auto left_neg = (left.num < 0) ^ (left.denom < 0);
  const auto right_neg = (right.num < 0) ^ (right.denom < 0);
  if (left_neg != right_neg) return left_neg;
  const auto left_crit = abs(left.num * right.denom);
  const auto right_crit = abs(left.denom * right.num);
  return left_neg ? left_crit > right_crit : left_crit < right_crit;
}

bool operator<=(const rational& left, const rational& right) {
  return !(left > right);
}

bool operator>(const rational& left, const rational& right) {
  return right < left;
}

bool operator>=(const rational& left, const rational& right) {
  return !(left < right);
}

ostream& operator<<(ostream& out, const rational& frac) {
  return out << frac.num << '/' << frac.denom;
}
