#include "MusimatTutorial.h"
MusimatTutorialSection(B0112) {
	Print("*** B.1.12 Operator Precedence and Associativity ***");
	/*****************************************************************************
	 
	 B.1.12 Operator Precedence and Associativity
	 
	 In the expression a * x + b * y, what is the order in which the operations are carried out? By 
	 the standard rules of mathematics, we should first form the products a*x and b*y, then 
	 sum the result. So multiplication has higher precedence than addition. The natural precedence of 
	 operations can be overridden by the use of parentheses. For example, a * (x + b) * y forces the 
	 summation to occur before the multiplications.
	 
	 In the expression a + b + c, we first add a to b, then add the result to c, so the associativity 
	 of addition is left to right. We could express left-to-right associativity explicitly like this: 
	 (((a) + b) + c).
	 
	 The rules of precedence and associativity in programming languages can be complicated, but 
	 the programming examples in this section use the following simplified rules.
	 
	 Expressions are evaluated from left to right, except
	 
	 o Multiplications and divisions are performed before additions and subtractions.
	 
	 o All arithmetic operations (+, -, *, /) are performed before logical operations (And, Or, 
	 ==, <, >).
	 
	 o Parentheses override the above precedence rules.
	 
	 For details, see section B.3.
	 
	 *****************************************************************************/
	
	Integer a = 2, x = 3, b = 4, y = 5;
	Print("a * x + b * y = ", a * x + b * y); // prints 26
	Print("a * (x + b) * y = ", a * (x + b) * y); // prints 70
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0112.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

