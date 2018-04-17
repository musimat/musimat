#include "MusimatTutorial.h"
MusimatTutorialSection(B0201a) {
	Print("*** Equal-Tempered Frequency ***");
	/*****************************************************************************
	 
	 Equal-Tempered Frequency
	 
	 Pitch provides a representation of scale degrees and does not 
	 denote frequency. We can convert to frequency using any scale system we like, beginning with the 
	 equal-tempered scale. We can compute the equal-tempered frequency of a Pitch, assuming a 
	 reference such as A4 equals 440 Hz, by adapting equation (3.3), 
	 f(k, v) = fR * 2^(v + k / 12), 
	 to compute hertz values from chromatic scale degrees:
	 *****************************************************************************/
	
	para1(); // Step into this function to continue the tutorial
	para2(); // Step into this function to continue the tutorial
}

Real pitchToHz(Pitch p){
	Real R = 440.0;												// reference frequency
	Real key = PitchClass(p) + Accidental(p);					// get key index
	Real oct = Octave(p);										// get octave
	Return(R * Pow(2.0, (oct - 4) + (key - 9) / 12.0));			// return frequency
}

Void para1() {
	
	/*****************************************************************************
	 A way to think about the expression in the Return() statement is as follows. Suppose the reference 
	 pitch is 440 Hz, corresponding to A4. So we want the value returned from this function to equal 
	 440.0 when p is A4. The triple for A4 is (9, 0, 4), so when pitchToHz() is called with A4, 
	 we want to evaluate fR * 2^0, which can be achieved by subtracting 9 from the pitch and 4 from the 
	 octave. Then, executing
	 *****************************************************************************/
	
	Print(pitchToHz(A4));
	
	/*****************************************************************************
	 prints 440.0, and substituting any other pitch, regardless of how it is spelled, will produce its 
	 proper hertz value. For example, A0 is 27.5 Hz, C4 is 261.63 Hz, and C8 is 4186.01 Hz.
	 
	 What if we have a frequency x in hertz and want to find its corresponding pitch? The problem 
	 is that x may lie in between the pitches of the scale because x can be any frequency. One approach 
	 is to compare x to each semitone on the keyboard from lowest frequency to highest, and to stop 
	 when the keyboard frequency exceeds x. Then the key one semitone below is the closest corre-
	 sponding pitch on the keyboard.
	 *****************************************************************************/
}

Pitch hzToPitch(Real x) { 								// find pitch closest to x Hz
	For(Integer k = 9+1; k < 88+9; k = k + 1) {			// test from As0 to C8
		Pitch p = Pitch(k);								// get pitch of k
		Real f = pitchToHz(p);							// get frequency of p
		If (f > x)										// have we passed our target?
			Return(p - 1);								// return previous pitch
	}
	// If we get here, the Hz value of x is beyond the end of the keyboard
	Return(C8);											// out of range, clip at C8
}

Void para2() {
	
	/*****************************************************************************
	 This code returns A0 if x is lower than or equal to A0, and it returns C8 if x is greater than or equal 
	 to C8.
	 
	 Lists of Pitches
	 
	 We can collect pitches into lists:
	 *****************************************************************************/
	
	PitchList shave(C5, G4, G4, Ab4, G4, B4, C5); // shave and a haircut, 2 bits
	
	/*****************************************************************************
	 We can do arithmetic on all the pitches in a list. To transpose this pitch list up a whole step,
	 *****************************************************************************/
	
	Print( shave = shave + 2 );
	
	/*****************************************************************************
	 adds two degrees to every pitch in shave, and prints {D5, A4, A4, As4, A4, Cs5, D5}. 
	 To transpose by an octave,
	 *****************************************************************************/
	
	Print( shave = shave * 2 );
	
	/*****************************************************************************
	 multiplies every pitch in the list by 2 and prints {D6, A5, A5, As5, A5, Cs6, D6}.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0201a.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

