#include "MusimatChapter9.h"
MusimatChapter9Section(C091201c) {
	Print("*** Permutation ***");
	/*****************************************************************************
	 
	 Permutation
	 
	 Iterate the supplied sequence in prime order until exhausted, then permute the 
	 entire row by inc steps and repeat from the beginning.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

Integer permute(IntegerList L, Integer Reference pos,
				Integer Reference count, Integer inc) { 
	Integer curPos = pos;							// save current position
	Integer x = cycle(L, pos, 1);					// update pos and get list value
	count = count + 1;								// increment counter
	If (count == Length(L)) {						// have we output L items from list?
		count = 0;									// reset count
		pos = curPos + inc;							// permute position for next time
	}
	Return(x); 
}

Static Void para1() {
	/*****************************************************************************
	 Here is an example of invoking permute().
	 *****************************************************************************/
	Print("*** Permutation ***");
	IntegerList L(10, 11, 12);
	Integer inc = -1;
	Integer pos = 0;
	Integer perm = 0;
	
	For (Integer i = 0; i < 3 * Length(L); i++) {
		Print(permute(L, pos, perm, inc));
	}
	
	/*****************************************************************************
	 prints 10, 11, 12, 11, 12, 10, 12, 10, 11. Because inc = -1, it skips back one place in the 
	 row every time. The trigger for it to skip is when it has output as many elements as are in the list.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:45 $ $Author: dgl $ $Name:  $ $Id: C091201c.cpp,v 1.3 2006/09/05 08:02:45 dgl Exp $ */
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

