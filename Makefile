UTILS=	cat	\
	false	\
	true

all:
	@for util in ${UTILS}; do		\
		${MAKE} -C src/$${util} all;	\
	done

clean:
	@for util in ${UTILS}; do		\
		${MAKE} -C src/$${util} clean;	\
		${MAKE} -C test/$${util} clean;	\
	done

test:
	@for util in ${UTILS}; do		\
		${MAKE} -C test/$${util} test;	\
	done

.PHONY: all clean test
