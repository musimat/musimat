/* $Revision: 1.5 $ $Date: 2006/09/08 18:56:52 $ $Author: dgl $ $Name:  $ $Id: Rhythm.h,v 1.5 2006/09/08 18:56:52 dgl Exp $ */
#ifndef RHYTHM_H
#define RHYTHM_H

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
///	@file Rhythm.h
///	@brief Rhythm class
///

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Musimat.h"
#include <iostream>

/// Rhythm class implements standard methods and data structures to manipulate musical rhythm arithmetically.
class Rhythm
{
	friend ostream& operator<<(ostream&, Rhythm&);
	friend istream& operator>>( istream& is, Rhythm& p );

	friend Bool operator==(Integer& i, Rhythm& p) { Return i == p.quotient(); }
	friend Bool operator==(Rhythm& p, Integer& i) { Return p.quotient() == i; }
	friend Bool operator!=(Integer& i, Rhythm& p) { Return i != p.quotient(); }
	friend Bool operator!=(Rhythm& p, Integer& i) { Return p.quotient() != i; }
	friend Bool operator>=(Rhythm& p, Integer& r) { Return p.quotient() >= r; }
	friend Bool operator>=(Integer& i, Rhythm& p) { Return i >= p.quotient(); }
	friend Bool operator>(Rhythm& p, Integer& i) { Return p.quotient() > i; }
	friend Bool operator>(Integer& i, Rhythm& p) { Return i > p.quotient(); }
	friend Bool operator<=(Rhythm& p, Integer& i) { Return p.quotient() <= i; }
	friend Bool operator<=(Integer& i, Rhythm& p) { Return i <= p.quotient(); }

	friend Bool operator==(Real& r, Rhythm& p) { Return r == p.quotient(); }
	friend Bool operator==(Rhythm& p, Real& r) { Return p.quotient() == r; }
	friend Bool operator!=(Real& r, Rhythm& p) { Return r != p.quotient(); }
	friend Bool operator!=(Rhythm& p, Real& r){ Return p.quotient() != r; }
	friend Bool operator>=(Rhythm& p, Real& r) { Return p.quotient() >= r; }
	friend Bool operator>=(Real& r, Rhythm& p) { Return r >= p.quotient(); }
	friend Bool operator>(Rhythm& p, Real& r) { Return p.quotient() > r; }
	friend Bool operator>(Real& r, Rhythm& p) { Return r > p.quotient(); }
	friend Bool operator<=(Rhythm& p, Real& r) { Return p.quotient() <= r; }
	friend Bool operator<=(Real& r, Rhythm& p) { Return r <= p.quotient(); }


public:

	/// Default constructor
	Rhythm() : m_num(0), m_den(0) { }

	/// Default constructor
	Rhythm(Integer i) : m_num(i), m_den(i) { }

	/// Construct rhythm given a fractional rhythmic value.
	/// @param x Rhythmic fraction expressed as a Real
	Rhythm(Real x) : m_num(0), m_den(0) { RealToRational( x, m_num, m_den ); }

	/// Construct rhythm given a rational fraction rhythmic value.
	/// @param num Numerator of rational fraction
	/// @param den Denominator of rational fraction
	Rhythm(Integer num, Integer den) : m_num(num), m_den(den) { 
		If (m_den == 0)
			m_den = 1;
	}

	/// Construct rhythm given a Real fractional rhythmic value, determine its rational approximation, assign numerator and denominator to reference arguments.
	/// @param x Real fractional reference rhythmic value
	/// @param num Reference Integer numerator of derived rational fraction approximation
	/// @param den Reference Integer denominator of derived rational fraction approximation 
	Rhythm(Real x, Integer& num, Integer& den) : m_num(0), m_den(0) { 
		RealToRational( x, num, den ); 
		m_num = num;
		m_den = den;
	}

	/// Construct rhythm given a Rhythm, determine its rational approximation, assign numerator and denominator to reference arguments.
	/// @param x Rhythmic value
	/// @param num Reference Integer numerator of derived rational fraction approximation
	/// @param den Reference Integer denominator of derived rational fraction approximation
	Rhythm(Rhythm x, Integer& num, Integer& den) : m_num(0), m_den(0) { 
		RealToRational( x.quotient(), num, den ); 
		m_num = num;
		m_den = den;
	}

	/// Rhythm equality operator
	Bool operator==(Const Rhythm& x) Const {
		Return m_num == x.m_num  And m_den == x.m_den;
	}

	/// Rhythm inequality operator
	Bool operator!=(Const Rhythm& x) Const {
		Return m_num != x.m_num || m_den != x.m_den;
	}
	
	/// Rhythm >= operator
	Bool operator>=(Const Rhythm& x) Const {
		Return quotient() >= x.quotient();
	}

	/// Rhythm > operator
	Bool operator>(Const Rhythm& x) Const {
		Return quotient() > x.quotient();
	}

	/// Rhythm < operator
	Bool operator<(Const Rhythm& x) Const {
		Return quotient() < x.quotient();
	}

	/// Rhythm <= operator
	Bool operator<=(Const Rhythm& x) Const {
		Return quotient() <= x.quotient();
	}

	/// Rhythm plus-equals operator
	Rhythm& operator+=(Const Real x) {
		Return( *this = Rhythm(quotient() + x) );
	}

	/// Rhythm plus-equals operator
	Rhythm& operator+=(Rhythm x) {
		Return( *this = Rhythm(quotient() + x.quotient()) );
	}

	/// Rhythm minus-equals operator
	Rhythm& operator-=(Const Real x) {
		Return( *this = quotient() - x );
	}

	/// Rhythm minus-equals operator
	Rhythm& operator-=(Rhythm x) {
		Return( *this = quotient() - x.quotient() );
	}

	/// Rhythm times-equals operator
	Rhythm& operator*=(Const Real x) {
		Return( *this = quotient() * x );
	}

	/// Rhythm times-equals operator
	Rhythm& operator*=(Rhythm x) {
		Return( *this = quotient() * x.quotient() );
	}

	/// Rhythm divide-equals operator
	Rhythm& operator/=(Const Real x) {
		Return( *this = quotient() / x );
	}

	/// Rhythm divide-equals operator
	Rhythm& operator/=(Rhythm x) {
		Return( *this = quotient() / x.quotient() );
	}

	/// Rhythm addition operator
	Rhythm operator+(Rhythm& x) {
		Return( Rhythm(quotient() + x.quotient()) );
	}

	/// Rhythm subtraction operator
	Rhythm operator-(Rhythm& x) {
		Return( Rhythm(quotient() - x.quotient()) );
	}

	/// Rhythm times operator
	Rhythm operator*(Rhythm& x) {
		Return( Rhythm(quotient() * x.quotient()) );
	}

	/// Rhythm divide operator
	Rhythm operator/(Rhythm& x) {
		Return( Rhythm(quotient() / x.quotient()) );
	}

	/// Rhythm add to Real operator
	Rhythm operator+(Const Real x) {
		Return( Rhythm(quotient() + x) );
	}

	/// Rhythm subtract from Real operator
	Rhythm operator-(Const Real x) {
		Return( Rhythm(quotient() - x) );
	}

	/// Rhythm multiply by Real operator
	Rhythm operator*(Const Real x) {
		Return( Rhythm(quotient() * x) );
	}

	/// Rhythm divide by Real operator
	Rhythm operator/(Const Real x) {
		Return( Rhythm(quotient() / x ) );
	}

	/// Print Rhythm prefixed by String
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
	
	/// Return the tempo used by all Rhythm instances to determine tempo
	Static Real tempo(Void) { 
		Return s_tempo; 
	}

	/// Set the tempo used by all Rhythm instances to determine tempo
	/// @return Current tempo
	Static Real tempo(Real t) {
		Real s = s_tempo;
		s_tempo = t;
		Return s;
	}

	/// Return the duration of a Rhythm given a Real beats per minute
	/// @param beats Rhythm indicating a duration to measure in time
	/// @param perMinute Real value indicating how many beats occupy a minute
	/// @return Corresponding duration of rhythmic value in seconds
	Real mm( Rhythm beats, Real perMinute ) Const { 
		Return( 1.0 / (4.0 * beats.quotient()) * 60.0 / perMinute ); 
	}

	/// Return the duration of this Rhythm at the prevailing tempo
	Real duration( ) { 
		Return ( quotient() * s_fourQuarters );
	}

	/// Return the absolute duration of this Rhythm
	Real absDuration( ) Const { 
		Return ( Real(m_num) / Real(m_den) );
	}

private:
	
	Real quotient() Const { Return( s_tempo * m_num / m_den ); }
	Static Real mmInit( Rhythm beats, Real perMinute ) { 
		Real x = ( 1.0 / (4.0 * (Real(beats.m_num) / Real(beats.m_den))) * 60.0 / perMinute );
		Return x;
	}

private:
	Integer m_num;
	Integer m_den;
	Static Real s_tempo;
	Static Real s_fourQuarters;
	Static char s_buf[128];
};

/// Calculate the tempo coefficient corresponding to some rhythmic duration B
/// at some tempo T.  B can be expressed as a ratio of reals, e.g., 1.0/4.0
/// for a quarternote.  The expression
/// metronome( 1.0/4.0, 60.0 )
/// returns the tempo coefficient for "quarter note gets the beat and there are
/// sixty beats per minute".  Hence, it returns 1.0.
Real metronome( Rhythm B, Real T );

/// Calculate the actual duration of a Real with the implicit
/// tempo scale applied, as a fraction of a whole note.  For example,
/// SetTempoScale( 0.5 );
/// Print( Duration( 1.0/4.0 ) );
/// prints 0.125.
Real Duration( Real x ); 

/// Calculate the actual duration of a Rhythm with the implicit
/// tempo scale applied, as a fraction of a whole note.
Real Duration( Rhythm x ); 

/// Calculate the absolute duration of a Real without the implicit
/// tempo scale applied, as a fraction of a whole note.
Real AbsDuration( Real x ); 

/// Calculate the absolute duration of a Rhythm without the implicit
/// tempo scale applied, as a fraction of a whole note.
Real AbsDuration( Rhythm x ); 

/// Set the tempo used by all instances of Rhythm
Void SetTempoScale( Real ts );

//////////////////////////////////////////////////////////////////////////////
///	\defgroup RhyVars Global Rhythm Variables
///	Simple rhythmic durations.
///@{

extern Rhythm 
	Whole,		///< Duration of a whole note
	Half, 		///< Duration of a half note
	Quarter,	///< Duration of a quarter note 
	Eighth, 	///< Duration of a eighth note
	Sixteenth	///< Duration of a sixteenth note
; 
///@}

#endif // RHYTHM_H
