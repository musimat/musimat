#include "MusimatChapter9.h"
MusimatChapter9Section(C090903) {
	Print("*** 9.9.3 Circular Permutation ***");
	/*****************************************************************************
	 
	 9.9.3 Circular Permutation
	 
	 A circular permutation, or rotation, occurs when the element at one end is 
	 lopped off and attached to the other end circularly (figure 9.9). There are n 
	 circular permutations of n objects. Rotation can be to the left or right by 
	 one or more places.
	 
	 Here is a method that rotates a list by an arbitrary number of places either 
	 to the right or left.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

Void rotate(IntegerList Reference f, Integer n, Integer i = 0){
	n = Mod(n, Length(f));						//constrain rotation to length of list
	Integer x = f[i];							//store f[i] for use after recursion
	If (i < Length(f)-1)							// reached the end?
		rotate(f, n, i+1);						// no, call rotate() recursively
	// continue from here when the recursion unwinds
	Integer pos = PosMod(i+n, Length(f));		// index list modulo its length
	f[pos] = x;									// assign value of x saved above
}

Static Void para1() {
	/*****************************************************************************
	 This example uses recursion to perform its function. It takes three arguments, 
	 a list f, the number n of positions to rotate by, and i, the index for where 
	 to begin, usually set to zero. If n is positive, the list is rotated to the 
	 right that many places; if n is negative, the list is rotated that many 
	 positions to the left. The first step is to constrain n modulo the length 
	 of the list so that any amount of rotation can be handled.
	 The declaration IntegerList Reference f requires a bit of explanation. We 
	 want Rotate() to modify the list that is supplied. But functions are 
	 ordinarily supplied only with copies of the value of the actual arguments 
	 (see appendix B, B.1.22). The word Reference in the declaration tells 
	 Musimat that it should supply Rotate() with the actual variable named when 
	 the function is invoked. Thus changes to the list handed to Rotate() will 
	 persist after the function is finished.
	 We need to make sure the variable pos stays within the range of valid list 
	 elements, which naturally suggests the use of Mod(), except that Mod() can 
	 return negative values. But list indexes must be strictly positive. So we 
	 use a function called PosMod(), which returns only the positive wing of 
	 modulo values (see appendix A.6).
	 
	 "Musimat" V1 Table 9.3 shows left and right rotation by various amounts for a list 
	 iL defined as follows.
	 *****************************************************************************/
	
	Print("*** Rotate examples ***");
	IntegerList iL = IntegerList(0, 1, 2, 3, 4, 5);
	Print("Starting list:", iL);
	Print("Successive forward rotations by 1:");
	
	For (Integer i = 0; i < Length(iL); i = i + 1) {
		rotate(iL, 1);
		Print(iL);
	}
	
	Print("Backward rotations by 1:");
	For (Integer i = 0; i < Length(iL); i = i + 1) {
		rotate(iL, -1);
		Print(iL);
	}
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:45 $ $Author: dgl $ $Name:  $ $Id: C090903.cpp,v 1.3 2006/09/05 08:02:45 dgl Exp $ */
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
