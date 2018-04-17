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
EXE = Chapter9.exe
DEPDIR = .deps
df = $(DEPDIR)/$(*F)


OBJ =   MusimatChapter9.o C090400.o \
	C090703.o \
	C090703a.o \
	C090703b.o \
	C090703c.o \
	C090903.o \
	C091101.o \
	C091102.o \
	C091200.o \
	C091201.o \
	C091201a.o \
	C091201b.o \
	C091201c.o \
	C091201d.o \
	C091201e.o \
	C091201f.o \
	C091204.o \
	C091204a.o \
	C091204b.o \
	C091204d.o \
	C091405.o \
	C091406.o \
	C091406a.o \
	C091406b.o \
	C091406c.o \
	C091704b.o \
	C091704c.o \
	C091704d.o

SRC =   MusimatChapter9.cpp C090400.cpp \
	C090703.cpp \
	C090703a.cpp \
	C090703b.cpp \
	C090703c.cpp \
	C090903.cpp \
	C091101.cpp \
	C091102.cpp \
	C091200.cpp \
	C091201.cpp \
	C091201a.cpp \
	C091201b.cpp \
	C091201c.cpp \
	C091201d.cpp \
	C091201e.cpp \
	C091201f.cpp \
	C091204.cpp \
	C091204a.cpp \
	C091204b.cpp \
	C091204d.cpp \
	C091405.cpp \
	C091406.cpp \
	C091406a.cpp \
	C091406b.cpp \
	C091406c.cpp \
	C091704b.cpp \
	C091704c.cpp \
	C091704d.cpp


$(EXE): $(OBJ)
	$(CC) -Wall -o $(EXE) $(OBJ) $(LIB) -lstdc++


clean:
#	rm -f $(EXE) $(OBJ) Debug/*.obj Debug/*.sbr Debug/*.log Debug/*.enc Debug/BuildLog.htm Debug/*.tlog
	rm -f $(EXE) $(OBJ) 
	rm -rf Debug Release

# Automatic make dependency generation
%.o : %.cpp
	$(COMPILE.cpp) $(CFLAGS) -MD -o $@ $<
	@cp $*.d $(df).P; \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $(df).P; \
	rm -f $*.d

-include $(SRC:%.cpp=$(DEPDIR)/%.P)


