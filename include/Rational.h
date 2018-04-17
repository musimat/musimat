/* $Revision: 1.5 $ $Date: 2006/09/08 18:56:52 $ $Author: dgl $ $Name:  $ $Id: Rational.h,v 1.5 2006/09/08 18:56:52 dgl Exp $ */
#ifndef Rational_H
#define Rational_H

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

///	@file Rational.h
///	Rational class
///

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Musimat.h"
#include <iostream>
#include <stdio.h>

/// Rational class implements standard methods and data structures to manipulate Rational ratios arithmetically.

class Rational
{
	friend ostream& operator<<(ostream&, Rational&);
	friend istream& operator>>( istream& is, Rational& p );

	friend Bool operator==(Integer& i, Rational& p) { Return i == p.quotient(); }
	friend Bool operator==(Rational& p, Integer& i) { Return p.quotient() == i; }
	friend Bool operator!=(Integer& i, Rational& p) { Return i != p.quotient(); }
	friend Bool operator!=(Rational& p, Integer& i) { Return p.quotient() != i; }
	friend Bool operator>=(Rational& p, Integer& r) { Return p.quotient() >= r; }
	friend Bool operator>=(Integer& i, Rational& p) { Return i >= p.quotient(); }
	friend Bool operator>(Rational& p, Integer& i) { Return p.quotient() > i; }
	friend Bool operator>(Integer& i, Rational& p) { Return i > p.quotient(); }
	friend Bool operator<=(Rational& p, Integer& i) { Return p.quotient() <= i; }
	friend Bool operator<=(Integer& i, Rational& p) { Return i <= p.quotient(); }

	friend Bool operator==(Real& r, Rational& p) { Return r == p.quotient(); }
	friend Bool operator==(Rational& p, Real& r) { Return p.quotient() == r; }
	friend Bool operator!=(Real& r, Rational& p) { Return r != p.quotient(); }
	friend Bool operator!=(Rational& p, Real& r){ Return p.quotient() != r; }
	friend Bool operator>=(Rational& p, Real& r) { Return p.quotient() >= r; }
	friend Bool operator>=(Real& r, Rational& p) { Return r >= p.quotient(); }
	friend Bool operator>(Rational& p, Real& r) { Return p.quotient() > r; }
	friend Bool operator>(Real& r, Rational& p) { Return r > p.quotient(); }
	friend Bool operator<=(Rational& p, Real& r) { Return p.quotient() <= r; }
	friend Bool operator<=(Real& r, Rational& p) { Return r <= p.quotient(); }

public:

	/// Default constructor
	Rational() : m_num(0), m_den(0) { }

	/// Default constructor
	Rational(Integer i) : m_num(i), m_den(i) { }

	/// Copy constructor
	Rational(Const Rational& x) : m_num(x.m_num), m_den(x.m_den) { }

	/// Construct Rational given a fractional value
	/// @param x Rational fraction expressed as a Real
	Rational(Real x) : m_num(0), m_den(0) { RealToRational( x, m_num, m_den ); }

	/// Construct Rational given a rational fraction value
	/// @param num Numerator of rational fraction
	/// @param den Denominator of rational fraction
	Rational(Integer num, Integer den) : m_num(num), m_den(den) {
		If (m_den == 0)
			m_den = 1;
	}

	/// Construct Rational given a Real fractional value, determine its rational approximation, assign numerator and denominator to reference arguments.
	/// @param x Real fractional reference value
	/// @param num Reference Integer numerator of derived rational fraction approximation
	/// @param den Reference Integer denominator of derived rational fraction approximation
	Rational(Real x, Integer& num, Integer& den) : m_num(0), m_den(0) { 
		RealToRational( x, num, den ); 
		m_num = num;
		m_den = den;
	}

	/// Construct Rational given a Rational, determine its rational approximation, assign numerator and denominator to reference arguments.
	/// @param x Rational value
	/// @param num Reference Integer numerator of derived rational fraction approximation
	/// @param den Reference Integer denominator of derived rational fraction approximation
	Rational(Rational x, Integer& num, Integer& den) : m_num(0), m_den(0) { 
		RealToRational( x.quotient(), num, den ); 
		m_num = num;
		m_den = den;
	}

	/// Rational assignment operator
	Rational& operator=(Const Rational& x) {
		m_num = x.m_num;
		m_den = x.m_den;
		Return *this;
	}

	/// Rational equality operator
	Bool operator==(Const Rational& x) Const {
		Return m_num == x.m_num  And m_den == x.m_den;
	}

	/// Rational inequality operator
	Bool operator!=(Const Rational& x) Const {
		Return m_num != x.m_num || m_den != x.m_den;
	}

	/// Rational >= operator
	Bool operator>=(Const Rational& x) Const {
		Return quotient() >= x.quotient();
	}

	/// Rational > operator
	Bool operator>(Const Rational& x) Const {
		Return quotient() > x.quotient();
	}

	/// Rational < operator
	Bool operator<(Const Rational& x) Const {
		Return quotient() < x.quotient();
	}

	/// Rational <= operator
	Bool operator<=(Const Rational& x) Const {
		Return quotient() <= x.quotient();
	}

	/// Rational plus-equals operator
	Rational& operator+=(Const Real x) {
		Return( *this = Rational(quotient() + x) );
	}

	/// Rational plus-equals operator
	Rational& operator+=(Rational x) {
		Return( *this = Rational(quotient() + x.quotient() ) );
	}

	/// Rational minus-equals operator
	Rational& operator-=(Const Real x) {
		Return( *this = quotient() - x );
	}

	/// Rational minus-equals operator
	Rational& operator-=(Rational x) {
		Return( *this = quotient() - x.quotient() );
	}

	/// Rational times-equals operator
	Rational& operator*=(Const Real x) {
		Return( *this = quotient() * x );
	}

	/// Rational times-equals operator
	Rational& operator*=(Rational x) {
		Return( *this = quotient() * x.quotient() );
	}

	/// Rational divide-equals operator
	Rational& operator/=(Const Real x) {
		Return( *this = quotient() / x );
	}

	/// Rational divide-equals operator
	Rational& operator/=(Rational x) {
		Return( *this = quotient() / x.quotient() );
	}

	/// Rational addition operator
	Rational operator+(Rational& x) {
		Return( Rational(quotient() + x.quotient()) );
	}

	/// Rational subtraction operator
	Rational operator-(Rational& x) {
		Return( Rational(quotient() - x.quotient()) );
	}

	/// Rational times operator
	Rational operator*(Rational& x) {
		Return( Rational(quotient() * x.quotient()) );
	}

	/// Rational divide operator
	Rational operator/(Rational& x) {
		Return( Rational(quotient() / x.quotient()) );
	}

	/// Rational add to Real operator
	Rational operator+(Const Real x) {
		Return( Rational(quotient() + x) );
	}

	/// Rational subtract from Real operator
	Rational operator-(Const Real x) {
		Return( Rational(quotient() - x) );
	}

	/// Rational multiply by Real operator
	Rational operator*(Const Real x) {
		Return( Rational(quotient() * x) );
	}

	/// Rational divide by Real operator
	Rational operator/(Const Real x) {
		Return( Rational(quotient() / x ) );
	}

	/// Print Rational prefixed by String
	/// @param s Prefix string
	String print(String s = 0) Const {
		If (s)
			cout << s;
#ifdef _MSC_VER
// Disable Microsoft Visual Studio warning about sprintf()
// until is universal agreement about how to handle its insecurities
#pragma warning(push)
#pragma warning(disable: 4996)
		sprintf(s_buf, "{%d,%d}", m_num, m_den);
#pragma warning(pop)
#else
		sprintf(s_buf, "{%d,%d}", m_num, m_den);
#endif
		Return s_buf;
	}
	
private:
	// Absolute value of a Real
//	Real abs( Real x ) Const { Return x < 0 ? -x : x; }
	Real quotient() Const { Return( Real(m_num) / Real(m_den) ); }

protected:
	Integer m_num;
	Integer m_den;
	Static char s_buf[128];
};

#endif // Rational_H
