/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:15 $ $Author: dgl $ $Name:  $ $Id: Euclid.cpp,v 1.2 2006/09/05 06:32:15 dgl Exp $ */
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

Integer Euclid( Integer m, Integer n ) {
	Repeat { 
		Integer r = Mod(m, n); 

		If ( r == 0 )  
			Return( n ) ;
		Else  { 
			m = n; 
			n = r; 
		}
	}
}
