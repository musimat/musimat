#include "MusimatTutorial.h"
MusimatTutorialSection(B0108) {
	Print("*** B.1.8 Operators and Operands ***");
	/*****************************************************************************
	 
	 B.1.8 Operators and Operands
	 
	 The symbols + and - are operators, and the data they act upon are operands. Most operators take 
	 two operands, and the operator lies between the operands, for example, a + b, and c / d. Such 
	 operators are called binary infix, meaning that the operator lies between two operands. In its binary 
	 infix form, the symbol "-" means subtraction, for example, a - b. The unary prefix "-" operator 
	 comes before the expression it negates, for example, -3.
	 *****************************************************************************/

	Print("2 + 2 = ", 2 + 2);
	Print("-3 = ", -3);
	
	/*****************************************************************************
	 
	 Multiplication in mathematics is typically expressed by the concatenation of variables, so for 
	 instance in standard mathematics parlance, "at" means the product of variables a and t. 
	 But this can be ambiguous, because at could 
	 also refer to the English word "at". 
	 To avoid ambiguity, the infix operator "*" indicates multiplication, 
	 so the product of m times n is written m * n.
	 
	 *****************************************************************************/
	
	Integer m = 2;
	Integer n = 3;
	Print("m * n = ", m * n);
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0108.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

