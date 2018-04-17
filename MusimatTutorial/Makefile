# The Musimat Tutorial © 2006 Gareth Loy
# Derived from Chapter 9 and Appendix B of "Musimathics Vol. 1" © 2006 Gareth Loy 
# and published exclusively by The MIT Press.
# This program is released WITHOUT ANY WARRANTY; without even the implied 
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
# For information on usage and redistribution, and for a DISCLAIMER OF ALL
# WARRANTIES, see the file, "LICENSE.txt," in this distribution.
# "Musimathics" is available here:	http://mitpress.mit.edu/catalog/item/default.asp?ttype=2&tid=10916
# Gareth Loy's Musimathics website:	http://www.musimathics.com/
# The Musimat website:			http://www.musimat.com/
# This program is released under the terms of the GNU General Public License
# available here:			http://www.gnu.org/licenses/gpl.txt

SHELL = /bin/sh
srcdir = .
INCLUDE = ../include
CC = gcc
INSTALL =
DEFS =
CDEBUG = -g
CFLAGS = $(CDEBUG) -I. -I$(INCLUDE) $(DEFS)
LDFLAGS =
LIB = ../MusimatLib/MusimatLib.a
EXE = MusimatTutorial.exe
DEPDIR = .deps
df = $(DEPDIR)/$(*F)


OBJ =   B0100.o  \
	B0101.o  \
	B0102.o  \
	B0103.o  \
	B0104.o  \
	B0105.o  \
	B0106.o  \
	B0107.o  \
	B0108.o  \
	B0109.o  \
	B0110.o  \
	B0111.o  \
	B0112.o  \
	B0113.o  \
	B0114.o  \
	B0115.o  \
	B0116.o  \
	B0117.o  \
	B0118.o  \
	B0119.o  \
	B0120.o  \
	B0121.o  \
	B0122.o  \
	B0123.o  \
	B0124.o  \
	B0125.o  \
	B0126.o  \
	B0127.o  \
	B0128.o  \
	B0129.o  \
	B0200.o  \
	B0201.o  \
	B0201a.o  \
	B0201b.o  \
	B0201c.o  \
	B0201d.o  \
	B0202.o  \
	B0203.o  \
	B0204.o  \
	B0300.o  \
	B0400.o  \
	MusimatTutorial.o

SRC =   B0100.cpp  \
	B0101.cpp  \
	B0102.cpp  \
	B0103.cpp  \
	B0104.cpp  \
	B0105.cpp  \
	B0106.cpp  \
	B0107.cpp  \
	B0108.cpp  \
	B0109.cpp  \
	B0110.cpp  \
	B0111.cpp  \
	B0112.cpp  \
	B0113.cpp  \
	B0114.cpp  \
	B0115.cpp  \
	B0116.cpp  \
	B0117.cpp  \
	B0118.cpp  \
	B0119.cpp  \
	B0120.cpp  \
	B0121.cpp  \
	B0122.cpp  \
	B0123.cpp  \
	B0124.cpp  \
	B0125.cpp  \
	B0126.cpp  \
	B0127.cpp  \
	B0128.cpp  \
	B0129.cpp  \
	B0200.cpp  \
	B0201.cpp  \
	B0201a.cpp  \
	B0201b.cpp  \
	B0201c.cpp  \
	B0201d.cpp  \
	B0202.cpp  \
	B0203.cpp  \
	B0204.cpp  \
	B0300.cpp  \
	B0400.cpp  \
	MusimatTutorial.cpp

$(EXE): $(OBJ)
	$(CC) -Wall -o $(EXE) $(OBJ) $(LIB) -lstdc++


clean:
	rm -f $(EXE) $(OBJ) Debug/*.obj

# Automatic make dependency generation
%.o : %.cpp
	$(COMPILE.cpp) $(CFLAGS) -MD -o $@ $<
	@cp $*.d $(df).P; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $(df).P; \
	rm -f $*.d

-include $(SRC:%.cpp=$(DEPDIR)/%.P)


