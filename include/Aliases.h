/* $Revision: 1.4 $ $Date: 2006/09/07 08:38:33 $ $Author: dgl $ $Name:  $ $Id: Aliases.h,v 1.4 2006/09/07 08:38:33 dgl Exp $ */
#ifndef ALIASES_H
#define ALIASES_H

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


///	@file Aliases.h
///	Declarations of Musimat typedefs and aliases

/// Type of an integer variable.
/// In C++, Integer is declared as type long int.
/// The underlying type this translates to is compiler dependent,
/// but is generally a 32-bit integer value.

typedef int Integer;

/// Type of a real variable.
/// In C++, Real is declared as type long double.
/// The underlying type this translates to is compiler dependent,
/// but is generally a 64-bit IEEE floating point value.

typedef double Real;

/// Type of a boolean variable.
/// In C++, Bool is declared as type bool.
/// The underlying type this translates to is compiler dependent,
/// but is generally a 32-bit integer value 
/// of which 1 bit (the LSB) is used.

typedef bool Bool;

/// String data type.
/// In C++, String is implemented as const char*.
/// Note, this is a change in this release. String used to be
/// implemented as just "char*" but is now a constant string
/// pointer to avoid warnings about "deprecated conversion
/// from string constant to 'char*' warnings.

typedef const char* String;

/// Repeat execution of a compound statement continuously.
/// Put Repeat at the head of a compound list to cause the 
/// enclosed statements to repeat indefinitely.  NOTE: the compound
/// list must contain a Halt, Return, Break or Continue statement,
/// otherwise the program will enter an infinite loop.

#define Repeat while (true)

/// Terminate execution at program location where Halt appears.
/// Terminate the current program at the program location where Halt appears.
/// Halt() takes an Integer argument, conventionally containing an 
/// error code to pass back to the calling context.
/// In C++, Halt() is implemented as exit().

#define Halt exit

/// Terminate execution of function and return a value (if given).
/// Terminate execution of the function in which it appears and returns 
/// control (and the value of expression if given) to the calling function.
/// In C++, Return is implemented as return.

#define Return return

/// Terminate the smallest enclosing repeating statement.
/// Terminate the smallest enclosing Do, 
/// For, Switch, While or Repeat statement in which it appears.
/// In C++, Break is implemented as break.

#define Break break

/// Pass control to the next iteration of the smallest enclosing repeating statement.
/// Pass control to the next iteration of the smallest enclosing 
/// Do, For, Repeat or While statement in which it appears.
/// In C++, Continue is implemented as continue.

#define Continue continue


/// Conditionally execute simple or compound statement.
/// 
/// 	If( expression )
/// 	statement1
/// 	[Else 
/// 	statement2]
/// 
/// 	The If keyword executes statement1 if expression is true (nonzero); 
/// 	If else is present and expression is false (zero), it executes statement2. 
/// 	After executing statement1 or statement2, control passes to the next statement.
/// 
/// 	In C++, If is implemented as if.

#define If if

/// Terminate execution of function and return a value (if given).
/// 
/// 	If( expression )
/// 	statement1
/// 	[Else 
/// 	statement2]
/// 
/// 	See If.
/// 
/// 	In C++, Else is implemented as else.

#define Else else

/// Execute statement repeatedly until expression becomes False.
/// 
/// 	Do 
/// 	statement 
/// 	While( expression );
/// 
/// 	Execute statement repeatedly until controlling expression becomes False (0).
/// 
/// 	In C++, Do is implemented as do.

#define Do do


/// Execute statement repeatedly until expression becomes False.
/// 
/// 	while ( expression ) statement
/// 
/// 	The expression is evaluated.
/// 
/// 	If expression is initially false, the body of the While statement is never executed, 
/// 	and control passes from the While statement to the next statement in the program.
/// 	If expression is True (nonzero), the body of the statement is executed and the 
/// 	process is repeated beginning at step 1.
/// 
/// 	The While statement can also terminate when a Break, Goto, or Return within the 
/// 	statement body is executed. Use the Continue statement to terminate an 
/// 	iteration without exiting the While loop. 
/// 	The Continue statement passes control to the next iteration of the While statement. 
/// 
/// 	In C++, While is implemented as while.

#define While while


/// Transfer control directly.
/// 
/// 	Goto name;
/// 	// . . .
/// 	name: statement
/// 
/// 	Transfer control directly to the statement specified by the label name.
/// 
/// 	In C++, Goto is implemented as goto.

#define Goto goto


/// Transfer control directly.
/// 
/// For( [init-expr]; [cond-expr]; [loop-expr] )
/// statement
/// 
/// The For keyword executes statement repeatedly. 
/// 
/// First, the initialization (init-expr) is evaluated. 
/// Then, while the conditional expression (cond-expr) evaluates to a nonzero value, 
/// statement is executed and the loop expression (loop-expr) is evaluated. 
/// When cond-expr becomes 0, control passes to the statement following the For loop.
/// 
/// In C++, For is implemented as for.

#define For for


/// Void declarator.
/// When used as a function return type, the Void keyword specifies 
/// that the function does not return a value. When used for a 
/// function's parameter list, Void specifies that the function takes no parameters. 
/// When used in the declaration of a pointer, Void specifies that the pointer 
/// is "universal."
/// 
/// If a pointer's type is Void *, the pointer can point to any variable 
/// that is not declared with the Const or Volatile keyword. 
/// A Void pointer cannot be dereferenced unless it is cast to another type. 
/// A Void pointer can be converted into any other type of data pointer.
/// 
/// A Void pointer can point to a function, but not to a class member.
/// 
/// Variables may not be declared to be of type void.
/// 
/// In C++, Void is implemented as void.

#define Void void


/// Const declarator.
/// When modifying a data declaration, the Const keyword specifies 
/// that the object or variable is not modifiable. 
/// When following a member function's parameter list, 
/// the const keyword specifies that the function doesn't modify the 
/// object for which it is invoked. 
/// 
/// In C++, Const is implemented as const.

#define Const const


/// Volatile declarator.
/// The volatile keyword is a type qualifier used to declare that 
/// an object can be modified in the program by something other than 
/// statements, such as the operating system, the hardware, or a 
/// concurrently executing thread.
/// 
/// Objects declared as volatile are not used in optimizations because 
/// their value can change at any time. The system always reads the 
/// current value of a volatile object at the point it is requested, 
/// even if the previous instruction asked for a value from the same object. 
/// Also, the value of the object is written immediately on assignment. 
/// 
/// One use of the volatile qualifier is to provide access to memory 
/// locations used by asynchronous processes such as interrupt handlers.
/// 
/// In C++, Volatile is implemented as volatile.

#define Volatile volatile



/// Positive boolean value.
/// True is one of the two values that a variable of type Bool can have. 
/// In C++, True is implemented as true.

#define True true


/// Negative boolean value.
/// False is the other of the two values that a variable of type Bool can have. 
/// In C++, False is implemented as false.

#define False false


/// Datatype of a single character.
/// In C++, Character is implemented as char.

#define Character char


/// Static declarator.
/// When modifying a variable, the static keyword specifies that the 
/// variable has static duration (it is allocated when the program 
/// begins and deallocated when the program ends) and initializes it to 0 
/// unless another value is specified. When modifying a variable or function 
/// at file scope, the static keyword specifies that the variable or function 
/// has internal linkage (its name is not visible from outside the file in 
/// which it is declared). 
/// 
/// In C++, when modifying a data member in a class declaration, 
/// the static keyword specifies that one copy of the member is shared 
/// by all the instances of the class. When modifying a member function 
/// in a class declaration, the static keyword specifies that the function 
/// accesses only static members.
/// 
/// In C++, Static is implemented as static.

#define Static static


/// Static declarator.
/// A Reference is a 16-bit or 32-bit quantity that holds the address 
/// of an object but behaves syntactically like that object. 
/// A Reference declaration consists of an (optional) list of specifiers 
/// followed by a Reference declarator.
/// 
/// Any object whose address can be converted to a given pointer 
/// type can also be converted to the analogous Reference type.
/// 
/// In C++, Reference is implemented as &.

#define Reference &


/// And operator.
/// The logical operators, And and Or, 
/// are used to combine multiple conditions formed using relational or 
/// equality expressions. The And operator returns the integral 
/// value 1 if both operands are nonzero; otherwise, it returns 0. 
/// And has left-to-right associativity.
/// 
/// In C++, And is implemented as &&.

#define And &&


/// Or operator.
/// The logical operators, And and Or, 
/// are used to combine multiple conditions formed using relational or 
/// equality expressions. The Or operator returns the integral value 1 
/// if either operand is nonzero; otherwise, it returns 0. 
/// Or has left-to-right associativity.
/// 
/// In C++, Or is implemented as ||.

#define Or ||

/// Conditionally execute multi-way branching.
/// 
/// 	Switch ( expression ) {
/// 	Case 1: [ Case 1a: . . . ] statement1 ; [ statemet1a ; . . . ; ] Break;
///		Case 2: [ Case 2a: . . . ] statement2 ; [ statement2a ; . . . ; ] Break;
///		. . .
///		[ Default: statementNa ; [ statementNb ; . . .] break; ]
///		}
///		If the result of evaluating the Switch expression matches the value of any Case,
///		the corresponding statement or statements are executed until the 
///		corresponding break statement, whereupon the Switch block is exited.
///		If no Case matches the expression, and there is a Default expression,
///		then the default statement(s) are executed. If there is no Default statement,
///		and no Case matches the Switch expression, nothing in the Switch block is executed.
///		Note: each Case's statement block must be terminated by Break. If it is not, then
///		execution continues at the next statement inline. This is either a bug or a feature
///		depending on whether you forget or remember this fact. Here's an example:
/*
 Switch ( getchar() ) { // read a character
	Case 'a': handle_a(); break; // receiving 'a' executes handle_a()
	Case 'b': Case 'B': handle_b_or_B(); break; // both 'b' and 'B' executes handle_b_or_B()
	Case 'c': handle_c(); // we forgot to put a break statement here!
	Case 'd': handle_d(); break; 
 }
 // What this means is 'c' will execute handle_c() AND handle_d(). 'd' will only execute handle_d().
 */
/// 	In C++, Switch is implemented as switch, Case is implemented as case, 
///		Break as break, and Default as default.

#define Switch switch
#define Case case
#define Default default
#define Break break

#endif // ALIASES_H
