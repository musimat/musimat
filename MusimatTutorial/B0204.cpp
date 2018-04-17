#include "MusimatTutorial.h"
MusimatTutorialSection(B0204) {
	Print("*** B.2.4 Loudness ***");
	/*****************************************************************************
	 
	 B.2.4 Loudness
	 
	 Loudness is expressed in common music notation using performance indications such as fortis-
	 simo or piano (see section 2.7). But the performed intensity depends upon the acoustical power of 
	 the instrument and the interpretation of the performer. A better approach for the purpose here 
	 would be to define loudness in objective terms using decibels (see section 5.5.1).
	 
	 Since microphones and loudspeakers measure and reproduce pressure waves, it is common to 
	 use dB SPL in audio work (see equation 5.32). It is also conventional in audio to take the loudest 
	 value that can be reproduced without distortion as a reference intensity of 0 dB (see section 4.24.2). 
	 Since measured intensities will be less intense than the reference, then by the definition of the deci-
	 bel they will be expressed as negative decibel levels. We can write, for example, -6 dB to indicate 
	 an amplitude that is (very close to) one half of the amplitude of the 0 dB reference.
	 
	 Restating (5.32), the equation for dB SPL, using standard mathematics symbols, is
	 
	 y dB = 20 Log10(A'/A)
	 
	 and simplifying by letting x=A'/A, we have y dB = 20 Log10(x). Solving for x, we have 
	 
	 x = 10^(y/20).	(B.1)
	 
	 (Note, in standard math, A' in English means "A prime", which means A' is like A, but is not
	 necessarily the same.  Also, the operator "^" in standard math means exponentiation, so that
	 2^2=4.  In modern programming languages, however, "^" means "exclusive-or".)
	 
	 For example, setting y = -6 dB, we have x = 10^(-6/20) = 0.501. The value of x is the coefficient by 
	 which a signal must be multiplied to lower its amplitude by 6 dB. For another example, setting 
	 y = 0 dB, we have x = 10^(0/20) = 1. So multplying by 0 dB does not affect amplitude. Setting 
	 y = -120 dB, we have x = 10^(-120/20) = 0.000001, so multiplying a signal by -120 dB renders it vir-
	 tually inaudible. Finally, if we wish to amplify a soft sound, scaling it by +6 dB makes it twice as 
	 loud. Thus, scaling sounds with decibel coefficients allows us to achieve arbitrary loudness levels 
	 for waveforms. So we define
	 *****************************************************************************/
	
	para1();  // Step into this function to continue the tutorial
}

Real dB(Real y){ 
	Return(Pow(10.0, y/20.0)); 
}

Static Void para1() {
	
	/*****************************************************************************
	 For example, Print(dB(-6)) prints 0.501187, Print(dB(0)) prints 1.0, and 
	 Print(dB(-120)) prints 0.000001.
	 
	 Suppose we have the following audio samples for a sound:
	 *****************************************************************************/
	
	RealList mySound(0, 0.16, 0.192, -0.37, -0.45, -0.245, -0.43, 0.09);
	
	/*****************************************************************************
	 We wish to halve the sound's amplitude. Then
	 *****************************************************************************/
	
	RealList scaledSound = mySound * dB(-6);
	Print(scaledSound);
	
	/*****************************************************************************
	 prints {0.02, 0.08, 0.10, -0.19, -0.23, -0.12, -0.22, 0.05, . . .}.
	 
	 See volume 2, chapter 1, for more about sampled signals.
	 
	 Musimat provides built-in definitions for standard music dynamics levels based on figure 4.7.
	 *****************************************************************************/
	
	Real ffff = dB(0), fff = dB(-10),  ff = dB(-18),  f = dB(-24),
	mf = dB(-32),  mp = dB(-40),  p = dB(-48),  pp = dB(-56),
	ppp = dB(-64);
	
	Print( ffff ); Print( fff ); Print(ff); Print(f); Print(mf); Print(mp); Print(mp); Print(p); Print(pp); Print(ppp);
	
	/*****************************************************************************
	 Thus ffff does not change the amplitude of the signal, but all others attenuate it to varying 
	 degrees.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0204.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

