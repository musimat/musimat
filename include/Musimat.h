/* $Revision: 1.5 $ $Date: 2006/09/08 18:56:52 $ $Author: dgl $ $Name:  $ $Id: Musimat.h,v 1.5 2006/09/08 18:56:52 dgl Exp $ */
#ifndef MUSIMAT_H
#define MUSIMAT_H

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
///	@file Musimat.h
///	@brief Declarations of Musimat datatypes and global functions
///

using namespace std;

#include "Aliases.h"
#include "MathFuns.h"
#include "Complex.h"
#include "List.h"
#include "Matrix.h"
#include "Rational.h"
#include "Rhythm.h"
#include "Pitch.h"

//////////////////////////////////////////////////////////////////////////////
/// Pi computed to the machine precision of a Real.
extern Const Real Pi;

//////////////////////////////////////////////////////////////////////////////
///	\defgroup ListTypeDefs Definitions of List Types
///	These typedefs simplify the declaration of List types.
///@{

///	A List of type Integer
typedef List<Integer> IntegerList;

///	A List of type Real
typedef List<Real> RealList;

///	A List of type String
typedef List<String> StringList;

/// A List of complex values
typedef List<Complex> ComplexList;

/// A List of type Pitch
typedef List<Pitch> PitchList;

/// A List of type Rational
typedef List<Rational> RationalList;

/// A List of type Rhythm
typedef List<Rhythm> RhythmList;
//@}

//////////////////////////////////////////////////////////////////////////////
///	\defgroup MatrixTypeDefs Definitions of Matrix Types
///@{

///	A Matrix of type Integer
typedef Matrix<Integer> IntegerMatrix;

///	A Matrix of type Real
typedef Matrix<Real> RealMatrix;

///	A Matrix of type String
typedef Matrix<String> StringMatrix;

/// A Matrix of complex values
typedef Matrix<Complex> ComplexMatrix;

/// A Matrix of type Pitch.
typedef Matrix<Pitch> PitchMatrix;

/// A Matrix of type Rational.
typedef Matrix<Rational> RationalMatrix;

/// A Matrix of type Rhythm.
typedef Matrix<Rhythm> RhythmMatrix;

//@}
//////////////////////////////////////////////////////////////////////////////

#include "Random.h"
#include "Dynamics.h"
#include "Pitches.h"
#include "Row.h"

//////////////////////////////////////////////////////////////////////////////
///	\defgroup MinMaxFuns Vector Min/Max Functions
///	Vector min/max functions, return minimum, maximum, minimum position, and maximum position of elements of a List.
/// List can be any defined type, such as RealList, IntegerList, Rhythm, Pitch, Complex, etc.
///@{

///	Maximum value of List L.
///	@param L List
template<class ListType> inline Real Max( ListType L ) { Return( L.max() ); }
inline Complex Max( ComplexList L ) { Return( L.max() ); }
inline Integer Max( IntegerList L ) { Return( L.max() ); }
inline Rhythm Max( RhythmList L ) { Return( L.max() ); }
inline Rational Max( RationalList L ) { Return( L.max() ); }
inline Pitch Max( PitchList L ) { Return( L.max() ); }

///	Index of the maximum value of List L.
///	@param L List
template<class ListType> inline Integer MaxPos( ListType L ) { Return( L.maxPos() ); }

///	Minimum value of list L.
///	@param L List
template<class Type> inline Real Min( Type L ) { Return( L.min() ); }
inline Complex Min( ComplexList L ) { Return( L.min() ); }
inline Integer Min( IntegerList L ) { Return( L.min() ); }
inline Rhythm Min( RhythmList L ) { Return( L.min() ); }
inline Rational Min( RationalList L ) { Return( L.min() ); }
inline Pitch Min( PitchList L ) { Return( L.min() ); }

///	Index of the minimum value of list L.
///	@param L List
template<class Type> inline Integer MinPos( Type L ) { Return( L.minPos() ); }
///@}

//////////////////////////////////////////////////////////////////////////////
///	\defgroup PrintFuns Scalar and Vector Print Functions
///	Type can be any defined type, such as RealList, IntegerList, Rhythm, Pitch, Complex, etc.
///@{

/// Global print function.
/// Type may be any scalar or vector type.
template<class Type> Void Print(Type i) { cout << i << endl; }

/// Global print function with prefix string.
/// Type may be any scalar or vector type.
template<class Type> Void Print(String s, Type i) { cout << s << i << endl; }
///@}

//////////////////////////////////////////////////////////////////////////////
///	\defgroup LengthFuns List Length Functions
///	Length of the appropriate type List.
///@{

///	Length of a ComplexList.
///	@param L ComplexList
Integer Length( RhythmList Reference L );

///	String length.
///	@param s String
///	@return The length of the String
Integer Length( String s );
//@}

/// Convert a RealList to a RationalList.
/// @param R RealList
/// @return RationalList
RationalList RealListToRationalList( RealList R );

/// Convert an IntegerList to a PitchList.
/// @param L IntegerList
/// @return PitchList
inline PitchList IntegerListToPitchList( IntegerList Reference L )
{
	PitchList P;
	For( Integer i = 0; i < Length( L ); i++ )
		P[i] = L[i];
	Return P;
}

/// Convert a PitchList to an IntegerList.
/// @param P PitchList
/// @return IntegerList
inline IntegerList PitchListToIntegerList( PitchList Reference P )
{
	IntegerList L;
	For( Integer i = 0; i < Length( P ); i++ )
		L[i] = P[i];
	Return L;
}

#endif // MUSIMAT_H

