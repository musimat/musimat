#include "MusimatTutorial.h"
MusimatTutorialSection(B0121) {
	Print("*** B.1.21 Scope of Variables ***");
	/*****************************************************************************
	 
	 B.1.21 Scope of Variables
	 
	 A function's formal arguments are said to have local scope because they flow into existence when 
	 the function begins to execute and cease to exist when the function is finished. 
	 
	 It is also possible to declare other variables within the body of a function. 
	 For example, the following function named add() defines a local variable named sum:
	 *****************************************************************************/
	
	sumExample1(); // Step into this function to continue the tutorial
	sumExample2(); // Step into this function to continue the tutorial
}

Integer add(Integer a, Integer b) {			//return the sum of a plus b
	Integer sum = a + b;
	Return(sum);
}

Static Void sumExample1() {
	
	/*****************************************************************************
	 Here is an example of calling the add() function.
	 *****************************************************************************/
	
	Integer z;
	z = add( 11, 13 );
	Print(z);
}

Static Void sumExample2() {
	
	/*****************************************************************************
	 Like the formal arguments a and b, the scope of variable sum is local to the function add(). They disappear 
	 when the function exits. The only thing that persists is the expression in the Return statement, 
	 which is passed back to the caller of the function.
	 
	 Local variables can also be declared within compound statements. For example,
	 *****************************************************************************/
	
	Integer x = 11;
	Integer y = 9;
	
	If (x > 10 And y < 10) {
		Integer sum = x + y;
		Print(sum);
	}
	
	/*****************************************************************************
	 These variables disappear when the enclosing compound statement is exited.
	 
	 Variables declared outside the scope of any function are called global variables. They are acces-
	 sible from the point they are declared until the end of the program. They are said to have global 
	 scope.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0121.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

