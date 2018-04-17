#include "MusimatTutorial.h"
MusimatTutorialSection(B0113) {
	Print("*** B.1.13 Type Promotion and Type Coercion ***");
	/*****************************************************************************
	 
	 B.1.13 Type Promotion and Type Coercion
	 
	 What if the values in an expression are not of the same type? For example, since both operands 
	 in the expression 2/3 are integers, the quotient will be an integer. The quotient of 4.5/2.25 will 
	 be a real number because both operands are reals. But what is the quotient of 2/2.25? Our options 
	 are to coerce the numerator to be a Real and then perform real division, or coerce the denominator 
	 to be an Integer and then perform integer division. Which shall it be?
	 
	 Since the set of all reals includes the set of all integers, it makes sense to promote the integer 
	 2 to the corresponding real value 2.0 and then perform real division. Musimat automatically con-
	 verts 2/2.25 into 2.0/2.25 and then performs real division. In general, integer values are auto-
	 matically promoted to reals wherever they occur in an expression with reals.
	 
	 If automatic type promotion is not desired, the type of an expression can be coerced by directly 
	 indicating its type. Consider the expression: 
	 *****************************************************************************/
	
	Print( 10/Integer(3.33) );
	
	/*****************************************************************************
	 First, the real value 3.33 is truncated to the integer value 3, then because both numerator and 
	 denominator are now integers, integer division is performed. Beware of things being done for you 
	 automatically by computers! You still must pay attention to head off unintended consequences. 
	 Consider:
	 *****************************************************************************/
	
	Print( 26/Integer(2.5) );
	
	/*****************************************************************************
	 prints 13, but
	 *****************************************************************************/
	
	Print( Integer(26/2.5) );
	
	/*****************************************************************************
	 prints 10.
	 *****************************************************************************/
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0113.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

