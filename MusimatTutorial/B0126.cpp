#include "MusimatTutorial.h"
MusimatTutorialSection(B0126) {
	Print("*** B.1.26 Fibonacci Numbers ***");
	/*****************************************************************************
	 
	 B.1.26 Fibonacci Numbers
	 
	 In the sequence
	 
	 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 377, 610, 987, 1597, 2584, . . .
	 
	 each subsequent term is the sum of its two immediately preceding values. For example, 8 = 5 + 3. 
	 This series, invented by Leonardo Pisano Fibonacci (1170-1250), is the solution to a problem he 
	 posed in his book "Liber Abaci": "A certain man put a pair of rabbits in a place surrounded on 
	 all sides by a wall. How many pairs of rabbits can be produced from that pair in a year if it is 
	 supposed that every month each pair begets a new pair which from the second month on becomes 
	 productive?"
	 
	 An iterative method of computing the Fibonacci sequence is shown below
	 in function iterFib().
	 *****************************************************************************/
	
	para1(); // Step into this function to continue the tutorial
	para2(); // Step into this function to continue the tutorial
}

Integer iterFib(Integer n) {
	Integer fn1 = 1;
	Integer fn2 = 1;
	Integer result = 1;
	
	For (Integer i = 2; i < n; i = i + 1) {
		result = fn1 + fn2;
		fn2 = fn1;
		fn1 = result;
	}
	Return (result);
}

Static Void para1() {
	
	/*****************************************************************************
	 Executing the following For loop,
	 *****************************************************************************/	
	
	For ( Integer i = 1; i < 10; i = i + 1 )
		Print(iterFib(i));
}

/*****************************************************************************
 prints the sequence 1, 1, 2, 3, 5, 8, 13, 21, 34. 
 Below is a method that accomplishes the same calculation using recursion:
 *****************************************************************************/

Integer recurFib(Integer n) {
	If (n == 1 Or n == 2)
		Return(1);
	Else
		Return (recurFib(n - 1) + recurFib( n - 2));
}

Static Void para2() {
	
	/*****************************************************************************
	 The recursive technique has crisper expressive power than the iterative approach because we see 
	 the inner structure of the sequence directly in the method of its construction. However, it is com-
	 putationally much more expensive, especially for large n, because we must call the recurFib() 
	 method twice at each step, whereas iterFib() performs only one addition and minor data 
	 shuffling at each step. Here is an example where Knuth's "goodness" criterion depends upon con-
	 text. If efficiency is paramount, the iterative approach is preferred; recursion is preferable if 
	 expressive crispness is most important.
	 
	 The Fibonacci sequence becomes relevant musically when we examine the ratios of subsequent 
	 terms:
	 
	 1 2 3 5 8 13
	 -,-,-,-,-,--, ...
	 1 1 2 3 5  8
	 
	 The corresponding sequence of quotients is
	 
	 1, 200, 1.500, 1.670, 1.600, 1.625, 1.619, 1.617, 1.618, . . .
	 
	 Thus we see that the ratio of adjacent Fibonacci numbers converges rapidly to the value of the 
	 golden mean, phi. The Greek letter phi is commonly used to stand for the golden 
	 mean. This number appears in a wide range of natural designs, including the arrangements of petals 
	 in flowers, seed clusters, and pine cones. Studied at least since Euclid wrote his Elements, the 
	 golden mean has appeared consciously and unconsciously as a central design element in countless 
	 musical works (see section 9.16.1).
	 *****************************************************************************/
	
	For (Integer i = 1; i < 10; i++)
		Print(recurFib(i));
	
	/*****************************************************************************
	 prints the same sequence.  It is useful to watch recurFib() compute using
	 a debugger because you can see how it recursively enters itself with
	 ever-changing values.
	 
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:03:08 $ $Author: dgl $ $Name:  $ $Id: B0126.cpp,v 1.3 2006/09/05 08:03:08 dgl Exp $ */
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


