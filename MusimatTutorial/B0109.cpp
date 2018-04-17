#include "MusimatTutorial.h"
MusimatTutorialSection(B0109) {
	Print("*** B.1.9 Assignment ***");
	/*****************************************************************************
	 
	 B.1.9 Assignment
	 
	 We have already seen assignment, but here's a proper introduction.
	 
	 We can assign the value of an expression to a variable using the assignment operator =. For example,
	 
	 lhs = rhs;
	 
	 assigns the expression rhs to lhs. The object on the right-hand side of the = sign (i.e., rhs) can 
	 be any expression. The object on the left-hand side (i.e., lhs) must be a variable name, with one 
	 exception. For example, the statement
	 *****************************************************************************/
	 
	 Integer s = 3 + 5;
	Print(s);
	 
	/*****************************************************************************
	 sets the value of Integer variable s to 8.
	 
	 The left-hand side of an assignment can also indicate that a certain element of a list is to receive 
	 the value on the right-hand side. For example, here's an IntegerList:
	 *****************************************************************************/
	
	IntegerList iL(10, 11, 12, 13);
	Print("Initial form of iL = ", iL);
	
	/*****************************************************************************
	 The next statement replaces the second element on the list (counting from 0) with 100:
	 *****************************************************************************/
	
	iL[2] = 100;
	
	/*****************************************************************************
	 This causes the list to become
	 
	 (10, 11, 100, 13)
	 
	 Note that lists are indexed starting at 0.
	 *****************************************************************************/
		
	Print( "After replacement of 2nd element, iL=", iL );
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0109.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

