/* VTY I/O for Files and Pipes -- Header
 *
 * Copyright (C) 2010 Chris Hall (GMCH), Highwayman
 *
 * This file is part of GNU Zebra.
 *
 * GNU Zebra is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * GNU Zebra is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Zebra; see the file COPYING.  If not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef _ZEBRA_VTY_IO_FILE_H
#define _ZEBRA_VTY_IO_FILE_H

#include "misc.h"

#include "vty_io.h"
#include "vty_command.h"
#include "command_parse.h"
#include "qpath.h"
#include "qstring.h"

/*==============================================================================
 * Here are structures and other definitions which are shared by:
 *
 *   vty_io.c   -- the main VTY I/O stuff
 *
 * for I/O to files
 */

/*==============================================================================
 * Functions
 */
extern void uty_config_read_open(vty_io vio, int fd, qpath path) ;

extern void vty_config_write_open(vty vty, int fd) ;
extern cmd_ret_t vty_config_write_close(struct vty* vty) ;

extern cmd_ret_t uty_file_read_open(vty_io vio, qpath path) ;
extern cmd_ret_t uty_file_write_open(vty_io vio, qpath path,
                                                      bool append, bool after) ;

extern cmd_ret_t uty_file_cmd_line_fetch(vio_vf vf) ;
extern cmd_ret_t uty_file_out_push(vio_vf vf) ;
extern cmd_ret_t uty_file_write_block(vio_vf vf) ;

extern cmd_ret_t uty_file_read_close(vio_vf vf) ;
extern cmd_ret_t uty_file_write_close(vio_vf vf) ;

extern cmd_ret_t uty_pipe_read_open(vty_io vio, qstring command) ;
extern cmd_ret_t uty_pipe_write_open(vty_io vio, qstring command,
                                                  bool shell_cmd, bool after) ;
//extern cmd_ret_t uty_pipe_cmd_line_fetch(vio_vf vf) ;
//extern cmd_ret_t uty_pipe_out_push(vio_vf vf) ;
extern cmd_ret_t uty_pipe_read_close(vio_vf vf) ;
extern cmd_ret_t uty_pipe_write_close(vio_vf vf) ;
extern void uty_pipe_all_return_stop(vio_vf vf) ;

#endif /* _ZEBRA_VTY_IO_FILE_H */