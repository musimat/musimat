/* $Revision: 1.4 $ $Date: 2006/09/09 06:24:16 $ $Author: dgl $ $Name:  $ $Id: MusimatTutorial.cpp,v 1.4 2006/09/09 06:24:16 dgl Exp $ */

/** \mainpage The Musimat Tutorial
 
 \section about_musimatTutorial About the Musimat Tutorial
 
 The following tutorial introduction to the Musimat programming language
 is based on Appendix B of "Musimathics Vol. 1", Published by the MIT Press
 and � 2006 Gareth Loy.
 
 It can be read as HTML text in your favorite web browser, or you can step 
 through the code with your debugger to see it in action.  
 
 - To read it as text, click on the "Files" tab.  You will see a list of all
 files that make up the tutorial.  Click on the first file, B0100(), which
 corresponds to "Musimathics V1", appendix B, section 1.  Continue with
 the tutorial by clicking the links for subsequent files.
 
 - The best way to go through the Tutorial is using a debugger such as gdb,
 or the one provided in Microsoft Visual .NET C++.  To do so, follow these
 steps:
 -# Open the file MusimatTutorial.cpp.
 -# Plant a breakpoint on the first function call (named B0100()) inside 
 the main() routine at the bottom of the file.
 -# Run the program from within the debugger.
 -# The program will halt at the breakpoint you set.
 -# Step into the function B0100().  You will eventually be returned to
 the main() subroutine when B0100() returns.
 -# Step into the next function to continue.
 -# You can use your debugger to examine data structures and follow the
 execution of the code.  The output of the Print() statements in the 
 program will appear in another window (Windows) or directly on the console
 (gdb).
 
 In order to follow the flow of Appendix B of "Musimathics", the tutorial had 
 to be broken into a set of unique functions.  You can follow the narrative 
 through the tutorial by using your debugger to step into the next tutorial 
 function when the  previous one returns to main().  See the main() function 
 at the bottom of this file for more details.
 
 The section names in this tutorial are the
 same as Appendix B in "Musimathics".  For example, tutorial function B0108()
 corresponds to the text in section B.1.8 of that appendix.
 *****************************************************************************/

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

#ifndef __GNUC__
#include "stdafx.h"
#endif
#include <iostream>

#include "MusimatTutorial.h"

#ifndef __GNUC__
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	// Plant your first breakpoint on the line below containing 
	// B0100().  Then run the program, which will stop just 
	// before executing that function.  To start the tutorial, use the 
	// debugger's "step into" command to step into the function.
	B0100();	// Introduction to Musimat -- The programming language for "Musimathics"
	
	// When you get here, you've finished stepping through B0100().
	// To continue the tutorial, use the debugger's "step into" command to 
	// step into the next function.
	B0101();	// B.1.1 Basic Elements
	
	// Use the debugger's "step into" command to continue the tutorial
	// by stepping into each of the following functions.
	// For some sections, there may be additional functions for you
	// to visit within each file.
	B0102();	// B.1.2 Statements and Expressions
	B0103();	// B.1.3 Data Types
	B0104();	// B.1.4 Constants
	B0105();	// B.1.5 Variables
	B0106();	// B.1.6 Reserved Words
	B0107();	// B.1.7 Lists
	B0108();	// B.1.8 Operators and Operands
	B0109();	// B.1.9 Assignment
	B0110();	// B.1.10 Relations
	B0111();	// B.1.11 Logical Operations
	B0112();	// B.1.12 Operator Precedence and Associativity
	B0113();	// B.1.13 Type Promotion and Type Coercion
	B0114();	// B.1.14 Accessing List Elements
	B0115();	// B.1.15 Functions
	B0116();	// B.1.16 Conditional Statements
	B0117();	// B.1.17 Compound Statements
	B0118();	// B.1.18 Iteration
	B0119();	// B.1.19 User-Defined Functions
	B0120();	// B.1.20 Invoking Functions
	B0121();	// B.1.21 Scope of Variables
	B0122();	// B.1.22 Pass by Value vs. Pass by Reference
	B0123();	// B.1.23 Type Conversion
	B0124();	// B.1.24 Recursion
	B0125();	// B.1.25 Recursive Factorial
	B0126();	// B.1.26 Fibonacci Numbers
	B0127();	// B.1.27 Other Built-in Functions
	B0128();	// B.1.28 Comments
	B0129();	// B.1.29 Representing Text
	B0200();	// B.2 Music Datatypes in Musimat
	B0201();	// B.2.1 Pitch
	B0201a();	// Equal-Tempered Frequency
	B0201b();	// Pythagorean Chromatic Scale
	B0201c();	// Natural Chromatic Scale
	B0201d();	// Sruti Scale
	B0202();	// B.2.2 Rhythm
	B0203();	// B.2.3 Tempo
	B0204();	// B.2.4 Loudness
	B0300();	// B.3 Unicode (ASCII) Character Codes
	B0400();	// B.4 Operator Associativity and Precedence in Musimat
	
	Return 0;
}


