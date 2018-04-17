#include "MusimatChapter9.h"
MusimatChapter9Section(C091406b) {
	Print("*** Traversing the Cumulative Distribution Function ***");
	/*****************************************************************************
	 
	 Traversing the Cumulative Distribution Function
	 
	 To automate this, we start at the top end of the cumulative distribution function and work 
	 down. As we go, we compare the value of R to the current step size. We've gone one step too far 
	 when the value of R exceeds the step size, so we return the previous step as the answer, and stop.
	 *****************************************************************************/
	para1(); // Step into this function to continue.)
	para2(); // Step into this function to continue.)
}

Integer getIndex(RealList L, Real R){
	Integer i;
	For (i = Length(L) - 1; i >= 0; i = i - 1) {
		If (R > L[i]) {
			Return(i + 1);
		}
	}
	Return( 0 );
}

Static Void para1() {
	Print("*** Invoking getIndex() ***");
	/*****************************************************************************
	 We can invoke getIndex() as follows:
	 *****************************************************************************/
	extern RealList f; // f was defined in C091406.cpp line 24
	
	Real R = Random();
	Integer p = getIndex(f, R);  
	Print(p);
}

Static Void para2() {
	/*****************************************************************************
	 If R is 0.1, then p prints 0. Now let's bring all the pieces together. Here is a program that creates 
	 a melody of 25 pitches favoring pitches that are at the low end of the chromatic scale:
	 *****************************************************************************/
	Print("*** Melody of 25 low pitches ***");
	RealList f(12.0, 11.0, 10.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0);
	StringList n("C", "Cs", "D", "Ds", "E", "F", "Fs", "G", "Gs", "A", "As", "B", "c");
	f = normalize(f, sum(f)); 	// replace f with its normalized form
	f = accumulate(f);	// calculate cumulative distribution function
	StringList s;	// a place to put the result
	
	For (Integer i = 0; i < 25; i = i + 1) {
		Integer p = getIndex(f, Random());
		s[i] = n[p];
	}
	
	Print("Melody: ", s); 							// print the melody
	
	/*****************************************************************************
	 Running this program will generate something like figure 9.23, depending upon the values pro-
	 duced by Random(). As we see, lower pitches are favored in approximately the proportions we 
	 specified. The longer the sample melody, the more likely the pitch choices would conform on aver-
	 age to the distribution function.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: C091406b.cpp,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
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

