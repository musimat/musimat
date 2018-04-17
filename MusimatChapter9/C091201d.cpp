#include "MusimatChapter9.h"
MusimatChapter9Section(C091201d) {
	Print("*** Transpose ***");
	/*****************************************************************************
	 
	 Transpose
	 
	 The dodecaphonic pitch classes are not tied to any octave. In order to realize music 
	 from a tone row, its intervallic content must be translated to actual pitches of the musical scale. 
	 One way to do this is to supply a pitch offset that transposes across pitch space (i.e., without lim-
	 iting it just to the range of pitch classes).
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

Integer transpose(Integer p, Integer off) {
	Return(p + off);
}

Static Void para1() {
	/*****************************************************************************
	 The C major diatonic scale in the fourth piano octave can then be given as follows:
	 *****************************************************************************/
	
	Print("*** Transposing across pitch space ***");
	PitchList Cmaj(C, D, E, F, G, A, B); // define C major scale
	Print(Cmaj);
	
	/*****************************************************************************
	 This prints {C4, D4, E4, F4, G4, A4, B4}.
	 *****************************************************************************/
	
	Cmaj += 4 * 12;
	Print("Transposed up 4 octaves:",  Cmaj);
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:45 $ $Author: dgl $ $Name:  $ $Id: C091201d.cpp,v 1.3 2006/09/05 08:02:45 dgl Exp $ */
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

