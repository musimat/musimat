#include "MusimatTutorial.h"
MusimatTutorialSection(B0107) {
	Print("*** B.1.7 Lists ***");
	/*****************************************************************************
	 
	 B.1.7 Lists
	 
	 We can group sets of variables to keep track of their relations. 
	 An IntegerList represents a collection of Integer expressions, for example,
	 *****************************************************************************/
	
	IntegerList iL(1, 1+1, 3, 5-1);
	
	/*****************************************************************************
	 defines a list iL containing the integers 1 through 4.
	 A RealList represents a collection of Real expressions:
	 *****************************************************************************/
	
	RealList rL(1.1, 2.2, 3.3, 4.4);
	
	/*****************************************************************************
	 We can print these lists as follows.
	 *****************************************************************************/
	
	Print("iL=", iL);
	Print("rL=", rL);
	
	/*****************************************************************************
	 We can obtain the length of a list of any type. For example,
	 *****************************************************************************/
	
	Integer n = Length(rL);
	Print(n);
	
	/*****************************************************************************
	 prints 4.
	 
	 The value can be seen when running this application in the console window 
	 if the output of this application has not been redirected.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0107.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

