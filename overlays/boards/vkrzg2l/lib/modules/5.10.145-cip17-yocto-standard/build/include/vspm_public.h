/*************************************************************************/ /*
 * VSPM
 *
 * Copyright (C) 2015-2021 Renesas Electronics Corporation
 *
 * License        Dual MIT/GPLv2
 *
 * The contents of this file are subject to the MIT license as set out below.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * the GNU General Public License Version 2 ("GPL") in which case the provisions
 * of GPL are applicable instead of those above.
 *
 * If you wish to allow use of your version of this file only under the terms of
 * GPL, and not to allow others to use your version of this file under the terms
 * of the MIT license, indicate your decision by deleting the provisions above
 * and replace them with the notice and other provisions required by GPL as set
 * out in the file called "GPL-COPYING" included in this distribution. If you do
 * not delete the provisions above, a recipient may use your version of this
 * file under the terms of either the MIT license or GPL.
 *
 * This License is also included in this distribution in the file called
 * "MIT-COPYING".
 *
 * EXCEPT AS OTHERWISE STATED IN A NEGOTIATED AGREEMENT: (A) THE SOFTWARE IS
 * PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT; AND (B) IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *
 * GPLv2:
 * If you wish to use this file under the terms of GPL, following terms are
 * effective.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */ /*************************************************************************/

#ifndef __VSPM_PUBLIC_H__
#define __VSPM_PUBLIC_H__

#include "vsp_drv.h"
#include "fdp_drv.h"
#include "isu_drv.h"
#include "vspm_cmn.h"

/* callback function */
typedef void (*PFN_VSPM_COMPLETE_CALLBACK)(
	unsigned long job_id, long result, void *user_data);

/* VSP Manager APIs */
long vspm_init_driver(
	void **handle,
	struct vspm_init_t *param);

long vspm_quit_driver(
	void *handle);

long vspm_entry_job(
	void *handle,
	unsigned long *job_id,
	char job_priority,
	struct vspm_job_t *ip_param,
	void *user_data,
	PFN_VSPM_COMPLETE_CALLBACK cb_func);

long vspm_cancel_job(
	void *handle,
	unsigned long job_id);

long vspm_get_status(
	void *handle,
	struct vspm_status_t *status);

#endif	/* __VSPM_PUBLIC_H__ */
