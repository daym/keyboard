
LDFLAGS += -lasound

all: alsarawmidiin alsarawportlist nonblockinginput

alsarawmidiin.o: alsarawmidiin.c
alsarawportlist.o: alsarawportlist.c
alsarawportlist.o: nonblockinginput.c

clean:
	rm -f -- *.o

distclean: clean
