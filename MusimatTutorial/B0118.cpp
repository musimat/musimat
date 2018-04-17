#include "MusimatTutorial.h"
MusimatTutorialSection(B0118) {
	Print("*** B.1.18 Iteration ***");
	/*****************************************************************************
	 
	 B.1.18 Iteration
	 
	 We must be able to repeat a statement or statements multiple times. For example, Euclid's method 
	 returns to step 1 from step 3, depending upon the value of variable r (see section 9.2.2). In 
	 Musimat, the Repeat statement causes a statement or compound statement to repeat intermina-
	 bly. This allows us to implement Euclid's method as follows:
	 *****************************************************************************/
	
	Integer m = 103;
	Integer n = 17;
	Integer r;
	
	Repeat{
		r = Mod(m, n);  //remainder of m divided by n
		If (r == 0)  {
			// Halt(n); // halt, and give answer n
			Break;		// break, and give answer n
		} Else  {
			m = n; 
			n = r; 
		} 
	}
	Print(n);
	
	/*****************************************************************************
	 This code shows an example of nested compound statement lists. The bare syntax of this example is
	 
	 Repeat {... If (...) {...} Else {...}
	 
	 and the compound statements following If and Else are nested inside the compound statement 
	 following Repeat. We can nest compound statements as deeply as we desire.
	 
	 Since it never stops by itself, the only way to terminate a Repeat statement is with a Halt state-
	 ment (or Return statement, see below).  It's a crude but effective technique; 
	 however, there are more elegant ways to decide how 
	 many times to repeat a block of statements. The Do-While statement allows us to specify a ter-
	 mination condition that is evaluated after the body has been executed. Here is an example that 
	 prints the random value assigned to x and repeats for as long as x is less than 0.9.
	 *****************************************************************************/
	
	Real x;
	Do {
		x = Random();  // choose a random value between 0.0 and 1.0
		Print(x);
	} While (x < 0.9);
	
	/*****************************************************************************
	 Because Random() returns a uniform random value in the range 0.0 to 1.0, its value will be less 
	 than 0.9 on average 90 percent of the time. It is possible, though unlikely, that this statement would 
	 print its value only once, and it is also possible that it could print dozens, even hundreds, of times before 
	 halting, depending upon the particular sequence of random numbers returned by Random().
	 
	 The For statement also implements a way of repeating a statement or compound statement a 
	 number of times, but it allows us to directly manage the value of one or more variables each time 
	 the statements are executed and to use them to determine when to stop. This example prints the 
	 integers between 0 and 9: 
	 *****************************************************************************/
	
	Integer i;
	For (i = 0; i < 10; i = i + 1) {
		Print(i);
	}
	
	/*****************************************************************************
	 The variable i is called the control variable. The example first sets i to 0, then tests if i < 10. 
	 Since 0 < 10, the Print() statement is executed. Next, the For statement executes the state-
	 ment i = i + 1, which adds 1 to the value of i. So now i equals 1. Again, the For loop tests 
	 if i < 10, and since 1 < 10, it executes Print() again. It again adds 1 to the value of i. So now 
	 i equals 2. This process continues until i == 10, whereupon the For loop terminates because 
	 then i < 10 is False.
	 
	 The For statement is a little twisty, so let's take a more careful look at its operation. In general, 
	 we can name the parts of the For statement as follows:
	 
	 For (initialization; test; change)
	 statement
	 
	 where statement can be a single statement (terminated by a semicolon) or a compound statement 
	 (enclosed with curly braces).
	 
	 The For statement first executes the initialization code, then 
	 evaluates the boolean expression test. If the value of test is False, the For statement terminates. 
	 If the value of test is True, the statement is executed, then the change expression is executed, 
	 and finally the test is evaluated again. If the value of test is False, the For statement terminates. 
	 If the value of test is True, the cycle repeats again and again until the value of test is False.
	 
	 As a convenience, it is possible to define and set the value of the initialization variable 
	 in one step, so the preceding example could have been written
	 *****************************************************************************/
	
	For (Integer i = 0; i < 10; i = i + 1) {
		Print(i);
	}
	
	/*****************************************************************************
	 Warning: the simple form of For statement is dangerous if you are not careful.
	 For example, here is a common mistake. By the way it is indented, it appears the
	 programmer perhaps wants that the Print(i * 10) statement to be executed
	 as part of the For statement. But it's only executed
	 once after the For statement prints the value of i ten times.
	 *****************************************************************************/
	
	For (Integer i = 0; i < 10; i = i + 1)
		Print(i);
		Print(i * 10);
	
	/*****************************************************************************
	 As a consequence, a good habit is to always use the compound For statement, showing
	 with brackets explicitly what statements you intend to include in the For statement:
	 *****************************************************************************/
	
	For (Integer i = 0; i < 10; i = i + 1) {
		Print(i);
		Print(i * 10);
	}
	
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:25 $ $Author: dgl $ $Name:  $ $Id: B0118.cpp,v 1.2 2006/09/05 06:32:25 dgl Exp $ */
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

