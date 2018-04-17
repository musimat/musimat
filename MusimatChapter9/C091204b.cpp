#include "MusimatChapter9.h"
MusimatChapter9Section(C091204b) {
	Print("*** Shuffle ***");
	/*****************************************************************************
	 
	 Shuffle
	 
	 We can create a random permutation of a row rather as one would shuffle a deck of cards. 
	 If we distinguish between the cards and their position in the deck, shuffling consists of swapping 
	 the positions of all cards a pair at a time. First, we need a way to swap the position of two cards 
	 in the deck. We can swap the position of two elements in IntegerList like this:
	 *****************************************************************************/
	para1(); // Step into this function to continue.
	para2(); // Step into this function to continue.
}

IntegerList swap(IntegerList L, Integer from, Integer to) {
	Integer x = L[to]; 				// save target value
	L[to] = L[from]; 				// swap from Æ to
	L[from] = x; 					// swap to Æ from
	Return(L);
}

Static Void para1() {
	/*****************************************************************************
	 To shuffle an entire deck of cards (or row of pitch classes), we visit each position in the list from 
	 first to last in order and swap the card at each position with a card at a randomly chosen other 
	 position. Because we use Random() to choose the position of the other card to swap, the "other" 
	 position can be any position in the deck, including the currently selected position; thus we may 
	 occasionally swap a card with its own position, leaving it where it was. However, in a subsequent 
	 step, that card might be chosen to be swapped elsewhere.
	 *****************************************************************************/
}

IntegerList shuffle(IntegerList L) {
	IntegerList M = randomRow(Length(L)); 								// elements to swap
	For (Integer i = 0; i < Length(L); i = i + 1) {
		Integer j = M[i];
		L = swap(L, i, j);
	}
	Return(L);
}

Static Void para2() {
	/*****************************************************************************
	 The first step is to generate a new row with randomRow(), which is stored in IntegerList M. 
	 Successive values of i and successive elements of M give the indexes of the elements in L that are 
	 to be swapped. Suppose we have
	 
	 L =   {0, 6, 2, 9, 7, 5, 4, 10, 8, 3, 1, 11}; // source row
	 
	 M = {5, 1, 0, 4, 6, 7, 9, 3, 10, 8, 11, 2};    // row created in shuffle
	 
	 Then each row in table 9.6 shows the intermediate values of L as its elements are being swapped. The 
	 pattern starts out like this: swap the value in position 0 and the value in position 5; swap the value 
	 in position 1 with itself; swap the value in position 2 and the value in position 0; swap the value in 
	 position 3 and the value in position 4; and so on. The result is that every element of the input row is 
	 swapped randomly with another element, but there's a chance it might be swapped with itself.
	 *****************************************************************************/
	
	Print("*** Shuffling a row ***");
	IntegerList x = IntegerList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	Print("A row:", x);
	Print("Same row after shuffling:", shuffle(x));
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: C091204b.cpp,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
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

