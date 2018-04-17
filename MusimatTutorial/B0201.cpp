#include "MusimatTutorial.h"
MusimatTutorialSection(B0201) {
	Print("*** B.2.1 Pitch ***");
	/*****************************************************************************
	 
	 B.2.1 Pitch
	 
	 We would ideally like to have a uniform way to represent all pitch systems discussed in chapter 3. 
	 It would be convenient if we could do arithmetic on pitches, for example, to find the size of an 
	 interval by subtracting two pitches, to calculate the frequency of a pitch, or to get the pitch of 
	 a frequency.
	 
	 Solving the simplest problem first, I designed a data type for the equal-tempered scale using the 
	 piano keyboard. This can be generalized to other scales. The gamut of a standard piano keyboard 
	 is 88 keys, indexed from 0 to 87, lowest to highest. We start by associating each key number with 
	 a name. The lowest pitch on standard pianos is A0, corresponding to key 0, and the highest pitch 
	 is C8, corresponding to key 87. Interval size in degrees is the difference between key indexes. For 
	 example, C4 is key 48 and F4 is key 53, so the interval C4 - F4 corresponds to five semitones, 
	 which is the diatonic interval of a fourth.
	 
	 Musimat comes with a built-in data type called Pitch. By default, it assumes 12 degrees per 
	 octave, but the degrees can correspond to any frequencies, so for example, it can be used directly 
	 to create any dodecaphonic scale. It also can be adjusted to handle scales with other than 12 degrees 
	 per octave.
	 
	 By default, the Pitch data type emulates common musical notation conventions regarding 
	 scale degrees, interval sizes, and transposition. For example, the pitch As4 (pitch class A# in the 
	 fourth piano octave) is defined as
	 *****************************************************************************/
	
	Pitch As4 = Pitch(9,1,4);
	
	/*****************************************************************************
	 The first number, 9, represents the diatonic degree as the number of semitones above C. 
	 Diatonic pitch A is the ninth semitone above C (see figure B.1). The second number, 1, indi-
	 cates the accidental. In this case, the A is sharped (raised by a semitone). The chromatic scale 
	 degree is obtained by adding the diatonic scale degree, 9, and the accidental, 1, which for A# 
	 yields 10 (see figure B.1). The third number, 4, indicates the octave on the standard piano 
	 keyboard.
	 
	 The chromatic degrees from A0 to C8 are predefined in Musimat in both flats and sharps. Since 
	 As4 and Bb4 represent the same chromatic degree, the statement
	 *****************************************************************************/
	
	Print(Bb4 == As4);
	
	/*****************************************************************************
	 prints True. In general, Pitch is defined by the triple (pitch-class, accidental, octave), where 
	 pitch-class is an integer from 0 to N-1, and N is the number of degrees in an octave.
	 
	 In defining the pitch A#4, the triple (9, 1, 4) is assigned to the variable As4. Variable As4 
	 contains these three values as one compound entity. This compound value can be passed from one 
	 Pitch variable to the next. For example, the statements
	 *****************************************************************************/
	
	Pitch x = As4; // assign As4 to x
	Print(x == As4);
	
	/*****************************************************************************
	 print True. Arithmetic can be performed on pitches to sharp or flat them. For example, 
	 *****************************************************************************/
	
	Print(Pitch(A4) + 1);
	
	/*****************************************************************************
	 prints As4, and 
	 *****************************************************************************/
	
	Print(Pitch(A4) - 3);
	
	/*****************************************************************************
	 prints Gb4. Similarly, 
	 *****************************************************************************/
	
	Print(Pitch(A4) * 3);
	
	/*****************************************************************************
	 prints C12, and 
	 *****************************************************************************/
	
	Print(Pitch(A4)/3);
	
	/*****************************************************************************
	 prints E1.
	 
	 Each element of a Pitch can be accessed using these built-in functions:
	 
	 PitchClass(Pitch p)	
	 Returns the diatonic pitch class. For example, if p is As4, 9 
	 is returned (see figure B.1).
	 
	 Accidental(Pitch p)	
	 Returns the accidental as an integer, where 0 is natural, 
	 negative values are increasingly flat, and positive values are 
	 increasingly sharp. For example, if p is As4, 1 is returned.
	 
	 Octave(Pitch p)	
	 Returns the octave on the piano keyboard. For example, if 
	 p is As4, 4 is returned.
	 
	 These elements can be used to determine the piano key index corresponding to 
	 a particular pitch, as shown by the key() function defined below.
	 *****************************************************************************/
	
	para1(); // Step into this function to continue the tutorial
}

Integer key(Pitch p) {
	Integer pc = PitchClass(p);							// from 0 .. 11
	Integer acc = Accidental(p);						// -1=flat, 0=natural, 1=sharp
	Integer oct = Octave(p);							// from 0 .. 8
	Return((pc + acc) + 12 * (oct - 1) + 3);			// combine
}

Static Void para1() {
	
	/*****************************************************************************
	 A way to think about the expression in the Return() statement is as follows. Say we want to find 
	 the piano key index for A0. We know it's the bottom note on the piano, so it should return an index 
	 value of 0. The triple of A0 is (9, 0, 0). The expression in the Return() statement equals 0 for 
	 this triple. Similarly, the triple of A4 is (9, 0, 4), and its corresponding key index is 48.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0201.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

