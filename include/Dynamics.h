/* $Revision: 1.4 $ $Date: 2006/09/07 08:38:33 $ $Author: dgl $ $Name:  $ $Id: Dynamics.h,v 1.4 2006/09/07 08:38:33 dgl Exp $ */
#ifndef DYNAMICS_H
#define DYNAMICS_H

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

#include <math.h>

///	@file Dynamics.h
///	@brief Functions for musical dynamic markings

//////////////////////////////////////////////////////////////////////////////
///	\defgroup dBFuns Global Decibel Functions
///	Convert to and from dB values from amplitude or energy coefficient values.
///@{

/// Return coefficient corresponding to a ratio of Real dB values.
/// Note: Type must be floating point type.
///	@param x dBSPL amplitude
///	@param ref dBSPL reference amplitude (defaults to 1.0)
template<class Type> inline Type dBCoefficient( Type x, Type ref = 1.0 ) { Return( pow(10.0, x / 20.0 ) / ref); }


///	Return the dB SPL of two amplitudes.
/// Note: Type must be floating point type.
///	@param x dBSPL amplitude
///	@param ref dBSPL reference amplitude (defaults to 1.0)
template<class Type> inline Type dBSPL( Type x, Type ref = 1.0 ) { Return 20.0 * log10(x / ref); }

///	Return the dB SIL of two amplitudes.
/// Note: Type must be floating point type.
///	@param x dBSIL amplitude
///	@param ref dBSIL reference amplitude (defaults to 1.0)
template<class Type> inline Type dBSIL( Type x, Type ref = 1.0 ) { Return 10.0 * log10(x / ref); }
///@}


//////////////////////////////////////////////////////////////////////////////
///	\defgroup DynVars Global Dynamics Variables
///	Arbitrary graded dynamic intensities, from "Musimathics".
///@{

Const Real 
	Fff = dBCoefficient(-10.0),		///< fortitissimo
	Ff = dBCoefficient(-18.0),		///< fortissimo
	Forte = dBCoefficient(-24.0),		///< forte  
	Mf = dBCoefficient(-32.0),		///< mezzoforte  
	Mp = dBCoefficient(-40.0),		///< mezzopiano  
	P = dBCoefficient(-48.0),		///< piano  
	Pp = dBCoefficient(-56.0),		///< pianisimo  
	Ppp = dBCoefficient(-64.0)		///< pianisisimo
;
///@}

#endif // DYNAMICS_H
