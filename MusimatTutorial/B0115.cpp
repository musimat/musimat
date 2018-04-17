#include "MusimatTutorial.h"
MusimatTutorialSection(B0115) {
	Print("*** B.1.15 Functions ***");
	/*****************************************************************************
	 
	 B.1.15 Functions
	 
	 Functional notation in mathematics allows us to encapsulate and name arithmetic expressions. For 
	 example, if we have defined the function f (a, b) = a + b, then f stands for a + b. The value or values 
	 in parentheses after a function name, called arguments, supply the function with inputs. Functions 
	 also typically return a result. For example, using this definition of f, 7 = f (3, 4). 
	 
	 Programming languages typically come with a set of predefined functions for the most common 
	 necessities, and they also allow new functions to be created. For example, in Musimat all oper-
	 ators also have a functional representation, so writing
	 *****************************************************************************/
	
	Real x = Divide(11.0, 4.0);
	Print("x=", x);
	
	/*****************************************************************************
	 is the same as writing
	 *****************************************************************************/
	
	Real e = 11.0/4.0;
	Print("e=", e);
	
	/*****************************************************************************
	 In this case, e is set to the quotient, 2.75. Real division is performed because both numerator 
	 and denominator are reals. If we want to perform integer division, both numerator and denominator 
	 must be integers. We could write
	 *****************************************************************************/
	
	Integer f = Divide(11, 4);
	Print("f=", f);
	
	/*****************************************************************************
	 or equivalently,
	 *****************************************************************************/
	
	Integer g = 11/4;
	Print("g=", g);
	
	/*****************************************************************************
	 In either case, f and g are set to the quotient, 2, and the remainder is discarded. To get the remainder after 
	 integer division we can write
	 *****************************************************************************/
	
	Integer h = Mod( 11, 4 ); // remainder of integer division 
	Print("h=", h);
	
	/*****************************************************************************
	 The variable h is set to 3, the remainder of 11/4. For positive integers m and n, Mod(m, n) 
	 lies between 0 and n - 1. Why is this function called Mod instead of, say, Remainder? See appen-
	 dix A, A.6. The equivalent operator form for remaindering also looks a little strange: 
	 *****************************************************************************/
	
	Integer i = 11 % 4;
	Print("i=", i);
	
	/*****************************************************************************
	 The % sign does not have its usual meaning of "percent" in Musimat. Instead, it means "remain-
	 der of integer division." Mod and % can only be applied to integer operands.
	 
	 Some useful built-in functions are not associated with operators. Exponentiation is performed 
	 by the function Pow(). These three statements,
	 *****************************************************************************/
	
	Real base = 10.0;
	Real exp = 2.0;
	Real j = Pow(base, exp);
	Print("j=", j);
	
	/*****************************************************************************
	 are equivalent to writing "j = 10.0 to the power of 2.0", and the result stored in j is 100.0. 
	 Going the other way: Log10(x) is equivalent to "log base 10 of x", and
	 *****************************************************************************/ 
	
	Real k = Log10(100.0); 
	Print("k=", k);
	
	/*****************************************************************************
	 sets k to 2.
	 
	 Another built-in function, Print(), allows us to observe the value of a variable or expression. 
	 When executed, the statements
	 *****************************************************************************/
	
	Real l = 11.0/4.0;
	Print("l=", l);
	
	/*****************************************************************************
	 display the value of l, or 2.75. The way in which the value is displayed varies with the type of the 
	 expression and the type of computer. If the computer is a person, for example, he or she might say "two 
	 point seven five." If it is an electromechanical computer, it might show the value on a display screen.
	 
	 When the predefined function Halt() is executed, the method in progress stops at that step in 
	 the program. The argument to Halt(), if any, can be used to indicate the answer or result obtained 
	 by the program up to that point.
	 
	 One final built-in function is Random(), which returns a real number in the range of 0.0 to 1.0 
	 chosen at random.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0115.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

