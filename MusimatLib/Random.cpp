/* $Revision: 1.5 $ $Date: 2006/09/08 18:55:37 $ $Author: dgl $ $Name:  $ $Id: Random.cpp,v 1.5 2006/09/08 18:55:37 dgl Exp $ */
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

#include <time.h>
#include "Musimat.h"

Static class Random ran;

Integer LCRandom( ) { Return ran.lCRandom( ); }

Real Random( Real L, Real U )
{
	Return ran.random( L, U );
}

Integer Random( Integer L, Integer U )
{
	Return ran.random( L, U ); 
}

Integer IRandom( Integer L, Integer U )
{
	Return ran.random( L, U ); 
}

Integer SeedRandom( Integer seed ) 
{
	Return ran.seed( seed ); 
}

Integer Random::getTime( )
{
	Return( Integer(time(0)) );  // time_t
}

Integer Time() 
{
	Return ran.getTime(); 
}
