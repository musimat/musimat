#include "MusimatTutorial.h"
MusimatTutorialSection(B0119) {
	Print("*** B.1.19 User-Defined Functions ***");
	/*****************************************************************************
	 
	 B.1.19 User-Defined Functions
	 
	 Musimat, like most programming languages, allows users to define their own functions. Take 
	 Euclid's method, for example. To define it, we must state how the input variables m and n receive 
	 their inputs, and determine what happens to the result when the method halts. We can define a func-
	 tion named euclid() in Musimat as follows:
	 *****************************************************************************/
	testEuclid(); // The tutorial continues in this function (step into the function).
}

Integer euclid (Integer m, Integer n){
	Repeat { 
		Integer r = Mod(m, n); 
		If (r == 0)  
			Return(n);
		Else  { 
			m = n; 
			n = r; 
		}
	}
}

Void testEuclid() {
	/*****************************************************************************
	 The function euclid() is declared to be of type Integer because it will return an Integer result. 
	 
	 Note that Return(n) has been substituted for the Halt(n) function shown previously. Instead 
	 of halting execution altogether, the Return(n) statement only exits the current function, carrying 
	 with it the value of its argument back to the context that invoked it. The program can then continue 
	 executing from there, if there are statements following its invocation. Here's an example of invok-
	 ing the euclid() function:
	 *****************************************************************************/											
	
	Integer x = euclid(91, 416);
	Print(x);
	
	/*****************************************************************************
	 which will print 13. If we had used Halt() in euclid(), we'd never reach the Print statement 
	 because the program would stop.
	 
	 Here's another way to compute the same thing:
	 *****************************************************************************/
	
	Print(euclid(91, 416));
	
	/*****************************************************************************
	 This way we can eliminate the "middleman" variable x, which only existed to carry the value from 
	 the euclid() function to the Print() function. In this example, the call to the euclid() func-
	 tion is nested within the Print() function. Musimat invokes the nested function first, and the 
	 value that euclid() returns is supplied automatically as an argument to the enclosing function, 
	 Print(). Functions can be nested to an arbitrary extent. The most deeply nested function is 
	 always called first.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0119.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

