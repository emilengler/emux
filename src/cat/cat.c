#define _POSIX_C_SOURCE	200809L

#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE	256

static void	cat(FILE *);
static void	usage(void);

static const char	*progname;

static void
cat(FILE *fp)
{
	/* TODO: Use some sort of buffering. */
	int	ch;

	while ((ch = fgetc(fp)) != EOF)
		putchar(ch);
}

static void
usage(void)
{
	fprintf(stderr, "usage: %s [-u] [file ...]\n", progname);
	exit(1);
}

int
main(int argc, char *argv[])
{
	int	ch, i;

	progname = argv[0];

	while ((ch = getopt(argc, argv, "u")) != -1) {
		switch (ch) {
		case 'u':
			setvbuf(stdout, NULL, _IONBF, 0);
			break;
		default:
			usage();
			break;
		}
	}

	/* Check if no files were given. */
	if (optind == argc) {
		/* Read on stdin. */
		cat(stdin);
	}

	/* Operate on each and every file. */
	for (i = optind; i < argc; ++i) {
		if (strcmp(argv[i], "-") == 0) {
			/* Read on stdin. */
			cat(stdin);
		} else {
			FILE	*fp;

			if ((fp = fopen(argv[i], "rb")) == NULL) {
				fprintf(stderr, "%s: %s: %s\n", argv[0],
					argv[i], strerror(errno));
				exit(1);
			}
			cat(fp);
			fclose(fp);
		}
	}

	return (0);
}
