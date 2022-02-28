/**
 * @file test.cpp
 * @author Andrew Wang (siweiw9@gmail.com)
 * @brief Test rational class.
 * @version 0.1
 * @date 2022-02-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <cmath>
#include <iostream>
#include <numeric>
#include <sstream>
#include <stdexcept>

#include "rational.h"
using std::abs;
using std::cerr;
using std::cout;
using std::ios_base;
using std::runtime_error;
using std::sqrt;
using std::stringstream;

namespace test {
void construct_integer();
void construct_num_denom();
void construct_copy();
void op_assign();
void value();
void op_positive();
void op_negative();
void op_add();
void op_subtract();
void op_multiply();
void op_divide();
void increment();
void decrement();
void op_equality();
void op_compare();
void op_write();
}  // namespace test

template <typename S, typename T>
void assert_equals(S expected, T actual) {
  if (expected != actual) {
    cerr << "\tASSERTION FAILURE: expected " << expected << " but was "
         << actual << '\n';
  }
}

void assert_equals(double expected, double actual, double delta) {
  if (abs(expected - actual) > delta) {
    cerr << "\tASSERTION FAILURE: expected " << expected << " but was "
         << actual << '\n';
  }
}

void assert_true(bool pred) {
  if (!pred) {
    cerr << "\tASSERTION FAILURE: expected true predicate but was false.\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  test::construct_integer();
  test::construct_num_denom();
  test::construct_copy();
  test::op_assign();
  test::value();
  test::op_positive();
  test::op_negative();
  test::op_add();
  test::op_subtract();
  test::op_multiply();
  test::op_divide();
  test::increment();
  test::decrement();
  test::op_equality();
  test::op_compare();
  test::op_write();

  {
    cout << "Approximation of Euler's constant via power series.\n";
    rational approx_e(1);
    for (rational::integer_t denom = 1, fac = 1; denom < 12; ++denom) {
      approx_e += rational(1, (fac *= denom));
    }
    cout << "\te \u2248 " << approx_e << " \u2248 " << approx_e.value() << '\n';
  }
  {
    cout << "Exploration of Zeno's paradox approaching 1.\n";
    rational zeno(0);
    for (rational::integer_t base = 1; base < 20; ++base) {
      zeno += rational(1, 1 << base);
    }
    cout << "\t1 \u2248 " << zeno << " \u2248 " << zeno.value() << '\n';
  }
}

void test::construct_integer() {
  cout << "Test: Construct Integer\n";

  const rational pos(18);
  assert_equals(18, pos.numerator());
  assert_equals(1, pos.denominator());

  const rational neg(-7);
  assert_equals(-7, neg.numerator());
  assert_equals(1, neg.denominator());
}

void test::construct_num_denom() {
  cout << "Test: Construct Num Denom\n";

  const rational red(-18, -12);
  assert_equals(3, red.numerator());
  assert_equals(2, red.denominator());

  const rational neg_red(4, -6);
  assert_equals(-2, neg_red.numerator());
  assert_equals(3, neg_red.denominator());
}

void test::construct_copy() {
  cout << "Test: Construct Copy\n";

  const rational frac(5, 6);
  const rational cpy(frac);
  assert_equals(5, cpy.numerator());
  assert_equals(6, cpy.denominator());
}

void test::op_assign() {
  cout << "Test: Assignment\n";

  const rational frac(5, 6);
  rational cpy(-10);
  cpy = frac;
  assert_equals(5, cpy.numerator());
  assert_equals(6, cpy.denominator());
}

void test::value() {
  cout << "Test: Value\n";

  const rational frac(5, 6);
  assert_equals(0.8333, frac.value(), 0.001);

  const rational neg(8, -5);
  assert_equals(-1.6, neg.value(), 0.001);
}

void test::op_positive() {
  cout << "Test: Positive\n";

  const rational neg(8, -5);
  const auto pos = +neg;
  assert_equals(8, pos.numerator());
  assert_equals(5, pos.denominator());
}

void test::op_negative() {
  cout << "Test: Negative\n";

  const rational neg(8, -5);
  assert_equals(8, (-neg).numerator());
  assert_equals(5, (-neg).denominator());

  const rational pos(-3, -7);
  assert_equals(-3, (-pos).numerator());
  assert_equals(7, (-pos).denominator());
}

void test::op_add() {
  cout << "Test: Add\n";

  const rational left(2, -4);
  const rational right(8, 6);
  const auto sum = left + right;

  assert_equals(5, sum.numerator());
  assert_equals(6, sum.denominator());
}

void test::op_subtract() {
  cout << "Test: Subtract\n";

  const rational left(2, -4);
  const rational right(8, 6);
  const auto diff = left - right;

  assert_equals(-11, diff.numerator());
  assert_equals(6, diff.denominator());
}

void test::op_multiply() {
  cout << "Test: Multiply\n";

  const rational left(11, -4);
  const rational right(-12);
  const auto prod = left * right;

  assert_equals(33, prod.numerator());
  assert_equals(1, prod.denominator());
}

void test::op_divide() {
  cout << "Test: Divide\n";

  const rational left(-16, 5);
  const rational right(4, -9);
  const auto quot = left / right;

  assert_equals(36, quot.numerator());
  assert_equals(5, quot.denominator());
}

void test::increment() {
  cout << "Test: Increment\n";

  rational frac(-4, 7);
  const auto old = frac++;

  assert_equals(-4, old.numerator());
  assert_equals(7, old.denominator());
  assert_equals(3, frac.numerator());
  assert_equals(7, frac.denominator());
}

void test::decrement() {
  cout << "Test: Decrement\n";

  rational frac(-4, 7);
  const auto old = frac--;

  assert_equals(-4, old.numerator());
  assert_equals(7, old.denominator());
  assert_equals(-11, frac.numerator());
  assert_equals(7, frac.denominator());
}

void test::op_equality() {
  cout << "Test: Equality\n";

  const rational left(160, -60);
  const rational right(-16, 6);

  assert_equals(left, right);
  assert_equals(-left, -right);
  assert_true(left != -right);
  assert_true(-left != right);
}

void test::op_compare() {
  cout << "Test: Compare\n";

  const rational left(16, -6);
  const rational right(-15, 6);

  assert_true(left <= left);
  assert_true(right <= right);
  assert_true(left < right);
  assert_true(right > left);

  const rational pos(1, 7);
  assert_true(left < pos);
  assert_true(pos > right);
  assert_true(pos >= left);
  assert_true(right <= pos);
  assert_true(pos >= pos);
}

void test::op_write() {
  cout << "Test: Write\n";

  const rational pos(-18, -32);
  stringstream pos_ss;
  pos_ss << pos;
  assert_equals("9/16", pos_ss.str());

  const rational neg(-5, 3);
  stringstream neg_ss;
  neg_ss << neg;
  assert_equals("-5/3", neg_ss.str());

  const rational whole(-9);
  stringstream whole_ss;
  whole_ss << whole;
  assert_equals("-9/1", whole_ss.str());
}
