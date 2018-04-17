#include "MusimatTutorial.h"
MusimatTutorialSection(B0120) {
	extern Integer euclid (Integer m, Integer n);
	Print("*** B.1.20 Invoking Functions ***");
	/*****************************************************************************
	 
	 B.1.20 Invoking Functions
	 
	 We had two situations where the function euclid() was followed by a list of arguments, once 
	 where it was defined, and another where it was invoked. The arguments associated with the def-
	 inition of euclid() are called its formal arguments. They are Integer m and Integer n. 
	 The values associated with its invocation (integers 91 and 416) are called its actual arguments. 
	 A function will have only one set of formal arguments that appear where the function is defined. 
	 It will have as many sets of actual arguments as there are invocations of the function in a program.
	 
	 When a function is invoked, three things happen:
	 
	 1. The values of the actual arguments are copied to the corresponding formal arguments.
	 
	 If an actual argument is a constant, its value is simply copied to the corresponding formal argu-
	 ment. Example: Print(3) copies 3 to the formal argument for Print().
	 
	 If an actual argument is a variable, its value is copied to the corresponding formal argument. Exam-
	 ple: Integer a = 3; Print(a) copies the value of a (which is 3) to the formal argument for 
	 Print().
	 
	 If an actual argument is another function, that function is evaluated first, and its return value 
	 replaces the function. Example: For the statement Print(euclid(91, 416)), first 
	 euclid(91, 416) is evaluated, and the result (which is 13) is substituted in its place. So the 
	 statement becomes Print(13). Finally, the 13 is copied to the corresponding formal argument 
	 of the Print() function.
	 
	 2. The body of the function is executed using the values copied to the formal arguments in the 
	 first step.
	 
	 3. The return value of the function is substituted for the function call in the enclosing program. 
	 
	 Here's an example. 
	 *****************************************************************************/
	
	// The following two statements ...
	Integer x = euclid(91, 416);
	Print( x );
	
	// ... are equivalent to this one statement:
	Print(euclid(91, 416));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0120.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

