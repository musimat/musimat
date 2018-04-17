#include "MusimatChapter9.h"
MusimatChapter9Section(C091204d) {
	Print("*** Random Tendency Mask ***");
	/*****************************************************************************
	 
	 Random Tendency Mask
	 
	 We can use a row to specify an upper boundary and another row to 
	 specify a lower boundary, and then pick a pitch in this range. We can pick any pitch in the range, either 
	 the median pitch or a random pitch or even all pitches, depending upon what we want to use it for. This 
	 example returns a random value lying between two rows that act as fences to limit the random range.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

Integer randTendency(
		IntegerList L1, Integer Reference pos1,
		IntegerList L2, Integer Reference pos2, Integer inc) {
	Integer x = cycle(L1, pos1, inc);
	Integer y = cycle(L2, pos2, inc);
	If (x < y)
		Return(Random(x, y));
	Else
		Return(Random(y, x));
}

Static Void para1() {
	/*****************************************************************************
	 For example, if L1 and L2 are as shown in the following table, the values in the middle row are 
	 random values chosen from between.  
	 *****************************************************************************/
	
	Print("*** Random Tendency Mask ***");
	IntegerList L1( 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 );
	Print("First list:", L1);
	Integer pos1 = 0;
	IntegerList L2( 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 );
	IntegerList R;
	Integer pos2 = 0;
	Integer inc = 1;
	For( Integer i = 0; i < Length( L1 ); i = i + 1 ) {
		R[ i ] = randTendency( L1, pos1, L2, pos2, inc );
	}
	Print("Result:", R);
	Print("Second list:", L2);
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: C091204d.cpp,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
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

