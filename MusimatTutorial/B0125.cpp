#include "MusimatTutorial.h"
MusimatTutorialSection(B0125) {
	Print("*** B.1.25 Recursive Factorial ***");
	/*****************************************************************************
	 
	 B.1.25 Recursive Factorial
	 
	 Here is a more direct approach to computing factorials using recursion. 
	 In standard mathematics, the "!" operator means "factorial". (This usage is
	 in conflict with standard programming languages, which typically don't have
	 a factorial operator.  Further, Musimat has taken over the "!" operator to mean "not".
	 
	 Using the mathematical form of "!" meaning factorial,  
		x! = x * (x - 1)!, 
	 which in English is "x factorial equals x times x minus 1 the quantity factorial."
	 We can write a function that calculates factorial using this expression, as shown below
	 in the function recurFactorial().
	 *****************************************************************************/
	
	para1(); // Step into this function to continue the tutorial
}

Integer recurFactorial(Integer x){
	If (x == 1) 
		Return(1);
	Else 
		Return(x * recurFactorial(x - 1));
}

Static Void para1() {
	
	/*****************************************************************************
	 This method has two states. If x == 1, we return 1 since 1! is equal to 1. Otherwise, we return 
	 x multiplied by the factorial of x - 1. Consider the statement
	 *****************************************************************************/
	
	Print(recurFactorial(5));
	
	/*****************************************************************************
	 When the recurFactorial function is called, x is assigned the value 5. Because 5 is not equal to 1, the fac-
	 torial function evaluates the Else statement and calls recurFactorial(4). Because 4 is not equal 
	 to 1, recurFactorial evaluates the Else statement and calls recurFactorial(3), and so on. 
	 Eventually, we reach recurFactorial(1), which returns 1, which is multiplied by 2, then by 3, then 
	 by 4, and finally by 5. The top-level recurFactorial() function returns the product, 120, to the 
	 Print() routine.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0125.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

