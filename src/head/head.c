#define _POSIX_C_SOURCE 200809L

#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	head(FILE *, long);
static void	head_file(const char *, long);
static void	usage(void);

static const char	*progname;

static void
head(FILE *fp, long number)
{
	/* TODO: Use some sort of buffering. */
	long	lines = 0L;
	int	ch;

	while ((ch = fgetc(fp)) != EOF && lines < number) {
		putchar(ch);
		if (ch == '\n')
			++lines;
	}
}

static void
head_file(const char *path, long number)
{
	if (strcmp(path, "-") == 0) {
		/* The given file is the standard input. */
		head(stdin, number);
	} else {
		FILE	*fp;

		if ((fp = fopen(path, "rb")) == NULL) {
			fprintf(stderr, "%s: %s: %s\n", progname, path,
				strerror(errno));
			exit(1);
		}
		head(fp, number);
		fclose(fp);
	}
}

static void
usage(void)
{
	fprintf(stderr, "usage: %s [-n number] [file ...]\n", progname);
	exit(1);
}

int
main(int argc, char *argv[])
{
	long	number = 10L;	/* The amount of lines to read per file. */
	int	ch;

	progname = argv[0];

	while ((ch = getopt(argc, argv, "n:")) != -1) {
		switch (ch) {
		case 'n':
			errno = 0;
			number = strtol(optarg, NULL, 10);
			if (errno != 0) {
				fprintf(stderr,
					"%s: invalid number of lines: %s: %s\n",
					progname, optarg, strerror(errno));
				exit(1);
			} else if (number <= 0L) {
				fprintf(stderr,
					"%s: invalid number of lines: %s\n",
					progname, optarg);
				exit(1);
			}
			break;
		default:
			usage();
			break;
		}
	}

	if (optind == argc) {
		/* No files were given, read from stdin. */
		head(stdin, number);
	} else if (optind + 1 == argc) {
		/* Only one file was given. */
		head_file(argv[optind], number);
	} else {
		/* Multiple files were given, read all of them. */
		int	i;
		for (i = optind; i < argc; ++i) {
			printf("%s==> %s <==\n", i == optind ? "" : "\n",
			       argv[i]);
			head_file(argv[i], number);
		}
	}

	return (0);
}
