/* $Revision: 1.4 $ $Date: 2006/09/07 08:38:24 $ $Author: dgl $ $Name:  $ $Id: cplxTest.cpp,v 1.4 2006/09/07 08:38:24 dgl Exp $ */
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

#include <stdio.h>
#include "Musimat.h"

Complex CI = Complex( 0.0, 1.0 );			// define imaginary number i
Complex CE = Complex( 2.71828182845904523536, 0.0 );	// define e

ComplexList DFT( RealList x ) {
	Integer N = Length( x );			// get length of x
	ComplexList X;					// place to store result
	Complex mI2pidN( -CI * 2.0 * Pi / N );		// calculate constants once
	
	For ( Integer k = 0; k < N; k++ ) {
		X[k] = 0.0;				// prepare to accumulate
		For ( Integer n = 0; n < N; n++ ) {
			Complex xn = Complex(x[n], 0.0);// cvt. Real input to Complex
			X[k] = X[k] + xn * Exp( CE, mI2pidN * n * k );
		}
		X[k] = X[k] / N;			// normalize
	}
	Return( X );
}

ComplexList IDFT( ComplexList X ) {
	Integer N = Length( X );			// get length of X
	ComplexList x;					// place to store result
	Complex I2pidN = CI * 2.0 * Pi / N;		// calculate constants once
	
	For ( Integer n = 0; n < N; n++ ) {
		x[n] = 0.0;				// prepare to accumulate
		For ( Integer k = 0; k < N; k++ ) {
			x[n] = x[n] + X[k] * Exp( CE, I2pidN * n * k );
		}
	}
	Return( x );
}

Void IDFTR( Real x[], Integer N, Complex X[] ) {
	Real pi2dN = 8.0 * atan( 1.0 ) / N;
	For ( Integer n = 0; n < N; n++ ) {
		Real im = x[n] = 0.0;
		For ( Integer k = 0; k < N; k++ ) {
			x[n] += RealPart(X[k]) * cos( pi2dN * k * n) - ImagPart(X[k]) * sin( pi2dN * k * n);
			im += RealPart(X[k]) * sin( pi2dN * k * n) + ImagPart(X[k]) * cos( pi2dN * k * n);
		}
		// Warn if non-zero imaginary part 
		If ( Abs( im ) > 1.e-5 )
			Print("warning, non-zero imaginary part in signal=", im);
	}
}

Void dftTest()
{
	printf ( "vvvvvvvvv dftTest vvvvvvvvv\n" );
	Const Integer N = 16;
	Real pi2dN = 8.0 * atan( 1.0 ) / N;
	RealList r1;
	
	For ( Integer n = 0; n < N; n++) {
		r1[n] = sin( pi2dN * 1 * n )
			+ 0.33 * sin( pi2dN * 3.0 * n )
			+ 0.2 * sin( pi2dN * 5.0 * n );
	}
	
	ComplexList cSpect = DFT( r1 );
	ComplexList cSig = IDFT( cSpect );
	
	For ( Integer n = 0; n < N; n++ ) {
		printf("[%2d] x1 = %6.3f, X = (%6.3f, %6.3f), x2 = %6.3f\n",
			   n, r1[n], cSpect[n].r(), cSpect[n].i(), cSig[n].r());
	}
	
	printf ( "^^^^^^^^^ dftTest ^^^^^^^^^\n" );
	fflush(stdout);
}


Void cplxTest()
{
	Print ( "vvvvvvvvv cplxTest vvvvvvvvv" );
	Complex x(3.3,4.4);
	Complex y(5.0, 6.0);
	Print("x+y=", x + y);
	Print("x-y=", x - y);
	Print("x*y=", x * y);
	Real rE = 2.71828182845904523536;
	Print("rE=", CE);
	Real rEE = exp(1.0);
	Print("exp(1.0)=", rEE);
	Print("Exp(rE, 1.0)=", Exp(rE, 1.0));
	Print("Exp(rE, 2.0)=", Exp(rE, 2.0));
	
	Complex cE = Complex(2.71828182845904523536, 0.0);
	Print("cE=", cE);
	Complex CI = Complex(0.0, 1.0);
	Print("CI=", CI);
	Complex one = Complex(1.0, 0.0);
	Print("one=", one);
	Print("Exp(cE, CI)=", Exp(cE, CI));
	Print("cE.Exp(CI)=", cE.Exp(CI));
	
	Print ( "^^^^^^^^^ cplxTest ^^^^^^^^^" );
}

RealList ImagPart( ComplexList x ) {
	Integer N = Length( x );
	RealList t;
	For ( Integer i = 0; i < N; i++ )
		t[i] = ImagPart( x[i] );
	Return( t );
}

// Return the real part of a Complex list
RealList RealPart( ComplexList x ) {
	Integer N = Length( x );				// Find its length
	RealList t;						// A place to store the result
	For ( Integer i = 0; i < N; i = i + 1 )
		t[ i ] = RealPart( x[ i ] );			// Take just the real part
	Return( t );
}

// Normalize a Real list to lie between L and U
RealList Normalize( RealList x, Real L, Real U ) {
	Integer N = Length( x );				// Find the length of the list
	Real max = Max( x );					// Find the maximum
	Real min = Min( x );					// Find the minimum
	For ( Integer k = 0; k < N; k = k + 1 ) {
		x[ k ] = (U - L) * ( x[ k ] - min) / (max - min) + L;
	}
	Return( x );
}

// Shape noise with spectral tendency B, restrict values to lie within L and R
RealList ShapedNoise( Real B, Integer N, Real L, Real U) {
	RealList x;
	For ( Integer k = 0; k < N; k = k + 1 )			// Start with broadband noise
		x[k] = Random( Real(-1.0), Real(1.0) );
	ComplexList X = DFT( x );				// Take the Fourier transform of x
	For ( Integer k = 1; k <= N/2; k = k + 1 ) {			// Scale the noise by 1/f^B
		Real r = RealPart( X[k] ); 			// Take the real part of a sample
		Real i = ImagPart( X[k] );			// Take its imaginary part
		Real power = r * r + i * i;			// Square amplitude to get power
		power = power / Pow(Real(k), B);		// Apply the spectral tendency
		Real amplitude = Sqrt( power );			// Convert back to amplitude
		Real phase = Atan2( i, r );			// Calculate the phase
		RealPart( X[k], amplitude * Cos(phase) );	// Reconstruct
		ImagPart( X[k], amplitude * Sin(phase) );	// the spectrum
	}
	// Force the spectrum to be conjugate-symmetrical around 0 Hz
	For ( Integer k = 1; k <= N/2; k = k + 1 ) {
		RealPart( X[N - k], RealPart(X[k]) );
		RealPart( X[N - k], -ImagPart(X[k]) );
	}
	ComplexList cx = IDFT( X );				// Take inverse Fourier transform
	RealList cr = RealPart( cx );				// Discard the imaginary part
	RealList result = Normalize( cr, L, U );		// Normalize
	Return( result );
}


Void shapedNoiseTest()
{
	Print ( "vvvvvvvvv shapedNoiseTest vvvvvvvvv" );
	
	Print("B=0.0",  ShapedNoise( 0.0, 16, -1.0, 1.0 ) );
	Print("B=1.0",  ShapedNoise( 1.0, 16, -1.0, 1.0 ) );
	Print("B=2.0",  ShapedNoise( 2.0, 16, -1.0, 1.0 ) );
	
	Print ( "^^^^^^^^^ shapedNoiseTest ^^^^^^^^^" );
}

// This is a version of the DFT that uses Real arithmetic
ComplexList DFT_Real( RealList x ) {
	Integer N = Length( x );
	ComplexList X;
	Real pi2dN = 8.0 * atan( 1.0 ) / N;
	For ( Integer k = 0; k < N; k++ ) {
		X[k] = 0.0;
		For ( Integer n = 0; n < N; n++ ) {
			X[k] += Complex( x[n] * Cos( pi2dN * k * n ), -x[n] * Sin( pi2dN * k * n ));
		}
		X[k] /= N;
	}
	Return( X );
}
// This is a version of the IDFT that uses Real arithmetic
ComplexList IDFT_Real( ComplexList X ) {
	Integer N = Length( X );
	ComplexList x;
	Real pi2dN = 8.0 * Atan( 1.0 ) / N;
	For ( Integer n = 0; n < N; n++ ) {
		x[n] = 0.0;
		For ( Integer k = 0; k < N; k++ ) {
			x[n] += Complex( RealPart(X[k]) * cos( pi2dN * k * n) - ImagPart(X[k]) * sin( pi2dN * k * n),
							RealPart(X[k]) * sin( pi2dN * k * n) + ImagPart(X[k]) * cos( pi2dN * k * n) );
		}
	}
	Return( x );
}

