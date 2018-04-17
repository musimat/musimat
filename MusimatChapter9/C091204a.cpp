#include "MusimatChapter9.h"
MusimatChapter9Section(C091204a) {
	Print("*** Sampling without Replacement ***");
	/*****************************************************************************
	 
	 Sampling without Replacement
	 
	 We can generate a randomly selected 12-tone row, for example, 
	 by putting 12 balls in an urn, each marked with one of the chromatic pitch classes, and draw them out 
	 one at a time without replacement, thereby guaranteeing that no pitch class is chosen more than once.
	 
	 Random(0, 11) returns a random integer between 0 and 11 with equal probability. But it could 
	 return the same value multiple times, so we must keep track of which pitch classes have been cho-
	 sen to ensure that it eventually picks one of each. This function takes one argument, N, determining 
	 the length of the row.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

IntegerList randomRow(Integer N) {
	IntegerList L; 						// keep track of pitches chosen so far
	IntegerList M; 						// used to build up random 12-tone row
	Integer i;
	
	// set all list elements to zero, which means "unused"
	For (i = 0; i < N; i = i + 1) {
		L[i] = 0;
	}
	
	// build up M, marking off elements in L when they are chosen
	i = 0;
	While (i < N) {
		Integer x = Random(0, N - 1);	 	// returns integer random value
		If (L[x] == 0) { 					// hasn't been chosen yet?
			L[x] = 1; 						// mark it "used"
			M[i] = x; 						// save result
			i = i + 1; 					// increment control variable
		}
	}
	Return(M);
}

Static Void para1() {
	/*****************************************************************************
	 Note that the second loop keeps repeating over and over until Random() has finally selected 
	 all N pitch classes. It then returns the newly created 12-tone row in M. 
	 *****************************************************************************/
	Print("*** Random Row ***"); 
	Print("A random row:", randomRow(12));
	
	/*****************************************************************************
	 Here is an example row created by randomRow(): 
	 
	 {0, 6, 2, 9, 7, 5, 4, 10, 8, 3, 1, 11}; 
	 
	 Every pitch class is represented exactly once.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: C091204a.cpp,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
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


