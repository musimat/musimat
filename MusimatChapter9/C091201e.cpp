#include "MusimatChapter9.h"
MusimatChapter9Section(C091201e) {
	Print("*** Interpolated Tendency Mask ***");
	/*****************************************************************************
	 
	 Interpolated Tendency Mask
	 
	 We can produce a new row that is a mixture of two other rows. 
	 Let's have a variable that varies continuously between 0.0 and 1.0 such that when it is 0.0, the out-
	 put row is exactly the same as the first row; when it is 0.5, the output is exactly halfway between 
	 the first and second; and when it is 1.0, the output is exactly the second row. For example, suppose 
	 the first pitches in each row are 3 and 9, and the interpolation parameter is 0.5. Then the expected 
	 result would be 6 because 6 lies halfway between the two values. If the interpolation parameter 
	 were 0.0, we'd select 3, and if it were 1.0, we'd select 9.
	 
	 Table 9.5 shows what happens if row A = {0, 2, 4, 6, 8, 10, 12} and row B = {12, 10, 8, 6, 4, 
	 2, 0}, and f  is set successively to 0.0, 0.25, 0.5, 0.75, and 1.0. When f = 0, we select the prime row, 
	 when f = 1.0, we select the retrograde row, and in between, we select weighted mixtures.
	 
	 We use unit interpolation to find intermediate values that lie a certain distance between two 
	 known points. If u is the upper bound and l is the lower bound and f  is a control parameter in the 
	 unit distance from 0.0 to 1.0, then
	 
	 y = f * (u - l) + l
	 
	 sets y to a value close to u if 0 is close to f; it sets y to a value close to l 
	 if f is close to 1; it sets y to a value exactly halfway between u and l if f = 0.5. 
	 
	 Below is the function for unit interpolation:
	 *****************************************************************************/
	para1(); // Step into this function to continue.
	para2(); // Step into this function to continue.
}

Static Void para1() {
	/*****************************************************************************
	 This is a Real function because f must be a Real to take on fractional values. 
	 Here are some examples of calling this function.
	 *****************************************************************************/
	
	Print("*** Unit Interpolation ***");
	Print("unitInterp(0.1, 0, 10)=", unitInterp(0.1, 0, 10));
	Print("unitInterp(0.5, 0, 10)=", unitInterp(0.5, 0, 10));
	Print("unitInterp(0.9, 0, 10)=", unitInterp(0.9, 0, 10));
	
	/*****************************************************************************
	 When we use it  as follows, we convert the Real result back to an Integer by rounding:
	 *****************************************************************************/
}

Integer interpTendency(
		Real f,									// factor ranging from 0.0 to 1.0
		IntegerList L1, Integer Reference pos1,	// list 1 and its position parameter
		IntegerList L2, Integer Reference pos2,	// list 2 and its position parameter
		Integer inc								// amount by which to adjust position
		) {
	Integer x = cycle(L1, pos1, inc);
	Integer y = cycle(L2, pos2, inc);
	Return(Integer(Round(unitInterp(f, x, y))));
}

Static Void para2() {
	/*****************************************************************************
	 This function can perform a couple of neat tricks. First, we can have the function return exactly L1 
	 or L2 by setting f = 0.0 or f = 1.0, respectively. By setting f = 0.5, we get the average of the 
	 two rows. By gradually changing the value of f from 0.0 to 1.0, we mutate L1, transforming it grad-
	 ually until it becomes L2. Also, the lengths of L1 and L2 need not be the same. If L1 has a length of 
	 5 and L2 a length of 6, it will take 5 Þ 6 iterations before the pattern repeats. Both lists use the same 
	 increment, but redesigning this to use separate increments would provide for even more possibilities.
	 *****************************************************************************/
	
	IntegerList X(10, 20, 30, 40, 50, 60);
	IntegerList Y(9,   8,  7,  6,  5,  4, 3);
	IntegerList Z;
	Integer posX = 0;
	Integer posY = 0;
	Integer inc = 1;
	Integer i;
	
	Print("*** Interpolation Tendency ***");
	Print("First row: ", X);
	Print("Second row: ", Y);
	
	For ( i = 0; i < Length( X ); i = i + 1 ) {
		Z[i] = interpTendency(0.0, X, posX, Y, posY, inc);
	}
	
	Print("interpTendency factor=0.0:", Z );
	
	posX = posY = 0; // reset to beginning
	For ( i = 0; i < Length( X ); i = i + 1 ) {
		Z[i] = interpTendency(0.5, X, posX, Y, posY, inc);
	}
	
	Print("interpTendency factor=0.5:", Z );
	
	posX = posY = 0; // reset to beginning
	For ( i = 0; i < Length( X ); i = i + 1 ) {
		Z[i] = interpTendency(1.0, X, posX, Y, posY, inc);
	}
	
	Print("interpTendency factor=1.0:", Z );
	
	posX = posY = 0; // reset to beginning
	For ( i = 0; i < Length( X ); i = i + 1 ) {
		Z[i] = interpTendency(Real(i)/Length(X), X, posX, Y, posY, inc);
	}
	
	Print("interpTendency factor=(0.0 -> 1.0):", Z );
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: C091201e.cpp,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
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

