/* $Revision: 1.2 $ $Date: 2006/09/05 06:32:15 $ $Author: dgl $ $Name:  $ $Id: MusimatTests.cpp,v 1.2 2006/09/05 06:32:15 dgl Exp $ */

// MusimatTests.cpp : Defines the entry point for the console application.
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
//

#ifndef __GNUC__
#include <crtdbg.h>
#include <assert.h>
#include "stdafx.h"
#endif
#include <iostream>

int miscTests(int argc, char* argv[]);

#ifndef __GNUC__
int _tmain(int argc, _TCHAR* argv[])
#else
int main(int argc, char* argv[])
#endif
{

#ifndef __GNUC__
#ifdef PERFORM_MEMTESTS
	// Get current flag
	int tmpFlag = _CrtSetDbgFlag( _CRTDBG_REPORT_FLAG );
	// Turn on leak-checking bit
	tmpFlag |= _CRTDBG_LEAK_CHECK_DF;
	tmpFlag |= _CRTDBG_CHECK_ALWAYS_DF;
	tmpFlag |= _CRTDBG_ALLOC_MEM_DF;
	tmpFlag |= _CRTDBG_CHECK_CRT_DF;
	// Set flag to the new value
	_CrtSetDbgFlag( tmpFlag );
	assert( _CrtCheckMemory( ) );
#endif // PERFORM_MEMTESTS
#endif // __GNUC__

	miscTests(argc, argv);
	   
#ifndef __GNUC__
	assert( _CrtCheckMemory( ) ); // no-op unless PERFORM_MEMTESTS is defined
#endif // __GNUC__

	return 0;
}

