.PHONY: clean install uninstall

VPATH = incl src lib

Code2: main.o libar.a libvol.so.1.0.0
	mkdir bin
	gcc -o ./bin/$@ main.o ./lib/libar.a ./lib/libvol.so.1.0.0

main.o: main.c area.h volume.h
	gcc -c $< -I./incl

libar.a: area.o
	mkdir lib
	ar rs ./lib/$@ $< 

libvol.so.1.0.0: volume.o
	gcc -shared $< -Wl,-soname,libvol.so.1 -o ./lib/$@
#						-> zdefiniowanie soname biblioteki dynamicznej
area.o: area.c 
	gcc -c $<

volume.o: volume.c 
	gcc -fPIC -c $<

clean: 
	rm -r bin lib *.o
#zmienne wskazujace miejsce instalacji
LDEST = /usr/lib
XDEST = /usr/bin

install:
	install ./bin/Code2 $(XDEST) && install ./lib/libar.a ./lib/libvol.so.1.0.0 $(LDEST)
	ln -s $(LDEST)/libvol.so.1.0.0 $(LDEST)/libvol.so.1 
#   	-> utworzenie linka do biblioteki dynamicznej

uninstall:
	rm $(XDEST)/Code2 $(LDEST)/libar.a $(LDEST)/libvol.so.1.0.0
	
