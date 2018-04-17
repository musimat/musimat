#include "MusimatChapter9.h"
MusimatChapter9Section(C091201a) {
	Print("*** Cycle ***");
	/*****************************************************************************
	 
	 Cycle
	 
	 This method iterates a sequence either forward or backward. It can either select successive 
	 elements or skip through the list. When it reaches the end of the list (either end), it starts over at 
	 the other end. Its inputs are
	 
	 o  The list to traverse
	 
	 o  The previous position in the list
	 
	 o  Whether to move forward (prime) or backward (retrograde)
	 
	 Its output is the next element in sequence based on its previous position in the list. As a side 
	 effect, it updates its position in the list.
	 
	 If it traverses the list forward, it returns to the head of the list when it goes past the tail. If it 
	 traverses the list in retrograde, it returns to the tail of the list when it goes past the head.
	 
	 In the following code example, setting inc to 1 moves forward one element every time 
	 cycle() is called, and setting inc to -1 moves backward one element at a time. Setting inc to 
	 any other value skips through the list by that amount, wrapping around at the ends.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

Integer cycle(IntegerList L, Integer Reference pos, Integer inc) {
	Integer i = PosMod(pos, Length(L)); // compute current index
	pos = PosMod(pos + inc, Length(L)); // compute index for next time
	Return(L[i]);
}

Static Void para1() {
	/*****************************************************************************
	 The pos argument keeps track of the position in the list. We wish to delegate to cycle() the 
	 job of managing the list position, so we declare pos as a Reference argument. Thus, when 
	 cycle() updates pos, the corresponding actual argument is changed. (If pos were not a 
	 Reference variable, any changes cycle() made to its value would be lost when it returns (see 
	 appendix B, B.1.22).
	 
	 Here's an example of invoking cycle():
	 *****************************************************************************/
	
	Print("*** Cycling a list ***");
	IntegerList L(10, 11, 12);
	Integer myPos = 0;
	Integer n = 2 * Length(L) -1; // go 1 less than two times through list
	
	For (Integer i = 0; i < n; i = i + 1)	
		Print(cycle(L, myPos, 1)); // 1 = forward direction
	
	Print("myPos=", myPos);
	
	/*****************************************************************************
	 This program prints 10, 11, 12, 10, 11. Last, it prints myPos=2, proving that cycle() is 
	 changing the myPos parameter.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:45 $ $Author: dgl $ $Name:  $ $Id: C091201a.cpp,v 1.3 2006/09/05 08:02:45 dgl Exp $ */
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

