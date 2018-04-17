#include "MusimatTutorial.h"
MusimatTutorialSection(B0128) {
	Print("*** B.1.28 Comments ***");
	/*****************************************************************************
	 
	 B.1.28 Comments
	 
	 We've already been using comments, but here's a little more about them.
	 
	 It is always helpful to readers if programmers insert comments into their programs. In Musimat, 
	 any text beginning with two slashes // out to the end of the line is commentary. For example:
	 *****************************************************************************/
	
	Real a = 1, b = 2;
	Real x = a + b; // this text is commentary
	
	/*****************************************************************************
	 Sometimes it's useful to be able to put a comment anywhere, even in the middle of an expres-
	 sion. All commentary between these delimiters is ignored.
	 *****************************************************************************/
	
	x = a /* this commentary is ignored by musimat */ + b;
	
	/*****************************************************************************
	 When the expression is evaluated, all commentary is ignored, so the resulting expression is x = 
	 a + b;. Commentary between comment delimeters can extend over multiple lines of text, as necessary.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:26 $ $Author: dgl $ $Name:  $ $Id: B0128.cpp,v 1.2 2006/09/05 06:32:26 dgl Exp $ */
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

