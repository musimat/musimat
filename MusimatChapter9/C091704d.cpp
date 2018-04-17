#include "MusimatChapter9.h"
MusimatChapter9Section(C091704d) {
	Print("*** Voss's Method ***");
	/*****************************************************************************
	 
	 Voss's Method
	 
	 Martin Gardner (1978) reported a fractal noise generator attributed to Voss. A 
	 set of random variables xk are summed on each sample n, and the result is output. The random vari-
	 ables are updated at different rates. If , then the k th variable is assigned a new random 
	 number Us. The index k ranges from 0 to N - 1. So x0 is randomized every sample, x1 is randomized 
	 every other sample, x2 is randomized every fourth sample, and so on, until finally xN-1 is only 
	 randomized every  samples.  We can code this method as follows:
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

Real VossFracRand( Integer n, RealList L ) {
	Real sum = 0.0;
	Integer N = Length( L );
	For(Integer k = 0; k < N; k = k + 1) {
		If (Mod(n, Integer(Pow(2, k))) == 0) {
			L[k] = Random(-1.0, 1.0);
		}
		sum = sum + L[ k ];
	}
	Return(sum);
}

Static Void para1() {
	/*****************************************************************************
	 The following creates and prints a list of 128 fractal noise samples over four octaves:
	 *****************************************************************************/
	
	RealList L(Random(), Random(), Random(), Random());
	RealList R;
	
	For (Integer n = 0; n < 128; n = n + 1) {
		R[n] = VossFracRand(n, L);
	}
	
	Print("*** Voss' Fractal Method ***");
	Print(R);
	
	/*****************************************************************************
	 Figure 9.32 shows how this noise is constructed by this method. Each function changes at a rate 
	 twice as fast as the previous function, and the functions are summed. Random values in the rapidly 
	 changing functions have only local influence, whereas values in the slowly changing functions extend 
	 their influence over many samples of the summed result, giving the result a fractal characteristic.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: C091704d.cpp,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
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

