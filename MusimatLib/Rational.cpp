/* $Revision: 1.4 $ $Date: 2006/09/07 08:38:42 $ $Author: dgl $ $Name:  $ $Id: Rational.cpp,v 1.4 2006/09/07 08:38:42 dgl Exp $ */
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
#include "float.h"

// Private buffer to format strings in
Character Rational::s_buf[128];

ostream& operator<<( ostream& os, Rational& r ) 
{
	os << r.print();
	Return os;
}

istream& operator>>( istream& is, Rational& p ) 
{
	char ch;
	is >> ch && (ch == '{' || ch == '(')
		&& is >> p.m_num >> ch && ch == ','
		&& is >> p.m_den >> ch && (ch == '}' || ch == '(');
	Return is;
}

RationalList RealListToRationalList( RealList R )
{
	RationalList L;
	For (Integer i = 0; i < Length( R ); i++ ) {
		Rational x(R[i]);
		L[i] = x;
	}
	Return( L );
}
