#include "MusimatChapter9.h"
MusimatChapter9Section(C091101) {
	Print("*** 9.11.1 Precomposition ***");
	/*****************************************************************************
	 
	 9.11.1 Precomposition
	 
	 The process of composing atonal music is typically divided into two parts.
	 
	 o Precomposing: assembling the musical materials
	 
	 o Composing: applying the assembled materials in a design
	 
	 Musimat already has a number of data types and operations, but a few more are needed:
	 
	 o To represent pitches as symbols with integer values, such as:
	 
	 Integer C = 0, Cs = Db = 1, D = 2, Ds = Eb = 3 . . ., B = 11;
	 
	 o To represent motives as lists, such as: 
	 
	 IntegerList a = {F, F, G, A}; 
	 IntegerList b = {F, A, G}; 
	 IntegerList c = {F, E};
	 IntegerList d = {Bb, A, G, F}; 
	 IntegerList e = {E, C, D, E, F, F};
	 
	 o To combine motives and concatenate lists:
	 
	 IntegerList y = Join(a, b, a, c, a, d, e);
	 
	 (y is defined as the list of pitches of the tune "Yankee Doodle.")
	 
	 The function transpose() below transposes a pitch set.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
	para2(); // Step into this function to continue.
	para3(); // Step into this function to continue.
}

IntegerList transpose(IntegerList L, Integer t) {
	For(Integer i = 0; i < Length(L); i = i + 1) {
		L[i] = PosMod(L[i] + t, 12); // BUG: given as Mod() in "Musimat", s.b. PosMod()
	}
	Return(L);
}

Static Void para1() {
	/*****************************************************************************
	 Here is an example of transposing a list:
	 *****************************************************************************/
	
	Print("*** Transposing a list ***");
	IntegerList L( 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 );
	Print("Original row:", L);
	Print("Row transposed by 6: ", transpose(L, 6) );
	
	/*****************************************************************************
	 To invert a pitch set:
	 *****************************************************************************/
}

IntegerList invert(IntegerList L) {
	For(Integer i = 0; i < Length(L); i = i + 1) {
		L[i] = Mod(12 - L[i], 12);
	}
	Return(L);
}

Static Void para2() {
	/*****************************************************************************
	 Here is an example of inverting a list:
	 *****************************************************************************/
	Print("*** Inverting a list ***");
	IntegerList L( 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 );
	Print("Original row:", L);
	Print( "Inverted row:", invert(L) );
	
	/*****************************************************************************
	 To take the retrograde of a set:
	 *****************************************************************************/
}

IntegerList retrograde(IntegerList L) {
	Integer n = Length(L);
	IntegerList R = L;								// make a new list as long as L
	For(Integer i = 0; i < n; i = i + 1) {
		R[i] = L[n - i - 1];
	}
	Return(R);
}

Static Void para3() {
	/*****************************************************************************
	 Here is an example of retrograding a list:
	 *****************************************************************************/
	Print("*** Retrograding a list ***");
	IntegerList L( 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 );
	Print("Original row:", L);
	Print( "Retrograded row:", retrograde(L) );
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:45 $ $Author: dgl $ $Name:  $ $Id: C091101.cpp,v 1.3 2006/09/05 08:02:45 dgl Exp $ */
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

