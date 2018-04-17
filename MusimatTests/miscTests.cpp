/* $Revision: 1.5 $ $Date: 2006/09/08 18:55:58 $ $Author: dgl $ $Name:  $ $Id: miscTests.cpp,v 1.5 2006/09/08 18:55:58 dgl Exp $ */
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

#ifndef __GNUC__
#include <crtdbg.h>
#endif // __GNUC__
#include <math.h>
#include "Musimat.h"
#include "Pitches.h"
#include "Guido.h"
#include "Euclid.h"
#include "cplxTest.h"
#include <iostream>

void MinMaxVecTest()
{
	Complex p(3.14, 3.14);
	Complex q(1.0, 1.0);
	// p is greater than q
	Print("p < q: ", p < q);
	Print("q < p: ", q < p);
	Print("p > q: ", p > q);
	Print("q > p: ", q > p);

	RealList rL(1.0, 2.0, 3.0, 4.0, 5.0);
	IntegerList iL(1, 2, 3, 4, 5);
	PitchList pL(A4, As4, B4, C5, Cs5);
	ComplexList cL(Complex(0.0, 1.0), Complex(3.14, 2.0), Complex(4.0,3.0));
	RhythmList rhL(Rhythm(1, 4), Rhythm(3, 1), Rhythm(4,1));
	RationalList raL(Rational(0, 1), Rational(3, 1), Rational(4,1));

	Print("rL=", rL);
	Print("iL=", iL);
	Print("pL=", pL);
	Print("cL=", cL);
	Print("rhL=", rhL);
	Print("raL=", raL);

	Print("Max(rL): ", Max(rL));
	Print("Max(iL): ", Max(iL));
	Print("Max(pL): ", Max(pL));
	Print("Max(cL): ", Max(cL));
	Print("Max(rhL): ", Max(rhL));
	Print("Max(raL): ", Max(raL));

	Print("MaxPos(rL): ", MaxPos(rL));
	Print("MaxPos(iL): ", MaxPos(iL));
	Print("MaxPos(pL): ", MaxPos(pL));
	Print("MaxPos(cL): ", MaxPos(cL));
	Print("MaxPos(rhL): ", MaxPos(rhL));
	Print("MaxPos(raL): ", MaxPos(raL));

	Print("Min(rL): ", Min(rL));
	Print("Min(iL): ", Min(iL));
	Print("Min(pL): ", Min(pL));
	Print("Min(cL): ", Min(cL));
	Print("Min(rhL): ", Min(rhL));
	Print("Min(raL): ", Min(raL));

	Print("MinPos(rL): ", MinPos(rL));
	Print("MinPos(iL): ", MinPos(iL));
	Print("MinPos(pL): ", MinPos(pL));
	Print("MinPos(cL): ", MinPos(cL));
	Print("MinPos(rhL): ", MinPos(rhL));
	Print("MinPos(raL): ", MinPos(raL));

}


Real sum( RealList f ) {
	Real s = 0.0;
	For ( Integer i = 0; i < Length( f ); i = i + 1 ) {
		s = s + f[ i ];
	}
	Return( s );
}

RealList Reference normalize( RealList Reference f, Real s ) {
	For ( Integer i = 0; i < Length( f ); i = i + 1 ) {
		 f[ i ] = f[ i ] / s;
	}
	Return( f );
}

RealList Reference accumulate( RealList Reference f ) {
	For ( Integer i = 1; i < Length( f ); i = i + 1 ) {
		 f[ i ] = f[ i ] + f[ i - 1 ];
	}
	Return( f );
}

Integer getIndex( RealList f, Real R ) {
	For ( Integer i = Length( f ) - 1; i >= 0; i = i - 1 ) {
		If ( R > f[ i ] ) {
			Return( i + 1 );
		}
	}
	Return( 0 );	// In case of an ill-formed list
}

// Indicate what percentage of the score we have completed
Real progress( Integer p, Integer L ) {
	Return Real( p ) / Real( L );							// L is the total number of notes and
}								// p is our current note

#ifdef __oldway__
Void randomMelody( RealList a, RealList b, RealList c, RealList d ) {
	StringList n( "C", "C#", "D", "D#", "E", "F", "F#", 
				"G", "G#", "A", "A#", "B", "c" );
	Integer K = 25;						// We'll play 25 notes
	Integer highPoint = Integer ( K * 2.0 / 3.0 );  
	StringList s;							// a place to put the result
	For ( Integer i = 0; i < K; i++ ) {
		RealList f;
		If ( i == 0 || i == K - 1 )						// Force the first and last notes to
			f = a;					// be the pitch C
		Else If ( progress( i, K ) < 0.30 )								// Less than 30% of the way?
			f = b;					// Force lower hexachord
		Else If ( progress( i, K ) < 0.60 )								// Between 30% and 60% ?
			f = c;					// Force upper hexachord
		Else If ( i == highPoint )						// Force high point to be high c 
			f = d;
		Else If ( progress( i, K ) < 0.80 )								// Between 60% and 80% ?
			f = c;					// Force upper hexachord
		Else						// Otherwise force lower hexachord
			f = b;
		f = normalize( f, sum( f ) ); 							// replace f with its normalized form
		f = accumulate( f ); 							// calculate cumulative distribution function
		Integer p = getIndex( f, Random() );
		s[ i ] = n[ p ];				// The StringList defined in the previous example
	}
	Print( s );
}
#else // __oldway__
Void randomMelody( RealList a, RealList b, RealList c, RealList d ) {
	PitchList n( C3, Cs3, D3, Ds3, E3, F3, Fs3, 
				G3, Gs3, A4, As4, B4, C4 );
	Integer K = 25;						// We'll play 25 notes
	Integer highPoint = Integer ( K * 2.0 / 3.0 );  
	PitchList s;							// a place to put the result
	For ( Integer i = 0; i < K; i++ ) {
		RealList f;
		If ( i == 0 || i == K - 1 )						// Force the first and last notes to
			f = a;					// be the pitch C
		Else If ( progress( i, K ) < 0.30 )								// Less than 30% of the way?
			f = b;					// Force lower hexachord
		Else If ( progress( i, K ) < 0.60 )								// Between 30% and 60% ?
			f = c;					// Force upper hexachord
		Else If ( i == highPoint )						// Force high point to be high c 
			f = d;
		Else If ( progress( i, K ) < 0.80 )								// Between 60% and 80% ?
			f = c;					// Force upper hexachord
		Else						// Otherwise force lower hexachord
			f = b;
//		f = normalize( f, sum( f ) ); 							// replace f with its normalized form
		Real x = sum(f);
		Print("f=", f);
		f= normalize( f, x ); 							// replace f with its normalized form
		Print("f norm=", f);
		f = accumulate( f ); 							// calculate cumulative distribution function
		Print("f acc=", f);
		Real r = Random();
		Print("r=", r);
		Integer p = getIndex( f,  r);
		Print("p=", p);
		s[ i ] = n[ p ];				// The StringList defined in the previous example
	}
	Print( s );
}
#endif // __oldway__

Real Brownian( Real x, Real w, Real B ) {
	Real R;
	Do {
		R = x + Random( -w, w );
	} While ( R > B || R < -B );
	Return R;
}

Real VossFracRand( Integer n, RealList L ) {
	Real sum = 0.0;
	Integer N = Length( L );
	For ( Integer k = 0; k < N; k = k + 1 ) {
		If ( Mod(n, int(pow(2.0, k))) == 0 ) {
			 L[ k ] = Random( );
		}
		sum = sum + L[ k ];
	}
	Return ( sum );
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// TESTS 
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

Void genPitches()
{
	For( Integer oct = 0; oct < 8; oct++) {
		printf("Const Pitch C%d = Pitch(0,0,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 0, 0, oct);
		printf("Const Pitch Cs%d = Pitch(0,1,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 0, 1, oct);
		printf("Const Pitch Db%d = Pitch(2,-1,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 2, -1, oct);
		printf("Const Pitch D%d = Pitch(2,0,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 2, 0, oct);
		printf("Const Pitch Ds%d = Pitch(2,1,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 2, 1, oct);
		printf("Const Pitch Eb%d = Pitch(4,-1,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 4, -1, oct);
		printf("Const Pitch E%d = Pitch(4,0,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 4, 0, oct);
		printf("Const Pitch F%d = Pitch(5,0,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 5, 0, oct);
		printf("Const Pitch Fs%d = Pitch(5,1,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 5, 1, oct);
		printf("Const Pitch Gb%d = Pitch(7,-1,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 7, -1, oct);
		printf("Const Pitch G%d = Pitch(7,0,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 7, 0, oct);
		printf("Const Pitch Gs%d = Pitch(7,1,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 7, 1, oct);
		printf("Const Pitch Ab%d = Pitch(9,-1,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 9, -1, oct);
		printf("Const Pitch A%d = Pitch(9,0,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 9, 0, oct);
		printf("Const Pitch As%d = Pitch(9,1,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 9, 1, oct);
		printf("Const Pitch Bb%d = Pitch(11,-1,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 11, -1, oct);
		printf("Const Pitch B%d = Pitch(11,0,%d);\t\t///< Pitch Class = %2d, Accidental = %2d, Octave = %d\n", oct, oct, 11, 0, oct);
	}
	fflush(stdout);
}

Void RhythmTests()
{
	Print ( "vvvvvvvvv RhythmTests vvvvvvvvv" );
	Rhythm a(2,3);
	Rhythm b(1,2);
	Rhythm c;
	Print("c = a: ", c = a);
	Print("a == b: ", a == b);
	Print("a != b: ", a != b);

	Print("a < b:", a < b);
	Print("a <= b:", a <= b);
	Print("a > b:", a > b);
	Print("a >= b:", a >= b);

	Print("c += b: ", c += b);
	Print("a + b: ", a + b);
	Print("a += 1: ", a += 1);
	Print("a -= 1: ", a -= 1);
	Print("a *= 2: ", a *= 2);
	Print("a /= 2: ", a /= 2);
	Print("a + 1: ", a + 1);
	Print("a - 1: ", a - 1);
	Print("a * 1: ", a * 1);
	Print("a / 2: ", a / 2);
	Print ( "^^^^^^^^^ RhythmTests ^^^^^^^^^" );
}

Void RationalTests()
{
	Print ( "vvvvvvvvv RationalTests vvvvvvvvv" );
	Rational a(2,3);
	Rational b(1,2);
	Rational c;
	Print("c = a: ", c = a);
	Print("a == b: ", a == b);
	Print("a != b: ", a != b);

	Print("a < b:", a < b);
	Print("a <= b:", a <= b);
	Print("a > b:", a > b);
	Print("a >= b:", a >= b);

	Print("c += b: ", c += b);
	Print("a + b: ", a + b);
	Print("a += 1: ", a += 1);
	Print("a -= 1: ", a -= 1);
	Print("a *= 2: ", a *= 2);
	Print("a /= 2: ", a /= 2);
	Print("a + 1: ", a + 1);
	Print("a - 1: ", a - 1);
	Print("a * 1: ", a * 1);
	Print("a / 2: ", a / 2);
	Print ( "^^^^^^^^^ RationalTests ^^^^^^^^^" );
}

Void RealListTests()
{
	Print ( "vvvvvvvvv RealListTests vvvvvvvvv" );
	RealList r(1,2,3,4,5,6,7,8,9,10);
	RealList s(0, 1,2,3,4,5,6,7,8,9);
	Print("r == r: ", r == r);
	Print("r != s: ", r != s);
	Print("r += s: ", r += s);
	Print("r + s: ", r + s);
	Print("r = s: ", r = s);
	Print("r[0] = s[0]: ", r[0] = s[0]);
	Print("r += 1: ", r += 1);
	Print("r -= 1: ", r -= 1);
	Print("r + 1: ", r + 1);
	Print("r - 1: ", r - 1);
	Print("r * 2: ", r * 2);
	Print("r / 2: ", r / 2);
	Print("r += 2.0: ", r += 2.0);
	Print("r -= 2.0: ", r -= 2.0);
	Print("r + 2.0: ", r + 2.0);
	Print("r - 2.0: ", r - 2.0);
	Print("r * 2.0: ", r * 2.0);
	Print("r / 2.0: ", r / 2.0);
	Print("s != r: ", s != r);
	Print("s += r: ", s += r);
	Print("s + r: ", s + r);
	Print("s = r: ", s = r);
	Print("s[0] = r[0]: ", s[0] = r[0]);
//	Print("1 + r: ", 1 + r);
//	Print("1 - r: ", 1 - r);
//	Print("2 * r: ", 2 * r);
//	Print("2 / r: ", 2 / r);
//	Print("2.0 + r: ", 2.0 + r);
//	Print("2.0 - r: ", 2.0 - r);
//	Print("2.0 * r: ", 2.0 * r);
//	Print("2.0 / r: ", 2.0 / r);
	Print ( "^^^^^^^^^ RealListTests ^^^^^^^^^" );
}

Void IntegerListTests()
{
	Print ( "vvvvvvvvv IntegerListTests vvvvvvvvv" );
	IntegerList r(1,2,3,4,5,6,7,8,9,10);
	IntegerList s(0, 1,2,3,4,5,6,7,8,9);
	Print("r == r: ", r == r);
	Print("r != s: ", r != s);
	Print("r += s: ", r += s);
	Print("r + s: ", r + s);
	Print("r = s: ", r = s);
	Print("r[0] = s[0]: ", r[0] = s[0]);
	Print("r += 1: ", r += 1);
	Print("r -= 1: ", r -= 1);
	Print("r + 1: ", r + 1);
	Print("r - 1: ", r - 1);
	Print("r * 2: ", r * 2);
	Print("r / 2: ", r / 2);
	//Print("r += 2.0: ", r += 2.0);
	//Print("r -= 2.0: ", r -= 2.0);
//	Print("r + 2.0: ", r + 2.0);
//	Print("r - 2.0: ", r - 2.0);
//	Print("r * 2.0: ", r * 2.0);
//	Print("r / 2.0: ", r / 2.0);
	Print ( "^^^^^^^^^ IntegerListTests ^^^^^^^^^" );
}

Void RationalListTests()
{
	Print ( "vvvvvvvvv RationalListTests vvvvvvvvv" );
	RationalList r(.1,.2,.3,.4,.5,.6,.7,.8,.9,1.0);
	RationalList s(2,3,4,5,6,7,8,9,10,11);
	Print("r == r: ", r == r);
	Print("r != s: ", r != s);

	Print("r += s: ", r += s); 
//	Print("r -= s: ", r -= s); // not implemented (what would it mean?)
	Print("r + s: ", r + s);
//	Print("r - s: ", r - s); // not implemented (what would it mean?)
	Print("r = s: ", r = s);
	Print("r[0] = s[0]: ", r[0] = s[0]);

	Print("r += 1: ", r += 1);
	Print("r -= 1: ", r -= 1);
	Print("r + 1: ", r + 1);
	Print("r - 1: ", r - 1);
	Print("r * 2: ", r * 2);
	Print("r / 2: ", r / 2);

	Print("r += 2.0: ", r += 2.0);
	Print("r -= 2.0: ", r -= 2.0);
	Print("r + 2.0: ", r + 2.0);
	Print("r - 2.0: ", r - 2.0);
	Print("r * 2.0: ", r * 2.0);
	Print("r / 2.0: ", r / 2.0);
	Print ( "^^^^^^^^^ RationalListTests ^^^^^^^^^" );
}

Void RhythmListTests()
{
	Print ( "vvvvvvvvv RhythmListTests vvvvvvvvv" );	
	RhythmList r(.1,.2,.3,.4,.5,.6,.7,.8,.9,1.0);	
	RhythmList s(2,3,4,5,6,7,8,9,10,11);	
	Print("r == r: ", r == r);	
	Print("r != s: ", r != s);	
	Print("r += s: ", r += s);  // xxx
	Print("r + s: ", r + s);	// xxx
	Print("r = s: ", r = s);
	Print("r[0] = s[0]: ", r[0] = s[0]);
	Print("r += 1: ", r += 1);
	Print("r -= 1: ", r -= 1);
	Print("r + 1: ", r + 1);
	Print("r - 1: ", r - 1);
	Print("r * 2: ", r * 2);
	Print("r / 2: ", r / 2);
	Print("r += 2.0: ", r += 2.0);
	Print("r -= 2.0: ", r -= 2.0);
	Print("r + 2.0: ", r + 2.0);
	Print("r - 2.0: ", r - 2.0);
	Print("r * 2.0: ", r * 2.0);
	Print("r / 2.0: ", r / 2.0);
	Print ( "^^^^^^^^^ RhythmListTests ^^^^^^^^^" );
}

Void PitchListTests()
{
	Print ( "vvvvvvvvv PitchListTests vvvvvvvvv" );
	PitchList r( C0, Cs1, D2, Ds3, E4, F5, Fs6, G7, Gs0, A4, As0, B7 );
	PitchList s( B7, C0, Cs1, D2, Ds3, E4, F5, Fs6, G7, Gs0, A4, As0 );
	Print("r == r: ", r == r);
	Print("r != s: ", r != s);
	Print("r += s: ", r += s);
	Print("r + s: ", r + s);
	Print("r = s: ", r = s);
	Print("r[0] = s[0]: ", r[0] = s[0]);
	Print("r += 1: ", r += 1);
	Print("r -= 1: ", r -= 1);
	Print("r + 1: ", r + 1);
	Print("r - 1: ", r - 1);
	Print("r * 2: ", r * 2);
	Print("r / 2: ", r / 2);
	//Print("r += 2.0: ", r += 2.0);
	//Print("r -= 2.0: ", r -= 2.0);
	Print("r + 2.0: ", r + 2.0);
	Print("r - 2.0: ", r - 2.0);
	Print("r * 2.0: ", r * 2.0);
	Print("r / 2.0: ", r / 2.0);
	Print ( "^^^^^^^^^ PitchListTests ^^^^^^^^^" );
}

Void pitchTest1()
{
	Print ( "vvvvvvvvv pitchTest1 vvvvvvvvv" );
	Pitch x = E4;
	Print ( "x = E4 =", x );
	Print( x += 2 );
	Print ( "x += 2 =", x );
	PitchList L( C0, Cs1, D2, Ds3, E4, F5, Fs6, G7, Gs0, A4, As0, B7 );
	Print("PitchList=", L );
	L += 2;
	Print("PitchList+=2 =", L );
	L -= 3;
	Print("PitchList-=3 =", L );
	Print ( "^^^^^^^^^ pitchTest1 ^^^^^^^^^" );
}

Void pitchOperatorTest()
{
	Print ( "vvvvvvvvv pitchOperatorTest vvvvvvvvv" );
	Integer a4 = Pitch(440.0);
	Print(a4);
	Print("A4==A4: ", A4==A4);
	Print("A4==A4.degree() ", A4==A4.degree());
	Print("A4==A4.hertz() ", A4==A4.hertz());
	Print("A4!=A4: ", A4!=A4);
	Print("A4!=A4.degree() ", A4!=A4.degree());
	Print("A4!=A4.hertz() ", A4!=A4.hertz());

	Print("A4>=B4: ", A4>=B4);
	Print("A4>=B4.degree() ", A4>=B4.degree());
	Print("A4>=B4.hertz() ", A4>=B4.hertz());

	Print("A4>B4: ", A4>B4);
	Print("A4>B4.degree() ", A4>B4.degree());
	Print("A4>B4.hertz() ", A4>B4.hertz());

	Print("A4<B4: ", A4<B4);
	Print("A4<B4.degree() ", A4<B4.degree());
	Print("A4<B4.hertz() ", A4<B4.hertz());

	Print("A4<=B4: ", A4<=B4);
	Print("A4<=B4.degree() ", A4<=B4.degree());
	Print("A4<=B4.hertz() ", A4<=B4.hertz());

	Pitch x = Pitch(B4);
	Print("x: ", x);
	Integer d = E.degree();
	Real h = E.hertz();

	Print("x += E: ", x += E);
	Print("x += d ", x += d);
	Print("x += h ", x += h);

	Print("x -= E: ", x -= E);
	Print("x -= d ", x -= d);
	Print("x -= h ", x -= h);

	x = Pitch( 100.0 );
	Print("x *= E: ", x *= E);
	Print("x *= d ", x *= d);
	Print("x *= h ", x *= h);

	x = Pitch( 4000.0 );
	Print("x /= E: ", x /= E);
	Print("x /= d ", x /= d);
	Print("x /= h ", x /= h);

	x = Pitch( A4 );
	Print("x + E: ", x + E);
	Print("x + d ", x + d);
	Print("x + h ", x + h);

	Print("x - E: ", x - E);
	Print("x - d ", x - d);
	Print("x - h ", x - h);

	Print("x * E: ", x * E);
	Print("x * d ", x * d);
	Print("x * h ", x * h);

	Print("x / E: ", x / E);
	Print("x / d ", x / d);
	Print("x / h ", x / h);

	Print("x % E: ", x % E);
	Print("x % d ", x % d);
	Print("x % h ", x % h);

	Print ( "^^^^^^^^^ pitchOperatorTest ^^^^^^^^^" );
}
Void pitchTest()
{
	Print ( "vvvvvvvvv pitchTest vvvvvvvvv" );
	PitchList L( C0, Cs1, D2, Ds3, E4, F5, Fs6, G7, Gs0, A4, As0, B7 );
	Print("PitchList=", L );
//	L = PitchList( Cs0, Db0, Ds0, Eb0, Fs0, Gb0, Gs0, Ab0, As0, Bb0 );
	PitchList P( Cs0, Db0, Ds0, Eb0, Fs0, Gb0, Gs0, Ab0, As0, Bb0 );
	L = P;
	Print("PitchList=", L );

	Pitch pcC("C");
	Pitch pcCs("Cs");
	Pitch C4("C4");
	Pitch Cn4("Cn4");
	Pitch D5("D5");
	Pitch Fs2("Fs2");
	Pitch A440("A4");
	Print("A440=", A440 );
	Integer x = Pitch("Cs4") - Pitch("C2");
	Print( "Pitch(\"Cs4\") - Pitch(\"C4\")=", x);
	Print( "C4 - Cs =", C4 - pcCs);
	Pitch q = pcC;
	Print("q=", q);
	q += 7;
	Print("q+=7=", q);
	q += 7;
	Print("q+=7=", q);
	q += 1;
	Print("q+=1=", q);
	q += -4;
	Print("q+= -3=", q);
	Print("PitchList=", L );
	Print ( "^^^^^^^^^ pitchTest ^^^^^^^^^" );
}

Void rhythmTest()
{
	Print ( "vvvvvvvvv rhythmTest vvvvvvvvv" );
	Rhythm w(1.0);
	Print("Whole", w);
	Print("Duration of whole=", w.duration());
	Rhythm h(0.5);
	Print("Half", h);
	Rhythm q(1, 4);
	Print("Quarter", q);

	Rhythm x = w;
	Print("Rhythm x = ", x);

	Print("x == w", x == w );

	Real oldTempo = Rhythm::tempo(0.5);
	Print("Whole at mm=120", w);
	Print("Duration of whole at mm=120=", w.duration());
	Rhythm::tempo(oldTempo);
	Print ( "^^^^^^^^^ rhythmTest ^^^^^^^^^" );
}

Void vossTest()
{
	Print ( "vvvvvvvvv vossTest vvvvvvvvv" );
	RealList L( Random( ), Random( ), Random( ), Random() );
	RealList R;
	For ( Integer n = 0; n < 128; n = n + 1 ) {
		R[ n ] = VossFracRand( n, L );
	}
	Print( R );
	Print ( "^^^^^^^^^ vossTest ^^^^^^^^^" );
}

Void brownianTest()
{
	Print ( "vvvvvvvvv brownianTest vvvvvvvvv" );
	Real x = 0.0;
	RealList R;
	For ( Integer i = 0; i < 100; i = i + 1 ) {
		x = Brownian( x, 1.0, 1.0 );
		R[ i ] = x;
	}
	Print( R );
	Print ( "^^^^^^^^^ brownianTest ^^^^^^^^^" );
}

Void slightlyLessBoringMusicalExample()
{
	Print ( "vvvvvvvvv slightlyLessBoringMusicalExample vvvvvvvvv" );
	// Each list specifies 13 pitches
	// IntegerList a forces the choice to be pitch C
	RealList a( 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 );
	// IntegerList b forces C#, D, D#, E, or F
	RealList b ( 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 );
	// IntegerList c forces F#, G, G# A, A#, or B
	RealList c ( 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0 );
	// IntegerList d forces pitch c an octave above
	RealList d ( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 );
//	SeedRandom( Time() );	// force a new choice every time
	randomMelody( a, b, c, d );
	Print ( "^^^^^^^^^ slightlyLessBoringMusicalExample ^^^^^^^^^" );
}

Void boringMusicalExample()
{
	Print ( "vvvvvvvvv boringMusicalExample vvvvvvvvv" );
	RealList f(12.0, 11.0, 10.0, 9.0, 8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0 );
	StringList n( "C", "C#", "D", "D#", "E", "F", "F#", 
				"G", "G#", "A", "A#", "B" );
	f = normalize( f, sum( f ) ); 							// replace f with its normalized form
	f = accumulate( f ); 							// calculate cumulative distribution function

	StringList s;
	For ( Integer i = 0; i < 25; i = i + 1 ) {
		Integer p = getIndex( f, Random( ) );
		s[ i ] = n[ p ];
	}
	Print( s ); 							// print the melody
	Print ( "^^^^^^^^^ boringMusicalExample ^^^^^^^^^" );
}

Void stringListTest()
{
	Print ( "vvvvvvvvv stringListTest vvvvvvvvv" );
	StringList s( "C", "C#" );
	Print("s=", s);
	Print ( "^^^^^^^^^ stringListTest ^^^^^^^^^" );
}

Void normTest()
{
	Print ( "vvvvvvvvv normTest vvvvvvvvv" );
	RealList f( 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 );
	Print("f=", f);
	Print( "Sum of f=", sum( f ) );
	RealList r = normalize( f, sum( f ) );
	Print( "normalize=", r );
	Print( "accumulate=", accumulate( r ) );

	Real R = 0.1; // Random( );
	Integer p = getIndex( f, R );
	Print("p=", p );
	Print ( "^^^^^^^^^ normTest ^^^^^^^^^" );
}

Void mapTest()
{
	Print ( "vvvvvvvvv mapTest vvvvvvvvv" );
	IntegerList L1( 0,	8,	10,	6,	7,	5,	9,	1,	3,	2,	11,	4 );
	PitchList p;
	p = IntegerListToPitchList( L1 );
	Print("L1=", L1);
	Print("P =", p);
	IntegerList Lx;
	Lx = PitchListToIntegerList( p );
	Print("And back again=",  Lx);
	For( Integer i = 0; i < Length( L1 ); i++ ) {
		assert( L1[i] == p[i] );
		assert( p[i] == L1[i] );
	}

	Pitch a = Pitch(A4);
	Integer b = a;
	assert( a == b );

	a = b;
	assert( b == a );
	assert( a == b );

	Real f(437.996);
	Print("Frequency f=", f);
	Pitch c = f;
	Print("Nearest (lower) semitone=", c);
	Print("Hertz value of nearest lower semitone=", c.hertz());
	Real g = c;
	Print("Frequency difference (g - f) = ", g - f );

	Pitch a4(A4);
	Real x = a4;
	assert( x == a4 );
	assert( a4 == x );

	IntegerList L2 = L1;
	assert( L1 == L2 );

	Bool t = L1 != L2;
	assert( !t );

	Print ( "^^^^^^^^^ mapTest ^^^^^^^^^" );
}

Void randTendencyTest()
{
	Print ( "vvvvvvvvv randTendencyTest vvvvvvvvv" );
	

	IntegerList L1( 0,	8,	10,	6,	7,	5,	9,	1,	3,	2,	11,	4 );
	Integer pos1 = 0;
	IntegerList L2( 4,	0,	2,	10,	11,	9,	1,	5,	7,	6,	3,	8 );
	IntegerList R;
	Integer pos2 = 0;
	Integer inc = 1;
	Print( "L1=", L1 );
	Print( "L2=", L2 );
	For( Integer i = 0; i < Length( L1 ); i = i + 1 )
		R[ i ] = randTendency<Integer,IntegerList>( L1, pos1, L2, pos2, inc );
		// Print( "tendency row=", randTendency( L1, pos1, L2, pos2, inc ) );
	Print("R=", R);
	Print ( "^^^^^^^^^ randTendencyTest ^^^^^^^^^" );
}

Void swapTest()
{
	Print ( "vvvvvvvvv swapTest vvvvvvvvv" );
	IntegerList L( 0,  6,  2,  9,  7,  5,  4, 10,  8,  3,  1, 11 );
	Print( "Original row=", L );
	Print( "Shuffled row=", shuffle<Integer,IntegerList>( L ) );
	Print ( "^^^^^^^^^ swapTest ^^^^^^^^^" );
}

Void randomRowTest()
{
	Print ( "vvvvvvvvv randomRowTest vvvvvvvvv" );
	IntegerList L = RandomRow<IntegerList>( 12 );
	Print( "Random row=", L );
	PitchList P = RandomRow<PitchList>( 12 );
	Print( "Random PitchList=", P );
	Print ( "^^^^^^^^^ randomRowTest ^^^^^^^^^" );
}

Void stretchTest()
{
	Print ( "vvvvvvvvv stretchTest vvvvvvvvv" );
	IntegerList L( 0,  8, 10,  6,  7,  5,  9,  1,  3,  2, 11,  4 );
	IntegerList x = stretch( L, 0, 11, 24, 47 );
	IntegerList y = stretch( L, 0, 11, 0, 5 );
	Print("IntegerList L=", L);
	Print("IntegerList x=", x);
	Print("IntegerList y=", y);

	PitchList P( Pitch(0),  Pitch(8), Pitch(10),  Pitch(6),  Pitch(7),  Pitch(5),  Pitch(9),  Pitch(1),  Pitch(3),  Pitch(2), Pitch(11),  Pitch(4) );
	Print("PitchList P=", P);
	PitchList p = stretch( P, Pitch(0), Pitch(11), Pitch(24), Pitch(47) );
	Print("Stretched PitchList p=", p);

	Print ( "^^^^^^^^^ stretchTest ^^^^^^^^^" );
}

	Void interpTendencyTest()
{
	Print ( "vvvvvvvvv interpTendencyTest vvvvvvvvv" );
	IntegerList X(0, 2, 4, 6, 8, 11);
	IntegerList Y(11, 6, 0, 0, 5, 7, 9);
	Integer posX = 0;
	Integer posY = 0;
	Integer inc = 1;
	Real fac = 1.0;
	Integer i;
	For ( i = 0; i < Length( X ); i = i + 1 )
		Print("InterpTendency1=", InterpTendency(fac, X, posX, Y, posY, inc) );

	posX = posY = 0;
	inc = 1;
	fac = 0.0;
	For ( i = 0; i < Length( X ); i = i + 1 )
		Print("InterpTendency2=", InterpTendency(fac, X, posX, Y, posY, inc) );

	posX = posY = 0;
	inc = 1;
	fac = 0.5;
	For ( i = 0; i < Length( X ); i = i + 1 )
		Print("InterpTendency3=", InterpTendency(fac, X, posX, Y, posY, inc) );
	Print ( "^^^^^^^^^ interpTendencyTest ^^^^^^^^^" );
}

Void cycleTest()
{
	Print ( "vvvvvvvvv cycleTest vvvvvvvvv" );
	IntegerList L( 10, 11, 12 );
	PitchList P(C4, Cs4, D4, Ds4);

	Integer myPos = 0;
	For (Integer i = 0; i < 2 * Length( L ) - 1; i = i + 1 )		// go twice through the list
		Print( cycle<Integer,IntegerList>( L, myPos, 1 ) );				// forward direction
	Print( "myPos=", myPos );

	Integer pos = 0;
	Print("L=", L);
	For (Integer i = 0; i < 2 * Length( L ); i++)
		Print( "cycle=", cycle<Integer,IntegerList>(L, pos, -4) );
	Print( "pos=", pos );

	pos = 0;
	For (Integer i = 0; i < 2 * Length( L ); i++)
		Print( "cycle=", cycle<Integer,IntegerList>(L, pos, 1) );
	Print( "pos=", pos );

	myPos = 0;
	For ( Integer i = 0; i < 4 * Length( P ); i = i + 1 )
		Print( cycle<Pitch, PitchList>( P, myPos, 1 ) );
	Print( "myPos=", myPos );

	IntegerList pal;
	Integer inc = 1;
	pos = 0;
	For (Integer i = 0; i < Length( L ) * Length( L ); i++)
		pal[i] = palindrome<Integer,IntegerList>(L, pos, inc);
	Print( "palindrome=", pal);
	
	PitchList ppal;
	inc = 1;
	pos = 0;
	For (Integer i = 0; i < Length( P ) * Length( P ); i++)
		ppal[i] = palindrome<Pitch, PitchList>(P, pos, inc);
	Print( "palindrome=", ppal );

	pal.SetListSize(0);
	inc = -1;
	pos = 0;
	Integer perm = 0;
	For (Integer i = 0; i < Length( L ) * Length( L ); i++)
		pal[i] = permute<Integer,IntegerList>(L, pos, perm, inc);
	Print( "permute=", pal );

	ppal.SetListSize(0);
	inc = 2;
	pos = 0;
	perm = 0;
	For (Integer i = 0; i < Length( P ) * Length( P ); i++)
		ppal[i] = permute<Pitch,PitchList>(P, pos, perm, inc);
	Print( "permute+2=", ppal );

	ppal.SetListSize(0);
	inc = -1;
	pos = 0;
	perm = 0;
	For (Integer i = 0; i < Length( P ) * Length( P ); i++)
		ppal[i] = permute<Pitch,PitchList>(P, pos, perm, inc);
	Print( "permute-1=", ppal );

	Print ( "^^^^^^^^^ cycleTest ^^^^^^^^^" );
}


Void matrixTest()
{
	Print ( "vvvvvvvvv matrixTest vvvvvvvvv" );
	IntegerList L(0,1,2,3,4,5,6,7,8,9,10,11);
	Print("L=", L);
	IntegerMatrix M = SetComplex<IntegerMatrix,IntegerList>( L );
	Print( "M=", M); 
	IntegerList Schoenberg(0,8,10,6,7,5,9,1,3,2,11,4);
	Print( "Schoenberg=", Schoenberg);
	IntegerMatrix S = SetComplex<IntegerMatrix,IntegerList>( Schoenberg );
	Print( "S=", S);
	Print("M == S: ", M == S);
	Print("M != S: ", M != S);
	IntegerMatrix N;
	N = S;
	Print( "N=", N);

	PitchList P(C0, Cs0, D0, Ds0, E0, F0, Fs0, G0, Gs0, A0, As0, B0);
	Print( "P=", P);
	PitchMatrix PM = SetComplex<PitchMatrix,PitchList>(P);
	Print( "PM=", PM);
	Print ( "^^^^^^^^^ matrixTest ^^^^^^^^^" );
}

Void transposeTest()
{
	Print ( "vvvvvvvvv transposeTest vvvvvvvvv" );

	IntegerList L(0,1,2,3,4,5,6,7,8,9,10,11);
	Print("L=", L);
	Print("L transposed 3 semitones=", Transpose(L, 3, 12));
	Print("L inverted=", Invert(L, 12));
	Print("L retrograde=", Retrograde(L));

	PitchList P(C0, Cs0, D0, Ds0, E0, F0, Fs0, G0, Gs0, A0, As0, B0);
	Print("P=", P);
	Print("P inverted=", Invert(P));

	Print("P=", P);
	Print("P transposed 3 semitones=", Transpose(P, 3));

	PitchList Q(A4, B4, C4, D4);
	Print("Q=", Q);
	Print("Q transposed -3 semitones=", Transpose(Q, -3));
	Print("Q=", Q);
	Print("Q inverted=", Invert(Q));

	PitchList R(A0, F1, E2, Ds3, Bb4);
	Print("R=", R);
	Print("R retrograde=", Retrograde(R));

	Print ( "^^^^^^^^^ transposeTest ^^^^^^^^^" );
}

Void joinTest()
{
	Print ( "vvvvvvvvv joinTest vvvvvvvvv" );
	IntegerList L(1, 2, 3, 4, 5, 6);
	IntegerList M(7, 8, 9, 10, 11, 12);
	Print("L=", L);
	Print("M=", M);
	IntegerList N = Join(L, M);
	Print("L=", L);
	Print("M=", M);
	Print("N=", N);
	IntegerList O = L + M + N;
	Print("O=", O);
	Print ( "^^^^^^^^^ joinTest ^^^^^^^^^" );
}

Void rotateTest()
{
	Print ( "vvvvvvvvv rotateTest vvvvvvvvv" );
	IntegerList L(1, 2, 3, 4, 5, 6);
	Print("L=", L);
	IntegerList M = L; // copy l
	Rotate( M, -3 );
	Print("M rotated -3=", M);
	Print("L=", L);
	M = L;	// copy L again
	Rotate( M, 4 );
	Print("M rotated 4=", M);
	M = L; // copy L again
	Rotate( M, -12 );
	Print("L rotated -12=", M);

	PitchList P(A4, C5, E5, G6, B6, D6);
	Print("PitchList P=", P);
	Rotate(P, 3);
	Print("PitchList P rotated=", P);

	ComplexList c(Complex(0,0), Complex(1,1), Complex(2,2), Complex(3,3));
	Print("ComplexList c=", c);
	Rotate(c, 3);
	Print("ComplexList c rotated=", c);
	Print ( "^^^^^^^^^ rotateTest ^^^^^^^^^" );
}

Void GuidoTest()
{
	Print ( "vvvvvvvvv GuidoTest vvvvvvvvv" );
	Guido("Ut queant laxis resonare.");
	Print ( "^^^^^^^^^ GuidoTest ^^^^^^^^^" );
}

Void piTest()
{
	Print ( "vvvvvvvvv piTest vvvvvvvvv" );
	Print("Pi=", Pi);
	Print ( "^^^^^^^^^ piTest ^^^^^^^^^" );
}

Void HzTest()
{
	Print ( "vvvvvvvvv HzTest vvvvvvvvv" );
	Print( "KeyToHertz(48)=", KeyToHertz( 48 ) );
	Print("PitchToHertz(A4)=", PitchToHertz( A4 ) );
	Print ( "^^^^^^^^^ HzTest ^^^^^^^^^" );
}

Void dBTest()
{
	Print ( "vvvvvvvvv dBTest vvvvvvvvv" );
	Print( "dBCoefficient=", dBCoefficient( -6.0 ) );
	Print( "dBSPL=", dBSPL( 2.0 / 1.0 ) );
	Print( "dBSIL=", dBSIL( 2.0 / 1.0 ) );
	Print( "Fff=", Fff );
	Print( "Ff=", Ff );
	Print( "F=", F );
	Print( "Mf=", Mf );
	Print( "Mp=", Mp );
	Print( "P=", P );
	Print( "Pp=", Pp );
	Print( "Ppp=", Ppp );
	Print ( "^^^^^^^^^ dBTest ^^^^^^^^^" );
}

Void keyTest()
{
	Print ( "vvvvvvvvv keyTest vvvvvvvvv" );
#if 0
	Print( key( C, 1 ) );
	Print( key( A, 4 ) );
	Print( sharp( A, 4 ) );
	Print( natural( A, 4 ) );
	Print( flat( A, 4 ) );
	Print( PitchClass( C ) ); Print( Octave( C ) );
#endif
	Print( "metronome( Quarter, 60 )=", metronome( Quarter, 60 )  );
	Print( "metronome( Quarter, 120 )=", metronome( Quarter, 120 )  );
	Print( "quintuplet eighth ", Duration( 1.0 / 20.0 ) );
	Print( "dottedHalf =", Duration( 1.0/2.0 + 1.0/4.0 ) ); 
	Print( "dottedHalf =", Duration( 3.0 / 4.0 ) );
	SetTempoScale( metronome( 1.0/4.0, 120.0 ) ); // Change the value of tempoScale
	Print( "quarter at MM120=", Duration( 1.0/4.0 ) );	
	Print("triplet eighth at MM120=", Duration( 1.0 / 12.0 ) );
	SetTempoScale( metronome( 1.0/4.0, 60.0 ) ); // Revert
	Print ( "^^^^^^^^^ keyTest ^^^^^^^^^" );
}

Void characterTest()
{
	Print ( "vvvvvvvvv characterTest vvvvvvvvv" );
	Integer i = Character( 65 );
	Print( Character( i ) );
	Integer c = Integer( 'A' );
	Print( c );
	Print ( "^^^^^^^^^ characterTest ^^^^^^^^^" );
}

Void stringTest()
{
	Print ( "vvvvvvvvv stringTest vvvvvvvvv" );
	String c = "Ut queant laxis resonare." ;
	Print( c );
	char d[] =  { 'U', 't', ' ', 'q', 'u', 'e', 'a', 'n', 't', ' ', 'l', 'a', 'x', 'i', 's', ' ', 'r', 'e', 's', 'o', 'n', 'a', 'r', 'e', '.', 0 };
	Print( d );
	Print ( "^^^^^^^^^ stringTest ^^^^^^^^^" );
}

Void absTest()
{
	Print ( "vvvvvvvvv absTest vvvvvvvvv" );
	assert( Abs( -5 ) == Abs( 5 ) );
	assert( Abs( -5.0 ) == Abs( 5.0 ) );
	If ( Abs( -5 ) == Abs( 5 ) )
		Print( True );
	Else
		Print( False );
	Print ( "^^^^^^^^^ absTest ^^^^^^^^^" );
}

Void occludeTest()
{
	Print ( "vvvvvvvvv occludeTest vvvvvvvvv" );
//	Print( sum( 4 ) );
	Print ( "^^^^^^^^^ occludeTest ^^^^^^^^^" );
}

Integer Factorial( Integer x ) {
	Integer i, n = 1;
	For ( i = x; i >= 1; i = i - 1)
		n = n * i;
	Return( n );
}

Integer FactorialR( Integer x ) {
	If ( x == 1 ) 
		Return( 1 );
	Else 
		Return( x * Factorial( x - 1 ) );
}

Integer Fi( Integer n ) {
	Integer fn1 = 1;
	Integer fn2 = 1;
	Integer result = 1;
	For (Integer i = 2; i < n; i = i + 1 ) {
		result = fn1 + fn2;
		fn2 = fn1;
		fn1 = result;
	}
	Return ( result );
}

Integer Fr( Integer n ) {
	If ( n == 1 || n == 2 )
		Return( 1 );
	Else
		Return ( Fr( n - 1) + Fr( n - 2) );
}


Void fiTest()
{
	Integer i;
	Print ( "vvvvvvvvv fiTest vvvvvvvvv" );
	For ( i = 1; i < 10; i++)
		Print( "fi=", Fi( i ) );
	For ( i = 1; i < 10; i++)
		Print( "fr=", Fr( i ) );
	Print ( "^^^^^^^^^ fiTest ^^^^^^^^^" );
}

Integer ifTest()
{
	Print ( "vvvvvvvvv ifTest vvvvvvvvv" );
	Integer a = 1;
	Integer b = 2;
	Integer c = 3;
	If ( a < b )
		Print( a );
	Integer x = -1;
	Integer y;
	If ( x < 0 ) 
		y = a ;
	Else If ( x >= 0 )
		y = b ;
	Print( y );
	x = 1;
	If ( x < 0 ) 
		y = a ;
	Else If ( x == 0 )
		y = b;
	Else
		y = c ;
	Print( y );

	Integer r = 1;
	Integer n = 0;
	Integer m;
	If ( r < 0 ) 
		Halt( n ) ;
	Else {
		m = n; 
		n = r; 
	}
	Print ( "^^^^^^^^^ ifTest ^^^^^^^^^" );
	Return( 0 );
}

Void facTest()
{
	Print ( "vvvvvvvvv facTest vvvvvvvvv" );
	Print( Factorial( 5 ) );
	Print( FactorialR( 5 ) );
	Print ( "^^^^^^^^^ facTest ^^^^^^^^^" );
}


Void floorTest()
{
	Print ( "vvvvvvvvv floorTest vvvvvvvvv" );
	Integer a = Integer( 10.0/3.0 ); 						// quotient 3.333… is truncated to 3
	Print( "a=", a);
	Real b = Real( a ); 
	Print( "b=", b);
	Real c = 10.0/3.0; 							// Real variable c is set to 3.333…
	Print( "c=", c);
	Real d = Floor( c );							// d is set to 3.0
	Print( "d=", d);
	Real x = Ceiling( c );
	Print( "x=", x);
	c = 2.499999;
	Real r = Floor( c + 0.5 );					// round c to the nearest whole number
	Print( "r=", r);
	c = 2.5;
	r = Floor( c + 0.5 );					// round c to the nearest whole number
	Print( "r=", r);
	c = 2.99999;
	r = Floor( c + 0.5 );					// round c to the nearest whole number
	Print( "r=", r);
	Print("Floor(3.3)=", Floor(3.3));
	Print ( "^^^^^^^^^ floorTest ^^^^^^^^^" );
}

Void divTest()
{
	Print ( "vvvvvvvvv divTest vvvvvvvvv" );
	Real x = Divide(11.0,4.0); 
	Print( x );
	Integer i = Divide(11,4); 
	Print( i );
	i = Mod(11,4); 
	Print( i );
	Print ( "^^^^^^^^^ divTest ^^^^^^^^^" );
}


Void plusTest()
{
	Print ( "vvvvvvvvv plusTest vvvvvvvvv" );
	Print ( Integer( Plus (3, 4) ) );
	Print ( Real( Plus (3, 4) ) );
	Print ( Integer( Plus (3.0, 4.0) ) );
	Print ( Real( Plus (3.0, 4.0) ) );
	Print ( "^^^^^^^^^ plusTest ^^^^^^^^^" );
}

Integer repeatTest()
{
	Integer n = 5;
	Integer m = 15;
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

Void doTest()
{
	Print ( "vvvvvvvvv doTest vvvvvvvvv" );
	Real x;
	Do {
		x = Random( );
		Print( x );
	} While ( x < 0.9);
	Print ( "^^^^^^^^^ doTest ^^^^^^^^^" );
}

Void forTest()
{
	Print ( "vvvvvvvvv forTest vvvvvvvvv" );
	Integer i;
	For ( i = 0; i < 10; i = i + 1)
		Print( i );
	Print ( "^^^^^^^^^ forTest ^^^^^^^^^" );
}

Void listTest()
{
	Print ( "vvvvvvvvv listTest vvvvvvvvv" );
	IntegerList L(1, 2, 3, 4);
	printf("%d\n", L[2]);
	L[2] = 10;
	Print("L=", L );
	IntegerList M = L;
	Print("M=", M);
	Print ( "^^^^^^^^^ listTest ^^^^^^^^^" );
}

Void ranTest()
{
	Integer i;
	Print ( "vvvvvvvvv ranTest vvvvvvvvv" );
	Real x;
	Do {
		x = Random( );
		Print( x );
	} While ( x < 0.5);
	For ( i = 0; i < 10; i++)
		Print( "Random( 0.0, 11.0 )=", Random( 0.0, 11.0 ) );
	For ( i = 0; i < 10; i++)
		Print( "Random( -10.0, 10.0 )=", Random( -10.0, 10.0 ) );
	Print ( "^^^^^^^^^ ranTest ^^^^^^^^^" );
}

Void iranTest()
{
	Print ( "vvvvvvvvv iranTest vvvvvvvvv" );
	For (Integer i = 0; i < 100; i++) {
		Print( IRandom(0, 11) );
	}
	Print ( "^^^^^^^^^ iranTest ^^^^^^^^^" );
}

Void castTest()
{
	Real x = 3.14159;
	Integer i = Integer( x );
	Print( i );
}

Void initIntegerMatrixRandom(IntegerMatrix Reference m) {
    For (Integer r=0; r < m.rows(); r++)
        For (Integer c = 0; c < m.cols(); c++)
            m[r][c] = rand()% 6;
}

Void initRealMatrixRandom(RealMatrix Reference m, Integer precision) {
    For (Integer r=0; r < m.rows(); r++)
        For (Integer c = 0; c < m.cols(); c++) {
            float dec = float(rand()%precision)/precision;
            m[r][c]=float(rand()%5)+1.0+dec;
        }
}

template<class MatrixType, class ValType> Void setMatrix(MatrixType Reference m, ValType val) {
    For (Integer r = 0; r < m.rows(); r++)
        For (Integer c = 0; c < m.cols(); c++) {
            m[r][c] = val;
        }
}

Integer matrixTests(Integer argc, char** argv)
{
	Print ( "vvvvvvvvv matrixTests vvvvvvvvv" );
//     srand((unsigned)time(NULL));
    
    IntegerMatrix a(5,5);
    setMatrix(a, 0);
    a[0][0] = -1;
    a[1][1] = 2;

    //cout << "Writing to file from Matrix a:" <<endl;
    //cout << a <<endl;
    //ofstream of;
    //of.open("test.txt");
    //of << a <<endl;
    //of.close();
    //ifstream iff("test.txt");
    //If (!iff) {
    //    cout << "Error opening file"<<endl;
    //    String 1;
    //}

    //Matrix<Integer> b;
    //cout << "Reading from file into Matrix b:"<<endl;
    //iff >> b;
    //iff.close();
    //cout <<endl;
    //cout << b<<endl;

    //Real matrices
    IntegerMatrix p(4,4);
    setMatrix(p, 2);
    cout << "Matrix p:" << endl << p << endl;
    IntegerMatrix q(4,4);
    setMatrix(q, 4);
    cout << "Matrix q:" << endl << q << endl;
    cout << "Matrix p + q:" << endl << p + q << endl;
    cout << "Matrix p + 10:" << endl << p + 10 << endl;
    cout << "Matrix p - q:" << endl << p - q << endl;
    cout << "Matrix q - 10:" << endl << q - 10 << endl;
    cout << "Matrix q * 2:" << endl << q * 2 << endl;
    cout << "Matrix p * q:" << endl << p * q << endl;

    //scale a floating-point matrix
    RealMatrix e(10,10);
    initRealMatrixRandom(e, 6);
    Real scalar = -1.5;
    cout << "Matrix e:" << endl << e << endl;
    cout << "Scalar: " << scalar << endl;
    cout << "e * scalar:" << endl << e * scalar << endl;
	Print ( "^^^^^^^^^ matrixTests ^^^^^^^^^" );
    
    Return 0;
}


Integer miscTests(Integer argc, char* argv[])
{

//	genPitches();
	pitchOperatorTest();
	MinMaxVecTest();
	RationalTests();
	RhythmTests();
	RealListTests();	
	IntegerListTests();	
	PitchListTests();	
	RhythmListTests();
	RationalListTests();
	rhythmTest();	
	pitchTest1();	
	pitchTest();	
	vossTest();	
	brownianTest();	
	slightlyLessBoringMusicalExample();	
	boringMusicalExample();	
	stringListTest();	
	normTest();	
	mapTest();	
	randTendencyTest();	
	swapTest();	
	randomRowTest();
	stretchTest();	
	interpTendencyTest();	
	cycleTest();	
	matrixTest();	
	transposeTest();	
	joinTest();	
	listTest();	
	rotateTest();	
	divTest();	
	ifTest();	
	plusTest();	
	castTest();	

	Print ( "vvvvvvvvv repeatTest vvvvvvvvv" );
	Integer x = repeatTest();
	printf("x=%d\n", x);
	Print ( "^^^^^^^^^ repeatTest ^^^^^^^^^" );
	Print ( "vvvvvvvvv Euclid vvvvvvvvv" );
	Integer y = Euclid(9, 12);
	printf("y=%d\n", y);
	y = Euclid(91, 416);
	printf("y=%d\n", y);
	Print( Euclid( 91, 416 ) );
	Print ( "^^^^^^^^^ Euclid ^^^^^^^^^" );
	floorTest();

	ranTest();
	iranTest();
	doTest();
	forTest();
	facTest();
	fiTest();
	occludeTest();
	absTest();
	stringTest();
	characterTest();
	keyTest();
	dBTest();
	HzTest();
	GuidoTest();
	piTest();
//	Repeat { };

	dftTest();
	cplxTest();
	shapedNoiseTest();
	matrixTests(argc, argv);

#if 0
	char buf[16];
	cout << "Enter a pitch as <pitchClass><accidental><octave>:";
	cin >> buf;
	Pitch p(buf);
	cout << endl << "You entered: " << p << endl;

	PitchList P;
	cout << "Enter a pitch list { <pitch0> , <pitch1>, ..., <pitchN> }: ";
	cin >> P;
	cout << endl << "You entered: " << P << endl;

	Rhythm r;
	cout << "Enter a rhythmic value { <num> , <den> }: ";
	cin >> r;
	cout << endl << "You entered: " << r << endl;

	RhythmList R;
	cout << "Enter a rhythm list { <rhy0> , <rhy1>, ..., <rhyN> }: ";
	cin >> R;
	cout << endl << "You entered: " << R << endl;

	IntegerList L;
	cout << "Enter an integer list { <num0> , <num1>, ..., <numN> }: ";
	cin >> L;
	cout << endl << "You entered: " << L << endl;

	Complex c;
	cout << "Enter a complex value { <real> , <imag> }: ";
	cin >> c;
	cout << endl << "You entered: " << c << endl;
#endif


	Return 0;
}

