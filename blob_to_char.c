/*
**  blob_to_char.c - copy an I4GL TEXT type to an I4GL CHAR type
**  Copyright (C) 1993,2003  David A. Snyder
**
**  This library is free software; you can redistribute it and/or
**  modify it under the terms of the GNU Library General Public
**  License as published by the Free Software Foundation; version
**  2 of the License.
**
**  This library is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
**  Library General Public License for more details.
**
**  You should have received a copy of the GNU Library General Public
**  License along with this library; if not, write to the Free
**  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <locator.h>
#include <string.h>

blob_to_char(arg)
int	arg;
{
	loc_t	*blobp;
	short	charsize, n;
	char	s1[513];

	if (arg != 2) 
		fgl_fatal("blob_to_char.c", 30, -1318);

	popshort(&charsize);
	poplocator(&blobp);

	if (charsize < 1)
		charsize = 1;
	if (charsize > 512)
		charsize = 512;
	n = (charsize < blobp->loc_size) ? charsize : blobp->loc_size;
	strncpy(s1, blobp->loc_buffer, n);
	s1[n] = '\0';
	cr_to_spc(s1);

	pushquote(s1, n);
	return(1);
}


cr_to_spc(s)
char	*s;
{
	while (*s)
		*s++ = (*s == '\n') ? ' ' : *s;
}


