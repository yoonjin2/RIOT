/*
 * Copyright (C) 2016 Michael Andersen <m.andersen@berkeley.edu>
 *               2018 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    sys_stdio_rtt STDIO over SEGGER RTT
 * @ingroup     sys_stdio
 *
 * @brief       STDIO mapping for running the STDIO over SEGGER's RTT interface
 *
 * To enable stdio over SEGGER's RTT, enable the module `stdio_rtt`:
 *
 *     USEMODULE += stdio_rtt
 *
 * @note    Currently, `stdio_rtt` is only supported when OpenOCD or J-Link is
 *          used as programmer.
 *
 * @{
 * @file
 *
 * @author      Michael Andersen <m.andersen@cs.berkeley.edu>
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 */

#ifndef STDIO_RTT_H
#define STDIO_RTT_H

#include "stdio_base.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief enable stdin polling, at a power consumption cost. This is enabled
 *        by default unless STDIO_RTT_DISABLE_STDIN is defined.
 */
void rtt_stdio_enable_stdin(void);

/**
 * @brief enable stdout blocking and free space polling. This must be done
 *        with caution because if there is no RTT client attached, all
 *        writes to stdout will block indefinitely. This can be enabled
 *        automatically by defining STDIO_RTT_ENABLE_BLOCKING_STDOUT
 */
void rtt_stdio_enable_blocking_stdout(void);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* STDIO_RTT_H */
