#include "MusimatChapter9.h"
MusimatChapter9Section(C091201b) {
	Print("*** Palindrome ***");
	/*****************************************************************************
	 
	 Palindrome
	 
	 We can iterate a sequence in prime order until the last element in the sequence is 
	 reached, then iterate the sequence retrograde until the first element in the sequence is reached, then 
	 repeat.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

Integer palindrome(IntegerList L, Integer Reference pos, Integer Reference inc) {
	Integer curPos = pos;
	Integer x = cycle(L, pos, inc);
	If (curPos + inc != pos){
		inc = inc * (-1); // change direction
		pos = curPos;
	}
	Return(x); 
}

Static Void para1() {
	/*****************************************************************************
	 This method calls cycle() to do most of its work. Like cycle(), this method updates pos, 
	 but it also must update its increment argument, inc, because whenever it hits the end of the list, 
	 we want it to reverse the direction of traversal rather than start over. The extra work done by this 
	 method is to change the increment and reset the position when either end of the list is reached. Here 
	 is an example of invoking palindrome().
	 *****************************************************************************/
	
	Print("*** Palindrome ***");
	IntegerList L(10, 11, 12);
	Integer myPos = 0;
	Integer myInc = 1; // can be any positive or negative integer
	
	For (Integer i = 0; i < 2 * Length(L); i = i + 1) {
		Print(palindrome(L, myPos, myInc));
	}
	
	/*****************************************************************************
	 prints 10, 11, 12, 12, 11, 10. Note that the end of the list is printed twice. This makes it a 
	 so-called even palindrome. It would be an odd palindrome if it were 10, 11, 12, 11, 10. It is left 
	 as an exercise for the reader to adapt palindrome() to generate odd palindromes.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:45 $ $Author: dgl $ $Name:  $ $Id: C091201b.cpp,v 1.3 2006/09/05 08:02:45 dgl Exp $ */
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

