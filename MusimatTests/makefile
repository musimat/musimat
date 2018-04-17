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
EXE = MusimatTests.exe
DEPDIR = .deps
df = $(DEPDIR)/$(*F)


OBJ = MusimatTests.o miscTests.o Guido.o Euclid.o cplxTest.o

SRC = MusimatTests.cpp miscTests.cpp Guido.cpp Euclid.cpp cplxTest.cpp

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


