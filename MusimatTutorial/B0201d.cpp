#include "MusimatTutorial.h"
MusimatTutorialSection(B0201d) {
	Print("*** Sruti Scale ***");
	/*****************************************************************************
	 
	 Sruti Scale
	 
	 As a final example, we adapt Pitch to handle nondodecaphonic scales by demon-
	 strating the sruti scale (see figure 3.25). There are 22 degrees in this scale. We start by defining 
	 the ratios of the sruti scale:
	 *****************************************************************************/
	para1();  // Step into this function to continue the tutorial
}

RealList srutiScale(
	1.0/1.0, 256.0/243.0, 16.0/15.0, 10.0/9.0, 9.0/8.0, 32.0/27.0, 6.0/5.0, 
	5.0/4.0, 81.0/64.0, 4.0/3.0, 27.0/20.0,45.0/32.0, 729.0/512.0, 
	3.0/2.0, 128.0/81.0, 8.0/5.0, 5.0/3.0, 27.0/16.0, 16.0/9.0, 9.0/5.0, 
	15.0/8.0, 243.0/128.0
);

Static Void para1() {
	
	/*****************************************************************************
	 We want to preserve the reference A440 Hz and use it to find the frequency of the lowest degree 
	 of the scale, as we've done for Pythagorean and natural scales. But which of the 22 degrees should 
	 correspond to A440? The sruti scale contains both the Pythagorean major sixth (27/16) and the 
	 natural major sixth (5/3). Let's choose the simpler 5/3 ratio at degree 17 to correspond to A440. 
	 Then the lowest degree of the sruti scale has the same frequency as the natural chromatic middle 
	 C, 264.0 Hz.
	 *****************************************************************************/
	
	Real		R = 440.0;
	Real		srutiRef = R * 3.0/5.0; // 264.00 Hz
	
	/*****************************************************************************
	 Next, we must inform Pitch of how many degrees there are per octave, which we can do by 
	 finding the length of the list of ratios:
	 *****************************************************************************/
	
	SetDegrees(Length(srutiScale)); 		// set number of degrees in scale
	
	/*****************************************************************************
	 The built-in SetDegrees( ) function adjusts the internal calculations of Pitch to the spec-
	 ified number of degrees in the scale. To keep things simple, the degrees of the sruti scale are indi-
	 cated only by their degree numbers, rather than by trying to extend the Western pitch-naming 
	 system. Then the frequencies of particular sruti degrees are computed as follows:
	 *****************************************************************************/
	
	For (Integer i = 0; i < Length(srutiScale); i = i + 1) {
		Pitch x( i, 0, 4 ); // pitch, accidental, octave
		Real f = pitchToHz(x, srutiRef, srutiScale);
		Print(f);
	}
	
	/*****************************************************************************
	 which prints the frequencies of the sruti scale from middle C as follows: 
	 
	 1       2       3       4       5       6       7       8       9       10      11
	 264.00	278.12	281.60	293.33	297.00	312.89	316.80	330.00	334.13	352.00	356.40
	 
	 12      13      14      15      16      17      18      19      20      21      22
	 371.25	375.89	396.00	417.19	422.40	440.00	445.50	469.33	475.20	495.00	501.19
	 
	 Other scales, such as Partch's scale and the quarter-tone scale, can be constructed in the same 
	 manner. The Bohlen-Pierce scale can also be constructed this way because the SetDegrees() 
	 function only specifies the number of degrees in the scale and makes no assumptions about octave 
	 equivalence.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0201d.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

