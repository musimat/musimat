/* $Revision: 1.5 $ $Date: 2006/09/09 06:23:51 $ $Author: dgl $ $Name:  $ $Id: Musimat.cpp,v 1.5 2006/09/09 06:23:51 dgl Exp $ */

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

///	@file Musimat.cpp
///	@brief Definitions of Musimat Datatypes
///

#include <string.h>
#include "Musimat.h"

Integer Length( String s ) { Return( Integer( strlen(s)+1 ) ); }

/// Convert from Real to rational fraction
/// @param f Real value to convert
/// @param a Integer numerator of rational fraction
/// @param b Integer denominator of rational fraction
/// @return The number of attempts to determine the rational fraction.  If the return value equals
/// the internal count value, then the method did not converge.  The values for the numerator and
/// denominator returned are nonetheless the best estimates given the limits.
/// Internal tuning values count and limit are used to control the amount of effort this routine
/// puts into finding the best estimate of the rational fractional equivalent.
Integer RealToRational( Real f, Integer Reference a, Integer Reference b ) {
	If (f == 0.0) {
		a = 0;
		b = 1;
		Return( 0 );
	} Else If (f == 1.0) {
		a = b = 1;
		Return( 0 );
	}

	Const Integer count = 3000000;
	Const Real limit = 0.0000001 /* or try: LDBL_EPSILON * 10000 */;

	If (f < limit) {
		a = 1;
		b = count;
		Return( 0 );
	}

	a = b = 1;	// start off with a ratio of 1/1
	Integer i;
	For (i = 0; i < count; i++) {
		If ( Abs(Real(a)/Real(b) - f) < limit )
			Return i;
		Else {
			Real x = Abs( Real(a+1)/Real(b) - f ); 
			Real y = Abs( Real(a)/Real(b+1) - f );
			If (x < y)
				a++;
			Else
				b++;
		}
	}
	Return i; // If we get here, we've not converged in the number of cycles available
}

Void About()
{
Print("The Musimat Tutorial (©) 2006 Gareth Loy");
Print("Derived from Chapter 9 and Appendix B of \"Musimathics Vol. 1\" © 2006 Gareth Loy");
Print("and published exclusively by The MIT Press.");
Print("This program is released WITHOUT ANY WARRANTY; without even the implied");
Print("warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.");
Print("For information on usage and redistribution, and for a DISCLAIMER OF ALL");
Print("WARRANTIES, see the file, LICENSE.txt, in this distribution.");
Print("\"Musimathics\" is available here:	http://mitpress.mit.edu/catalog/item/default.asp?ttype=2&tid=10916");
Print("Gareth Loy's Musimathics website: http://www.musimathics.com/");
Print("The Musimat website:	http://www.musimat.com/");
Print("This program is released under the terms of the GNU General Public License");
Print("available here: http://www.gnu.org/licenses/gpl.txt");
}

/** \mainpage Musimat Library
\section about_musimatTutorial About MusimatLib
The Musimat Library, documented here, implements the data types and operations used 
by the Musimat Tutorial and Chapter 9 materials.

Musimat is released WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, LICENSE.txt, in this distribution.
This program is released under the terms of the GNU General Public License
available here: http://www.gnu.org/licenses/gpl.txt

"Musimathics" is available here:	http://mitpress.mit.edu/catalog/item/default.asp?ttype=2&tid=10916

Gareth Loy's Musimathics website: http://www.musimathics.com/

The Musimat website:	http://www.musimat.com/
 */

