/*
 * libexplain - Explain errno values returned by libc functions
 * Copyright (C) 2010, 2013 Peter Miller
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBEXPLAIN_BUFFER_ERRNO_SOCKETPAIR_H
#define LIBEXPLAIN_BUFFER_ERRNO_SOCKETPAIR_H

#include <libexplain/ac/sys/socket.h>

#include <libexplain/string_buffer.h>

/**
  * The explain_buffer_errno_socketpair function is used to obtain an
  * explanation of an error returned by the <i>socketpair</i>(2) system
  * call. The least the message will contain is the value of
  * <tt>strerror(errnum)</tt>, but usually it will do much better, and
  * indicate the underlying cause in more detail.
  *
  * @param sb
  *     The string buffer to print the message into. If a suitable buffer
  *     is specified, this function is thread safe.
  * @param errnum
  *     The error value to be decoded, usually obtained from the errno
  *     global variable just before this function is called. This is
  *     necessary if you need to call <b>any</b> code between the system
  *     call to be explained and this function, because many libc functions
  *     will alter the value of errno.
  * @param domain
  *     The original domain, exactly as passed to the <i>socketpair</i>(2)
  *     system call.
  * @param type
  *     The original type, exactly as passed to the <i>socketpair</i>(2)
  *     system call.
  * @param protocol
  *     The original protocol, exactly as passed to the
  *     <i>socketpair</i>(2) system call.
  * @param sv
  *     The original sv, exactly as passed to the <i>socketpair</i>(2)
  *     system call.
  */
void explain_buffer_errno_socketpair(explain_string_buffer_t *sb, int errnum,
    int domain, int type, int protocol, int *sv);

/**
  * The explain_buffer_errno_socketpair_explanation function is used to
  * obtain the explanation (the part after "because") of an error returned
  * by the <i>socketpair</i>(2) system call (and similar).
  *
  * @param sb
  *     The string buffer to print the message into. If a suitable buffer
  *     is specified, this function is thread safe.
  * @param errnum
  *     The error value to be decoded, usually obtained from the errno
  *     global variable just before this function is called. This is
  *     necessary if you need to call <b>any</b> code between the system
  *     call to be explained and this function, because many libc functions
  *     will alter the value of errno.
  * @param syscall_name
  *     The name of the offending system call.
  * @param domain
  *     The original domain, exactly as passed to the <i>socketpair</i>(2)
  *     system call.
  * @param type
  *     The original type, exactly as passed to the <i>socketpair</i>(2)
  *     system call.
  * @param protocol
  *     The original protocol, exactly as passed to the
  *     <i>socketpair</i>(2) system call.
  * @param sv
  *     The original sv, exactly as passed to the <i>socketpair</i>(2)
  *     system call.
  */
void explain_buffer_errno_socketpair_explanation(explain_string_buffer_t *sb,
    int errnum, const char *syscall_name, int domain, int type, int protocol,
    int *sv);

/* vim: set ts=8 sw=4 et : */
#endif /* LIBEXPLAIN_BUFFER_ERRNO_SOCKETPAIR_H */