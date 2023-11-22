/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(app);

int main(void)
{
	printk("SPI sample started (%s)\n", CONFIG_BOARD);

	while (1) {
		k_msleep(1000);
	}

	return 0;
}
