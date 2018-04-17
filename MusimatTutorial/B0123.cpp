#include "MusimatTutorial.h"
MusimatTutorialSection(B0123) {
	Print("*** B.1.23 Type Conversion ***");
	/*****************************************************************************
	 
	 B.1.23 Type Conversion
	 
	 We can explicitly convert Integer expressions to Real, and vice versa. For example:
	 *****************************************************************************/
	
	Real a = 10.0/3.0;
	Print(a);
	
	/*****************************************************************************
	 prints 3.333 . . . , and
	 *****************************************************************************/
	
	Integer b = Integer(a); 								// convert a to Integer
	Print(b);
	
	/*****************************************************************************
	 prints 3.
	 
	 When assigning a to b, the Real value a is converted to an Integer by truncating (discarding) 
	 the fractional part of a (that is, by discarding 0.333…), and the integer residue (3) is assigned to 
	 b. If we then write
	 *****************************************************************************/
	
	Real c =  Real(b); 
	Print(c);
	
	/*****************************************************************************
	 the integer value of b (which is 3) is converted to the equivalent Real value (3.0), which is stored 
	 in Real variable c.
	 
	 Converting from Real to Integer, we have some choices. For example, if
	 *****************************************************************************/
	
	Real p = 10.0/3.0;   // Real variable a is set to 3.333 . . .
	
	/*****************************************************************************
	 then
	 *****************************************************************************/
	
	Real d = Floor(p); // d is set to 3.0
	Print(d);
	
	/*****************************************************************************
	 sets d to 3.0. The built-in Floor() function returns the largest integer less than its Real argu-
	 ment. The statement
	 *****************************************************************************/
	
	Real x = Ceiling(p);
	Print(x);
	
	/*****************************************************************************
	 sets x to 4 because the built-in Ceiling() function returns the smallest integer greater than its 
	 argument.
	 
	 We can round a Real to the nearest whole number as follows:
	 *****************************************************************************/
	
	Real r = Floor(p + 0.5);	 						// round c to the nearest whole number
	Print(r);
	
	/*****************************************************************************
	 If a = 2.4, then Floor(a + 0.5) returns 2.0. But if a = 2.5, Floor(a + 0.5) returns 
	 3.0. Floor(a + 0.5) returns 2.0 for any value a in the range 2.0 to 2.499... and returns 
	 3.0 for any value a in the range 2.5 to 2.999.... But we don't have to do rounding ourselves, 
	 Musimat has a built-in function:
	 *****************************************************************************/
	
	Print(Round(2.49999)); 							// prints 2.0
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0123.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

