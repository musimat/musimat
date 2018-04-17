#include "MusimatTutorial.h"
MusimatTutorialSection(B0122) {
	Print("*** B.1.22 Pass by Value vs. Pass by Reference ***");
	/*****************************************************************************
	 
	 B.1.22 Pass by Value vs. Pass by Reference
	 
	 Global variables can be accessed directly within functions. For example, this function returns the 
	 difference of global variables x and y.
	 *****************************************************************************/
	
	para1();		// Step into this function to continue the tutorial
	addExample();	// Step into this function to continue the tutorial
	para2();		// Step into this function to continue the tutorial
}


Integer x = 2; 			// x is a global variable
Integer y = 3; 			// y is a global variable

Integer subxy() { 
	Return(x - y); 
}

Static Void para1() {
	
	/*****************************************************************************
	 The above definitions of x and y are global because they occur outside the scope of a compound block or function.
	 The function subxy() accesses these global variables directly and forms their difference.
	 
	 Referencing global variables directly inside a function is not a recommended practice because 
	 it ties the function to particular individual variables, limiting its usefulness.
	 
	 The reason people are tempted to reference global variables directly inside functions is that ordi-
	 narily all that returns from a function is the expression in its Return() statement. Sometimes, it's 
	 nice to allow a function to have additional side effects. That way functions can affect more than 
	 one thing at a time in the program. But there's a better way to accomplish side effects: we can use 
	 arguments to pass in a reference to a variable from outside.
	 
	 As described in the preceding section, ordinarily only the value is copied from an actual argu-
	 ment to its corresponding formal argument. But declaring a formal argument to be of type 
	 Reference causes Musimat to let the function directly manipulate a variable supplied as an 
	 actual argument. The function doesn't get the value of the variable, it gets the variable itself. When 
	 a function changes a Reference formal argument, it changes the variable supplied as the actual 
	 argument.
	 
	 We can use Reference arguments to allow functions to have multiple effects on the variables 
	 in a program. For example, let's declare a function that takes two Reference arguments and adds 
	 10 to each of their values.
	 *****************************************************************************/
	
}


Void add10(Integer Reference a, Integer Reference b) {
	a = a + 10;
	b = b + 10;
}


Static Void addExample() {
	
	/*****************************************************************************
	 Now let's use the two global variables defined above as actual arguments to 
	 the function and then print their values:
	 *****************************************************************************/
	
	add10(x, y);
	Print(x);
	Print(y);
}

Static Void para2() {
	
	/*****************************************************************************
	 This prints 12 and 13 because the function changed the values of both global variables. This is a 
	 very handy trick.
	 
	 Here are the rules to remember:
	 
	 o An ordinary (non-Reference) formal argument provides its function with a copy of its actual 
	 argument. Changing the value of an ordinary (non-Reference) formal argument inside the func-
	 tion does not change anything outside the function, that is, such arguments have local scope. The 
	 actual arguments are said to be passed by value to the formal arguments. 
	 
	 o A Reference formal argument provides its function with direct access to the variable named 
	 as its actual argument. The actual argument must be a variable. Modifying the value of a 
	 Reference argument inside a function changes the referenced variable outside the function. 
	 Thus, the scope of a Reference formal argument is the same as the scope of its actual argument. 
	 The actual arguments are said to be passed by reference to formal arguments when they are 
	 declared to be of type Reference.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0122.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

