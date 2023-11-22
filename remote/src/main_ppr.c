/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
LOG_MODULE_REGISTER(app);

#define PPR_SPI DT_NODELABEL(ppr_spi)

const struct device *spi_dev;
struct spi_cs_control spim_cs = {
	.gpio = SPI_CS_GPIOS_DT_SPEC_GET(DT_NODELABEL(ppr_spi_sensor)),
	.delay = 0,
};

static void spi_init(void)
{
	spi_dev = DEVICE_DT_GET(PPR_SPI);
	if(!device_is_ready(spi_dev)) {
		printk("SPI master device not ready!\n");
	}
	if(!device_is_ready(spim_cs.gpio.port)){
		printk("SPI master chip select device not ready!\n");
	}
}

int main(void)
{
	printk("SPI sample started (%s)\n", CONFIG_BOARD);

	while (1) {
        static int cnt = 0;
        printk("SPI transaction: %i\n", cnt++);
		// Add SPI TX here
		k_msleep(1000);
	}

	return 0;
}
