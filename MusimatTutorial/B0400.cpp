#include "MusimatTutorial.h"
MusimatTutorialSection(B0400) {
	Print("*** B.4 Operator Associativity and Precedence in Musimat ***");
	/*****************************************************************************
	 
	 B.4 Operator Associativity and Precedence in Musimat
	 
	 To keep it simple, the Musimat expressions in this book are formatted to obey simple left-to-right 
	 evaluation. In fact, the rules are a little more complex because Musimat is basically C++ in 
	 sheep's clothing.
	 
	 Table B.2 
	 Operator Precedence and Associativity  
	 --------------------------------------------------------------------------------------------------------
	 Operator			Associativity		Description								Examples
	 ( )				left to right       grouping                                a * (x+y) == ax + ay
	 -					right to left		negation								-3 == -1 * 3
	 *    /				left to right		multiplication and division				a * b, a / b
	 %					left to right		remainder after integer division		10 % 3 == 1, 12 % 3 == 0
	 +    -				left to right		addition and subtraction				a + b, a - b
	 <   <=   >   >=	left to right		less-than, less-than-or-equal,			a < b, a <= b
	 greater-than, greater-than-or-equal											a > b, a >= b
	 ==    !=			left to right		equal, not equal						a == b, a != b
	 And				left to right		logical AND								False And False == False
																					False And True == False
																					True And False == False
																					True And True == True
	 Or					left to right		logical OR								False Or False == False
																					False Or True == True
																					True Or False == True
																					True Or True == True
	 =					right to left       assignment								a = b, a = b + c
	 
	 
	 Associativity of operators is generally left to right, except for assignment and negation. For 
	 example the expression a = c = d assigns the value d to c, then assigns c to a, thereby making 
	 all three have equal value.
	 
	 Table B.2 shows Musimat's simplified operator precedence and associativity in order from 
	 highest to lowest. This precedence list is a shortened version derived from C and C++. Since you 
	 can't effectively read or write computer programs unless you have memorized these rules of oper-
	 ator precedence and associativity, experts recommend that you study these tables while you brush 
	 your teeth every night (Press et al. 1988, 23).
	 
	 Warning: some expressions that might seem to have self-evident meaning can't be expressed 
	 as such in C/C++ and so don't work in Musimat either. Take the expression c > b > a, for exam-
	 ple. You'd hope it would test whether b lies between a and c. Alas. Consider this example:
	 
	 If (3 > 2 > 1) Print("True") Else Print("False")
	 
	 It first evaluates (3 > 2), which it discovers is True, and replaces this expression with the integer 
	 1 (which stands for True in C++). It then evaluates the expression ( 1 > 1 ) which is False. Prob-
	 ably not what we wanted. This example can be rewritten as follows:
	 *****************************************************************************/
	
	If (3 > 2 And 2 > 1) 
		Print("True"); 
	Else 
		Print("False");
	
	/*****************************************************************************
	 which will print True.
	 *****************************************************************************/
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0400.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

