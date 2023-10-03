#include "sys/alt_irq.h"

#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"

#include "system.h"

static unsigned leds = 0;

static void timer_isr(void *context)
{
	// No usamos esto
	(void) context;

	leds = leds << 1 | (IORD_ALTERA_AVALON_PIO_DATA(PIO_CONTINUE_0_BASE) & 1);
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, leds);

	// Limpiamos status.TO
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
}

int main()
{
	// Asociamos la señal de IRQ con el ISR
	alt_ic_isr_register(
			TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID,
			TIMER_0_IRQ,
			timer_isr,
			NULL,
			NULL);

	// Habilitamos IRQs periódicas generadas por el timer
	IOWR_ALTERA_AVALON_TIMER_CONTROL(
			TIMER_0_BASE,
			  ALTERA_AVALON_TIMER_CONTROL_ITO_MSK
			| ALTERA_AVALON_TIMER_CONTROL_CONT_MSK);

	while (1);
}
