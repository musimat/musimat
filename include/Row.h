/* $Revision: 1.4 $ $Date: 2006/09/08 18:56:52 $ $Author: dgl $ $Name:  $ $Id: Row.h,v 1.4 2006/09/08 18:56:52 dgl Exp $ */
#ifndef ROW_H
#define ROW_H

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

///	@file Row.h
///	Functions for manipulating Lists as musical rows.

//////////////////////////////////////////////////////////////////////////////
///	\defgroup RowFuns Global Row Functions
///	Functions for manipulating Lists as musical rows.
///@{

/// Rotate the elements of a List.
/// @param f Row to rotate
/// @param n Number of positions to rotate by
template<class Type> Type Reference Rotate( Type Reference f, Integer n )
{
	f.rotate(n);
	Return( f );
}

/// Transpose the elements of a List.
/// @param L List to transpose
/// @param t Number of degrees to transpose by
/// @param lim Number of scale degrees. E.g., for the equal tempered scale, lim=12 semitones.
/// @return Transposed list
template<class Type1, class Type2> Type1 Transpose( Type1 L, Type2 t, Type2 lim ) {
	L.transpose(t, lim);
	Return( L );
}


/// Transpose the elements of a PitchList.
/// Transpose performs modulus arithmetic on pitches within the scale.  That is, pitches transposed
/// outside the span of the scale are wrapped back into the scale.
/// @param L PitchList to transpose
/// @param t Number of degrees to transpose by
/// @return Transposed list
inline PitchList Transpose( PitchList L, Integer t ) {
	For ( Integer i = 0; i < L.length(); i = i + 1 ) {
		L[i].transModuloOctave(t);
	}
	Return( L );
}

/// Invert a List.
/// @param L List to invert
/// @param lim Modulo limit to apply
/// @return Inverted list
template<class Type1, class Type2> Type1 Invert( Type1 L, Type2 lim ) {
	L.invert(lim);
	Return( L );
}

/// Invert a PitchList.
/// @param L PitchList to invert
/// @param lim Modulo limit to apply
/// @return Inverted PitchList
inline PitchList Invert( PitchList L, Integer lim = 12 ) {
	For ( Integer i = 0; i < L.length(); i = i + 1 ) {
		L[i].invert();
	}
	Return( L );
}

/// Retrograde a List.
/// @param L List to retrograde
/// @return Retrograde list
template<class Type> Type Reference Retrograde( Type Reference L ) {
	L.retrograde();
	Return( L );
}

/// Create a set class (matrix) from a List.
/// @param prime Prime form of the list
/// @return The set class (matrix)
template<class MatrixType, class ListType> MatrixType SetComplex( ListType prime ) {
	Integer len = Length( prime );
	MatrixType M( len, len );
	ListType inverted = Invert( prime, 12 );
	Integer i;

	For ( i = 0; i < len; i = i + 1 ) {
		 M[0][i] = prime[i];
		 M[i][0] = inverted[i];
	}

	For ( i = 1; i < len; i = i + 1 ) {
		For ( Integer j = 1; j < len; j = j + 1 ) {
			  M[ i ][ j ] = Mod( M[ i ][ 0 ] + M[ 0 ][ j ], len);
		}
	}

	Return( M );
}

/// Traverse cyclicly through a List.
/// cycle() returns to the head of the list when it walks off the end,
/// and returns to the end of the list if it walks off the head.
/// @param L List to be traversed
/// @param pos Current position in the list.  Updated on return to new position in the list.
/// @param inc Number of list elements to skip.
/// @return The element of the list based on pos and inc
template<class ElementType, class ListType> ElementType cycle( ListType L, Integer Reference pos, Integer inc ) {
	Integer i = PosMod( pos, Length( L ) );
	pos = PosMod( pos + inc, Length( L ) );
	Return( L[ i ] );
}

/// Traverse a List palindromically.
/// palindrome() returns to the head of the list when it walks off the end,
/// and returns to the end of the list if it walks off the head.
/// palindrome() alternates traversal of prime and retrograde form
/// @param L List to be traversed
/// @param pos Current position in the list.  Updated on return to new position in the list.
/// @param inc Number of list elements to skip.
/// @return The element of the list based on pos and inc
template<class ElementType, class ListType> ElementType palindrome( ListType L, Integer Reference pos, Integer Reference inc ) {
	Integer curPos = pos;
	ElementType x = cycle<ElementType,ListType>( L, pos, inc );
	If ( curPos + inc != pos ) {
		inc = inc * (-1); // change direction
		pos = curPos;
	}
	Return( x ); 
}

/// Permute a List.
/// Iterate the supplied sequence in prime order until exhausted, then permute the entire row by inc steps and repeat from the beginning
/// @param L List to be traversed
/// @param pos Current position in the list.  Updated on return to new position in the list.
/// @param count Reference parameter that tracks the number of steps so far
/// @param inc Number of list elements to skip when we permute
/// @return The element of the list based on pos
template<class ElementType, class ListType> ElementType permute( ListType L, Integer Reference pos, Integer Reference count, Integer inc ) { 
	Integer curPos = pos;			// save the current position
	ElementType x = cycle<ElementType,ListType>( L, pos, 1 );	// update pos and get list value
	count = count + 1;				// increment counter
	If ( count == Length( L ) ) {	// have we output L items from list?
		count = 0;					// reset count
		pos = curPos + inc;			// permute position for next time
	}
	Return( x ); 
}

/// Interpolation tendency.
/// @param f Factor ranging from 0.0 to 1.0
/// @param L1 List 1
/// @param pos1 Position parameter for List 1
/// @param L2 List 2
/// @param pos2 Position parameter for List 2
/// @param inc Amount by which to adjust position
/// @return Interpolated tendency value
Integer InterpTendency( Real f, IntegerList L1, Integer Reference pos1, IntegerList L2, Integer Reference pos2, Integer inc );

/// Linear interpolation in Pitch space.
/// @param x Value ranging from xMin to xMax
/// @param xMin Minimum range of x
/// @param xMax Maximum range of x
/// @param yMin Target minimum range
/// @param yMax Target maximum range
/// @return The interpolated value
Pitch LinearInterpolate( Pitch x, Pitch xMin, Pitch xMax, Pitch yMin, Pitch yMax );

/// Use linear interpolation to map an entire function to a different range
/// @param L List to stretch
/// @param xMin Minimum value range of L
/// @param xMax Maximum value range L
/// @param yMin Minimum range of resulting stretched list
/// @param yMax Maximum range of resulting stretched list
/// @return Stretched list
template<class ElementType, class ListType> ListType stretch( ListType L, ElementType xMin, ElementType xMax, ElementType yMin, ElementType yMax ) {
	For ( Integer i = 0; i < Length( L ); i = i + 1 ) {
		 L[ i ] = ElementType( linearInterpolate( L[ i ], xMin, xMax, yMin, yMax ) );
	}
	Return( L );
}


/// RandomRow
/// @param N Length of row
/// @return Randomly generated row of length N
template<class ListType> ListType RandomRow( Integer N ) {
	IntegerList L;				// Keep track of the pitches chosen so far
	ListType M;				// Used to build up our random 12-tone row 
	Integer i;
	// First, set all list elements to zero, which means "unused"
	For ( i = 0; i < N; i = i + 1 ) {
		 L[ i ] = 0;	
	}
	// Now build up M, marking off elements in L when they are chosen
	For ( i = 0; i < N; i = i ) {
		Integer x = IRandom( 0, N - 1 );
		If ( L[ x ] == 0 ) {	// Hasn't been chosen yet?
			 L[ x ] = 1;	// Mark it "used"
			 M[ i ] = x;	// Save the result
			i = i + 1;	// Now increment the control variable
		}
	}
	Return( M );
}

/// Swap two elements in a List.
/// @param L List with elements to swap
/// @param from Index of source
/// @param to Index of destination
/// @return Modified list
template<class ElementType, class ListType> Void swap( ListType Reference L, Integer from, Integer to ) {
	ElementType x = L[ to ];		// save the target value
	 L[ to ] = L[ from ];		// swap from -> to
	 L[ from ] = x;			// swap to -> from
}

/// Perform swap() operation on every element of List, thereby shuffling it.
/// @param L List to shuffle
/// @return Shuffled list
template<class ElementType, class ListType> ListType shuffle( ListType L ) {
	// SeedRandom( 788429 );	// Uncomment to test alternative shuffle
	ListType M = RandomRow<ListType>( Length( L ) ); // Determine what elements to swap
	Print( "M=", M );
	For ( Integer i = 0; i < Length( L ); i = i + 1 ) {
		Integer j = M[ i ];
		swap<ElementType,ListType>( L, i, j );
	}
	Return( L );
}

/// Use a row to specify an upper boundary and another row to specify a lower boundary, and then pick a pitch in this range.
/// @param L1 List specifying upper boundary
/// @param pos1 Current position in L1
/// @param L2 List specifying upper boundary
/// @param pos2 Current position in L2
/// @param inc Amount to increment
/// \returns Random value chosen to lie in the range between indexed elements of L1 and L2
template<class ElementType, class ListType> ElementType randTendency( ListType L1, Integer Reference pos1, ListType L2, Integer Reference pos2, Integer inc ) {
	Integer x = cycle<ElementType,ListType>( L1, pos1, inc );
	Integer y = cycle<ElementType,ListType>( L2, pos2, inc );
	If ( x < y )
		Return( IRandom( x, y ) );
	Else
		Return( IRandom( y, x ) );		
}


///@}
#endif // ROW_H
