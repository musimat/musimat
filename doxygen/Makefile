# default installation directory for Windows
# DOX = C:/"Program Files"/doxygen/bin/doxygen.exe
# default installation directory for Macintosh
DOX = /Applications/Doxygen.app/Contents/Resources/doxygen 

all: clean
	$(DOX) MusimatChapter9.Doxyfile
	$(DOX) MusimatLib.Doxyfile
	$(DOX) MusimatTutorial.Doxyfile

clean:  
	cd ../Documentation/MusimatChapter9; rm -rf *
	cd ../Documentation/MusimatLib; rm -rf *
	cd ../Documentation/MusimatTutorial; rm -rf *
