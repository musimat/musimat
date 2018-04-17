#include "MusimatChapter9.h"
MusimatChapter9Section(C090703b) {
	Print("*** Random Real Numbers ***");
	/*****************************************************************************
	 
	 Random Real Numbers
	 
	 The LCRandom() method returns integers between 0 and c. It is straightforward 
	 to map its output to any range of Real values between an upper bound U and a 
	 lower bound L, as shown in the Random function, below.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

/*****************************************************************************
 luRandom() is a copy of the Musimat Random() function defined in Random.cpp,
 reproduced here for dydactic reasons (to keep things simple).
 *****************************************************************************/
Real luRandom(Real L = 0.0, Real U = 1.0) {
	Static Const Integer c = Musimat_Random_Seed; // defined in Random.h
	Integer i = LCRandom();			// get a random integer value
	Real r = Real(i);				// convert it to a real value
	r = r/Real(c);					// scale it to 0.0 <= r < 1.0
	Return(r * (U - L) + L);		// scale it to the range L to U
}

Static Void para1() {
	/*****************************************************************************
	 First, we use LCRandom() to get a random integer. Recall that LCRandom() 
	 forces the result to be positive. We promote its random integer result to 
	 Real and store it in r. Next, we divide it by c so its range is 0.0 <= r < 1.0. 
	 Finally, we scale it by the difference between U and L, and add L, so that 
	 the random value is bounded above by U and below by L. That way we can get 
	 a random result from a particular range of values that we can stipulate.
	 
	 Here is an example of invoking this Real Random() method:
	 *****************************************************************************/
	
	Print("*** Ten invocations of luRandom() ***");
	RealList x;
	
	For (Integer i = 0; i < 10; i++ ) {
		x[i] = luRandom(0.0, 1.0);
	}
	
	Print( x );
	
	/*****************************************************************************
	 luRandom() is declared above with initializing values for its
	 two arguments. This means luRandom() can be called with 0, 1, or 2 arguments.
	 If called with zero arguments, both initial values are employed; if called with one
	 argument, only the second initial value is employed; if called with two arguments,
	 the initial values are ignored.
	 Initial value for L defaults to 0.0, and U defaults to 1.0.  Thus, to
	 get a number in the unsigned unit interval [0,1), it suffices to invoke 
	 luRandom() without arguments, as follows:
	 *****************************************************************************/
	Print("*** Various Calls to luRandom() ***");
	Real r = luRandom();
	Print(r);
	Print("luRandom(37.5, 37.9)=", luRandom(37.5, 37.9));
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:45 $ $Author: dgl $ $Name:  $ $Id: C090703b.cpp,v 1.3 2006/09/05 08:02:45 dgl Exp $ */
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
