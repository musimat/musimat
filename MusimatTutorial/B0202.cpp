#include "MusimatTutorial.h"
MusimatTutorialSection(B0202) {
	Print("*** B.2.2 Rhythm ***");
	/*****************************************************************************
	 
	 B.2.2 Rhythm
	 
	 Duration in common music notation is expressed as a fraction of a whole note. For example a whole 
	 note equals four quarter notes:
	 
	 w  = q + q + q + q
	 
	 /*****************************************************************************
	 We could write this mathematically as follows:
	 
	 1   1 1 1 1
	 - = -,-,-,-
	 1   4 4 4 4
	 
	 which suggests using rational fractions to represent rhythmic durations. A rational fraction is a 
	 ratio of integers. Musimat comes with a built-in data type called Rhythm, which emulates com-
	 mon musical notation conventions regarding rhythm. For example, the quarter note is defined as
	 *****************************************************************************/
	
	Rhythm Q = Rhythm( 1, 4 );
	
	/*****************************************************************************
	 The first number is the numerator of the rational fraction, the second is the denominator. Note that 
	 we can't write Rhythm(1/4) because the integer quotient of 1/4 is 0 with a remainder of 1; integer 
	 division is performed if both the numerator and denominator are integers, which won't work here. 
	 Specifying the numerator and denominator separately avoids this problem and has some other 
	 numerical advantages as well. Executing Print(Q); prints (1, 4). Internally, Rhythm() 
	 keeps the integer numerator and denominator values separately.
	 
	 Rhythmic duration can also be given as a real expression. 
	 *****************************************************************************/
	
	Print(Rhythm(0.5)); 
	
	/*****************************************************************************
	 prints (1, 2). How does Rhythm() convert this real expression into a ratio of integers? It does so by 
	 calling the following function internally:
	 *****************************************************************************/
	
	para1();  // Step into this function to continue the tutorial
	para2();  // Step into this function to continue the tutorial
}

Void realToRational(Real f, Integer Reference num, Integer Reference den) {
	Const Integer iterations = 3000000;
	Const Real limit = 0.000000000001;
	num = den = 1; // start off with ratio of 1/1
	For (Integer i = 0; i < iterations; i = i + 1) {
		If (Abs( Real(num) / Real(den) - f ) < limit)
			Return; // we have reached the limit
		Else {
			Real x = Abs(Real(num+1) / Real(den) - f);
			Real y = Abs(Real(num) / Real(den+1) - f);
			If (x < y)
				num = num + 1;
			Else
				den = den + 1;
		}
	}
	Return; // if we get here, we've not converged on the limit
}

Static Void para1() {
	
	/*****************************************************************************
	 Function realToRational() takes a Real value f and attempts to find a rational fraction 
	 num/den that is as close as possible to it. It starts by setting num = den = 1 and asking whether 
	 num/den is already close enough to f. If so, it returns. Otherwise, it asks whether (num+1) / den 
	 is closer than num / (den+1). If so, it increments num; otherwise it increments den and repeats the 
	 process. Because num and den are Reference arguments, any changes to these variables within 
	 realToRational() are reflected in the value of the actual arguments supplied to it.
	 
	 This method can be used to find rational approximations to most any real value. For example,
	 *****************************************************************************/
	
	Real Pi = 3.14159265;
	Print(Rhythm(Pi));
	
	/*****************************************************************************
	 prints (1953857, 621932). Note that 1953857/621932 = 3.14159265, which is 
	 pretty close to the value of Pi. This method is limited by the precision of the computer hardware. 
	 The precision of a rational approximation depends upon the value of the built-in variables 
	 iterations and limit. For example, with the values shown in the preceding code, it took 
	 realToRational() 2,575,787 trials to come up with its best approximation of Pi, requiring 
	 about 1 second on my computer. The iteration and limit parameters can be set to whatever 
	 values produce the optimal performance/accuracy cost/benefit ratio. Barring obscure rhythms 
	 (nothing, say, beyond triplet eights), iterations = 240 and limit = 1.0/480 should be 
	 satisfactory.
	 
	 Although the details go beyond the scope of this book, here is a sketch of how Rhythm() uses 
	 realToRational():
	 
	 Rhythm(Real x) {
	 Integer num, den; // internal parameters for Rhythm
	 realToRational( x, num, den ); // convert x to num / den rational fraction
	 // . . .
	 }
	 
	 When called with a Real argument, Rhythm() calls realToRational() to set its internal integer 
	 rational fraction values.
	 
	 Musimat provides built-in definitions for standard binary divisions of a whole note:
	 *****************************************************************************/
	
	Rhythm Whole = Rhythm(1.0/1.0);
	Rhythm Half = Rhythm(1.0/2.0);
	Rhythm Quarter = Rhythm(1.0/4.0);
	Rhythm Eighth = Rhythm(1.0/8.0);
	Rhythm Sixteenth = Rhythm(1.0/16.0);
	
	/*****************************************************************************
	 It is easy to define ternary divisions as well. For example, a triplet eighth is Rhythm(1.0/12.0) 
	 because there are  triplet eighths per whole note. By the same reasoning, a quintuplet 
	 eighth is 
	 *****************************************************************************/
	
	Rhythm Qe = Rhythm(1.0/20.0);
	
	/*****************************************************************************
	 We can express compound rhythms by addition. For example, a dotted half note is
	 *****************************************************************************/
	
	Rhythm Hd = Rhythm(1.0/2.0 + 1.0/4.0); 					// dotted half
	
	/*****************************************************************************
	 Equivalently,
	 *****************************************************************************/
	
	Rhythm H1 = Rhythm(3.0 / 4.0);							// also a dotted half
	
	/*****************************************************************************
	 We can also do arithmetic directly with rhythms. For example, 
	 *****************************************************************************/
	
	Print(Eighth+Sixteenth); 
	
	/*****************************************************************************
	 prints (3, 16). 
	 
	 Also, 
	 *****************************************************************************/
	
	Print(Whole - Sixteenth);
	
	/*****************************************************************************
	 prints (15,16), 
	 *****************************************************************************/
	
	Print(Quarter * Sixteenth);
	
	/*****************************************************************************
	 prints (1,64), and 
	 *****************************************************************************/
	
	Print(Quarter / Sixteenth);
	
	/*****************************************************************************
	 prints (4,1). The last value corresponds to a duration of four whole notes.
	 
	 We can extract the numerator and denominator from Rhythm():
	 *****************************************************************************/
	
	Integer num, den;
	Rhythm z = Rhythm(Eighth + Sixteenth, num, den); // assigns rational fraction for E+S to num and den
	
	/*****************************************************************************
	 Used this way, Rhythm() calculates the rational fraction of its first argument and sets num and 
	 den by reference to the result. For the preceding example, num is set to 3 and den is set to 16. We 
	 can leverage this capability to obtain the duration of a rhythm as a real number:
	 *****************************************************************************/
}

Real realRhythm(Rhythm x) {
	Integer num, den;
	Rhythm(x, num, den); // find rational fraction for x and set num and den
	Return(Real(num)/Real(den)); // convert num and den to reals and divide
}

Void para2() {

	/*****************************************************************************
	 Then, for example, executing Print(realRhythm(E + S)); prints 0.1875.
	 As with pitches, we can make lists of rhythms.
	 *****************************************************************************/
	
	RhythmList RL = RhythmList(Quarter, Eighth, Eighth, Eighth, Sixteenth, Sixteenth, Quarter);
	Print(RL);
	
	/*****************************************************************************
	 prints {(1,4), (1,8), (1,8), (1,8), (1,16), (1,16), (1,4)}.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0202.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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

