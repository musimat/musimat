#include "MusimatTutorial.h"
MusimatTutorialSection(B0103) {
	Print("*** B.1.3 Data Types ***");
	/*****************************************************************************
	 
	 B.1.3 Data Types
	 
	 To begin, we need only two types of numbers, Integer, which is a positive or negative whole 
	 number, and Real, which is an approximate real number. To keep things simple, let's assume for 
	 our purposes that we have virtually unlimited precision for computations. As we go along, I intro-
	 duce additional data types as needed.
	 
	 *****************************************************************************/
	
	Integer x;		// This statement introduces a variable "x" which can store an integer.
	x = 3;			// This statement assigns the value 3 to integer "x".
	Integer y = 7;	// We can combine steps: we define y as an Integer and assign it the value 7.
	
	Real pi = 3.14;	// Real variables can store real numbers
	Real pi2 = 22.0/7.0; // We can initialize variables with expressions.
	
	// Now let's print out the values we just created
	Print("x=", x);
	Print("y=", y);
	Print("pi=", pi);
	Print("pi2=", pi2);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:24 $ $Author: dgl $ $Name:  $ $Id: B0103.cpp,v 1.2 2006/09/05 06:32:24 dgl Exp $ */
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

