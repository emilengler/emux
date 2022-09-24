UTIL=	head

TESTS=	test1	\
	test2	\
	test3	\
	test4	\
	test5	\
	test6	\
	test7	\
	test8	\
	test9	\
	test10	\
	test11	\
	test12	\
	test13	\
	test14	\
	test15

include ../Makefile.inc

# Read from stdin.
test1:
	cat in | ${BIN} | cmp -s out /dev/stdin

# Read from stdin with a dash.
test2:
	cat in | ${BIN} - | cmp -s out /dev/stdin

# Read ten lines from stdin.
test3:
	cat in | ${BIN} -n10 | cmp -s out /dev/stdin

# Read ten lines from stdin with a dash.
test4:
	cat in | ${BIN} -n10 - | cmp -s out /dev/stdin

# Read from file.
test5:
	${BIN} in | cmp -s out /dev/stdin

# Read ten lines from file.
test6:
	${BIN} -n10 in | cmp -s out /dev/stdin

# Read five lines from stdin.
test7:
	cat in | ${BIN} -n5 | cmp -s out_5 /dev/stdin

# Read fifteen lines from stdin.
test8:
	cat in | ${BIN} -n15 | cmp -s out_15 /dev/stdin

# Read twenty lines from stdin.
test9:
	cat in | ${BIN} -n20 | cmp -s out_20 /dev/stdin

# Read more lines than in the file from stdin.
test10:
	cat in | ${BIN} -n25 | cmp -s out_20 /dev/stdin

# Read from multiple files and stdin.
test11:
	cat in | ${BIN} in - in | cmp -s out_3x /dev/stdin

# Read five lines from multiple files and stdin.
test12:
	cat in | ${BIN} -n5 in - in | cmp -s out_5_3x /dev/stdin

# Read fifteen lines from multiple files and stdin.
test13:
	cat in | ${BIN} -n15 in - in | cmp -s out_15_3x /dev/stdin

# Read twenty lines from multiple files and stdin
test14:
	cat in | ${BIN} -n20 in - in | cmp -s out_20_3x /dev/stdin

# Read more lines from multiple files and stdin
test15:
	cat in | ${BIN} -n25 in - in | cmp -s out_20_3x /dev/stdin
