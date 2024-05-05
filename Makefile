LDFLAGS += -g

SDIR = src
IDIR = headers
ODIR = obj

CC = gcc

WFLAGS = -Wall -Wno-comment -Wno-missing-braces -Wno-unused-function -Wno-unused-variable
override CFLAGS += -I ${IDIR}
override CFLAGS += -fcommon

PROG = wavelets

_SRCS = test.c \
    utils.c \
    utils_internal.c \
    signal_base.c \
    signal_base_internal.c \
    wavelet_base.c \
    wavelet_thresholding.c \
    wavelet_thresholding_internal.c \
    wavelet_transform.c \
    wavelet_transform_internal.c
SRCS = $(patsubst %,${SDIR}/%,${_SRCS})

_DEPS = utils.h \
    utils_internal.h \
    signal_base.h \
    signal_base_internal.h \
    wavelet_base.h \
    wavelet_thresholding.h \
    wavelet_thresholding_internal.h \
    wavelet_transform.h \
    wavelet_transform_internal.h
DEPS = $(patsubst %,${IDIR}/%,${_DEPS})

_OBJS = test.o \
    utils.o \
    utils_internal.o \
    signal_base.o \
    signal_base_internal.o \
    wavelet_base.o \
    wavelet_thresholding.o \
    wavelet_thresholding_internal.o \
    wavelet_transform.o \
    wavelet_transform_internal.o
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

run:
	./main.exe
