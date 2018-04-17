#include "MusimatTutorial.h"
MusimatTutorialSection(B0203) {
	Print("*** B.2.3 Tempo ***");
	/*****************************************************************************
	 
	 B.2.3 Tempo
	 
	 In common music notation, tempo is expressed using Mälzel's metronome markings (see sec-
	 tion 2.6.2). For example, Q = 60MM indicates that the beat or pulse of the music is associated 
	 with quarter notes and that there are 60 beats per minute. Thus at Q = 60MM each quarter note 
	 lasts 1 second, and at Q = 120MM each quarter note lasts 0.5 second. Thus tempo scales the 
	 durations of rhythms.
	 
	 We can emulate this by calculating a tempo factor based on Mälzel's metronome markings. 
	 Rhythms are then multiplied by this coefficient to determine their actual duration. First, we need 
	 a function that calculates the tempo factor:
	 *****************************************************************************/
	
	para1();  // Step into this function to continue the tutorial
}

Real mm(Real beats, Real perMinute) {
	Return(1.0 / (4.0 * beats) * 60.0 / perMinute);
}

Static Void para1() {
	
	/*****************************************************************************
	 The beats argument is the rhythmic value that gets the beat, and the perMinute argument is the 
	 number of beats per minute. For example, 
	 *****************************************************************************/
	
	Real tempoScale = mm( Duration(Quarter), 60.0 ); 		// 60 quarternotes per minute
	
	/*****************************************************************************
	 sets tempoScale to 1.0, and 
	 *****************************************************************************/
	
	tempoScale = mm(Duration(Quarter), 120.0); 			// 120 quarternotes per minute
	
	/*****************************************************************************
	 sets tempoScale to 0.5. Scaling a list of rhythms with tempoScale adjusts them to the pre-
	 vailing tempo. Start with a rhythm list.
	 *****************************************************************************/
	
	RhythmList T(Quarter, Eighth, Eighth, Eighth, Sixteenth, Sixteenth, Quarter);
	Print(T);
	
	/*****************************************************************************
	 prints {(1,4), (1,8), (1,8), (1,8), (1,16), (1,16), (1,4)}. Now scale it.
	 *****************************************************************************/
	
	RhythmList S = T * tempoScale; 										// tempoScale == 0.5
	Print(S);
	
	/*****************************************************************************
	 prints {(1,8), (1,16), (1,16), (1,16), (1,32), (1,32), (1,8)}.
	 
	 Though this explicit approach to managing tempo works fine, in fact Rhythm() has this cal-
	 culation conveniently built in. It works in conjunction with a built-in function named Set-
	 Tempo() that implicitly scales all rhythmic durations by the specified tempo factor. So, for 
	 example, given the preceding definition of RhythmList T,
	 *****************************************************************************/
	
	SetTempoScale(mm(Duration(Quarter), 90)); 				// set tempo to 90 quarternotes per minute
	Print(T);
	
	/*****************************************************************************
	 prints {(1,6), (1,12), (1,12), (1,12), (1,24), (1,24), (1,6)}. All rhythmic values 
	 are scaled implicitly by Rhythm().
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0203.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

