/*
 * ToriX - TORres Interactive eXecution
 * Copyright (c) 2008 Devin Torres
 * Licensed under the MIT license.
 */

#include <stdlib.h>

int abs(int x)
{
	return x < 0 ? -x : x;
}

div_t div(int numer, int denom)
{
	div_t r;

	r.quot = numer / denom;
	r.rem = numer % denom;

	if (numer >= 0 && r.rem < 0) {
		++r.quot;
		r.rem -= denom;
	} else if (numer < 0 && r.rem > 0) {
		--r.quot;
		r.rem += denom;
	}

  return r;
}

long labs(long x)
{
	return x < 0 ? -x : x;
}

ldiv_t ldiv(long numer, long denom)
{
	ldiv_t r;

	r.quot = numer / denom;
	r.rem = numer % denom;

	if (numer >= 0 && r.rem < 0) {
		++r.quot;
		r.rem -= denom;
	} else if (numer < 0 && r.rem > 0) {
		--r.quot;
		r.rem += denom;
	}

	return r;
}
