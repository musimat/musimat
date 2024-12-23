#include "MusimatTutorial.h"
MusimatTutorialSection(B0124) {
	Print("*** B.1.24 Recursion ***");
	/*****************************************************************************
	 
	 B.1.24 Recursion
	 
	 Recursion means referring back to a value we've calculated previously. Consider the factorial 
	 operation where 5! means 5 x 4 x 3 x 2 x 1. We could use a For statement to calculate factorials. 
	 This function calculates factorials using iteration:
	 *****************************************************************************/
	
	para1(); // Step into this function to continue the tutorial
}

Integer factorial(Integer x) {
	Integer n = 1;
	For (Integer i = x; i > 1; i = i - 1) {
		n = n * i;
	}
	Return(n);
}

Static Void para1() {
	
	/*****************************************************************************
	 The statement
	 *****************************************************************************/
	
	Print(factorial(5));
	
	/*****************************************************************************
	 prints 120.
	 
	 We start with n = 1 and i = 5. The For loop takes the previous value of n, multiplies it by the 
	 current value of i and reassigns the value to n. It then decrements i and performs the operation 
	 repeatedly so long as i > 1.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0124.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

