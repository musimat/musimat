#include "MusimatChapter9.h"
MusimatChapter9Section(C091704c) {
	Print("*** Fractional Brownian Motion ***");
	/*****************************************************************************
	 
	 Fractional Brownian Motion
	 
	 The preceding Brownian number generator produces a high degree 
	 of local similarity because subsequent points are constrained to remain relatively close to previous 
	 points. But because the random increment at each step is independent, Brownian motion typically only 
	 shows self-similarity in a region of its spectrum, so its fractal quality degenerates with scaling.
	 
	 Fractional Brownian motion (fBm) is like Brownian motion, but the increments are no longer 
	 independent. Instead, just as low-frequency ocean waves extend their influence over many cycles 
	 of higher-frequency waves, in fBm, local rapidly fluctuating values are influenced by broader, 
	 slower-moving values extending proportionately over the entire spectrum. As fBm is magnified, 
	 it retains its statistically self-similar shape, and so it is fractal regardless of magnification.
	 
	 Think of it this way. If we had an ideal tape recorder that accurately recorded all frequencies, 
	 and we gradually increased the speed of a tape recording of Brownian noise, the character of the 
	 noise would change (from a relatively low-frequency "whoosh" to a higher-frequency "whish"). 
	 But a recording of fBm noise will sound the same regardless of playback speed. All speeds sound 
	 the same because both the signal and the spectrum are self-similar at all levels of scale. A number 
	 of methods can be used to generate fBm noises.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:03 $ $Author: dgl $ $Name:  $ $Id: C091704c.cpp,v 1.2 2006/09/05 06:32:03 dgl Exp $ */
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

