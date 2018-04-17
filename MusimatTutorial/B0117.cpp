#include "MusimatTutorial.h"
MusimatTutorialSection(B0117) {
	Print("*** B.1.17 Compound Statements ***");
	/*****************************************************************************
	 
	 B.1.17 Compound Statements
	 
	 Suppose we need to do more than one thing depending on the value of a predicate. If we need to execute 
	 multiple statements that depend upon a common predicate, we can group them together into a list of 
	 statements. For example, {m = n; n = r;} is a list of statements, also called a compound state-
	 ment. Consider steps 2 and 3 of Euclid's method (see section 9.2.2), which can be expressed:
	 *****************************************************************************/
	
	Integer m, n = 1, r = 1;
	
	If (r == 0)
		Halt(n);
	Else {
		m = n;
		n = r;
	}
	
	/*****************************************************************************
	 If r is not equal to 0, first m is assigned the value of n, and then n is assigned the value of r. We 
	 express this in Musimat by making these two steps into a compound statement.
	 
	 Any legal statement can appear within a compound statement, including other compound state-
	 ments. This means we can nest compound statements inside each other.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0117.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

