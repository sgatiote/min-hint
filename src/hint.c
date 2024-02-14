#include "min/hint/hint.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char * colour_formats[25] =
{
	"\x1b[30m", "\x1b[31m", "\x1b[32m", "\x1b[33m",
	"\x1b[34m", "\x1b[35m", "\x1b[36m", "\x1b[37m",

	"\x1b[1;30m", "\x1b[1;31m", "\x1b[1;32m", "\x1b[1;33m",
	"\x1b[1;34m", "\x1b[1;35m", "\x1b[1;36m", "\x1b[1;37m",

	"\x1b[30;100m", "\x1b[31;101m", "\x1b[32;102m", "\x1b[33;103m",
	"\x1b[34;104m", "\x1b[35;105m", "\x1b[36;106m", "\x1b[37;107m",

	"\x1b[0m"
};

char * hintColour(const char * text, HintColourCode code)
{
	if (code < HINT_COLOUR_BLACK || code > HINT_COLOUR_MAX_LENGTH)
	{
		hintError("invalid colour code");
		return NULL;
	}

	size_t colour_format_length;

	if (code >= HINT_COLOUR_BLACK && code <= HINT_COLOUR_WHITE)
		colour_format_length = HINT_COLOUR_NORMAL_LENGTH;

	else if (code >= HINT_COLOUR_BOLD_BLACK && code <= HINT_COLOUR_BOLD_WHITE)
		colour_format_length = HINT_COLOUR_BOLD_LENGTH;

	else
		colour_format_length = HINT_COLOUR_HIGHLIGHT_LENGTH;

	char * result = (char *) malloc(colour_format_length + strlen(text) + HINT_COLOUR_RESET_LENGTH + 1);

	if (!result)
	{
		hintError("memory allocation failed");
		return NULL;
	}

	strcpy(result, colour_formats[code]);
	strcat(result, text);
	strcat(result, colour_formats[HINT_COLOUR_RESET]);
	return result;
}

static void hintError(const char * message)
{
	fprintf(
		stderr, "%sError:%s %s\n",
		colour_formats[HINT_COLOUR_RED],
		colour_formats[HINT_COLOUR_RESET],
		message
	);
}