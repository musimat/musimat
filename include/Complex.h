/* $Revision: 1.5 $ $Date: 2006/09/08 18:56:52 $ $Author: dgl $ $Name:  $ $Id: Complex.h,v 1.5 2006/09/08 18:56:52 dgl Exp $ */
#ifndef COMPLEX_H
#define COMPLEX_H

// The Musimat Tutorial � 2006 Gareth Loy
// Derived from Chapter 9 and Appendix B of "Musimathics Vol. 1" � 2006 Gareth Loy 
// and published exclusively by The MIT Press.
// This program is released WITHOUT ANY WARRANTY; without even the implied 
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.
// "Musimathics" is available here:	http://mitpress.mit.edu/catalog/item/default.asp?ttype=2&tid=10916
// Gareth Loy's Musimathics website:	http://www.musimathics.com/
// The Musimat website:			http://www.musimat.com/
// This program is released under the terms of the GNU General Public License
// available here:			http://www.gnu.org/licenses/gpl.txt

///	@file Complex.h
///	@brief The Complex datatype

#include <iostream>
#include <math.h>
#include "Musimat.h"


/// Complex class implements a set of data types, conversions, and operations for complex numbers.
class Complex
{
	/// Print to output stream.
	/// Complex number is printed as '(' \<real_part\> ',' \<imag_part\> ')'
	friend ostream& operator<<( ostream& os, const Complex& c ) {
		cout << "(";
		// cout.precision(2); // Use this to set precision, if desired
		cout << c.m_r << ", ";
		cout << c.m_i;
		cout << ")";
		Return os;
	}

	/// Read from input stream.
	/// Complex number is scanned as '{' \<real_part\> ',' \<imag_part\> '}'
	/// Alternately, parenthesis can be used to bracket complex number.
	friend istream& operator>>( istream& is, Complex& c ) {
		char ch;
		is >> ch && (ch == '{' || ch == '(')
			&& is >> c.m_r >> ch && ch == ','
			&& is >> c.m_i >> ch && (ch == '}' || ch == '(');
		Return is;
	}

public:

	/// Default constructor.
	Complex() : 
	  m_r(0), 
	  m_i(0) {
	  }

	/// Construct Complex from real part.
	/// @param i Initializer for both real and imaginary parts.
	Complex(Real i) : 
	  m_r(i), 
	  m_i(i) {
	  }

	/// Construct Complex from real and imaginary.
	/// @param r Real part of complex number as a Real datatype
	/// @param i Imaginary part of the complex number as a Real datatype
	Complex(Real r, Real i) : 
	  m_r(r), 
	  m_i(i) {
	  }

	/// Get the real part of Complex number as a Real.
	/// @return The real part of the complex number as a Real
	Real r(Void) {
		Return m_r;
	}

	/// Get the imaginary part of the Complex number as a Real.
	/// @return The imaginary part of the complex number as a Real
	Real i(Void) {
		Return m_i;
	}

	/// Set the real part of Complex number.
	/// @see r(Void)
	Void r(Real r) { m_r = r; }

	/// Set the imaginary part of Complex number.
	/// @see i(Void)
	Void i(Real i) { m_i = i; }

	/// Asignment operator for Complex = Real.  
	Complex& operator=(Const Real& x) {
		m_r = x;
		m_i = 0;
		Return *this;
	}

	/// Equality operator for Complex == Complex.  
	Bool operator==(Const Complex& x) Const {
		Return m_r == x.m_r && m_i == x.m_i;
	}

	/// Inquality operator for Complex != Complex.  
	Bool operator!=(Const Complex& x) Const {
		Return !(m_r == x.m_r && m_i == x.m_i);
	}

	/// Less-than operator for Complex < Complex.  
	Bool operator<(Const Complex& x) Const {
		Return m_r < x.m_r && m_i < x.m_i;
	}

	/// Less-than or equal operator for Complex < Complex.  
	Bool operator<=(Const Complex& x) Const {
		Return m_r <= x.m_r && m_i <= x.m_i;
	}

	/// Greater-than or equal operator for Complex < Complex.  
	Bool operator>=(Const Complex& x) Const {
		Return m_r >= x.m_r && m_i >= x.m_i;
	}

	/// Greater-than operator for Complex < Complex.  
	Bool operator>(Const Complex& x) Const {
		Return m_r > x.m_r && m_i > x.m_i;
	}

	/// Addition operator for Complex + Complex.
	Complex operator+(Const Complex& c){
		Return Complex(m_r + c.m_r, m_i + c.m_i);
	}

	/// Subtraction operator for Complex - Complex.
	Complex operator-(Const Complex& c){
		Return Complex(m_r - c.m_r, m_i - c.m_i);
	}

	/// Negation operator for Complex. Both real and imaginary parts are negated.  
	/// @see operator~()
	Complex operator-(){
		Return Complex(-m_r, -m_i);
	}

	/// Conjugation operator for Complex. Only imaginary part is negated.  
	/// @see operator-()
	Complex operator~(){
		Return Complex(m_r, -m_i);
	}

	/// Multiplication operator for Complex * Complex.  
	Complex operator*(Const Complex& c){
		Return Complex(m_r * c.m_r - m_i * c.m_i,
					   m_r * c.m_i + m_i * c.m_r);
	}

	/// Multiplication operator for Complex * Real.  
	Complex operator*(Const Real& r){
		Complex c(r, 0.0);
		Return *this * c;
	}

	/// Division operator for Complex / Complex.  
	Complex operator/(Const Complex& c){
		Real modulus = c.m_r * c.m_r + c.m_i * c.m_i;
		Real r = m_i * c.m_i + m_r * c.m_r;
		Real i = m_i * c.m_r - m_r * c.m_i;
    
		Return Complex(r / modulus, i / modulus);
	}

	/// Division operator for Complex / Real.  
	Complex operator/(Const Real& r){
		Complex c(r, 0.0);
		Return *this / c;
	}

	/// Increment operator for Complex += Complex.
	Complex& operator+=(const Complex x) {
		Return( *this = *this + x );
	}

	/// Decrement operator for Complex -= Complex.
	Complex& operator-=(const Complex x) {
		Return( *this = *this - x );
	}

	/// Multiply scale operator for Complex *= Complex.
	Complex& operator*=(const Complex x) {
		Return( *this = *this * x );
	}

	/// Divide scale operator for Complex /= Complex.
	Complex& operator/=(const Complex x) {
		Return( *this = *this / x );
	}

	/// Divide scale operator for Complex /= Real.
	Complex& operator/=(const Real r) {
		Complex x(r, 0.0);
		Return( *this = *this / x );
	}

	/// Complex absolute value.
	/// @return Absolute value.
	Complex Abs() {
		Complex t(m_r < 0.0 ? -m_r : m_r, m_i < 0.0 ? -m_i : m_i);
		Return(t);
	}

	/// Complex conjugate.
	/// @return Conjugate value.
	Complex Conjugate() {
		Complex t(m_r, -m_i);
		Return(t);
	}

	/// Complex exponentiation.
	Complex Exp(Complex e) {
		Real r = e.r();
		r = exp(r);
		Real theta = e.i();
		Complex t(r * Cos(theta), r * Sin(theta));
		Return t;
	}

	/// Print complex value, prepended by String s if not null.
	/// Complex value is printed as "{r,i}".
	/// @param s String to prefix to complex number.
	Void print(String s = 0) {
		If (s)
			cout << s;
		cout << "{ ";
		cout.precision(2);
		cout << m_r << ", ";
		cout << m_i;
		cout << " }" << endl;
	}


private:
	Real m_r;		///< The real part
	Real m_i;		///< The imaginary part
};

/// Convenience function to get the real part of a Complex number
/// @return Real part of Complex number as a Real
inline Real RealPart( Complex c ) { Return c.r(); }

/// Convenience function to get the imaginary part of a Complex number
/// @return Imaginary part of Complex number as a Real
inline Real ImagPart( Complex c ) { Return c.i(); }

/// Convenience function to set the real part of a Complex number
inline Void RealPart( Complex& c, Real r ) { c.r(r); }

/// Convenience function to set the imaginary part of a Complex number
inline Void ImagPart( Complex& c, Real r ) { c.i(r); }

/// Convenience function to return the absolute value of a Complex number
inline Complex Abs( Complex c ) { Return(c.Abs()); }

/// Convenience function to return the conjugate value of a Complex number
inline Complex Conjugate( Complex c ) { Return(~c); }

///	Raise Complex a to the power of Complex b
///	@param a Complex base
///	@param b Complex exponent
inline Complex Exp( Complex a, Complex b ) {
	Complex x = a.Exp( b );
	Return x;
}

///	Raise Real r to the power of Real theta
///	@param r Real base
///	@param theta Real exponent
inline Complex Exp(Real r, Real theta) {
	Complex t(r * Cos(theta), r * Sin(theta));
	Return t;
}

#endif // COMPLEX_H
