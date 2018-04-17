/* $Revision: 1.5 $ $Date: 2006/09/08 18:55:37 $ $Author: dgl $ $Name:  $ $Id: Pitch.cpp,v 1.5 2006/09/08 18:55:37 dgl Exp $ */
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

#include "Musimat.h"

char Pitch::s_buf[16];						///< Used to format string representation of Pitch
String Pitch::s_pcNames = (char*)"CCDDEFFGGAAB";	///< Used to identify diatonic pitch
Real Pitch::s_HzReference = 440.0;			///< Reference frequency
Integer Pitch::s_nDegrees = 12;				///< Global spec. of how many degrees per Ntave (octave, tritave, etc.)
Integer Pitch::s_lowestDegree = 0;			///< The lowest degree in the gamut
Integer Pitch::s_highestDegree = 88;		///< The highest degree in the gamut

ostream& operator<<( ostream& os, Pitch& p ) 
{
	os << p.print();
	Return os;
}

inline Bool isnumeric(char c)
{
	Return c >= '0' && c <= '9';
}

inline Bool inRange(char c, char lb, char ub)
{
	Return c >= lb && c <= ub;
}

istream& operator>>( istream& is, Pitch& p ) 
{
	//char buf[16];
	//cin >> buf;
	//p = Pitch(buf);
	//Return is;
	char c;
	cin >> c;
	If ((p.m_pc = p.isPitchClass(c)) == -1) {
		cin.unget();
		Return is;
	}

	Integer acc = 0;
	While (cin >> c && ((acc = p.isAccidental(c)) != -3)) {
		p.m_acc += acc;
	}

	If (!inRange(c, '0', '9')) {
		cin.unget();
		Return is;
	} Else {
		char buf[16];
		char* b = buf;
		Integer cnt = 0;
		cin.unget(); 
		While (!cin.eof() && cin >> c && isnumeric(c) && cnt++ < 16) {
//			char y = cin.eof();
			*b++ = c;
		}
		cin.unget();
		*b = '\0';
		p.m_oct = atoi(buf);
	}
	Return is;
}

Pitch::Pitch(String s) : m_pc(0), m_acc(0), m_oct(0) {
	If ((m_pc = isPitchClass(*s)) == -1)
		Return;

	Integer acc = 0;
	While ((acc = isAccidental(*++s)) != -3) {
		m_acc += acc;
	}

	If (*s == 0)
		Return;
	Else
		m_oct = atoi(s);
}

