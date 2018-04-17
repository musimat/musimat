#include "MusimatChapter9.h"
MusimatChapter9Section(C091406a) {
	Print("*** Accumulation ***");
	/*****************************************************************************
	 Accumulation
	 
	 If we index the y-axis of figure 9.22 with a random value in the unit interval, the corresponding 
	 x-axis value will be one of the 12 pitches of the scale. Furthermore, the choice will more likely 
	 fall on a step that occupies a wider footprint on the y-axis, corresponding in this case to the 
	 lower pitches of the scale, just as we wanted. We can create the cumulative distribution function 
	 in figure 9.22 as follows:
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

RealList Reference accumulate(RealList Reference L){
	For(Integer i = 1; i < Length(L); i = i + 1) {
		L[i] = L[i] + L[i - 1];
	}
	Return(L);
}

Static Void para1() {
	/*****************************************************************************
	 Starting with the second element in the list (indexed as 1), we replace this element with its original 
	 value plus the value of the previous element. As we proceed through the list, each list element will 
	 be equal to itself plus all previous elements. Given the preparation of the RealList r performed 
	 above, Print(accumulate(r)); prints {0.15, 0.29, 0.42, 0.54, 0.64, 0.73, 0.81, 
	 0.87, 0.92, 0.96, 0.99, 1.0}.
	 
	 We have prepared the cumulative distribution function, and now we can access it with a random 
	 value to select a pitch. Pick a number in the unit interval to be the next note of the melody: 
	 *****************************************************************************/
	
	Real R = Random();
	Print(R);
	
	/*****************************************************************************
	 R will fall within the range of one of the 12 steps in figure 9.22 because both Random() and the 
	 cumulative distribution function exactly span the unit interval, 0 to 1. For example, if R equals 0.1, 
	 then by inspection of figure 9.22, we can see that R lies within the first step, which covers the inter-
	 val [0, 0.15], so the pitch that this value of R selects is C.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: C091406a.cpp,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
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

