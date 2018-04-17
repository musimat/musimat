/* $Revision: 1.5 $ $Date: 2006/09/08 18:56:52 $ $Author: dgl $ $Name:  $ $Id: Random.h,v 1.5 2006/09/08 18:56:52 dgl Exp $ */
#ifndef RANDOM_H
#define RANDOM_H

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

#include "Aliases.h"

///	@file Random.h
///	Pseudorandom class
///


/// Random class provides a set of Real and Integer linear congruential random operations.  
/// Note, this implementation does not produce very high-quality randomness.
/// The methods here are good for understanding general principles, but for better numerical results
/// see Press, et. al., "Numerical Recipes in C", Cambridge University Press, 198

const Integer Musimat_Random_Seed = 2147483647;

class Random {

public:

	/// Default constructor.  Initialization constants from Park and Miller.
	Random(Integer a = 16807, Integer b = 0, Integer c = Musimat_Random_Seed) : m_a(a), m_b(b), m_c(c) { m_x = 1; }

	/// Linear congruential method of random number generation.  See Knuth, "Seminumerical Methods".
	Integer lCRandom( ) {
		m_x = mod( m_a * m_x + m_b, m_c ); 	// update x based on its previous value
		Integer r = m_x;
		If ( r < 0 ) 						// force the result to be positive							
			r = -r;	
		Return( r ); 
	}

	/// Return a random value as a Real within a range of Reals.
	/// @param L Lower bound
	/// @param U Upper bound
	/// @return Random Real value
	Real random( Real L, Real U ) {
		Real r = lCRandom();
		r = r / Real( m_c );
		Return( r * ( U - L ) + L );
	}

	/// Return a random value as a Real within a range of Reals.
	/// @param L Lower bound
	/// @param U Upper bound
	/// @return Random Integer value
	Integer random( Integer L, Integer U ) {
		Real i = random( Real( L ), U + 1.0 );
		Return( Integer( i ) );
	}

	/// Return old random seed, set new seed.
	/// @param s New Integer seed
	/// @return Old Integer seed
	Integer seed( Integer s ) {
		Integer r = m_x;
		m_x = s;
		Return( r );
	}

	/// Return number of seconds since epoch.  Used to automatically obtain fluctuating random sequences.
	/// @return Time in seconds since the epoch.
	Integer getTime();

private:
	Const Integer m_a;
	Const Integer m_b;
	Const Integer m_c;
	Integer m_x;						///< stores the previous random value

# if 0
	// This is the didactic method for modulo arithmetic described in "Musimathics"
	Integer mod( Integer j, Integer k ) {
		While ( j >= k ) { j = j - k; }
		While ( j <= -k ) { j = j + k; }
		Return( j );
	}
# else
	// We'll use the built-in mod operator instead for speed
	Integer mod( Integer j, Integer k ) {
		Return j % k; 
	}
#endif
};

/// Didactic wrapper for lCRandom method.
Integer LCRandom( );

///Didactic wrapper for Integer random method.
Integer IRandom( Integer L, Integer U );

/// Didactic wrapper for seed method.
Integer SeedRandom( Integer seed );

/// Return elapsed seconds since epoch.
/// Get the elapsed seconds since the epoch by calling system time function.
Integer Time();

/// Didactic wrapper for random method.
Real Random( Real L = 0.0, Real U = 1.0 );

/// Integer didactic wrapper for random method.
Integer Random( Integer L, Integer U );

#endif // RANDOM_H

