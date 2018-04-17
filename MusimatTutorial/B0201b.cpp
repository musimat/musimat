#include "MusimatTutorial.h"
MusimatTutorialSection(B0201b) {
	Print("*** Pythagorean Chromatic Scale ***");
	/*****************************************************************************
	 
	 Pythagorean Chromatic Scale
	 
	 We can compute the frequency of a Pitch in Pythagorean 
	 chromatic tuning, assuming a reference such as A4 equals 440 Hz. We start by computing the fre-
	 quency of Pythagorean middle C from the reference frequency, using equation (3.11).
	 *****************************************************************************/
	
	para1();  // Step into this function to continue the tutorial
	para2();  // Step into this function to continue the tutorial
}


/*****************************************************************************
 Next, referring to figure 3.7, we tabulate the ratios of the Pythagorean chromatic scale in 
 Musimat using a RealList:
 *****************************************************************************/

RealList pythagoreanChromatic( 
	1.0/1.0, 256.0/243.0, 9.0/8.0, 32.0/27.0,
	81.0/64.0, 4.0/3.0, 1024.0/729.0, 3.0/2.0,
	128.0/81.0, 27.0/16.0, 16.0/9.0, 243.0/128.0
);

Static Void para1() {
	
	/*****************************************************************************
	 Last, we define a variation of the pitchToHz() function. This version has the same name but 
	 takes three arguments instead of one. When supplied with a certain Pitch p, it returns the fre-
	 quency corresponding to its Pythagorean intonation as a Real value in hertz.
	 *****************************************************************************/
	
	para2();
}

Real pitchToHz( 
			   Pitch p,										// pitch
			   Real refC,										// reference frequency
			   RealList scale									// ratios of scale degrees
			   ) {
	Integer key = PitchClass(p) + Accidental(p);	// get key from pitch
	Real oct = Octave(p);							// get octave from pitch
	Return(refC * scale[key] * Pow(2.0, (oct - 4)));// compute frequency
}  

Static Void para2() {
	
	/*****************************************************************************
	 The Return() statement calculates the frequency of the key from the reference frequency 
	 times the ratio for that degree, then adjusts it for the proper octave.
	 
	 We define the reference frequencies in Musimat as follows:
	 *****************************************************************************/
	
	Real R = 440.0;
	Real cPi4 = R * 16.0/27.0; // Pythagorean middle C, 260.74 Hz
	
	/*****************************************************************************
	 Finally, we call pitchToHz() with the pitch we want, the Pythagorean reference
	 frequency, and the ratios of the Pythagorean scale:
	 *****************************************************************************/
	
	Print("Pythagorian A4=",  pitchToHz(A4 , cPi4, pythagoreanChromatic));
	
	/*****************************************************************************
	 This prints A4=440.0, and
	 *****************************************************************************/
	
	Print("Pythagorian C4=",  pitchToHz(C4 , cPi4, pythagoreanChromatic));
	
	/*****************************************************************************
	 prints C4=260.74, as expected.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0201b.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

