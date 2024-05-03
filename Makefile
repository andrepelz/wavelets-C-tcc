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
    wavelet_transform.c \
    wavelet_transform_internal.c \
    haar_wavelet.c \
    haar_wavelet_internal.c
SRCS = $(patsubst %,${SDIR}/%,${_SRCS})

_DEPS = wavelet_base.h \
    wavelet_base_internal.h \
    wavelet_transform.h \
    wavelet_transform_internal.h \
    haar_wavelet.h \
    haar_wavelet_internal.h
DEPS = $(patsubst %,${IDIR}/%,${_DEPS})

_OBJS = test.o \
    wavelet_base.o \
    wavelet_base_internal.o \
    wavelet_transform.o \
    wavelet_transform_internal.o \
    haar_wavelet.o \
    haar_wavelet_internal.o
OBJS = $(patsubst %,${ODIR}/%,${_OBJS})

${ODIR}/%.o: ${SDIR}/%.c ${DEPS}
	${CC} ${LDFLAGS} -c -o $@ $< ${CFLAGS} ${WFLAGS}

win: setup_win main

setup_win:
	make -f Makefile.win

unix: setup_unix main

setup_unix:
	make -f Makefile.nix

main: ${OBJS}
	${CC} -o $@ $^ ${CFLAGS}
