#include "MusimatTutorial.h"
MusimatTutorialSection(B0116) {
	Print("*** B.1.16 Conditional Statements ***");
	/*****************************************************************************
	 
	 B.1.16 Conditional Statements
	 
	 A mathematical notation for determining the sign of a number is
	 
		 | x < 0, a
	 y = |
		 | x >= 0, b
	 
	 
	 which sets y to a if x is negative; otherwise it sets y to b. Such relational expressions are called 
	 predicates. Musimat accomplishes the same thing like this:
	 *****************************************************************************/
	
	Real a = 1;
	Real b = 2;
	Real y = 5;
	
	If (y < 0) 
		y = a;
	Else 
		y = b;
	
	/*****************************************************************************
	 In this example, y receives the value of a if y is less than 0; otherwise y receives the value of b. 
	 The Else part of this construction is optional. So for example,
	 *****************************************************************************/
	
	If (a < b)
		Print(a);
	
	/*****************************************************************************
	 prints a only if it is less than b. If and Else can be combined to allow chains of predicates:
	 *****************************************************************************/
	Real r = -1.0;
	
	If (a < 0)         // is x negative?
		y = a;
	Else If (a == 0)   // it's not negative, but is it zero?
		y = b;
	Else               // neither negative nor zero, x must be positive
		y = r;
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0116.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

