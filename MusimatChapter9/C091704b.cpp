#include "MusimatChapter9.h"
MusimatChapter9Section(C091704b) {
	Print("*** Brownian Nose Generator ***");
	/*****************************************************************************
	 
	 Brownian Nose Generator
	 
	 Here is a simple Brownian number generator (F. R. Moore 1990):
	 *****************************************************************************/
	para1(); // Step into this function to continue.
}

Real brownian(Real x, Real w, Real B){
	Real R;
	Do {
		R = x + Random( -w, w );
	} While ( R > B Or R < -B );
	Return R;
}

Static Void PlotPoint(Real x, Real y)
{
	// Note, this function is a placeholder for the appropriate
	// graphics function call on your platform to plot a point
	//on a graph.
	
	RealList rL(x, y);
	Print(rL);
}

Static Void para1() {
	/*****************************************************************************
	 Parameter x is either the initial value of the random walk or the value last calculated by brownian(). 
	 Parameter w is called the window parameter because it determines the maximum amount by which 
	 the value of x can change at one time. Parameter B is the bounds, limiting the Brownian motion 
	 to within its range. This method departs from strict Brownian motion by retrying the random 
	 choice until the new value lies within this range.
	 
	 We call the brownian() method each time we want a new Brownian number, passing it either 
	 an initial value or the value of its previous output. For example, the following code generated the 
	 function shown in figure 9.30.
	 *****************************************************************************/
	
	Real x = 0.0;
	Real y = 0.0;
	
	For (Integer i = 0; i < 10; i = i + 1) {
		x = brownian(x, 0.5, 0.5);
		y = brownian(y, 0.5, 0.5);
		PlotPoint(x, y);	// plot a point on a graph at location [x, y]
	}
	
	/*****************************************************************************
	 A Brownian noise signal and its power spectrum on a log-log plot are shown in figure 9.31. The 
	 straight line in the figure traces the contour of 1/(f*f) for reference.
	 *****************************************************************************/
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
/* $Revision: 1.3 $ $Date: 2006/09/05 08:02:46 $ $Author: dgl $ $Name:  $ $Id: C091704b.cpp,v 1.3 2006/09/05 08:02:46 dgl Exp $ */
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

