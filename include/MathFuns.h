/* $Revision: 1.4 $ $Date: 2006/09/07 08:38:33 $ $Author: dgl $ $Name:  $ $Id: MathFuns.h,v 1.4 2006/09/07 08:38:33 dgl Exp $ */
#ifndef MATHFUNS_H
#define MATHFUNS_H

// The Musimat Tutorial © 2006 Gareth Loy
// Derived from Chapter 9 and Appendix B of "Musimathics Vol. 1" © 2006 Gareth Loy 
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

#include "Musimat.h"
#include <math.h>

///	@file MathFuns.h
///	Miscellaneous mathematics functions

/// A convenient way to calculate the value of Pi.
/// Always works to the precision of your hardware.
Const Real Pi = 4.0 * atan( 1.0 );

//////////////////////////////////////////////////////////////////////////////
///	\defgroup MiscMathFuns Miscellaneous Math Functions
///	Miscellaneous scalar math functions.
///@{

///	Absolute value.
/// @param x Value
template<class Type> inline Type Abs( Type x ) { Return x < 0 ? -x : x; }

///	j modulo k.
/// Note: Because of its implementation, Type need not be an integral type.
///	@param j Base of modulo operation
///	@param k Modulus of modulo operation
template<class Type> inline Type Mod(Type j, Type k) {
	While ( j >= k ) { j = j - k; }
	While ( j <= -k ) { j = j + k; }
	Return( j );
}

///	Positive wing of j modulo k.
/// PosMod performs modulus arithmetic but returns only the positive wing of modulus values. 
/// Note: Because of its implementation, Type need not be an integral type.
///	@param j Base of modulo operation
///	@param k Modulus of modulo operation
///	Note, the result will always be positive.
template<class Type> inline Type PosMod( Type j, Type k )
{
	While ( j >= k ) {
		j = j - k; 
	}
	While ( j < 0 ) {
		j = j + k; 
	}
	Return( j );
}

///	Floor function.
///	@param x Real value
inline Real Floor( Real x ) { Return floor( x ); }

///	Ceiling function.
///	@param x Real value
inline Real Ceiling( Real x ) { Return ceil( x ); }

///	Square root.
///	@param x Real value
inline Real Sqrt( Real x ) { Return sqrt( x ); }

/// x to the power of y.
///	@param x Base
///	@param y Exponent
inline Real Pow( Real x, Real y ) { Return pow( x, y ); }

///	Log of x to the base E.
/// Note: Type must be a floating point type.
///	@param x Value
template<class Type> inline Type Log( Type x ) { Return log( x ); }

///	Log base 10 of x.
/// Note: Type must be a floating point type.
///	@param x Value
template<class Type> inline Type Log10( Type x ) { Return log( x ) / log (10.0); }

///	Arctangent of x.
/// Note: Type must be a floating point type.
///	@param x Value
template<class Type> inline Type Atan( Type x ) { Return atan( x ); }

///	Arctangent of ratio expressed as numerator x and denominator y.
/// Note: Type must be a floating point type.
///	@param x Numerator
///	@param y Denominator
template<class Type> inline Type Atan2( Type x, Type y ) { Return atan2( x, y ); }

///	Sine of Type x.
/// Note: Type must be a floating point type.
///	@param x Value
template<class Type> inline Type Sin( Type x ) { Return sin( x ); }

///	Cosine of Type x.
/// Note: Type must be a floating point type.
///	@param x Value
template<class Type> inline Type Cos( Type x ) { Return cos( x ); }

/// Unit interpolation.
/// @param f Fraction, in the range 0<=f<=1.0
/// @param L Lower bound of unit interpolation
/// @param U Upper bound of unit interpolation
/// @return The interpolated value
inline Real unitInterp( Real f, Integer L, Integer U ) {
	Return( f * ( U - L ) + L );
}

/// Linear interpolation.
/// @param x Value ranging from xMin to xMax
/// @param xMin Minimum range of x
/// @param xMax Maximum range of x
/// @param yMin Target minimum range
/// @param yMax Target maximum range
/// @return The interpolated value
inline Real linearInterpolate( Integer x, Integer xMin, Integer xMax, Integer yMin, Integer yMax ) {
	Real a = Real( x - xMin) / Real(xMax - xMin); // Real division
	Real b = Real( yMax - yMin );
	Return( a * b + yMin );
}

/// Rounding
/// @param x Value to round
/// @return Rounded value
inline Real Round( Real x ) { 
	Return( Floor( x + 0.5 ) );
}

/// Convert Real value to rational value.
/// @param f Real value
/// @param a Numerator of resulting rational value
/// @param b Denominator of resulting rational value
Integer RealToRational( Real f, Integer Reference a, Integer Reference b);

///@}

//////////////////////////////////////////////////////////////////////////////
///	\defgroup MathOps Operator Templates
///	Template functions for addition, subtraction, division, 
///	multiplication of class objects.
///@{

///	Rule for Type + Type.
template <class Type> Type Plus(Type i, Type j) { Return i + j; }

///	Rule for Type - Type.
template <class Type> Type Minus(Type i, Type j) { Return i - j; }

///	Rule for Type / Type.
template <class Type> Type Divide(Type i, Type j) { Return i / j; }

///	Rule for Type * Type.
template <class Type> Type Multiply(Type i, Type j) { Return i * j; }
///@}

#endif // MATHFUNS_H
