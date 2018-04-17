#include "MusimatTutorial.h"
MusimatTutorialSection(B0201c) {
	Print("*** Natural Chromatic Scale ***");
	/*****************************************************************************
	 
	 Natural Chromatic Scale
	 
	 To create the natural chromatic scale, all we need now is to establish 
	 the frequency reference for natural chromatic middle C and tabulate the ratios of the scale.
	 *****************************************************************************/
	para1();  // Step into this function to continue the tutorial
}

Real	R = 440.0;
Real	cNat4 = R * 3.0/5.0; //264.00 Hz

RealList naturalChromatic(
	1.0/1.0, 16.0/15.0, 9.0/8.0, 6.0/5.0,
	5.0/4.0, 4.0/3.0, 64.0/45.0, 3.0/2.0,
	8.0/5.0, 5.0/3.0, 16.0/9.0, 15.0/8.0
);

Static Void para1() {
	
	/*****************************************************************************
	 Then
	 *****************************************************************************/
	
	Print("A4=",  pitchToHz(A4 , cNat4, naturalChromatic));
	
	/*****************************************************************************
	 prints A4=440.0, and
	 *****************************************************************************/
	
	Print("C4=",  pitchToHz(C4 , cNat4, naturalChromatic));
	
	/*****************************************************************************
	 prints C4=264.00.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0201c.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

