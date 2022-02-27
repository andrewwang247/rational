/**
 * @file rational.h
 * @author Andrew Wang (siweiw9@gmail.com)
 * @brief Interface for exact representation of rational numbers.
 * @version 0.1
 * @date 2022-02-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <cstdint>
#include <iostream>

/**
 * @brief Exact representation of rational numbers.
 *
 * Satisfies invariant that denominator is always positive.
 */
class rational {
  using integer = std::int64_t;

 private:
  integer num;
  integer denom;

  /**
   * @brief Reduces num and denom such that they are relatively prime.
   *
   */
  void simplify();

 public:
  /**
   * @brief Disallow no-arg default constructor.
   *
   */
  rational() = delete;

  /**
   * @brief Construct a rational given its integer value.
   *
   * @param value The value of the constructed rational.
   */
  explicit rational(integer value);

  /**
   * @brief Construct a rational given numerator and denominator.
   *
   * @param numerator The numerator.
   * @param denominator The denominator.
   */
  rational(integer numerator, integer denominator);

  /**
   * @brief Copy constructor.
   *
   * @param other The rational to copy into this.
   */
  rational(const rational& other);

  /**
   * @brief Assignment operator.
   *
   * @param other The rational to assign to this.
   * @return this
   */
  rational& operator=(const rational& other);

  /**
   * @brief Unsigned value of the numerator. Relatively prime to denominator.
   *
   * @return integer absolute value of numerator.
   */
  integer numerator() const;

  /**
   * @brief Unsigned value of the deminator. Relatively prime to numerator.
   *
   * @return integer absolute value of denominator.
   */
  integer denominator() const;

  /**
   * @brief Get approximate value of the rational.
   *
   * @return double approximation of rational.
   */
  double value() const;

  /**
   * @brief Absolute value of this.
   *
   * @return abs(this)
   */
  rational operator+() const;

  /**
   * @brief Opposite sign of this.
   *
   * @return this reflected through 0
   */
  rational operator-() const;

  /**
   * @brief Add another rational.
   *
   * @param other The other rational.
   * @return this
   */
  rational& operator+=(const rational& other);

  /**
   * @brief Binary addition.
   *
   * @param left Left side rational.
   * @param right Right side rational.
   * @return operation on left and right.
   */
  friend rational operator+(rational left, const rational& right);

  /**
   * @brief Subtract another rational.
   *
   * @param other The other rational.
   * @return this
   */
  rational& operator-=(const rational& other);

  /**
   * @brief Binary subtraction.
   *
   * @param left Left side rational.
   * @param right Right side rational.
   * @return operation on left and right.
   */
  friend rational operator-(rational left, const rational& right);

  /**
   * @brief Multiply another rational.
   *
   * @param other The other rational.
   * @return this
   */
  rational& operator*=(const rational& other);

  /**
   * @brief Binary multiplication.
   *
   * @param left Left side rational.
   * @param right Right side rational.
   * @return operation on left and right.
   */
  friend rational operator*(rational left, const rational& right);

  /**
   * @brief Divide another rational.
   *
   * @param other The other rational.
   * @return this
   */
  rational& operator/=(const rational& other);

  /**
   * @brief Binary division.
   *
   * @param left Left side rational.
   * @param right Right side rational.
   * @return operation on left and right.
   */
  friend rational operator/(rational left, const rational& right);

  /**
   * @brief Prefix increment by one.
   *
   * @return this
   */
  rational& operator++();

  /**
   * @brief Postfix increment by one.
   *
   * @return copy of this
   */
  rational operator++(int);

  /**
   * @brief Prefix decrement by one.
   *
   * @return this
   */
  rational& operator--();

  /**
   * @brief Postfix decrement by one.
   *
   * @return copy of this
   */
  rational operator--(int);

  /**
   * @brief Equality comparison.
   *
   * @param left Left side rational.
   * @param right Right side rational.
   * @return whether relation is satisfied.
   */
  friend bool operator==(const rational& left, const rational& right);

  /**
   * @brief Inequality comparison.
   *
   * @param left Left side rational.
   * @param right Right side rational.
   * @return whether relation is satisfied.
   */
  friend bool operator!=(const rational& left, const rational& right);

  /**
   * @brief Less than comparison.
   *
   * @param left Left side rational.
   * @param right Right side rational.
   * @return whether relation is satisfied.
   */
  friend bool operator<(const rational& left, const rational& right);

  /**
   * @brief Less than or equal to comparison.
   *
   * @param left Left side rational.
   * @param right Right side rational.
   * @return whether relation is satisfied.
   */
  friend bool operator<=(const rational& left, const rational& right);

  /**
   * @brief Greater than comparison.
   *
   * @param left Left side rational.
   * @param right Right side rational.
   * @return whether relation is satisfied.
   */
  friend bool operator>(const rational& left, const rational& right);

  /**
   * @brief Greater than or equal to comparison.
   *
   * @param left Left side rational.
   * @param right Right side rational.
   * @return whether relation is satisfied.
   */
  friend bool operator>=(const rational& left, const rational& right);

  /**
   * @brief Write rational to stream.
   *
   * @param out The output stream.
   * @param frac The rational to write.
   * @return out
   */
  friend std::ostream& operator<<(std::ostream& out, const rational& frac);
};
