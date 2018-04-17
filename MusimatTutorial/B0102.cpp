#include "MusimatTutorial.h"
MusimatTutorialSection(B0102) { 
	Print("*** B.1.2 Statements and Expressions ***");
	/*****************************************************************************
	 
	 B.1.2 Statements and Expressions
	 
	 Most methods read, "Do this, then do that." Each "do this" step is a statement. Sequences of state-
	 ments are read left to right, then down the page. The elements of each statement, called expressions, 
	 determine what the statement is about. In many programming languages (including Musimat), 
	 semicolons (;) separate statements.
	 
	 Here is a simple example of two statements.
	 The first prints "Do this", the next prints "Then do that" to the console.
	 *****************************************************************************/
	
	Print("Do this");
	Print("Then do that");
	
	// Note, this comment is not a statement. All text to the end of the line is treated as a comment.
	
	/* This comment is also not a statement. */
	
	/*
	 Comments like this one can
	 extend over an arbitrary numbrer of lines.
	 */
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:24 $ $Author: dgl $ $Name:  $ $Id: B0102.cpp,v 1.2 2006/09/05 06:32:24 dgl Exp $ */
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

