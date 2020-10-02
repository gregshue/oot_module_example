/*
 * Copyright (c) 2020 Legrand North America, LLC.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <init.h>
#include <sys/printk.h>
#include <omx/omx_module_hello.h>

#include <logging/log.h>
LOG_MODULE_REGISTER(omx_module_hello);

int32_t omx_module_hello_said(void)
{
	return 1;
}

static int init(struct device *dev)
{
	ARG_UNUSED(dev);

	printk("Hello from " MODULE_NAME "!\n");
	LOG_INF("Hello from " STRINGIFY(MODULE_NAME));
	LOG_WRN("Hello from " STRINGIFY(MODULE_NAME));

	return 0;
}

SYS_INIT(init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
