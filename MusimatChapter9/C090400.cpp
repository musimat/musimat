#include "MusimatChapter9.h"
MusimatChapter9Section(C090400) {
	Print("*** 9.4 Program for Guido's Method ***");
	/*****************************************************************************
	 
	 9.4 Program for Guido's Method
	 
	 With the Musimat programming language we can program a version of Guido's method.
	 First, we transform Guido's vowel sequences to pitches by defining
	 the PitchList guidoPitches, below.  This lists the available pitches in
	 the vocal gamut of his day.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
	para2(); // Step into this function to continue.
}

PitchList guidoPitches(G3,A3,B3,C4,D4,E4,F4,G4,A4,B4,C5,D5,E5,F5,G5);

Static Void para1() {
	/*****************************************************************************
	 See "Musimathics" section B.2.1 for a description of PitchList. 
	 Then we need a source of judgment for which of Guido's three vowel sequences 
	 should be chosen. We'll use the integer Random( ) method to generate random values. 
	 Combining these, we obtain the program for Guido's method. Here is the
	 version from Musimathics:
	 *****************************************************************************/
}

PitchList guido1(String text) {
	PitchList G;					//place to put the mel	ody
	Integer k = 0;					//indexes G
	Integer offset;					//indexes guidoPitches[ ]
	//evaluate one character of the text at a time
	For (Integer i = 0; i < Length(text); i = i + 1) {
		Character c = text[ i ];	//get a character of the text
		If ( c == 'a' ) { offset = 0; }
		Else If ( c == 'e' ) { offset = 1; }
		Else If ( c == 'i' ) { offset = 2; }
		Else If ( c == 'o' ) { offset = 3; }
		Else If ( c == 'u' ) { offset = 4; }
		Else { offset = -1; }		//the character is not a vowel
		If ( offset != -1 ) {		//if the character is a vowel. . .
			Integer R = Random( 0, 2 );	//returns 0, 1, or 2
			Integer n = ( 5 * R ) + offset;
			G[ k ] = guidoPitches[ n ];
			k = k + 1;
		}
	}
	Return( G );					//return the list of pitches composed
}

/*****************************************************************************
 As an alternative to lots of If/Else statements, we can instead use the 
 more compact Switch statement. Here's an alternative definition of function guido() 
 using the more efficient switch statement. We'll add support for upper Case as well.
 *****************************************************************************/
PitchList guido(String text) {
	PitchList G;					//place to put the mel	ody
	Integer k = 0;					//indexes G
	Integer offset;					//indexes guidoPitches[ ]
	//evaluate one character of the text at a time
	For (Integer i = 0; i < Length(text); i = i + 1) {
		Character c = text[ i ];	//get a character of the text
		Switch ( c ) {
			Case 'a': Case 'A': offset = 0; Break;
			Case 'e': Case 'E': offset = 1; Break;
			Case 'i': Case 'I': offset = 2; Break;
			Case 'o': Case 'O': offset = 3; Break;
			Case 'u': Case 'U': offset = 4; Break;
			Default: offset = -1;			Break; //the character is not a vowel
		}
		If ( offset != -1 ) {		//if the character is a vowel. . .
			Integer R = Random( 0, 2 );	//returns 0, 1, or 2
			Integer n = ( 5 * R ) + offset;
			G[ k ] = guidoPitches[ n ];
			k = k + 1;
		}
	}
	Return( G );					//return the list of pitches composed
}


Static Void para2() {
	/*****************************************************************************
	 The program indexes one Character at a time of text. 
	 If Character c is a vowel, it calculates offset based on which vowel it is. 
	 If it is not a vowel, the program sets offset to -1 so that the final step is skipped. 
	 If it is a vowel, the program chooses a random number 0, 1, or 2, corresponding to the 
	 three possible outcomes for each vowel. This is multiplied by 5, corresponding to the
	 number of vowels, and added to offset to arrive at the index of the selected element in 
	 the list of guidoPitches. The selected Character from that list is then stored in PitchList G. 
	 The method is repeated until text is exhausted. PitchList G then contains the list of pitches 
	 composed for this text. As its final action, the PitchList G is returned to the calling program.
	 To invoke the function guido(), we need a Latin text. I'll use the first phrase of the text 
	 Guido used to name the solfeggio syllables, the medieval hymn Sanctus Joharines (St. John). 
	 This program fragment prints the pitches for a plain chant melody based on the text:
	 *****************************************************************************/
	
	Print("*** Guidonian melody for the text: Ut queant laxis resonare ***");
	Print(guido("Ut queant laxis resonare"));
	
	/*****************************************************************************
	 An example result of this method is shown in "Musimathics" V1, figure 9.3.
	 *****************************************************************************/											
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:45 $ $Author: dgl $ $Name:  $ $Id: C090400.cpp,v 1.3 2006/09/05 08:02:45 dgl Exp $ */
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
