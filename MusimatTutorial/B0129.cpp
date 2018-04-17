#include "MusimatTutorial.h"
MusimatTutorialSection(B0129) {
	Print("*** B.1.29 Representing Text ***");
	/*****************************************************************************
	 
	 B.1.29 Representing Text
	 
	 In order to print text, we use a data type called Character, which consists of the letters of the Roman 
	 alphabet, digits from 0 to 9, and some nonprinting characters like tab, white space, and punctuation. 
	 Characters are written in single quotes: 'a', 'B', 'c', and so on. Punctuation marks include ' ' 
	 (blank), ',' (comma), ';' (semicolon), and '.' (period). We can spell words and sentences by 
	 making lists of characters, for example {'G', 'u', 'i', 'd', 'o'}, but this would be exces-
	 sively tedious. A shortcut for lists of characters is another data type called String. For example,
	 *****************************************************************************/
	
	String c = "Ut queant laxis resonare";
	Print(c);
	
	/*****************************************************************************
	 This string is equivalent to, and much simpler than, assembling a list of characters.
	 
	 Computers operate with binary numbers, not alphabetic letters. So we must associate each char-
	 acter we want to display with a unique binary number. The computer operates only on the binary 
	 numeric values; the display screen connected to the computer knows how to convert binary 
	 numeric values to the corresponding characters for display.
	 
	 We need a table listing the association between particular binary values and the corresponding 
	 printed characters. This table is called a character set. When a key is pressed on a computer key-
	 board, the keyboard looks up the corresponding binary number in the character set and sends it 
	 to the computer. The computer forwards the number to the display screen, which also uses 
	 the character set to determine which character to display. Only the keyboard and the screen use the 
	 character set; the computer just stores the corresponding binary numbers.
	 
	 International standard ISO-10646 defines a Universal Character Set, commonly called Unicode. 
	 To keep things simple, Musimat uses a common subset of Unicode called ASCII (see section B.2). 
	 The built-in Character() function takes an ASCII character code as its argument and returns 
	 the corresponding printable Character.
	 *****************************************************************************/
	
	Print(Character(65));
	
	/*****************************************************************************
	 prints the character 'A'. The Integer() function can take a printable Character as its argu-
	 ment and return the corresponding ASCII character code. For example:
	 *****************************************************************************/
	
	Print(Integer('A'));
	
	/*****************************************************************************
	 prints 65.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:26 $ $Author: dgl $ $Name:  $ $Id: B0129.cpp,v 1.2 2006/09/05 06:32:26 dgl Exp $ */
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

