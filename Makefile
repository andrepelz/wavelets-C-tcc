LDFLAGS += -g

SDIR = src
IDIR = headers
ODIR = obj

CC = gcc

WFLAGS = -Wall -Wno-comment -Wno-missing-braces -Wno-unused-function -Wno-unused-variable
CFLAGS += -I ${IDIR}
CFLAGS += -fcommon

PROG = wavelets

_SRCS = test.c \
    wavelet_base.c \
    wavelet_base_internal.c \
    haar_wavelet.c \
    haar_wavelet_internal.c
SRCS = $(patsubst %,${SDIR}/%,${_SRCS})

_DEPS = wavelet_base.h \
    wavelet_base_internal.h \
    haar_wavelet.h \
    haar_wavelet_internal.h
DEPS = $(patsubst %,${IDIR}/%,${_DEPS})
_OBJS = test.o \
    wavelet_base.o \
    wavelet_base_internal.o \
    haar_wavelet.o \
    haar_wavelet_internal.o
OBJS = $(patsubst %,${ODIR}/%,${_OBJS})

${ODIR}/%.o: ${SDIR}/%.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS} ${WFLAGS}

all: setup clean main

setup:
	if not exist "obj" mkdir obj

main: ${OBJS}
	${CC} -o $@ $^ ${CFLAGS}

.PHONY: clean

clean:
	del /f ${ODIR}\*.o
