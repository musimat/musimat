/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:54 $ $Author: dgl $ $Name:  $ $Id: Row.cpp,v 1.3 2006/09/05 08:02:54 dgl Exp $ */
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

///	@file Row.cpp
///	@brief Misc. row functions
///

#include "Musimat.h"

Integer InterpTendency( Real f, IntegerList L1, Integer Reference pos1, IntegerList L2, Integer Reference pos2, Integer inc ) {
	Integer x = cycle<Integer,IntegerList>(L1, pos1, inc);
	Integer y = cycle<Integer,IntegerList>(L2, pos2, inc);
	Return( Integer( Round( unitInterp( f, x, y ) ) ) );
}

Pitch LinearInterpolate( Pitch x, Pitch xMin, Pitch xMax, Pitch yMin, Pitch yMax ) {
	Real xr = x.degree();
	Real xm = xMin.degree();
	Real xM = xMax.degree();
	Real ym = yMin.degree();
	Real yM = yMax.degree();
	Real a = ( xr - xm) / (xM - xm );
	Real b = yM - ym;
	Return( Integer(a * b + ym) );
}
