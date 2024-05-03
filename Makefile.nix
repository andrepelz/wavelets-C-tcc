ODIR = obj

all: setup clean main

setup:
	mkdir -p obj

clean:
	rm -f ${ODIR}/*.o
