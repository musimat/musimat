/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:00 $ $Author: dgl $ $Name:  $ $Id: Guido.cpp,v 1.3 2006/09/05 08:03:00 dgl Exp $ */
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
#include "Guido.h"

Static String pitches = "TABCDEFGabcdefg";

Void Guido( String text ) {
	// Evaluate one Character of the text at a time
	For ( Integer i = 0; i < Length( text ); i = i + 1 ) {
		Integer offset;
		Character c = text[ i ]; // Get a Charater of the text
		
		If ( c == 'a' ) { offset = 0; }
		Else If ( c == 'e' ) { offset = 1; }
		Else If ( c == 'i' ) { offset = 2; }
		Else If ( c == 'o' ) { offset = 3; }
		Else If ( c == 'u' ) { offset = 4; }
		Else { offset = -1; } // The Character is not a vowel 
		
		If ( offset != -1 ) { // If the Character is a vowel, print it
			Integer R = IRandom( 0, 2 ); // Returns 0, 1 or 2
			Integer n = ( 3 * R ) + offset;
			Print( pitches[ n ] );
		}
	}
}
