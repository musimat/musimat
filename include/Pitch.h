/* $Revision: 1.6 $ $Date: 2006/09/08 18:56:52 $ $Author: dgl $ $Name:  $ $Id: Pitch.h,v 1.6 2006/09/08 18:56:52 dgl Exp $ */
#ifndef PITCH_H
#define PITCH_H

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

///	@file Pitch.h
///	The Pitch class
///

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

/// Pitch implements representation and manipulation of musical pitches.
/// It operates by default on the equal tempered dodecaphonic scale, but
/// can trivially be configured to just scales, microtonal scales, and non octave-based
/// scales.

/// Pitch class implements a set of data types, conversions, and operations for musical pitches, scales, and tuning systems.
class Pitch
{
	friend ostream& operator<<(ostream&, Pitch&);
	friend istream& operator>>(istream&, Pitch&);

	friend Bool operator==(Integer& i, Pitch& p) { Return i == p.degree(); }
	friend Bool operator==(Pitch& p, Integer& i) { Return p.degree() == i; }
	friend Bool operator!=(Integer& i, Pitch& p) { Return i != p.degree(); }
	friend Bool operator!=(Pitch& p, Integer& i) { Return p.degree() != i; }
	friend Bool operator>=(Pitch& p, Integer& r) { Return p.degree() >= r; }
	friend Bool operator>=(Integer& i, Pitch& p) { Return i >= p.degree(); }
	friend Bool operator>(Pitch& p, Integer& i) { Return p.degree() > i; }
	friend Bool operator>(Integer& i, Pitch& p) { Return i > p.degree(); }
	friend Bool operator<=(Pitch& p, Integer& i) { Return p.degree() <= i; }
	friend Bool operator<=(Integer& i, Pitch& p) { Return i <= p.degree(); }

	friend Bool operator==(Real& r, Pitch& p) { Return r == p.hertz(); }
	friend Bool operator==(Pitch& p, Real& r) { Return p.hertz() == r; }
	friend Bool operator!=(Real& r, Pitch& p) { Return r != p.hertz(); }
	friend Bool operator!=(Pitch& p, Real& r){ Return p.hertz() != r; }
	friend Bool operator>=(Pitch& p, Real& r) { Return p.hertz() >= r; }
	friend Bool operator>=(Real& r, Pitch& p) { Return r >= p.hertz(); }
	friend Bool operator>(Pitch& p, Real& r) { Return p.hertz() > r; }
	friend Bool operator>(Real& r, Pitch& p) { Return r > p.hertz(); }
	friend Bool operator<=(Pitch& p, Real& r) { Return p.hertz() <= r; }
	friend Bool operator<=(Real& r, Pitch& p) { Return r <= p.hertz(); }

public:

	operator Integer() { Return degree(); }
	operator Real() { Return hertz(); }

	/// Default Pitch constructor -- sets all fields to 0
	Pitch() : m_pc(0), m_acc(0), m_oct(0) { }

	/// Pitch constructor from scale degree
	/// @param degree Scale degree
	Pitch(Integer degree) : m_pc(0), m_acc(0), m_oct(0) { 
		transpose( degree, m_pc, m_acc, m_oct ); 
	}

	/// Pitch constructor from degree/accidental/octave
	/// @param pitchClass Scale degree
	/// @param accidental Accidental
	/// @param octave Octave
	Pitch(Integer pitchClass, Integer accidental, Integer octave) : m_pc(pitchClass), m_acc(accidental), m_oct(octave) { }

	/// Pitch constructor from string encoding
	/// @param s String containing pitch encoding
	Pitch(String s);

	/// Pitch constructor from frequency in Hz
	/// @param hz Frequency of pitch in Hz.  The nearest lower pitch class
	/// is chosen.  For example, Pitch(440.5) chooses A4.
	Pitch(Real hz) : m_pc(0), m_acc(0), m_oct(0) {
		For(Integer pc = s_lowestDegree; pc < s_lowestDegree+s_highestDegree; pc++) {
			Pitch p = Pitch(pc);
			Real x = p.hertz(); // get the Hz equivalent of this pitch
			If ( x > hz) {				// have we passed our target?
				pc -= 1;
				*this = Pitch(pc); // return the pitch
				Return;
			}
		}
		// If we get here, the hz value is out of range
		*this = Pitch(s_highestDegree); // Pitch is out of range, clip at top of range
	}

	/// Degree is the index of this pitch in pitch space
	/// @return The index of this pitch in pitch space.
	/// For example, Pitch p(A4); p.degree(); returns 48
	Integer degree() Const {
		Return( degree(m_pc, m_acc, m_oct) ); 
	}

	/// Find the degree corresponding to pitch
	/// @param pc pitch class
	/// @param acc accidental
	/// @param oct octave
	/// @return The degree (index) of the specified pitch
	Integer degree(Integer pc, Integer acc, Integer oct) Const {
		Return((pc + acc) + s_nDegrees * oct); 
	}

	/// The piano key index
	/// @return Piano key index of this Pitch
	Integer pianoKey() Const {
		Return( pianoKey(m_pc, m_acc, m_oct) ); 
	}

	/// Find the piano key corresponding to pitch
	/// @param pc pitch class
	/// @param acc accidental
	/// @param oct octave
	/// @return The piano key index of the specified pitch
	Integer pianoKey(Integer pc, Integer acc, Integer oct) Const {
		Return((pc + acc) + s_nDegrees * (oct - 1) + 3); 
	}

	/// Transpose pitch
	/// @param x Number of degrees to transpose by
	/// @param pc pitch class
	/// @param acc accidental
	/// @param oct octave
	/// @return The transposed Pitch
	Void transpose(Integer x, Integer& pc, Integer& acc, Integer& oct) {
		pc += acc + x;  // add the pitch, its accidental and the transposition to get raw semitones
		acc = 0; // clear the accidental
		While ( pc >= s_nDegrees ) { pc = pc - s_nDegrees; oct++; }
		While ( pc < 0 ) { pc = pc + s_nDegrees; oct--; }
		// cvt. to diatonic
		switch (pc) {			// adjust for enharmonic spelling
		case 0: Break;													// C
		case 1: If (x>0) { pc--; acc++; } Else { pc++; acc--; } Break;	// C# Db
		case 2: Break;													// D
		case 3: If (x>0) { pc--; acc++; } Else { pc++; acc--; } Break;	// D# Eb
		case 4: Break;													// E
		case 5: Break;													// F
		case 6: If (x>0) { pc--; acc++; } Else { pc++; acc--; } Break;	// F# Gb
		case 7: Break;													// G
		case 8: If (x>0) { pc--; acc++; } Else { pc++; acc--; } Break;	// G# Ab
		case 9: Break;													// A
		case 10:If (x>0) { pc--; acc++; } Else { pc++; acc--; } Break;	// A# Bb
		case 11: Break;													// B
		}
	}

	/// Void transModuloOctave(Integer x)
	/// Transposition modulo the number of degrees in the scale (s_nDegrees)
	/// @param x Degrees to transpose
	Void transModuloOctave(Integer x) {
		Integer o = m_oct;
		transpose( x, m_pc, m_acc, m_oct );
		m_oct = o;
	}

	/// Void invert()
	/// Inversion modulo the number of degrees in the scale (s_nDegrees)
	Void invert() {
		Integer p = Mod( m_pc + m_acc, s_nDegrees );
		p = Mod( s_nDegrees - p, s_nDegrees );
		transpose( p, m_pc = 0, m_acc = 0, m_oct );
	}

	/// Pitch equality operator
	Bool operator==(Const Pitch& x) Const {
		Return degree() == x.degree();
	}

	/// Pitch equality operator with Integer
	Bool operator==(Const Integer& x) Const {
		Return degree() == x;
	}

	/// Pitch equality operator with Real
	Bool operator==(Const Real& x) Const {
		Return hertz() == x;
	}

	/// Pitch inequality operator
	Bool operator!=(Const Pitch& x) Const {
		Return degree() != x.degree();
	}

	/// Pitch inequality operator with Integer
	Bool operator!=(Const Integer& x) Const {
		Return degree() != x;
	}

	/// Pitch inequality operator with Real
	Bool operator!=(Const Real& x) Const {
		Return hertz() != x;
	}

	/// Pitch >= operator
	Bool operator>=(Const Pitch& x) Const {
		Return degree() >= x.degree();
	}

	/// Pitch >= operator with Integer
	Bool operator>=(Const Integer& x) Const {
		Return degree() >= x;
	}

	/// Pitch >= operator with Real
	Bool operator>=(Const Real& x) Const {
		Return hertz() >= x;
	}

	/// Pitch > operator
	Bool operator>(Const Pitch& x) Const {
		Return degree() > x.degree();
	}

	/// Pitch > operator with Integer
	Bool operator>(Const Integer& x) Const {
		Return degree() > x;
	}

	/// Pitch > operator with Real
	Bool operator>(Const Real& x) Const {
		Return hertz() > x;
	}

	/// Pitch < operator
	Bool operator<(Const Pitch& x) Const {
		Return degree() < x.degree();
	}

	/// Pitch < operator with Integer
	Bool operator<(Const Integer& x) Const {
		Return degree() < x;
	}

	/// Pitch < operator with Real
	Bool operator<(Const Real& x) Const {
		Return hertz() < x;
	}

	/// Pitch <= operator
	Bool operator<=(Const Pitch& x) Const {
		Return degree() <= x.degree();
	}

	/// Pitch <= operator with Integer
	Bool operator<=(Const Integer& x) Const {
		Return degree() <= x;
	}

	/// Pitch <= operator with Real
	Bool operator<=(Const Real& x) Const {
		Return hertz() <= x;
	}

	/// Pitch increment operator
	Pitch& operator+=(Const Pitch x) {
		transpose( x.degree(), m_pc, m_acc, m_oct );
		Return( *this );
	}

	/// Pitch increment operator with Integer
	Pitch& operator+=(Const Integer x) {
		transpose( x, m_pc, m_acc, m_oct );
		Return( *this );
	}

	/// Pitch increment operator with Real
	Pitch& operator+=(Const Real x) {
		Real hz = hertz() + x;
		*this = Pitch( hz );
		Return( *this );
	}

	/// Pitch decrement operator
	Pitch& operator-=(Const Pitch x) {
		transpose( -x.degree(), m_pc, m_acc, m_oct );
		Return( *this );
	}

	/// Pitch decrement operator with Integer
	Pitch& operator-=(Const Integer x) {
		transpose( -x, m_pc, m_acc, m_oct );
		Return( *this );
	}

	/// Pitch decrement operator with Real
	Pitch& operator-=(Const Real x) {
		Real hz = hertz() - x;
		Return( *this = Pitch( hz ) );
	}

	/// Pitch multiply scale operator
	Pitch& operator*=(Const Pitch x) {
		Integer d = degree() * x.degree();
		Return( *this = Pitch(d) );
	}

	/// Pitch multiply scale operator with Integer
	Pitch& operator*=(Const Integer x) {
		Integer d = degree() * x;
		Return( *this = Pitch(d) );
	}

	/// Pitch multiply scale operator with Real
	Pitch& operator*=(Const Real x) {
		Real hz = hertz() * x;
		Return( *this = Pitch(hz) );
	}

	/// Pitch divide scale operator
	Pitch& operator/=(Const Pitch x) {
		Integer d = degree() / x.degree();
		Return( *this = Pitch(d) );
	}

	/// Pitch divide scale operator with Integer
	Pitch& operator/=(Const Integer x) {
		Integer d = degree() / x;
		Return( *this = Pitch(d) );

	}

	/// Pitch divide scale operator with Real
	Pitch& operator/=(Const Real x) {
		Real hz = hertz() / x;
		Return( *this = Pitch(hz) );
	}

	/// Pitch addition operator
	Pitch operator+(Const Pitch& x) {
		Return( degree() + x.degree() );
	}

	/// Pitch addition operator with Integer
	Pitch operator+(Const Integer x) {
		Return( degree() + x );
	}

	/// Pitch addition operator with Real
	Pitch operator+(Const Real x) {
		Real hz = hertz() * x;
		Return( Pitch(hz) );
	}

	/// Pitch subtraction operator
	Pitch operator-(Const Pitch& x) {
		Return( degree() - x.degree() );
	}

	/// Pitch subtraction operator with Integer
	Pitch operator-(Const Integer x) {
		Return( degree() - x );
	}

	/// Pitch subtraction operator with Real
	Pitch operator-(Const Real x) {
		Real hz = hertz() - x;
		Return( hz );
	}

	/// Pitch multiplication operator
	Pitch operator*(Const Pitch& x) {
		Return( degree() * x.degree() );
	}

	/// Pitch multiplication operator with Integer
	Pitch operator*(Const Integer x) {
		Return( degree() * x );
	}

	/// Pitch multiplication operator with Real
	Pitch operator*(Const Real x) {
		Return( hertz() * x );
	}

	/// Pitch division operator
	Pitch operator/(Const Pitch& x) {
		Return( degree() / x.degree() );
	}

	/// Pitch division operator with Integer
	Pitch operator/(Const Integer x) {
		Return( degree() / x );
	}

	/// Pitch division operator with Real
	Pitch operator/(Const Real x) {
		Real hz = hertz() / x;
		Return( Pitch(hz) );
	}

	/// Pitch modulo operator
	Pitch operator%(Const Pitch x) {
		Integer d = Mod(degree(), x.degree());
		Return( d );
	}

	/// Pitch modulo operator with Integer
	Pitch operator%(Const Integer x) {
		Integer d = Mod(degree(), x);
		Return( d );
	}

	/// Pitch modulo operator with Real
	Pitch operator%(Const Real x) {
		Real hz = Mod(hertz(), x);
		Return( Pitch(hz) );
	}

	/// Print pitch prefixed by string
	/// @param s String to prefix
	String print(String s = 0) Const {
		If (s)
			cout << s;
		Character pc = s_pcNames[ m_pc ];
		Character acc;
		switch (m_acc) {
		case 0: acc = 0; Break;			// natural
		case 1: acc = 's'; Break;		// sharp
		case -1: acc = 'b'; Break;		// flat
		case 2: acc = 'x'; Break;		// double-sharp
		case -2: acc = 'v'; Break;		// double-flat
		default: acc = 0; Break;		// natural
		}
		If (acc)
#ifdef _MSC_VER
// Disable Microsoft Visual Studio warning about sprintf()
// until is universal agreement about how to handle its insecurities
#pragma warning(push)
#pragma warning(disable: 4996)
			sprintf(s_buf, "%c%c%d", pc, acc, m_oct);
#pragma warning(pop)
#else
			sprintf(s_buf, "%c%c%d", pc, acc, m_oct);
#endif
		Else
#ifdef _MSC_VER
// Disable Microsoft Visual Studio warning about sprintf()
// until is universal agreement about how to handle its insecurities
#pragma warning(push)
#pragma warning(disable: 4996)
			sprintf(s_buf, "%c%d", pc, m_oct);
#pragma warning(pop)
#else
			sprintf(s_buf, "%c%d", pc, m_oct);
#endif
		Return s_buf;
	}

	/// The pitch class of this pitch
	Integer pitchClass() Const { Return m_pc; }

	/// The accidental of this pitch
	Integer accidental() Const { Return m_acc; }

	/// The octave of this pitch
	Integer octave() Const { Return m_oct; }

	/// The frequency in Hz of this pitch
	Real hertz() Const {
		Real R = s_HzReference;
		Real k = pitchClass() + accidental() - 9.0;
		Real o = octave() - 4.0;
		Return( R * Pow(2.0, o + k / Real(s_nDegrees) ) );
	}

	/// Set the reference frequency of the scale
	Static Void HzReference( Real ref ) { s_HzReference = ref; }

	/// Get the reference frequency of the scale
	Static Real HzReference( ) { Return( s_HzReference); }

	/// Set the index of the lowest degree in the scale's gamut
	Static Void SetLowestKey( Integer ref ) { s_lowestDegree = ref; }

	/// Set the index of the highest degree in the scale's gamut
	Static Void SetHighestKey( Integer ref ) { s_highestDegree = ref; }

	/// Set the number of degrees in the scale's gamut
	Static Void SetDegrees( Integer ref ) { s_nDegrees = ref; }

	/// Returns the chromatic degree of a diatonic step or -1 if not matched.
	/// Pitch classes are the upper- or lower-case letters A-G
	/// @return -1 if not a pitch class name
	Integer isPitchClass(char c) Const {
		switch (c) {
		case 'C': case 'c': Return 0; Break;
		case 'D': case 'd': Return 2; Break;
		case 'E': case 'e': Return 4; Break;
		case 'F': case 'f': Return 5; Break;
		case 'G': case 'g': Return 7; Break;
		case 'A': case 'a': Return 9; Break;
		case 'B': case 'b': Return 11; Break;
		default: Return -1;
		}
	}

	/// Returns an offset for a chromatic degree.
	/// Accidentals are {#,S,s}=sharp, {N,n,\<nil\>}=natural, {B,b,F,f}=flat, X=double-sharp, V=double-flat
	/// Accidentals in a pitch specification may be repeated, so that Abb equals AV equals Bbbbb, etc.
	/// @return -3 if not a pitch class name
	Integer isAccidental(char c) Const {
		switch (c) {
		case '#':           Return  1;	Break;	// sharp
		case 'S': case 's': Return  1;	Break;	// sharp
		case 'N': case 'n': Return  0;	Break;	// natural
		case 'B': case 'b':	Return -1;	Break;	// flat
		case 'F': case 'f':	Return -1;	Break;	// flat
		case 'X': case 'x':	Return  2;	Break;	// double-sharp
		case 'V': case 'v':	Return -2;	Break;	// double-flat
		default: Return -3;             Break; // may be an octave spec. with no accidental
		}
	}

private:
	Integer m_pc;					///< Pitch class
	Integer m_acc;					///< Accidental
	Integer m_oct;					///< Octave
	Static Real s_HzReference;				///< Reference frequency
	Static Integer s_lowestDegree;			///< Lowest key in the gamut
	Static Integer s_highestDegree;		///< Highest key in the gamut
	Static Integer s_nDegrees;				///< Number of degrees in the octave (or tritave, or whatever)
	Static String s_pcNames;		///< Array of single letter pitch class names for the diatonic scale
	Static char s_buf[16];			///< Temporary buffer to format string form of pitch names
};



/// The accidental of a pitch
/// @param p Pitch
/// @return Accidental of a Pitch as an Integer
inline Integer Accidental( Pitch p )
{
	Return p.accidental();
}

/// Finds the corresponding pitch class of a key index
/// @param i Key index
/// @return The pitch class of the corresponding key index
inline Integer PitchClass( Integer i ) 
{
	Return( Mod( (i - 3), 12 ) ); 
}

/// Finds the corresponding pitch class of a Pitch
/// @param p Pitch
/// @return The pitch class of the corresponding Pitch
inline Integer PitchClass( Pitch p ) 
{
	Return( p.pitchClass() ); 
}

/// Finds the corresponding octave of a key index
/// @param i Key index
/// @return The octave of the corresponding key index
inline Integer Octave( Integer i )
{
	Return( (i - 3) / 12 + 1 ); 
}

/// Returns the octave of a Pitch
/// @param p Pitch
/// @return The octave of the corresponding Pitch
inline Integer Octave( Pitch p )
{
	Return( p.octave() ); 
}

/// Return the frequency of a Pitch
/// @param p Key index
/// @return The frequency of the corresponding key index
inline Real PitchToHertz( Pitch p )
{
	Return( p.hertz() );
}

/// Return the frequency of a key index
/// @param i Key index
/// @return The frequency of the corresponding key index
inline Real KeyToHertz( Integer i ) 
{
	Real R = Pitch::HzReference();
	Integer k = PitchClass( i );
	Integer o = Octave( i );
	Return( R * pow(2.0, ( (o - 4) + k / 12) ) );
}

/// Set the number of degrees used globally by Pitch
/// @param ref # of degrees
inline Void SetDegrees( Integer ref )
{
	Pitch::SetDegrees(ref); 
}

inline Pitch Mod(Pitch p, Integer len)
{
	Return( p % len );
}

#endif // PITCH_H
