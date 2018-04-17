#include "MusimatTutorial.h"
MusimatTutorialSection(B0105) {
	Print("*** B.1.5 Variables ***");
	/*****************************************************************************
	 
	 B.1.5 Variables
	 
	 We've seen variables already, but here's a proper introduction to them.
	 
	 Variables are named places to store data. Names are indicated by one or more upper- or lower-case 
	 letters, like Q, n, or fred. Alphabetic case is significant, so fred  denotes a different variable than 
	 does Fred. Numbers can also be used in variable names (for example,  Fred33), but the first letter 
	 of a variable name may not be a number.
	 
	 Since they physically embody data, variables occupy space and time. Variables flow into 
	 existence when they are defined, and generally hold their value until the end of the program 
	 unless additional steps are taken to change their value or to restrict their existence to a certain 
	 region of the program.
	 
	 Here are some examples of Integer and Real variables.  The examples also show the initialization
	 of the variables with initial constant values using the assignment operator '='.
	 
	 *****************************************************************************/
	
	Integer a = 3;	// Define variable a and assign it an initial value of 3
	Real b = 3.14;	// Define variable b and assign it an initial value of 3.14
	Print("a=", a);
	Print("b=", b);
	
	// "Camel case" can make long variable names (slightly) easier to read
	Integer hereIsAFunnyVariableNameUsingCamelCase = 666;
	Print( hereIsAFunnyVariableNameUsingCamelCase );
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:24 $ $Author: dgl $ $Name:  $ $Id: B0105.cpp,v 1.2 2006/09/05 06:32:24 dgl Exp $ */
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

