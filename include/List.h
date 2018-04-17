/* $Revision: 1.5 $ $Date: 2006/09/08 18:56:52 $ $Author: dgl $ $Name:  $ $Id: List.h,v 1.5 2006/09/08 18:56:52 dgl Exp $ */
#ifndef LIST_H
#define LIST_H

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

///	@file List.h
///	The basic List class template

#include <assert.h>
#include <memory.h>
#include <iostream>

/// The List class template is used to construct lists of all types, Integer, Real, Complex, Pitch, Rhythm, etc.
/// List automatically adjusts its length to accommodate whatever index is provided, therefore, no initial bounds
/// must be provided when the list is created.  Simply indexing an element of the list causes it to come
/// into being, initialized to 0 (for reference), or to the value being assigned.

template <class Type>
class List
{
	/// Print list to output stream.
	/// List is printed as '{' \<elem0\> ',' \<elem1\> ',' ... '}'
	friend ostream& operator<<(ostream& os,Const List& r) {
		If (r.m_len > 0)
			os << "(";
		for (Integer i = 0; i < r.m_len; i++) {
			os << r.m_val[i];
			If (i != r.m_len-1)
				os << ", ";
			Else
				os << ")";
		}
		os << endl;
		Return os;
	 }

	/// Lists are auto-ranging in size.
	/// This function reallocates the memory for a list to match
	/// its length requirements.
	 friend Void adjustSize(Integer len, List& r) {
		If (r.m_val == 0) {
			r.m_val = new Type [ r.m_len = len+1 ];
		} Else If (r.m_len <= len) {
			r.m_len = len+1;
			r.m_val = (Type*) realloc( r.m_val, r.m_len * sizeof(Type));
		}
	 }

	 /// Read a list from the input stream.
	 /// List is read as '(' \<elem0\> ',' \<elem1\> ',' ... ')'
	 friend istream& operator>>(istream& is, List& r) {
		 char ch;
		 Type t;
		 Integer len = 0;
		 is >> ch;
		 If (ch != '{' And ch != '(')
			 Return is;
		 While (is >> t >> ch And ch == ',') {
			adjustSize(len, r);
			r.m_val[len++] = t;
		 }
		adjustSize(len, r);
		r.m_val[len++] = t;
		assert( ch == '}' || ch == ')');
		Return is;
	 }

public:

	/// Default List constructor.
	/// @see ~List
	List() : m_val(0), m_len(0) { }

	/// List copy constructor.
	/// @param L List to copy
	/// @see ~List
	/// @return The copied list
	List( List Const& L ) {
		m_val = new Type [ m_len = L.m_len ];
		memcpy(m_val, L.m_val, sizeof(Type) * m_len);
	}

	/// List constructor for a list of length 1.
	/// @param i_ First value
	/// @see ~List
	/// @return the created list containing one element i_
	List(Type i_) { 
		m_val = new Type [ m_len = 1 ];
		m_val[0] = i_; 
	}

	/// List constructor for a list of length 2.
	/// @param i1_ First value
	/// @param i2_ Second value
	/// @see ~List
	/// @return the created list containing 2 elements
	List(Type i1_, Type i2_)  { 
		m_val = new Type [ m_len = 2 ];
		m_val[0] = i1_; 
		m_val[1] = i2_; 
	}

	/// List constructor for a list of length 3.
	List(Type i1_, Type i2_, Type i3_)  {
		m_val = new Type [ m_len = 3 ];
		m_val[0] = i1_; 
		m_val[1] = i2_; 
		m_val[2] = i3_; 
	}

	/// List constructor for a list of length 4.
	List(Type i1_, Type i2_, Type i3_, Type i4_)  {
		m_val = new Type [ m_len = 4 ];
		m_val[0] = i1_; 
		m_val[1] = i2_; 
		m_val[2] = i3_; 
		m_val[3] = i4_; 
	}

	/// List constructor for a list of length 5.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_)  {
		m_val = new Type [ m_len = 5 ];
		m_val[0] = i1_; 
		m_val[1] = i2_; 
		m_val[2] = i3_; 
		m_val[3] = i4_; 
		m_val[4] = i5_; 
	}

	/// List constructor for a list of length 6.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_)  {
		m_val = new Type [ m_len = 6 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_; 
	}

	/// List constructor for a list of length 7.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_, Type i7_)  {
		m_val = new Type [ m_len = 7 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_;  m_val[6] = i7_; 
	}

	/// List constructor for a list of length 8.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_, Type i7_, Type i8_)  {
		m_val = new Type [ m_len = 8 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_;  m_val[6] = i7_;  m_val[7] = i8_; 
	}

	/// List constructor for a list of length 9.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_, Type i7_, Type i8_, Type i9_)  {
		m_val = new Type [ m_len = 9 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_;  m_val[6] = i7_;  m_val[7] = i8_; 
		m_val[8] = i9_;
	}

	/// List constructor for a list of length 10.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_, Type i7_, Type i8_, Type i9_, Type i10_)  {
		m_val = new Type [ m_len = 10 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_;  m_val[6] = i7_;  m_val[7] = i8_; 
		m_val[8] = i9_; m_val[9] = i10_;
	}

	/// List constructor for a list of length 11.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_, Type i7_, Type i8_, Type i9_, Type i10_, Type i11_)  {
		m_val = new Type [ m_len = 11 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_;  m_val[6] = i7_;  m_val[7] = i8_; 
		m_val[8] = i9_; m_val[9] = i10_; m_val[10] = i11_;
	}

	/// List constructor for a list of length 12.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_, Type i7_, Type i8_, Type i9_, Type i10_, Type i11_, Type i12_)  {
		m_val = new Type [ m_len = 12 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_;  m_val[6] = i7_;  m_val[7] = i8_; 
		m_val[8] = i9_; m_val[9] = i10_; m_val[10] = i11_; m_val[11] = i12_;
	}

	/// List constructor for a list of length 13.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_, Type i7_, Type i8_, Type i9_, Type i10_, Type i11_, Type i12_, Type i13_)  {
		m_val = new Type [ m_len = 13 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_;  m_val[6] = i7_;  m_val[7] = i8_; 
		m_val[8] = i9_; m_val[9] = i10_; m_val[10] = i11_; m_val[11] = i12_; m_val[12] = i13_;
	}

	/// List constructor for a list of length 14.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_, Type i7_, Type i8_, Type i9_, Type i10_, Type i11_, Type i12_, Type i13_, Type i14_ )  {
		m_val = new Type [ m_len = 14 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_;  m_val[6] = i7_;  m_val[7] = i8_; 
		m_val[8] = i9_; m_val[9] = i10_; m_val[10] = i11_; m_val[11] = i12_; m_val[12] = i13_; m_val[13] = i14_;
	}

	/// List constructor for a list of length 15.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_, Type i7_, Type i8_, Type i9_, Type i10_, Type i11_, Type i12_, Type i13_, Type i14_, Type i15_ )  {
		m_val = new Type [ m_len = 15 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_;  m_val[6] = i7_;  m_val[7] = i8_; 
		m_val[8] = i9_; m_val[9] = i10_; m_val[10] = i11_; m_val[11] = i12_; m_val[12] = i13_; m_val[13] = i14_; m_val[14] = i15_;
	}

	/// List constructor for a list of length 16.
	List(Type i1_, Type i2_, Type i3_, Type i4_, Type i5_, Type i6_, Type i7_, Type i8_, Type i9_, Type i10_, Type i11_, Type i12_, Type i13_, Type i14_, Type i15_,
		Type i16_, Type i17_, Type i18_, Type i19_, Type i20_, Type i21_, Type i22_ )  {
		m_val = new Type [ m_len = 22 ];
		m_val[0] = i1_; m_val[1] = i2_;  m_val[2] = i3_; m_val[3] = i4_; m_val[4] = i5_; m_val[5] = i6_;  m_val[6] = i7_;  m_val[7] = i8_; 
		m_val[8] = i9_; m_val[9] = i10_; m_val[10] = i11_; m_val[11] = i12_; m_val[12] = i13_; m_val[13] = i14_; m_val[14] = i15_;
		m_val[15] = i16_; m_val[16] = i17_; m_val[17] = i18_; m_val[18] = i19_; m_val[19] = i20_; m_val[20] = i21_; m_val[21] = i22_;
	}

	/// Default List destructor.
	~List() { 
		If ( m_val )
			delete [] m_val; 
		m_val = 0;
		m_len = 0;
	}

	/// List equality operator.
	/// Two lists are equal if they have the same length and all elements in corresponding positions are identical.
	Bool operator==( Const List& L ) {
		If ( L.m_len != m_len )
			Return(False);
		For( Integer i = 0; i < length(); i++ ) {
			If ( L.m_val[i] != m_val[i] )
				Return( False );
		}
		Return( True );
	}

	/// List inequality operator.
	Bool operator!=( Const List& L ) {
		If ( L.m_len != m_len )
			Return(True);
		Integer cnt = 0;
		For( Integer i = 0; i < length(); i++ ) {
			If ( L.m_val[i] == m_val[i] )
				cnt++;
		}
		Return( cnt != m_len );
	}

	/// List concatenation/copy operator, joins lists together.
	/// @param L List to concatenate to this
	/// @returns Concatenated lists
	List& operator+=( Const List& L ) {
		m_val = (Type*) realloc( m_val, (m_len + L.m_len) * sizeof(Type));
		memcpy(&m_val[m_len], L.m_val, sizeof(Type) * L.m_len);
		m_len += L.m_len;
		Return( *this );
	}

	/// List concatenation operator, joins lists together.
	/// @param L List to concatenate to this
	/// @returns Concatenated lists
	List operator+( Const List &L ) {
		List r = *this;
		r += L;
		Return r;
	}

	/// List assignment operator.
	/// @param L List to assign to this
	/// @returns Assigned list
	List& operator=( Const List& L ) {
		If (this == &L)
			Return *this;
		If (m_val != 0)
			delete [] m_val;
		m_val = new Type [ m_len = L.m_len ];
		memcpy(m_val, L.m_val, sizeof(Type) * m_len);
		Return( *this );
	}

	/// List indexing operator.
	/// Performs range checking.
	/// @param elem Integer index of list element to return
	/// @returns Indexed list element
	Type& operator[]( Integer elem ) {
		assert( elem >= 0);
		checkSize(elem);
		Return m_val[elem];
	}

	/// List increment operator, adds Integer to value of all elements of list.
	/// @param x Integer value to add to all elements of list
	/// @returns Modified list
	List& operator+=( Const Type x ) {
		For ( Integer i = 0; i < m_len; i++ )
			m_val[i] += x;
		Return( *this );
	}

	/// List decrement operator, subtracts Integer to value from all elements of list.
	/// @param x Integer value to subtract from all elements of list
	/// @returns Modified list
	List& operator-=( Const Type x ) {
		For ( Integer i = 0; i < m_len; i++ )
			m_val[i] -= x;
		Return( *this );
	}

	/// List addition operator, adds Integer to value of all elements of list.
	/// @param x Integer value to add to all elements of list
	/// @returns Modified list
	List& operator+( Const Type x ) {
		List* t = new List (*this);
		*t = *this; // copy this
		For ( Integer i = 0; i < m_len; i++ )
			t->m_val[i] += x;
		Return( *t );
	}

	/// List subtraction operator, subtracts Integer to value from all elements of list.
	/// @param x Integer value to subtract from all elements of list
	/// @returns Modified list
	List& operator-( Const Type x ) {
		List* t = new List [ m_len ];
		*t = *this; // copy this
		For ( Integer i = 0; i < m_len; i++ )
			t->m_val[i] -= x;
		Return( *t );
	}

	/// List multiplication operator, multiplies Integer by value of all elements of list.
	/// @param x Integer value to multiply by all elements of list
	/// @returns Modified list
	List& operator*( Const Type x ) {
		List* t = new List (*this);
		*t = *this; // copy this
		For ( Integer i = 0; i < m_len; i++ )
			t->m_val[i] *= x;
		Return( *t );
	}

	/// List division operator, multiplies Integer by value of all elements of list.
	/// @param x Integer value to divide by all elements of list
	/// @returns Modified list
	List& operator/( Const Type x ) {
		List* t = new List [ m_len ];
		*t = *this; // copy this
		For ( Integer i = 0; i < m_len; i++ )
			t->m_val[i] /= x;
		Return( *t );
	}

	///// List increment operator, adds Real to value of all elements of list.
	///// @param x Real value to add to all elements of list
	///// @returns Modified list
	//List& operator+=( Const Real x ) {
	//	For ( Integer i = 0; i < m_len; i++ )
	//		m_val[i] += Type(x);
	//	Return( *this );
	//}

	///// List decrement operator, subtracts Real from value of all elements of list.
	///// @param x Real value to subtract from all elements of list
	///// @returns Modified list
	//List& operator-=( Const Real x ) {
	//	For ( Integer i = 0; i < m_len; i++ )
	//		m_val[i] -= Type(x);
	//	Return( *this );
	//}

	///// List addition operator, adds Real to value of all elements of list.
	///// @param x Real value to add to all elements of list
	///// @returns Modified list
	//List& operator+( Const Real x ) {
	//	List* t = new List (*this);
	//	*t = *this; // copy this
	//	For ( Integer i = 0; i < m_len; i++ )
	//		t->m_val[i] += Type(x);
	//	Return( *t );
	//}

	///// List subtraction operator, subtracts Real to value of all elements of list.
	///// @param x Real value to subtract from all elements of list
	///// @returns Modified list
	//List& operator-( Const Real x ) {
	//	List* t = new List [ m_len ];
	//	*t = *this; // copy this
	//	For ( Integer i = 0; i < m_len; i++ )
	//		t->m_val[i] -= Type(x);
	//	Return( *t );
	//}

	///// List multiplication operator, multiplies Real by value of all elements of list.
	///// @param x Real value to multiply by all elements of list
	///// @returns Modified list
	//List& operator*( Const Real x ) {
	//	List* t = new List (*this);
	//	*t = *this; // copy this
	//	For ( Integer i = 0; i < m_len; i++ )
	//		t->m_val[i] *= Type(x);
	//	Return( *t );
	//}

	///// List division operator, multiplies Real by value of all elements of list.
	///// @param x Real value to divide by all elements of list
	///// @returns Modified list
	//List& operator/( Const Real x ) {
	//	List* t = new List;
	//	*t = *this;
	//	For ( Integer i = 0; i < m_len; i++ )
	//		t->m_val[i] /= Type(x);
	//	Return( *t );
	//}

	/// List print method.
	/// @param s String value to print at head of list.
	Void print(String s = 0) {
		If (s)
			cout << s;
		cout << "{ ";
		cout.precision(2);
		For (Integer i = 0; i < m_len-1; i++)
			cout << m_val[i] << ", ";
		cout << m_val[m_len-1];
		cout << " }" << endl;
	}

	/// Preset list to a particular size.
	Void SetListSize(Integer n) {
        If(m_val)
			delete[] m_val;
        If (n > 0) {
            m_val = new Type[n];
            memset( m_val, 0, sizeof(Type) * n / sizeof(char) );
        }
        Else 
			m_val = NULL;
        m_len = n;
    }

	/// List range checking method.
	/// If the list is empty, the list is created.
	/// If the list exists, and it is less than length len, then it is reallocated to contain len elements.
	/// @param len Size to reallocate list, if necessary.
	/// @returns Modified list
	Void checkSize(Integer len) {
		If (m_val == 0)
			m_val = new Type [ m_len = len+1 ];
		Else If (m_len <= len) {
			m_len = len+1;
			m_val = (Type*) realloc( m_val, m_len * sizeof(Type));
		}
	}

	/// List length method.
	/// @returns Length of the list
	Integer length() { 
		Return m_len; 
	}

	/// List max method.
	/// @returns Maximum element of the list
	Type max() {
		assert(m_len > 0);
		Type max = m_val[0];
		For ( Integer i = 1; i < m_len; i++ )
			max = m_val[i] < max ? max : m_val[i];
		Return max;
	}

	/// List maxPos method.
	/// @returns index of Maximum element of the list.
	/// If multiple elements have the same max. value, this returns the first one.
	Integer maxPos() {
		assert(m_len > 0);
		Type max = m_val[0];
		Integer mp = 0;
		For ( Integer i = 1; i < m_len; i++ ) {
			If ( m_val[i] > max ) {
				max = m_val[i];
				mp = i;
			}
		}
		Return mp;
	}

	/// List min method.
	/// @returns Minimum element of the list
	Type min() {
		assert(m_len > 0);
		Type min = m_val[0];
		For ( Integer i = 1; i < m_len; i++ )
			min = m_val[i] < min ? m_val[i] : min;
		Return min;
	}

	/// List minPos method.
	/// @returns Minimum element of the list
	/// If multiple elements have the same max. value, this returns the first one.
	Integer minPos() {
		assert(m_len > 0);
		Type min = m_val[0];
		Integer mp = 0;
		For ( Integer i = 1; i < m_len; i++ ) {
			If ( m_val[i] < min ) {
				min = m_val[i];
				mp = i;
			}
		}
		Return mp;
	}

	/// Rotate list by n elements from position i.
	/// @param i Starting position, usually set to 0.
	/// @param n Number of elements to rotate.  Positive n rotates counterclockwise; negative n rotates clockwise.
	Void rotate( Integer n, Integer i = 0 ) {
		n = Mod( n, length() );			// constrain rotation to length of list
		Type x = m_val[ i ];			// store f[ i ] for use after recursion
		If ( i < length() - 1 )			// reached the end?
			rotate( n, i+1 );			// no, set up next element via recursion
		// We continue from here when the recursion unwinds
		Integer pos = PosMod( i+n, length() );	// index list modulo its length
		m_val[ pos ] = x;				// assign value of x saved above
	}

	/// Offset values of list elements by t modulo lim.
	/// Note: uses PosMod() to preserve elements within the interval 0..lim.
	/// @param t Transposition value
	/// @param lim Transposition limit
	Void transpose( Type t, Type lim ) {
		For ( Integer i = 0; i < length(); i = i + 1 ) {
			Type x = m_val[ i ] + t;
			m_val[ i ] = PosMod(x, lim);
		}
	}

	/// Invert values of list elements at limit
	/// @param lim Limit for inversion
	Void invert( Type lim ) {
		For ( Integer i = 0; i < length(); i = i + 1 ) {
			m_val[ i ] = ( lim - m_val[ i ] ) % lim;
		}
	}

	/// Retrograde values of list elements
	Void retrograde( ) {
		Integer n = length( );
		Type* t = new Type [ m_len ];
		memcpy(t, m_val, sizeof(Type) * m_len);
		For ( Integer i = 0; i < n; i = i + 1 )
			m_val[ i ] = t[ n - i - 1 ];
	}

private:
	Type* m_val;		///< The List value
	Integer m_len;		///< The List length
};



///	Return the length of a list
template<class Type> inline Integer Length( Type& L )  { Return( L.length() ); }


//////////////////////////////////////////////////////////////////////////////
///	\defgroup JoinFuns Global List Join Functions
///	Join Lists of various lengths, flattening the list 
///	that is returned.  They are used in "Musimathics" for simplicity.
///@{

/// Join 2 Lists
template<class Type> Type inline Join( Type& L1, Type& L2 ) { Return ( L1 + L2 ); }

/// Join 3 Lists
template<class Type> Type inline Join( Type& L1, Type& L2, Type& L3) { Return L1 + L2 + L3; }

/// Join 4 Lists
template<class Type> Type inline Join( Type& L1, Type& L2, Type& L3, Type& L4) { Return L1 + L2 + L3 + L4; }

/// Join 5 Lists
template<class Type> Type inline Join( Type& L1, Type& L2, Type& L3, Type& L4, Type& L5) { Return L1 + L2 + L3 + L4 + L5; }

/// Join 6 Lists
template<class Type> Type inline Join( Type& L1, Type& L2, Type& L3, Type& L4, Type& L5, Type& L6) { Return L1 + L2 + L3 + L4 + L5 + L6; }

/// Join 7 Lists
template<class Type> Type inline Join( Type& L1, Type& L2, Type& L3, Type& L4, Type& L5, Type& L6, Type& L7) { Return L1 + L2 + L3 + L4 + L5 + L6 + L7; }
//@}

/// Map -- Apply function to all elements of a list.
template<class TargetListType, class ElementType, class ListType> TargetListType Map( ListType L, ElementType (*fn)(ElementType) )
{
	For( Integer i = 0; i < Length( L ); i++ )
		L[i] = fn( L[i] );
	Return( L );
}

#endif // LIST_H
