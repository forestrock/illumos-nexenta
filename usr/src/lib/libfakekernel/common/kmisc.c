/*
 * This file and its contents are supplied under the terms of the
 * Common Development and Distribution License ("CDDL"), version 1.0.
 * You may only use this file in accordance with the terms of version
 * 1.0 of the CDDL.
 *
 * A full copy of the text of the CDDL should have accompanied this
 * source.  A copy of the CDDL is also available via the Internet at
 * http://www.illumos.org/license/CDDL.
 */

/*
 * Copyright 2013 Nexenta Systems, Inc.  All rights reserved.
 */

#include <sys/types.h>
#include <sys/time.h>
#include <sys/thread.h>
#include <sys/proc.h>

#include <sys/poll.h>

#include <time.h>
#include <unistd.h>

pri_t minclsyspri = 60;

proc_t p0;

proc_t *
_curproc(void)
{
	return (&p0);
}

pid_t
ddi_get_pid(void)
{
	return ((pid_t)getpid());
}

void
delay(clock_t ticks)
{
	int msec = ticks;  /* NB: hz==1000 */
	(void) poll(0, 0, msec);
}
