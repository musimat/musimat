#include "MusimatTutorial.h"
MusimatTutorialSection(B0111) {
	Print("*** B.1.11 Logical Operations ***");
	/*****************************************************************************
	 
	 B.1.11 Logical Operations
	 
	 Logical operators compare truth values. For example, the expression x And y is True if and only 
	 if x == True and y == True. The expression x Or y is True if either x == True or 
	 y == True.
	 *****************************************************************************/
	
	Bool applesAreRed = True;
	Bool bananasAreYellow = True;
	Bool nightIsDay = False;

	Print("applesAreRed And bananasAreYellow is ", applesAreRed And bananasAreYellow); // prints 1
	Print("applesAreRed And nightIsDay is ", applesAreRed And nightIsDay); // prints 0
	
	Print("applesAreRed Or bananasAreYellow is ", applesAreRed Or bananasAreYellow); // prints 1
	Print("applesAreRed Or nightIsDay is ", applesAreRed Or nightIsDay); // prints 1

	/*****************************************************************************
	 
	 B.1.11 Logical Operations
	 
	 We can invert the sense of a Bool expression with the operator "!".
	 *****************************************************************************/
	
	Print("!applesAreRed is ", !applesAreRed); // prints 0
	
	Print("applesAreRed Or !bananasAreYellow is ", applesAreRed Or !bananasAreYellow); // prints 1
	Print("!applesAreRed Or nightIsDay is ", applesAreRed Or !nightIsDay); // prints 1

	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0111.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

