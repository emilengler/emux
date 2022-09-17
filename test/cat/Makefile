UTIL=	cat

TESTS=	test1	\
	test2	\
	test3	\
	test4	\
	test5	\
	test6	\
	test7	\
	test8	\
	test9	\
	test10

include ../Makefile.inc

test1:
	cat in | ${BIN} | cmp -s out /dev/stdin

test2:
	cat in | ${BIN} -u | cmp -s out /dev/stdin

test3:
	cat in | ${BIN} - | cmp -s out /dev/stdin

test4:
	cat in | ${BIN} -u - | cmp -s out /dev/stdin

test5:
	${BIN} in | cmp -s out /dev/stdin

test6:
	${BIN} -u in | cmp -s out /dev/stdin

test7:
	${BIN} in in | cmp -s out_twice /dev/stdin

test8:
	${BIN} -u in in | cmp -s out_twice /dev/stdin

test9:
	echo "---" | ${BIN} in - in | cmp -s out_mixed /dev/stdin

test10:
	echo "---" | ${BIN} -u in - in | cmp -s out_mixed /dev/stdin
