SHELL = /bin/sh
LIB = ./MusimatLib
TESTS = ./MusimatTests
CHAP9 = ./MusimatChapter9
TUT = ./MusimatTutorial
RLS = ../Musimat.com
DOX = ./doxygen
TARG = Musimat1.2

# to make everything, say:
#	% make
# to clean temporaries, say:
#	% make clean
# to make a release, say:
#	% make release
# to make documentation (doxygen), say:
#	% make doxygen

.PHONY: all
all: clean build 
	echo "Musimat build done."

.PHONY: build
build:
	cd $(LIB); make
	cd $(TESTS); make
	cd $(CHAP9); make
	cd $(TUT); make
	
.PHONY: clean
clean:
	rm -rf ipch
	rm -f *.suo *.ncb
	cd $(LIB); make clean
	cd $(TESTS); make clean
	cd $(CHAP9); make clean
	cd $(TUT); make clean
	rm -rf $(LIB)/Debug
	rm -rf $(CHAP9)/Debug
	rm -rf $(TESTS)/Debug
	rm -rf $(TUT)/Debug
	rm -rf ./build
	find . -name "*.sbr" -exec rm -f '{}' \;
	find . -name "*.enc" -exec rm -f '{}' \;
	find . -name "*.enc" -exec rm -f '{}' \;
	find . -name "*.o" -exec rm -f '{}' \;

.PHONY: doxygen
doxygen:
	cd $(DOX); make

.PHONY: release
release: clean doxygen
	cp -rf Documentation/* $(RLS)
	rm -f $(RLS)/MusimatRelease/$(TARG).zip
	zip -r $(RLS)/MusimatRelease/$(TARG).zip .
	echo Musimat released to $(RLS)
	echo Now use WinZip to create $(TARG).exe from $(TARG).zip

