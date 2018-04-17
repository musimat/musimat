/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:54 $ $Author: dgl $ $Name:  $ $Id: Rhythm.cpp,v 1.3 2006/09/05 08:02:54 dgl Exp $ */
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

#include "Musimat.h"

// There are 4 quarter notes in a whole note
Real Rhythm::s_fourQuarters = 4.0;

// Implicit coefficient applied to all rhythmic values globally.
// Initial value is 1.0, equal to a quarter note at MM=60 BPM.
Real Rhythm::s_tempo = Rhythm::mmInit( 1.0/4.0, 60.0 );

// Private buffer to format strings in
Character Rhythm::s_buf[128];

Void SetTempoScale( Real ts )
{
	Rhythm::tempo(ts);
}

Real metronome( Rhythm B, Real T )
{
	Return( 1.0 / (4.0 * B.absDuration()) * 60.0 / T );
}

Real Duration( Real x )
{
	Rhythm(y);
	Return y.duration();
}

Real Duration( Integer n, Integer d)
{
	Rhythm y = Rhythm(n, d);
	Return y.duration();
}

Real AbsDuration( Real x )
{
	Rhythm(y);
	Return y.absDuration();
}

Real Duration( Rhythm y )
{
	Return y.absDuration();
}

Real AbsDuration( Rhythm y )
{
	Return y.absDuration();
}

ostream& operator<<( ostream& os, Rhythm& r ) 
{
	os << r.print();
	Return os;
}

istream& operator>>( istream& is, Rhythm& p ) 
{
	char ch;
	is >> ch && (ch == '{' || ch == '(')
		&& is >> p.m_num >> ch && ch == ','
		&& is >> p.m_den >> ch && (ch == '}' || ch == '(');
	Return is;
}

Rhythm Whole = Duration( 1 ),		///< Duration of a whole note
	Half = Duration( 1, 2 ), 		///< Duration of a half note
	Quarter = Duration( 1, 4 ),		///< Duration of a quarter note 
	Eighth = Duration( 1, 8 ), 		///< Duration of a eighth note
	Sixteenth = Duration( 1, 16 )	///< Duration of a sixteenth note
; 

