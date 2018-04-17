#include "MusimatTutorial.h"
MusimatTutorialSection(B0300) {
	Print("*** B.3 Unicode (ASCII) Character Codes ***");
	/*****************************************************************************
	 
	 B.3 Unicode (ASCII) Character Codes
	 
	 The Universal Character Set, or Unicode, encodes virtually all of the world's characters and even 
	 leaves room for characters not yet invented. A common subset of Unicode is ASCII (American Stan-
	 dard Code for Information Interchange), which was proposed by ANSI in 1963 and adopted in 1968. 
	 Recent standards that refer to ASCII include ISO-14962-1997 and ANSI-X3.4-1986 (R1997). The 
	 ASCII code includes many punctuation marks and white space such as blank, tab, and newline 
	 (which forces subsequent text onto a new line).
	 
	 Table B.1 
	 ASCII Character Codes
	 
	    0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15
	 0	NUL	SOH	STX	ETX	EOT	ENQ	ACK	BEL	BS	HT	LF	VT	FF	CR	SO	SI
	 1	DLE	DC1	DC2	DC3	DC4	NAK	SYN	ETB	CAN	EM	SUB	ESC	FS	GS	RS	US
	 2	SP	!	"	#	$	%	&	'	(	)	*	+	,	-	.	/
	 3	0	1	2	3	4	5	6	7	8	9	:	;	<	=	>	?
	 4	@	A	B	C	D	E	F	G	H	I	J	K	L	M	N	O
	 5	P	Q	R	S	T	U	V	W	X	Y	Z	[	\	]	^	_
	 6	`	a	b	c	d	e	f	g	h	i	j	k	l	m	n	o
	 7	p	q	r	s	t	u	v	w	x	y	z	{	|	}	~	DEL
	 
	 
	 To obtain the integer ASCII number corresponding to a character, first find the row r and column 
	 c containing the character in table B.1. The ASCII number of this character is . For example, 
	 the character ‘A' corresponds to .
	 
	 The characters between 0 and 31 and DEL are reserved for functions that mostly don't concern 
	 computer users, except for CR (carriage return) and LF (line feed). SP stands for the space 
	 character '  '. This is another one of those tables that you must learn if you expect your geek friends 
	 to take you seriously, so place a copy of table B.1 at your bedside or above the mantelpiece, where 
	 you can refer to it frequently.
	 *****************************************************************************/
	
	For (Integer i = 32; i < 128; i++)
		Print(Character(i));
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:26 $ $Author: dgl $ $Name:  $ $Id: B0300.cpp,v 1.2 2006/09/05 06:32:26 dgl Exp $ */
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

