#ifndef __FRACTION_H_
#define __FRACTION_H_

#include <iostream>
using namespace std;

class Fraction {
   private:
      // Data members should almost always be private.  If you would like
      // users of your class to have "access" to data members, create 
      // "getter" and "setter" public member functions.  For example, we could
      // support "int getNumerator()" to return the numerator. 
      int numerator; 
      unsigned int denominator;
      void reduce();
      bool sanityCheck();

  public:
      // Three constructors for objects of this class. The constructor is 
      // "overloaded" with three different parameter lists
  
      // The "default constructor" takes no parameters. Constructors have
      // no return type/value (not even void). We have only scratched
      // the surface of C++, including with all the options for default
      // constructors.  Default constructor rabbit hole:
      // https://en.cppreference.com/w/cpp/language/default_constructor
      Fraction();

      // The "copy constructor" takes a reference to an object of this class
      // That copied object is not changed, so it can and should be made const.
      Fraction(const Fraction &f1);

      // One "value constructor" that takes a numerator and denominator
      Fraction(int num, unsigned int denom);

      // Allows programmers to assign a new value to the fraction.
      bool set(int num, unsigned int denom);

      // Some regular old functions to do things that could be (and are, 
      // below) more naturally done as overloaded operators
      void promptedRead();
      void show() const;
      Fraction add(const Fraction &f) const;
      bool equals(Fraction f);

      // Destructor. Called every time the object goes out of scope.
      // This class does not use dynamic memory, so the destructor is not 
      // necessary, and provided only to show syntax.
      ~Fraction();

      // ===========================================================
      // Overloaded operators for the =, +, -, and == operations.
      // ===========================================================

      // assignment operator (=) as member function (1 arg)
      Fraction &operator=(const Fraction& rhs); 

      // binary operator (+) as member function (1 arg)
      Fraction operator+(const Fraction& rhs) const; 
 
      // binary operator (-) as a friend function (2 args) 
      friend Fraction operator-(const Fraction& lhs, 
                                const Fraction& rhs); 

      // binary operator (==) as a member function (1 arg)
      bool operator==(const Fraction& other) const; 

      // ===========================================================
      // Friend functions for the << and >> operators.
      // ===========================================================
      friend istream & operator>>(istream &in, Fraction &f); 
      friend ostream & operator<<(ostream &out, const Fraction &f); 
};

#endif
