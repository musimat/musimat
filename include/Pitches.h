/* $Revision: 1.4 $ $Date: 2006/09/08 18:56:52 $ $Author: dgl $ $Name:  $ $Id: Pitches.h,v 1.4 2006/09/08 18:56:52 dgl Exp $ */
#ifndef PITCHES_H
#define PITCHES_H

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

///	@file Pitches.h
///	Global pitch names of the dodecaphonic scale over the range of the piano
///

///	\defgroup PitchConst Const pitch values for the dodecaphonic scale
///@{
/// The following Pitches across 8 octaves are defined with global scope.\n
///\n
/// Const Pitch C0, C1, ..., C7, C natural in all piano octaves\n
/// Const Pitch Cs0, Cs1, ..., Cs7, C sharp (D flat) in all piano octaves\n
/// Const Pitch Db0, Db1, ..., Db7, D flat (C sharp) in all piano octaves\n
/// Const Pitch D0, D1, ..., D7, D natural in all piano octaves\n
/// ...\n
///\n
/// The Pitches implemented are C*, Cs*, Db*, D*, Eb*, E*, F*, Fs*, Gb*, G*, Gs*, Ab*, A*, As*, Bb*, B*
/// where * is any piano octave in the range [0,7]

Const Pitch C0 = Pitch(0,0,0);		///< Pitch Class =  0, Accidental =  0, Octave = 0
Const Pitch Cs0 = Pitch(0,1,0);		///< Pitch Class =  0, Accidental =  1, Octave = 0
Const Pitch Db0 = Pitch(2,-1,0);	///< Pitch Class =  2, Accidental = -1, Octave = 0
Const Pitch D0 = Pitch(2,0,0);		///< Pitch Class =  2, Accidental =  0, Octave = 0
Const Pitch Ds0 = Pitch(2,1,0);		///< Pitch Class =  2, Accidental =  1, Octave = 0
Const Pitch Eb0 = Pitch(4,-1,0);	///< Pitch Class =  4, Accidental = -1, Octave = 0
Const Pitch E0 = Pitch(4,0,0);		///< Pitch Class =  4, Accidental =  0, Octave = 0
Const Pitch F0 = Pitch(5,0,0);		///< Pitch Class =  5, Accidental =  0, Octave = 0
Const Pitch Fs0 = Pitch(5,1,0);		///< Pitch Class =  5, Accidental =  1, Octave = 0
Const Pitch Gb0 = Pitch(7,-1,0);	///< Pitch Class =  7, Accidental = -1, Octave = 0
Const Pitch G0 = Pitch(7,0,0);		///< Pitch Class =  7, Accidental =  0, Octave = 0
Const Pitch Gs0 = Pitch(7,1,0);		///< Pitch Class =  7, Accidental =  1, Octave = 0
Const Pitch Ab0 = Pitch(9,-1,0);	///< Pitch Class =  9, Accidental = -1, Octave = 0
Const Pitch A0 = Pitch(9,0,0);		///< Pitch Class =  9, Accidental =  0, Octave = 0
Const Pitch As0 = Pitch(9,1,0);		///< Pitch Class =  9, Accidental =  1, Octave = 0
Const Pitch Bb0 = Pitch(11,-1,0);	///< Pitch Class = 11, Accidental = -1, Octave = 0
Const Pitch B0 = Pitch(11,0,0);		///< Pitch Class = 11, Accidental =  0, Octave = 0
Const Pitch C1 = Pitch(0,0,1);		///< Pitch Class =  0, Accidental =  0, Octave = 1
Const Pitch Cs1 = Pitch(0,1,1);		///< Pitch Class =  0, Accidental =  1, Octave = 1
Const Pitch Db1 = Pitch(2,-1,1);	///< Pitch Class =  2, Accidental = -1, Octave = 1
Const Pitch D1 = Pitch(2,0,1);		///< Pitch Class =  2, Accidental =  0, Octave = 1
Const Pitch Ds1 = Pitch(2,1,1);		///< Pitch Class =  2, Accidental =  1, Octave = 1
Const Pitch Eb1 = Pitch(4,-1,1);	///< Pitch Class =  4, Accidental = -1, Octave = 1
Const Pitch E1 = Pitch(4,0,1);		///< Pitch Class =  4, Accidental =  0, Octave = 1
Const Pitch F1 = Pitch(5,0,1);		///< Pitch Class =  5, Accidental =  0, Octave = 1
Const Pitch Fs1 = Pitch(5,1,1);		///< Pitch Class =  5, Accidental =  1, Octave = 1
Const Pitch Gb1 = Pitch(7,-1,1);	///< Pitch Class =  7, Accidental = -1, Octave = 1
Const Pitch G1 = Pitch(7,0,1);		///< Pitch Class =  7, Accidental =  0, Octave = 1
Const Pitch Gs1 = Pitch(7,1,1);		///< Pitch Class =  7, Accidental =  1, Octave = 1
Const Pitch Ab1 = Pitch(9,-1,1);	///< Pitch Class =  9, Accidental = -1, Octave = 1
Const Pitch A1 = Pitch(9,0,1);		///< Pitch Class =  9, Accidental =  0, Octave = 1
Const Pitch As1 = Pitch(9,1,1);		///< Pitch Class =  9, Accidental =  1, Octave = 1
Const Pitch Bb1 = Pitch(11,-1,1);	///< Pitch Class = 11, Accidental = -1, Octave = 1
Const Pitch B1 = Pitch(11,0,1);		///< Pitch Class = 11, Accidental =  0, Octave = 1
Const Pitch C2 = Pitch(0,0,2);		///< Pitch Class =  0, Accidental =  0, Octave = 2
Const Pitch Cs2 = Pitch(0,1,2);		///< Pitch Class =  0, Accidental =  1, Octave = 2
Const Pitch Db2 = Pitch(2,-1,2);	///< Pitch Class =  2, Accidental = -1, Octave = 2
Const Pitch D2 = Pitch(2,0,2);		///< Pitch Class =  2, Accidental =  0, Octave = 2
Const Pitch Ds2 = Pitch(2,1,2);		///< Pitch Class =  2, Accidental =  1, Octave = 2
Const Pitch Eb2 = Pitch(4,-1,2);	///< Pitch Class =  4, Accidental = -1, Octave = 2
Const Pitch E2 = Pitch(4,0,2);		///< Pitch Class =  4, Accidental =  0, Octave = 2
Const Pitch F2 = Pitch(5,0,2);		///< Pitch Class =  5, Accidental =  0, Octave = 2
Const Pitch Fs2 = Pitch(5,1,2);		///< Pitch Class =  5, Accidental =  1, Octave = 2
Const Pitch Gb2 = Pitch(7,-1,2);	///< Pitch Class =  7, Accidental = -1, Octave = 2
Const Pitch G2 = Pitch(7,0,2);		///< Pitch Class =  7, Accidental =  0, Octave = 2
Const Pitch Gs2 = Pitch(7,1,2);		///< Pitch Class =  7, Accidental =  1, Octave = 2
Const Pitch Ab2 = Pitch(9,-1,2);	///< Pitch Class =  9, Accidental = -1, Octave = 2
Const Pitch A2 = Pitch(9,0,2);		///< Pitch Class =  9, Accidental =  0, Octave = 2
Const Pitch As2 = Pitch(9,1,2);		///< Pitch Class =  9, Accidental =  1, Octave = 2
Const Pitch Bb2 = Pitch(11,-1,2);	///< Pitch Class = 11, Accidental = -1, Octave = 2
Const Pitch B2 = Pitch(11,0,2);		///< Pitch Class = 11, Accidental =  0, Octave = 2
Const Pitch C3 = Pitch(0,0,3);		///< Pitch Class =  0, Accidental =  0, Octave = 3
Const Pitch Cs3 = Pitch(0,1,3);		///< Pitch Class =  0, Accidental =  1, Octave = 3
Const Pitch Db3 = Pitch(2,-1,3);	///< Pitch Class =  2, Accidental = -1, Octave = 3
Const Pitch D3 = Pitch(2,0,3);		///< Pitch Class =  2, Accidental =  0, Octave = 3
Const Pitch Ds3 = Pitch(2,1,3);		///< Pitch Class =  2, Accidental =  1, Octave = 3
Const Pitch Eb3 = Pitch(4,-1,3);	///< Pitch Class =  4, Accidental = -1, Octave = 3
Const Pitch E3 = Pitch(4,0,3);		///< Pitch Class =  4, Accidental =  0, Octave = 3
Const Pitch F3 = Pitch(5,0,3);		///< Pitch Class =  5, Accidental =  0, Octave = 3
Const Pitch Fs3 = Pitch(5,1,3);		///< Pitch Class =  5, Accidental =  1, Octave = 3
Const Pitch Gb3 = Pitch(7,-1,3);	///< Pitch Class =  7, Accidental = -1, Octave = 3
Const Pitch G3 = Pitch(7,0,3);		///< Pitch Class =  7, Accidental =  0, Octave = 3
Const Pitch Gs3 = Pitch(7,1,3);		///< Pitch Class =  7, Accidental =  1, Octave = 3
Const Pitch Ab3 = Pitch(9,-1,3);	///< Pitch Class =  9, Accidental = -1, Octave = 3
Const Pitch A3 = Pitch(9,0,3);		///< Pitch Class =  9, Accidental =  0, Octave = 3
Const Pitch As3 = Pitch(9,1,3);		///< Pitch Class =  9, Accidental =  1, Octave = 3
Const Pitch Bb3 = Pitch(11,-1,3);	///< Pitch Class = 11, Accidental = -1, Octave = 3
Const Pitch B3 = Pitch(11,0,3);		///< Pitch Class = 11, Accidental =  0, Octave = 3
Const Pitch C4 = Pitch(0,0,4);		///< Pitch Class =  0, Accidental =  0, Octave = 4
Const Pitch Cs4 = Pitch(0,1,4);		///< Pitch Class =  0, Accidental =  1, Octave = 4
Const Pitch Db4 = Pitch(2,-1,4);	///< Pitch Class =  2, Accidental = -1, Octave = 4
Const Pitch D4 = Pitch(2,0,4);		///< Pitch Class =  2, Accidental =  0, Octave = 4
Const Pitch Ds4 = Pitch(2,1,4);		///< Pitch Class =  2, Accidental =  1, Octave = 4
Const Pitch Eb4 = Pitch(4,-1,4);	///< Pitch Class =  4, Accidental = -1, Octave = 4
Const Pitch E4 = Pitch(4,0,4);		///< Pitch Class =  4, Accidental =  0, Octave = 4
Const Pitch F4 = Pitch(5,0,4);		///< Pitch Class =  5, Accidental =  0, Octave = 4
Const Pitch Fs4 = Pitch(5,1,4);		///< Pitch Class =  5, Accidental =  1, Octave = 4
Const Pitch Gb4 = Pitch(7,-1,4);	///< Pitch Class =  7, Accidental = -1, Octave = 4
Const Pitch G4 = Pitch(7,0,4);		///< Pitch Class =  7, Accidental =  0, Octave = 4
Const Pitch Gs4 = Pitch(7,1,4);		///< Pitch Class =  7, Accidental =  1, Octave = 4
Const Pitch Ab4 = Pitch(9,-1,4);	///< Pitch Class =  9, Accidental = -1, Octave = 4
Const Pitch A4 = Pitch(9,0,4);		///< Pitch Class =  9, Accidental =  0, Octave = 4
Const Pitch As4 = Pitch(9,1,4);		///< Pitch Class =  9, Accidental =  1, Octave = 4
Const Pitch Bb4 = Pitch(11,-1,4);	///< Pitch Class = 11, Accidental = -1, Octave = 4
Const Pitch B4 = Pitch(11,0,4);		///< Pitch Class = 11, Accidental =  0, Octave = 4
Const Pitch C5 = Pitch(0,0,5);		///< Pitch Class =  0, Accidental =  0, Octave = 5
Const Pitch Cs5 = Pitch(0,1,5);		///< Pitch Class =  0, Accidental =  1, Octave = 5
Const Pitch Db5 = Pitch(2,-1,5);	///< Pitch Class =  2, Accidental = -1, Octave = 5
Const Pitch D5 = Pitch(2,0,5);		///< Pitch Class =  2, Accidental =  0, Octave = 5
Const Pitch Ds5 = Pitch(2,1,5);		///< Pitch Class =  2, Accidental =  1, Octave = 5
Const Pitch Eb5 = Pitch(4,-1,5);	///< Pitch Class =  4, Accidental = -1, Octave = 5
Const Pitch E5 = Pitch(4,0,5);		///< Pitch Class =  4, Accidental =  0, Octave = 5
Const Pitch F5 = Pitch(5,0,5);		///< Pitch Class =  5, Accidental =  0, Octave = 5
Const Pitch Fs5 = Pitch(5,1,5);		///< Pitch Class =  5, Accidental =  1, Octave = 5
Const Pitch Gb5 = Pitch(7,-1,5);	///< Pitch Class =  7, Accidental = -1, Octave = 5
Const Pitch G5 = Pitch(7,0,5);		///< Pitch Class =  7, Accidental =  0, Octave = 5
Const Pitch Gs5 = Pitch(7,1,5);		///< Pitch Class =  7, Accidental =  1, Octave = 5
Const Pitch Ab5 = Pitch(9,-1,5);	///< Pitch Class =  9, Accidental = -1, Octave = 5
Const Pitch A5 = Pitch(9,0,5);		///< Pitch Class =  9, Accidental =  0, Octave = 5
Const Pitch As5 = Pitch(9,1,5);		///< Pitch Class =  9, Accidental =  1, Octave = 5
Const Pitch Bb5 = Pitch(11,-1,5);	///< Pitch Class = 11, Accidental = -1, Octave = 5
Const Pitch B5 = Pitch(11,0,5);		///< Pitch Class = 11, Accidental =  0, Octave = 5
Const Pitch C6 = Pitch(0,0,6);		///< Pitch Class =  0, Accidental =  0, Octave = 6
Const Pitch Cs6 = Pitch(0,1,6);		///< Pitch Class =  0, Accidental =  1, Octave = 6
Const Pitch Db6 = Pitch(2,-1,6);	///< Pitch Class =  2, Accidental = -1, Octave = 6
Const Pitch D6 = Pitch(2,0,6);		///< Pitch Class =  2, Accidental =  0, Octave = 6
Const Pitch Ds6 = Pitch(2,1,6);		///< Pitch Class =  2, Accidental =  1, Octave = 6
Const Pitch Eb6 = Pitch(4,-1,6);	///< Pitch Class =  4, Accidental = -1, Octave = 6
Const Pitch E6 = Pitch(4,0,6);		///< Pitch Class =  4, Accidental =  0, Octave = 6
Const Pitch F6 = Pitch(5,0,6);		///< Pitch Class =  5, Accidental =  0, Octave = 6
Const Pitch Fs6 = Pitch(5,1,6);		///< Pitch Class =  5, Accidental =  1, Octave = 6
Const Pitch Gb6 = Pitch(7,-1,6);	///< Pitch Class =  7, Accidental = -1, Octave = 6
Const Pitch G6 = Pitch(7,0,6);		///< Pitch Class =  7, Accidental =  0, Octave = 6
Const Pitch Gs6 = Pitch(7,1,6);		///< Pitch Class =  7, Accidental =  1, Octave = 6
Const Pitch Ab6 = Pitch(9,-1,6);	///< Pitch Class =  9, Accidental = -1, Octave = 6
Const Pitch A6 = Pitch(9,0,6);		///< Pitch Class =  9, Accidental =  0, Octave = 6
Const Pitch As6 = Pitch(9,1,6);		///< Pitch Class =  9, Accidental =  1, Octave = 6
Const Pitch Bb6 = Pitch(11,-1,6);	///< Pitch Class = 11, Accidental = -1, Octave = 6
Const Pitch B6 = Pitch(11,0,6);		///< Pitch Class = 11, Accidental =  0, Octave = 6
Const Pitch C7 = Pitch(0,0,7);		///< Pitch Class =  0, Accidental =  0, Octave = 7
Const Pitch Cs7 = Pitch(0,1,7);		///< Pitch Class =  0, Accidental =  1, Octave = 7
Const Pitch Db7 = Pitch(2,-1,7);	///< Pitch Class =  2, Accidental = -1, Octave = 7
Const Pitch D7 = Pitch(2,0,7);		///< Pitch Class =  2, Accidental =  0, Octave = 7
Const Pitch Ds7 = Pitch(2,1,7);		///< Pitch Class =  2, Accidental =  1, Octave = 7
Const Pitch Eb7 = Pitch(4,-1,7);	///< Pitch Class =  4, Accidental = -1, Octave = 7
Const Pitch E7 = Pitch(4,0,7);		///< Pitch Class =  4, Accidental =  0, Octave = 7
Const Pitch F7 = Pitch(5,0,7);		///< Pitch Class =  5, Accidental =  0, Octave = 7
Const Pitch Fs7 = Pitch(5,1,7);		///< Pitch Class =  5, Accidental =  1, Octave = 7
Const Pitch Gb7 = Pitch(7,-1,7);	///< Pitch Class =  7, Accidental = -1, Octave = 7
Const Pitch G7 = Pitch(7,0,7);		///< Pitch Class =  7, Accidental =  0, Octave = 7
Const Pitch Gs7 = Pitch(7,1,7);		///< Pitch Class =  7, Accidental =  1, Octave = 7
Const Pitch Ab7 = Pitch(9,-1,7);	///< Pitch Class =  9, Accidental = -1, Octave = 7
Const Pitch A7 = Pitch(9,0,7);		///< Pitch Class =  9, Accidental =  0, Octave = 7
Const Pitch As7 = Pitch(9,1,7);		///< Pitch Class =  9, Accidental =  1, Octave = 7
Const Pitch Bb7 = Pitch(11,-1,7);	///< Pitch Class = 11, Accidental = -1, Octave = 7
Const Pitch B7 = Pitch(11,0,7);		///< Pitch Class = 11, Accidental =  0, Octave = 7
Const Pitch C8 = Pitch(0,0,8);		///< Pitch Class =  0, Accidental =  0, Octave = 8
///@}

///	\defgroup PitchClasses Const pitch classes for the dodecaphonic scale
///@{
/// The following Pitch Classes are defined in global scope.\n

Const Pitch C   = Pitch(0,0,0);		///< Pitch Class =  0, Accidental =  0, Octave = 0
Const Pitch Cs  = Pitch(0,1,0);		///< Pitch Class =  0, Accidental =  1, Octave = 0
Const Pitch Db  = Pitch(2,-1,0);	///< Pitch Class =  2, Accidental = -1, Octave = 0
Const Pitch D   = Pitch(2,0,0);		///< Pitch Class =  2, Accidental =  0, Octave = 0
Const Pitch Ds  = Pitch(2,1,0);		///< Pitch Class =  2, Accidental =  1, Octave = 0
Const Pitch Eb  = Pitch(4,-1,0);	///< Pitch Class =  4, Accidental = -1, Octave = 0
Const Pitch E   = Pitch(4,0,0);		///< Pitch Class =  4, Accidental =  0, Octave = 0
Const Pitch F   = Pitch(5,0,0);		///< Pitch Class =  5, Accidental =  0, Octave = 0
Const Pitch Fs  = Pitch(5,1,0);		///< Pitch Class =  5, Accidental =  1, Octave = 0
Const Pitch Gb  = Pitch(7,-1,0);	///< Pitch Class =  7, Accidental = -1, Octave = 0
Const Pitch G   = Pitch(7,0,0);		///< Pitch Class =  7, Accidental =  0, Octave = 0
Const Pitch Gs  = Pitch(7,1,0);		///< Pitch Class =  7, Accidental =  1, Octave = 0
Const Pitch Ab  = Pitch(9,-1,0);	///< Pitch Class =  9, Accidental = -1, Octave = 0
Const Pitch A   = Pitch(9,0,0);		///< Pitch Class =  9, Accidental =  0, Octave = 0
Const Pitch As  = Pitch(9,1,0);		///< Pitch Class =  9, Accidental =  1, Octave = 0
Const Pitch Bb  = Pitch(11,-1,0);	///< Pitch Class = 11, Accidental = -1, Octave = 0
Const Pitch B   = Pitch(11,0,0);	///< Pitch Class = 11, Accidental =  0, Octave = 0

///@}
#endif // PITCHES_H

