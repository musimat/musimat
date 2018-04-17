#include "MusimatChapter9.h"
MusimatChapter9Section(C091406c) {
	Print("*** A Less Boring (?) Musical Example ***");
	/*****************************************************************************
	 
	 A Less Boring (?) Musical Example
	 
	 Unfortunately, this melody is dreadfully dull, but it strictly obeys our requirements. This goes to 
	 show that one only gets back from an approach like this exactly what one specifies. A more graceful 
	 melody might rise to its climax gradually, then fall at the end. The following example accomplishes 
	 this by selecting among a set of probability distributions at different points of the melody.
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}


//each list specifies 13 pitches
RealList a(	 //force choice to be pitch C
		   1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		   );
RealList b(	 //force selection of C#, D, D#, E, or F
		   0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 
		   );
RealList c( 	 //force selection of F#, G, G# A, A#, or B
		   0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 
		   );
RealList d( 	 // force selection of pitch c an octave above
		   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 
		   );

// indicate what percentage of the score is completed
Real progress(Integer p, Integer L) {
	Return Real(p) / Real(L);	// L is the total number of notes and p is the current note
}

StringList n("C", "Cs", "D", "Ds", "E", "F", "Fs", 
			 "G", "Gs", "A", "As", "B", "c");

Void randomMelody(RealList a, RealList b, RealList c, RealList d) {
	Integer K = 25;								// we'll play 25 notes
	Integer highPoint = Integer(K * 2.0/3.0);
	normalize(a, sum(a)); normalize(b, sum(b));
	normalize(c, sum(c)); normalize(d, sum(c));
	StringList s;								// a place to put result
	For (Integer i = 0; i < K; i++) {
		RealList f;
		
		If (i == 0 Or i == K - 1)	 			// force first and last notes to
			f = a;								// be pitch C
		Else If (progress(i, K) < 0.30)			// less than 30% of the way?
			f = b;								// force lower hexachord
		Else If (progress(i, K) < 0.60)			// between 30% and 60%?
			f = c;								// force upper hexachord
		Else If (i == highPoint)				// force high point to be high c 
			f = d;
		Else If (progress(i, K) < 0.80)			// between 60% and 80%?
			f = c;								// force upper hexachord
		Else									// otherwise force lower hexachord
			f = b;
		
		f = normalize(f, sum(f)); 				// replace f with its normalized form
		accumulate(f);
		Real r = Random();
		Integer p = getIndex(f, r);
		s[i] = n[p];							// n is StringList defined in previous example
	}
	
	Print(s);
}

Static Void para1() {
	/*****************************************************************************
	 Running this program will generate something like figure 9.24, depending upon the values pro-
	 duced by Random(). The distributions responsible for each section are shown in the figure.
	 *****************************************************************************/
	
	// Each list specifies 13 pitches
	// List a forces the choice to be pitch C
	RealList a( 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 );
	// List b forces C#, D, D#, E, or F
	RealList b ( 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 );
	// List c forces F#, G, G# A, A#, or B
	RealList c ( 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 );
	// List d forces pitch c an octave above
	RealList d ( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 );
	SeedRandom( Time() );	// force a new choice every time
	randomMelody( a, b, c, d );
	
	/*****************************************************************************
	 The musical example in figure 9.24 is certainly an improvement, but I doubt it would win any 
	 prizes. Certainly a composer of a melody takes its whole shape into consideration during writing, 
	 but successive weighted random selections are completely independent of the past and future. 
	 Many composers have used techniques like this to obtain freedom from predictable musical con-
	 texts. But we must have a way to correlate past and future choices to the present before random 
	 choice techniques are of use in those musical styles that manipulate listener expectation. The next 
	 section lays the foundations for a mathematics of expectation.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: C091406c.cpp,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
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

