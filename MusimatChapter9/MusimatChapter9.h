/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: MusimatChapter9.h,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
#ifndef __TUTORIAL__
#define __TUTORIAL__

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

#include "Musimat.h"
#include "Pitches.h"

	Void C090400(); 
	Void C090703(); 
	Void C090703a();
	Void C090703b();
	Void C090703c();
	Void C090903();
	Void C091101();
	Void C091102();
	Void C091200();
	Void C091201();
	Void C091201a();
	Void C091201b();
	Void C091201c();
	Void C091201d();
	Void C091201e();
	Void C091201f();
	Void C091204();
	Void C091204a();
	Void C091204b();
	Void C091204d();
	Void C091405();
	Void C091406();
	Void C091406a();
	Void C091406b();
	Void C091406c();
	Void C091704b();
	Void C091704c();
	Void C091704d();

	IntegerList transpose(IntegerList, Integer);
	IntegerList invert(IntegerList);
	Integer getIndex(RealList, Real);
	Void rotate(IntegerList Reference, Integer, Integer);
	Integer cycle(IntegerList, Integer Reference, Integer);
	Real sum(RealList L);	
	RealList Reference accumulate(RealList Reference L);
	IntegerList randomRow(Integer);
	RealList normalize(RealList L, Real s);
	Void realToRational(Real f, Integer Reference num, Integer Reference den);

	Static Void para1();
	Static Void para2();
	Static Void para3();

#define MusimatChapter9Section(x) Void x()

#endif // __TUTORIAL__
