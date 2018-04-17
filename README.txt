
About the Musimat Tutorial

To install the software and get started, see INSTALL.txt.

In "Musimathics Vol. 1", Gareth Loy introduces a language he calls "Musimat"
taylored for the musical examples in his book.  He describes Musimat as
"C++ in sheep's clothing."  Indeed, Musimat is just a version 
of C++ designed for didactic purposes.  Nonetheless, it provides
a straightforward introduction to programming in a modern computer language
and provides insightful demonstrations of how to begin to adapt such 
a language to musical purposes.

The distribution is in the following parts:
o  The Musimat Tutorial
o  Musimat examples Chapter 9
o  The Musimat runtime library
o  Documentation

The Musimat Tutorial is an executable program that is simultaneously
a graded introduction to programming in general and to Musimat in particular.
It is based on Appendix B of "Musimathics V1".  The tutorial is in the 
directory ./MusimatTutorial.  The executable in that directory is
named MusimatTutorial.exe.

The Musimat examples from Chapter 9 incorporate the code and surrounding
text of these examples into an executable program.  The source code and
executable are in the directory ./MusimatChapter9.  The executable in 
that directory is named Chapter9.exe.

Though the executables can be run as console applications, 
the best way to go through the tutorial and Chapter 9 materials is by 
stepping through them with a debugger such as gdb, or the debugger in
Microsoft Visual C++.  That way the text, code, and program output
can be followed and explored to maximum advantage.  See the README.txt
file in ./MusimatTutorial and ./MusimatChapter9 for details.

The Musimat runtime library is a static linked library that contains
the main Musimat data structures and a set of routines to manipulate them.
It is located in ./MusimatLib in file MusimatLib.a.

The contents of this distribution are released under the terms of 
the GNU Public License.  See the  LICENSE.txt file in this directory
for license information and for a DISCLAIMER OF ALL WARRANTIES.
