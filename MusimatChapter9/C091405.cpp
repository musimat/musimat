#include "MusimatChapter9.h"
MusimatChapter9Section(C091405) {
	Print("*** 9.14.5 Generating Outcomes from Probability Distributions ***");
	/*****************************************************************************
	 
	 9.14.5 Generating Outcomes from Probability Distributions
	 
	 Probability distributions allow us to analyze random systems like dice and coins, but we can also 
	 use them to synthesize random numbers that are distributed in probability according to our choos-
	 ing. We can use such systems to drive compositional processes to automatically generate music 
	 according to rules that we supply.
	 
	 Say, for instance, we wish to use a random system to create a melody so that it favors lower 
	 pitches in the scale. Let's limit the sample space to one octave of the chromatic scale. We can rep-
	 resent this as a probability inequality:
	 
	 f (x) == P( R = C ) > P(R = C#) > P(R = D)  > . . . > P(R = B).
	 
	 To be specific, suppose we want to create a probability distribution function that is 12 times more 
	 likely to pick C than B, 11 times more likely to pick C# than B, 10 times more likely to pick D than 
	 B, and so on. The probability distribution function would look like the one in figure 9.20.
	 
	 We know what we want, but how do we get it? So far, the only things we have to work with are 
	 a random number generator, Random() (see appendix B, B.1.27) and a probability distribution 
	 function (figure 9.21).
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:02 $ $Author: dgl $ $Name:  $ $Id: C091405.cpp,v 1.2 2006/09/05 06:32:02 dgl Exp $ */
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

