UTIL=	false

TESTS=	test1	\
	test2

include ../Makefile.inc

test1:
	sh -c "${BIN} ; [ \$$? -eq 1 ]"

test2:
	sh -c "${BIN} ; [ \$$? -ne 0 ]"
