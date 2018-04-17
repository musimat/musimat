// MusimatChapter9.cpp : Defines the entry point for the console application.
//

/** \mainpage The Musimat Examples from Chapter 9 of "Musimathics" V1

\section about_musimatTutorial About the Examples

The following materials in Musimat are excerpted from Chapter 9, "Composition and
Methodology", of "Musimathics Vol. 1", Published by the MIT Press
and © 2006 Gareth Loy.

It can be read as HTML text in your favorite web browser, or you can step 
through the code with your debugger to see it in action.  

- To read it as text, click on the "Files" tab.  You will see a list of all
files that make up the tutorial with a link that says [code] at the end of 
each line.  Click on the [code] link next to the first file, C090400(), which
corresponds to "Musimathics V1", Chapter 9, section 4.  Continue with
the tutorial by clicking the links for subsequent files.

- The best way to go through the Tutorial is using a debugger such as gdb,
or the one provided in Microsoft Visual .NET C++.  To do so, follow these
steps:
-# Open the file Musimat'.cpp.
-# Plant a breakpoint on the first function call (named C090400()) inside 
the main() routine at the bottom of the file.
-# Run the program from within the debugger.
-# The program will halt at the breakpoint you set.
-# Step into the function C090400().  You will eventually be returned to
the main() subroutine when C090400() returns.
-# Step into the next function to continue.
-# You can use your debugger to examine data structures and follow the
execution of the code.  The output of the Print() statements in the 
program will appear in another window (Windows) or directly on the console
(gdb).

In order to follow the flow of Chapter 9 of "Musimathics", the tutorial had 
to be broken into a set of unique functions.  You can follow the narrative 
by using your debugger to step into the next tutorial 
function when the  previous one returns to main().  See the main() function 
at the bottom of this file for more details.

The section names in this tutorial are the
same as Chapter 9 in "Musimathics" V1.  For example, tutorial function C090400()
corresponds to the text in section Chapter 9, section 4.
*****************************************************************************/

#ifndef __GNUC__
#include "stdafx.h"
#endif
#include <iostream>
#include "MusimatChapter9.h"

#ifndef __GNUC__
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	// Plant your first breakpoint on the line below containing 
	// C090400().  Then run the program, which will stop just 
	// before executing that function.  To start, use the 
	// debugger's "step into" command to step into the function.
	C090400();	// 9.4 Program for Guido's Method

	// When you get here, you've finished stepping through C090400().
	// To continue, use the debugger's "step into" command to 
	// step into the next function.
	C090703();	// 9.7.3 Linear Congruential Method

	// Use the debugger's "step into" command to continue
	// by stepping into each of the following functions.
	// For some sections, there may be additional functions for you
	// to visit within each file.
	C090400();	// Program for Guido's Method
	C090703a();	// Seeding the Random Number Generator
	C090703b();	// Random Real Numbers
	C090703c();	// Random Integer Numbers Scaled to an Arbitrary Range
	C090903();	// 9.9.3 Circular Permutation
	C091101();	// 9.11.1 Precomposition
	C091102();	// 9.11.2 The Set Complex
	C091200();	// 9.12 Traversing and Manipulating Musical Materials
	C091201();	// 9.12.1 Deterministic Serial Methods
	C091201a();	// Cycle
	C091201b();	// Palindrome
	C091201c();	// Permutation
	C091201d();	// Transpose
	C091201e();	// Interpolated Tendency Mask
	C091201f();	// Linear Interpolation
	C091204();	// 9.12.4 Nondeterministic Serial Methods
	C091204a();	// Sampling without Replacement
	C091204b();	// Shuffle
	C091204d();	// Random Tendency Mask
	C091405();	// 9.14.5 Generating Outcomes from Probability Distributions
	C091406();	// 9.14.6 Cumulative Distribution Function
	C091406a();	// Accumulation
	C091406b();	// Traversing the Cumulative Distribution Function
	C091406c();	// A Less Boring (?) Musical Example
	C091704b();	// Brownian Nose Generator
	C091704c();	// Fractional Brownian Motion
	C091704d();	// Voss's Method

	Return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.4 $ $Date: 2006/09/09 06:23:23 $ $Author: dgl $ $Name:  $ $Id: MusimatChapter9.cpp,v 1.4 2006/09/09 06:23:23 dgl Exp $ */
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

