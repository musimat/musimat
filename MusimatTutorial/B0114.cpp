#include "MusimatTutorial.h"
MusimatTutorialSection(B0114) {
	Print("*** B.1.14 Accessing List Elements ***");
	/*****************************************************************************
	 
	 B.1.14 Accessing List Elements
	 
	 We can access an element of a list using the index operator []. Suppose we have the following 
	 declarations:
	 *****************************************************************************/											
	
	Integer w = 1, x = 2, y = 3, z = 4;
	IntegerList iL(w, x, y, z);
	
	/*****************************************************************************
	 Then the statement
	 *****************************************************************************/
	
	Integer c = iL[0];
	
	/*****************************************************************************
	 assigns c the same value as w (which is 1). Here's the proof:
	 *****************************************************************************/
	
	Print("c=", c);
	Print("w=", w);
	
	/*****************************************************************************
	 The statement
	 *****************************************************************************/
	
	c = iL[3];
	
	/*****************************************************************************
	 assigns c the same value as z (which is 4). 
	 *****************************************************************************/
	
	Print("Now c=", c);
	
	/*****************************************************************************
	 The first element on a list is indexed by 0, and if a List has N elements, the last one is indexed 
	 by N - 1.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0114.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

