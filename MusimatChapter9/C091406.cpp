#include "MusimatChapter9.h"
MusimatChapter9Section(C091406) {
	Print("*** 9.14.6 Cumulative Distribution Function ***");
	/*****************************************************************************
	 
	 9.14.6 Cumulative Distribution Function
	 
	 Let's rotate each of the weights in figure 9.21 and then concatenate them. Their sum is 78, so we divide 
	 the length of each weight by 78 so that the weights sum to a length of 1.0 (figure 9.21). We have effec-
	 tively divided up the x-axis in the unit interval into 12 areas that are proportional to the weights in the 
	 original distribution. Now we pick a random number in the unit interval with the Random() function, 
	 see which interval the number would fall in, and then determine the chosen pitch. The probability that 
	 a particular interval will be chosen is proportional to the extent of its footprint on the x-axis.
	 
	 How can we represent this formally so that a computer can do this? First, the definition
	 of list f shown below defines the weights for each pitch, lowest to highest, left to right. 
	 Note that the type of list f is RealList.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
	para2(); // Step into this function to continue.
	para3(); // Step into this function to continue.
}

RealList f(12.0, 11.0, 10.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0);

Static Void para1() {
	Print("*** Cumulative Distribution Function ***");
	Print("f=", f);
	/*****************************************************************************
	 
	 Next, we normalize the weights so that they sum to 1.0 (see appendix A, A.3).
	 Normalizing is done in two steps:
	 
	 1. Find the sum of all weights with the sum() function:
	 *****************************************************************************/
}

Real sum(RealList L) {
	Real s = 0.0;
	For (Integer i = 0; i < Length(L); i = i + 1) {
		s = s + L[i];
	}
	Return(s);
}

Static Void para2() {
	/*****************************************************************************
	 Given the definition of RealList f above, 
	 *****************************************************************************/
	
	Print("Sum of f: ", sum(f));
	
	/*****************************************************************************
	 prints 78.
	 
	 2. Divide each weight by sum(f) so that the sum of the weights equals 1.0:
	 *****************************************************************************/
}

RealList normalize(RealList L, Real s){
	For (Integer i = 0; i < Length(L); i = i + 1) {
		L[i] = L[i]/s;
	}
	Return(L);
}

Static Void para3() {
	/*****************************************************************************
	 The normalize() function can be replaced with operations performed directly on the list.
	 This statement:
	 
	 RealList r = normalize(f, sum(f));
	 
	 can be replaced with:
	 
	 RealList r = f / sum(f);
	 
	 So we don't really need the normalize() function.
	 Given the definition of RealList f above, the statements:
	 *****************************************************************************/
	
	RealList r = f / sum(f);
	Print("Normalized f=", r);
	RationalList x = RealListToRationalList(r); // RealListToRationalList is a built-in function
	Print(x);
	
	/*****************************************************************************
	 print 
	 {{2,13}, {11,78}, {5,39}, {3,26}, {4,39}, {7,78}, {1,13}, {5,78}, {2,39}, {1,26}, {1,39}, {1,78}
	 which correspond to the reduced form of the following ratios, as we'd expect:
	 {12/78, 11/78, 10/78, 9/78, 8/78, 7/78, 6/78, 5/78, 4/78, 3/78, 2/78, 1/78}.
	 
	 After these two steps, r will look like figure 9.20 except that all values are scaled down by 78. (The 
	 built-in RealToRational() function is described in appendix B, B.2.2.) 
	 
	 Next, we create a function such that each step along the x-axis accumulates all the weights to 
	 its left with its own weight (figure 9.22). The first column has a height of 12/78, the second of 
	 12/78 + 11/78, the next of 12/78 + 11/78 + 10/78, and so on. This function is called a cumulative 
	 distribution function.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.4 $ $Date: 2006/09/07 08:38:15 $ $Author: dgl $ $Name:  $ $Id: C091406.cpp,v 1.4 2006/09/07 08:38:15 dgl Exp $ */
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

