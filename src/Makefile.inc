OBJS=		${SRCS:.c=.o}

CFLAGS+=	-std=c89 -g -O2
CFLAGS+=	-Wall -Wextra -Wpedantic
CFLAGS+=	-Wmissing-prototypes -Wstrict-prototypes -Wwrite-strings

all: ${UTIL}

${UTIL}: ${OBJS}
	${CC} ${CFLAGS} ${CPPFLAGS} -o $@ ${OBJS} ${LDFLAGS}

clean:
	rm -f ${UTIL} ${OBJS}

.PHONY: all clean
