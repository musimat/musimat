#include "MusimatTutorial.h"
MusimatTutorialSection(B0110) {
	Print("*** B.1.10 Relations ***");
	/*****************************************************************************
	 
	 B.1.10 Relations
	 
	 Relational operators compare pairs of numeric values. The relational operators are:

		Operator	Comparison
		<			less than
		>			greater than
		==			equal
		!=			not equal
		<=			less than or equal
		>=			greater than or equal.
	 
	 A relational expression compares two values. If the relationship is False, the value of the
	 relational expression is 0. If the relationship is True, the value of the relational expression
	 is 1.
	 
	 For example, trivially, the expression 2 < 3 is True, because 2 is less than 3. Therefore,
	 if we evaluate this expression and print the result, the value 1 will be printed.
	 *****************************************************************************/

	Print("2 < 3 is ", 2 < 3); // will print 1
	Print("2 > 3 is ", 2 > 3); // will print 0

	/*****************************************************************************
	 Because "=" has already been given the meaning of assignment, we must choose another way to 
	 express equality, which we do by putting two equals signs together: "==". For example, the expres-
	 sion x == y is True if x and y have the same value.
	 
	 Inequality is expressed by !=, so for example, x != y is True if x and y have different values.
	 *****************************************************************************/
	
	Integer x = 2;
	Integer y = 3;
	Print("x == y is ", x == y); // will print 0
	Print("x != y is ", x != y); // will print 1
	
	/*****************************************************************************
	 Musimat defines True == 1 and False == 0.
	 *****************************************************************************/
	
	Print("True is ", True);
	Print("False is ", False);
	
	/*****************************************************************************
	 Besides Integer and Real, there is also a data type called Bool that can store
	 the truth value of a relational expression.
	 *****************************************************************************/
	
	Bool t = True;
	Bool f = False;
	Print("t == True ", t == True); // prints 1
	Print("f == False ", f == False); // prints 1
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0110.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

