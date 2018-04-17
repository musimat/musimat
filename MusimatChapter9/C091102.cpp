#include "MusimatChapter9.h"
MusimatChapter9Section(C091102) {
	Print("*** 9.11.2 The Set Complex ***");
	/*****************************************************************************
	 
	 9.11.2 The Set Complex
	 
	 Using these tools, we can create a matrix containing the prime form, inverse, 
	 retrograde, and all transpositions of any row, called the set complex. The 
	 purpose of these transformations is to generate variants that are related to 
	 the original intervallic structure of the prime row, to be used as material 
	 in developing compositions.
	 
	 Matrix is simply a two-dimensional grid, or list of lists, all of the same 
	 length. The individual elements of Matrix can be accessed by extending the 
	 index operator […]. The first operand is the matrix, the second is the row 
	 position, and the third is the column position. (Whether row or column comes 
	 first is arbitrary. The following order is called row/column order.)   
	 
				0	1
	 M =	0	A	B
			1	C	D
	 
	 For example, for this matrix, M[0][0] == A, M[0][1] == B, M[1][0] == C, and 
	 M[1][1] == D. The following is a method for creating a set complex. It 
	 basically copies the prime form to the zeroth row, then copies the inverse 
	 form to the zeroth column, then for each other cell in the matrix sums the 
	 corresponding row and column value modulo the length of the prime form:
	 *****************************************************************************/
	para1(); // Step into this function to continue.
	para2(); // Step into this function to continue.
}

IntegerMatrix setComplex(IntegerList prime) {
	Print("Prime row:", prime);
	Integer len = Length(prime);
	IntegerMatrix M(len, len);
	IntegerList inverted = invert(prime);
	Print("Inverted row:", inverted);
	For (Integer i = 0; i < len; i = i + 1) {
		M[0][i] = prime[i];
		M[i][0] = inverted[i];
	}
	For (Integer i = 1; i < len; i = i + 1) {
		For (Integer j = 1; j < len; j = j + 1) {
			Integer a = M[i][0];
			Integer b = M[0][j];
			// M(i,j) = Mod(M(i,0) + M(0,j), len);
			M[i][j] = Mod(a + b, len);
		}
	}
	Return(M);
}


Static Void para1() {
	/*****************************************************************************
	 To demonstrate these tools, table 9.4 shows the set complex the following row: 
	 (G, As, B, F, E, Cs, C, A, Gs, D, Ds, Fs) 
	 o  Prime rows are read left to right, 
	 o  Retrograde rows, right to left 
	 o  Inverse rows, top to bottom, 
	 o  Retrograde inverse rows, bottom to top.
	 This completes the precomposition phase. Now it's time to look at methods to 
	 traverse the rows created with the preceding techniques to generate a 
	 composition.
	 
	 Table 9.4 Set Complex
	 {0, 3, 4, 10, 9, 6, 5, 2, 1, 7, 8, 11}
	 {9, 0, 1, 7, 6, 3, 2, 11, 10, 4, 5, 8}
	 {8, 11, 0, 6, 5, 2, 1, 10, 9, 3, 4, 7}
	 {2, 5, 6, 0, 11, 8, 7, 4, 3, 9, 10, 1}
	 {3, 6, 7, 1, 0, 9, 8, 5, 4, 10, 11, 2}
	 {6, 9, 10, 4, 3, 0, 11, 8, 7, 1, 2, 5}
	 {7, 10, 11, 5, 4, 1, 0, 9, 8, 2, 3, 6}
	 {10, 1, 2, 8, 7, 4, 3, 0, 11, 5, 6, 9}
	 {11, 2, 3, 9, 8, 5, 4, 1, 0, 6, 7, 10}
	 {5, 8, 9, 3, 2, 11, 10, 7, 6, 0, 1, 4}
	 {4, 7, 8, 2, 1, 10, 9, 6, 5, 11, 0, 3}
	 {1, 4, 5, 11, 10, 7, 6, 3, 2, 8, 9, 0}
	 
	 The functions below perform steps in preparation for calling setComplex().
	 getPC() converts a PitchList to an IntegerList by summing the diatonic
	 pitch class and accidental of the Pitch.
	 generateSetComplex() first calls getPC() to convert the Pitch list to
	 an IntegerList, then transposes the resulting set, then
	 invokes setComplex() to generate the set complex Matrix.
	 *****************************************************************************/
}

IntegerList getPC(PitchList p) {
	IntegerList x;
	
	For (Integer i = 0; i < Length(p); i++)
		x[i] = PitchClass(p[i]) + Accidental( p[i] );
	
	Return( x );
}


Void generateSetComplex(PitchList P) {
	IntegerList set = getPC(P);
	Print("Starting set:", set);
	Integer offset = set[0];
	IntegerList tSet = transpose(set, -offset);
	Print("Transposed set:", tSet);
	IntegerMatrix sc = setComplex( tSet );
	Print("Set complex:");
	Print(sc);
}

Static Void para2() {
	/*****************************************************************************
	 Here we evaluate the set complex for our test set.
	 *****************************************************************************/
	PitchList test(G, As, B, F, E, Cs, C, A, Gs, D, Ds, Fs);
	Print("*** Pitch classes for test ***");
	Print(test);
	generateSetComplex(test);
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:45 $ $Author: dgl $ $Name:  $ $Id: C091102.cpp,v 1.3 2006/09/05 08:02:45 dgl Exp $ */
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

