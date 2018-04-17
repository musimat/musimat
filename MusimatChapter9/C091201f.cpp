#include "MusimatChapter9.h"
MusimatChapter9Section(C091201f) {
	Print("*** Linear Interpolation ***");
	/*****************************************************************************
	 
	 Linear Interpolation
	 
	 Linear interpolation allows us to map a range of values so that it covers 
	 a proportionately wider or narrower range. Figure 9.14 shows linear interpolation from the range 
	 1-4 on the left being mapped to the range 3-9 on the right. The value 3 on the left corresponds by 
	 linear interpolation to 7 on the right. Linear interpolation maintains the linear proportions of the 
	 two number lines: 3 is two-thirds of the way from 1 to 4, and 7 is two-thirds of the way from 3 to 9. 
	 
	 Linear interpolation is a slight generalization of unit interpolation, as follows. If xMax is 
	 the upper bound and xMin is the lower bound, and x is a parameter in the range xmin <= x <= xmax, then 
	 
	      x - xMin
	 y = ----------- (yMax - yMin) + yMin
	     xMax - xMin
	 
	 sets y to a position within the range yMin <= y <= yMax that is proportional to the position of x within 
	 its range. Below is the definition of linear interpolation in Musimat:
	 *****************************************************************************/
	para1(); // Step into this function to continue.
	para2(); // Step into this function to continue.
}

Real linearInterpolate(
		Real x,						// value ranging from xMin to xMax
		Real xMin,					// minimum range of x
		Real xMax,					// maximum range of x
		Real yMin,					// target minimum range
		Real yMax					// target maximum range
		) {
	Real a = (x - xMin) / (xMax - xMin);
	Real b = yMax - yMin;
	Return(a * b + yMin);
}

Static Void para1() {
	/*****************************************************************************
	 Here is an example of linear interpolation:
	 *****************************************************************************/
	
	Print("*** Linear Interpolation ***");
	Print("linearInterpolate(3.0, 1.0, 4.0, 3.0, 9.0) = ", linearInterpolate(3.0, 1.0, 4.0, 3.0, 9.0));
	
	/*****************************************************************************
	 We also can use linear interpolation to map an entire function to a different range. We do so by 
	 applying linear interpolation to every point on the function. For example, we can scale a chromatic 
	 melody to occupy a wider or narrower tessatura as follows:
	 *****************************************************************************/
}

IntegerList stretch(IntegerList L, Integer yMin, Integer yMax) {
	Integer xMin = Integer(Min(L)); 									// find the list's minimum
	Integer xMax = Integer(Max(L)); 									// find the list's maximum
	For (Integer i = 0; i < Length(L); i = i + 1) {
		L[i] = Integer(linearInterpolate(L[i], xMin, xMax, yMin, yMax));
	}
	Return(L);
}

Static Void para2() {
	/*****************************************************************************
	 For example, if the input is
	 *****************************************************************************/
	
	Print("*** Stretch ***");
	IntegerList L(0, 8, 10, 6, 7, 5, 9, 1, 3, 2, 11, 4);
	Print("Source list: ", L);
	
	/*****************************************************************************
	 invoking stretch() with these arguments
	 *****************************************************************************/
	
	Print("stretch(L, 24, 47)=", stretch(L, 24, 47));
	
	/*****************************************************************************
	 will scale the row to cover a two-octave range and offset it upward by one octave. 
	 Then x will be {24, 40, 44, 36, 38, 34, 42, 26, 30, 28, 47, 32}. It can also be used to com-
	 press rows. With the same input, 
	 *****************************************************************************/
	
	Print("stretch(L, 0, 5)=", stretch(L, 0, 5));
	
	/*****************************************************************************
	 will produce {0, 3, 4, 2, 3, 2, 4, 0, 1, 0, 5, 1}.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: C091201f.cpp,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
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

