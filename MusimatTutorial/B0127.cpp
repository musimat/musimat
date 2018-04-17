#include "MusimatTutorial.h"
MusimatTutorialSection(B0127) {
	Print("*** B.1.27 Other Built-in Functions ***");
	/*****************************************************************************
	 
	 B.1.27 Other Built-in Functions
	 
	 Musimat includes standard mathematical functions such as Sqrt(x). There are trigono-
	 metric functions such as Sin(x), Cos(x), and Tan(x). Arguments to trigonometric functions 
	 are in real radian values. Speaking of radian measure, here's an interesting way to compute Pi to 
	 the machine precision of your computer:
	 *****************************************************************************/
	
	Const Real Pi = Atan(1.0) * 4.0; 			// arctangent of 1 times 4 equals Pi
	Print("Pi=", Pi);
	
	/*****************************************************************************
	 The function Abs(x) returns the absolute value of its argument. It works for either Real or 
	 Integer expressions. For instance, both of the following statements will print True:
	 *****************************************************************************/
	
	If (Abs(-5) == Abs(5))  // Integer Abs( )
		Print(True); 
	Else 
		Print(False);
	
	If (Abs(-5.0) == Abs(5.0)) // Real Abs( ) 
		Print(True); 
	Else 
		Print(False);
	
	/*****************************************************************************
	 With no arguments, the built-in function Random() returns a real random value between 0.0 and 
	 1.0, but if Random() is given arguments specifying Real lower and upper bounds, it returns a 
	 Real random value between those boundaries. For example,
	 *****************************************************************************/
	
	Real x = Random(0.0, 11.0);
	Print(x);
	
	/*****************************************************************************
	 returns a random Real value in the range 0.0 <= x < 11.0. Note the range is from 0.0 to almost 11.0.
	 
	 If Random() is given arguments specifying Integer lower and upper bounds, it returns an 
	 Integer random value between those boundaries. For example,
	 *****************************************************************************/
	
	Integer y = Random(0, 11);
	Print(y);
	
	/*****************************************************************************
	 returns a random Integer value in the range [0..11]. Note the range is inclusive from 0 to 11.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0127.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

