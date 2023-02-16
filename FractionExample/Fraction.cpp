#include <iostream>
using namespace std;

#include "Fraction.h"

bool isInteger(const std::string &str) {
   for (const char &c : str)
      if (!std::isdigit(c)) 
         return false;
   return true;
}

Fraction::Fraction() {
   // cout << "Called default constructor" << endl;
   numerator = 1;
   denominator = 1;
}

Fraction::Fraction(const Fraction &f2) {
   // cout << "Called copy constructor" << endl;
   numerator = f2.numerator;
   denominator = f2.denominator;
}

Fraction::Fraction (int num, unsigned int denom) {
   // cout << "Called value constructor" << endl;
   numerator = num;
   denominator = denom;
   sanityCheck(); 
}

bool Fraction::set(int num, unsigned int denom) {
   Fraction test;
   test.numerator = num;
   test.denominator = denom;
   if (test.sanityCheck()) {
      numerator = num;
      denominator = denom;
      return true;
   }
   // Leave the old value as is and return false
   return false;
}

void Fraction::promptedRead() {
   // WEAK programming effort here. Should check for numberic input
   string in;
   cout << "  Enter the numerator: ";
   numerator = denominator = 1;
   cin >> in; 
   if (isInteger(in))
      numerator = stoi(in);
   else
      cout << "Input is not an integer, usting 1." << endl;
   cout << "Enter the denominator: ";
   cin >> in; 
   if (isInteger(in))
      denominator = stoi(in);
   else 
      cout << "Input is not an integer, usting 1." << endl;
   sanityCheck(); 
   reduce();
}

void Fraction::show() const {
   cout << numerator << "/" << denominator;
}

Fraction Fraction::add(const Fraction &f) const {
   Fraction result;
   result.numerator = numerator * f.denominator + 
                      denominator * f.numerator;
   result.denominator = denominator * f.denominator;

   // You can access private member functions and private data members of
   // Fraction inside Fraction methods. Notice that "result" is NOT the 
   // fraction object that this add() function was called on, and yet we can
   // still call reduce. And we set the numeratror and denominator directly
   // above.
   result.reduce();
   return result;
}

Fraction::~Fraction() {
   // nothing to do in the destructor because Fraction does not use new
   // to create any dynamically allocated memory. (There are other things that
   // are sometimes done in the destructor, but using C++ "delete" to free
   // dynamically allocated memory is by far the most important one for CS240.
}

bool Fraction::equals(Fraction f) {
   // Causes the object that the function is called on to be reduced.
   // The overloaded == operator below shows one way to get around this.
   reduce();
   f.reduce();
   return ((numerator == f.numerator) && (denominator == f.denominator));
}

int greatestCommonDivisor(int i1, int i2)
{
   if (i1 == 0) 
      return i2;
   return greatestCommonDivisor((i2%i1), i1);
}

void Fraction::reduce() {
   bool negate = false;
   if (numerator < 0) {
      numerator *= -1;
      negate = true;
   }
   int gcd = greatestCommonDivisor(numerator, denominator);
   numerator /= gcd;
   denominator /= gcd;
   if (negate)
      numerator *= -1;
   return;
}

bool Fraction::sanityCheck() {
  if (denominator == 0) {
     cout << "Tried to make a fraction with a zero in the denominator." << endl;
     cout << "Setting fraction to 1/1 instead." << endl; 
     numerator = denominator = 1; 
     return false;
  }
  return true;
}

// assignment operator (=) as member function (1 arg)
Fraction &Fraction::operator=(const Fraction& other) {
   // cout << "Called assignment operator." << endl;
   if (this == &other) return *this;
   numerator = other.numerator;
   denominator = other.denominator;
   return (*this); 
}

// binary operator (+) as member function (1 arg)
Fraction Fraction::operator+(const Fraction& rhs) const {
   Fraction f;
  
   f.numerator = (this->numerator * rhs.denominator) + 
                 (rhs.numerator * this->denominator);
   f.denominator = this->denominator * rhs.denominator;
   f.reduce(); 

   return f;
}
 
// binary operator (-) as a friend function (2 args) 
Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
   Fraction f;
  
   f.numerator = (lhs.numerator * rhs.denominator) -
                 (rhs.numerator * lhs.denominator);
   f.denominator = lhs.denominator * rhs.denominator;
   f.reduce(); 

   return f;
}

// binary operator (==) as a member function (1 args)
bool Fraction::operator==(const Fraction& other) const {
   Fraction f = other;  // make a copy of other
   Fraction f2 = *this; // make a copy of myself
   f2.reduce();
   f.reduce(); // const prevents calling reduce() on "other" directly

   // The code below assumes both fractions are reduced!
   return ((f2.numerator == f.numerator) && 
           (f2.denominator == f.denominator));
}

istream &operator>>(istream &in, Fraction &f) {
   char ch;
   // WEAK programming effort here... assumes 4/5 format, 
   // doesn't type check anything including the '/', etc. 
   // Works if the input is formatted properly.
   in >> f.numerator >> ch >> f.denominator; 
   f.sanityCheck();
   return (in);  
}

ostream &operator<<(ostream &out, const Fraction &f) {
   // use the fact that << is implemented for unsigned int and int
   out << f.numerator << '/' << f.denominator; 
   return out;
}
