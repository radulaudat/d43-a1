/*
 * psql - the PostgreSQL interactive terminal
 *
 * Copyright (c) 2000-2003, PostgreSQL Global Development Group
 *
 * $Header: /cvsroot/pgsql/src/bin/psql/print.h,v 1.19 2003/08/04 23:59:40 tgl Exp $
 */
#ifndef PRINT_H
#define PRINT_H

#include "libpq-fe.h"


extern FILE *PageOutput(int lines, unsigned short int pager);

extern void html_escaped_print(const char *in, FILE *fout);

enum printFormat
{
	PRINT_NOTHING = 0,			/* to make sure someone initializes this */
	PRINT_UNALIGNED,
	PRINT_ALIGNED,
	PRINT_HTML,
	PRINT_LATEX
	/* add your favourite output format here ... */
};


typedef struct _printTableOpt
{
	enum printFormat format;	/* one of the above */
	bool		expanded;		/* expanded/vertical output (if supported
								 * by output format) */
	unsigned short int pager;	/* use pager for output (if to stdout and
								 * stdout is a tty) 0=off 1=on 2=always */
	bool		tuples_only;	/* don't output headers, row counts, etc. */
	unsigned short int border;	/* Print a border around the table.
								 * 0=none, 1=dividing lines, 2=full */
	char	   *fieldSep;		/* field separator for unaligned text mode */
	char	   *recordSep;		/* record separator for unaligned text
								 * mode */
	char	   *tableAttr;		/* attributes for HTML <table ...> */
	int			encoding;		/* character encoding */
} printTableOpt;


/*
 * Use this to print just any table in the supported formats.
 * - title is just any string (NULL is fine)
 * - headers is the column headings (NULL ptr terminated). It must be given and
 *	 complete since the column count is generated from this.
 * - cells are the data cells to be printed. Now you know why the correct
 *	 column count is important
 * - footers are lines to be printed below the table
 * - align is an 'l' or an 'r' for every column, if the output format needs it.
 *	 (You must specify this long enough. Otherwise anything could happen.)
*/
void printTable(const char *title, const char *const * headers,
		   const char *const * cells, const char *const * footers,
		   const char *align,
		   const printTableOpt *opt, FILE *fout);



typedef struct _printQueryOpt
{
	printTableOpt topt;			/* the options above */
	char	   *nullPrint;		/* how to print null entities */
	bool		quote;			/* quote all values as much as possible */
	char	   *title;			/* override title */
	char	  **footers;		/* override footer (default is "(xx
								 * rows)") */
	bool		default_footer; /* print default footer if footers==NULL */
} printQueryOpt;

/*
 * Use this to print query results
 *
 * It calls the printTable above with all the things set straight.
 */
void		printQuery(const PGresult *result, const printQueryOpt *opt, FILE *fout);

#ifndef __CYGWIN__
#define DEFAULT_PAGER "more"
#else
#define DEFAULT_PAGER "less"
#endif

#endif   /* PRINT_H */
