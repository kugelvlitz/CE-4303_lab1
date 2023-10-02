#include "sys/alt_irq.h"

#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"

#include "system.h"

static unsigned int display1 = 0;
static unsigned int display2 = 0;
static unsigned int display3 = 0;
static unsigned int display4 = 0;
static unsigned int display5 = 0;
static unsigned int display6 = 0;

static unsigned int temp_display = 16;

static unsigned btnleftright = 3;
static unsigned lastbtnleftright = 3;
static unsigned int display_selector = 0;

static unsigned btnupdown = 3;
static unsigned lastbtnupdown = 3;

static unsigned int continue0 = 0;
static unsigned int reset0 = 0;
static unsigned int set_value = 0;
static unsigned int auto_manual = 0;


// Mapeo para los displays
static void displaymap(){

	if (display1 == 0) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 64);
	if (display1 == 1) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 121);
	if (display1 == 2) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 36);
	if (display1 == 3) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 48);
	if (display1 == 4) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 25);
	if (display1 == 5) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 18);
	if (display1 == 6) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 2);
	if (display1 == 7) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 120);
	if (display1 == 8) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 0);
	if (display1 == 9) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 16);
	if (display1 == 10) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 8);
	if (display1 == 11) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 3);
	if (display1 == 12) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 70);
	if (display1 == 13) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 33);
	if (display1 == 14) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 6);
	if (display1 == 15) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 14);
	if (display1 == 16) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 127);

	if (display2 == 0) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 64);
	if (display2 == 1) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 121);
	if (display2 == 2) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 36);
	if (display2 == 3) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 48);
	if (display2 == 4) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 25);
	if (display2 == 5) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 18);
	if (display2 == 6) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 2);
	if (display2 == 7) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 120);
	if (display2 == 8) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 0);
	if (display2 == 9) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 16);
	if (display2 == 10) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 8);
	if (display2 == 11) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 3);
	if (display2 == 12) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 70);
	if (display2 == 13) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 33);
	if (display2 == 14) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 6);
	if (display2 == 15) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 14);
	if (display2 == 16) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 127);

	if (display3 == 0) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 64);
	if (display3 == 1) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 121);
	if (display3 == 2) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 36);
	if (display3 == 3) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 48);
	if (display3 == 4) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 25);
	if (display3 == 5) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 18);
	if (display3 == 6) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 2);
	if (display3 == 7) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 120);
	if (display3 == 8) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 0);
	if (display3 == 9) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 16);
	if (display3 == 10) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 8);
	if (display3 == 11) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 3);
	if (display3 == 12) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 70);
	if (display3 == 13) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 33);
	if (display3 == 14) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 6);
	if (display3 == 15) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 14);
	if (display3 == 16) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 127);

	if (display4 == 0) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 64);
	if (display4 == 1) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 121);
	if (display4 == 2) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 36);
	if (display4 == 3) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 48);
	if (display4 == 4) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 25);
	if (display4 == 5) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 18);
	if (display4 == 6) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 2);
	if (display4 == 7) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 120);
	if (display4 == 8) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 0);
	if (display4 == 9) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 16);
	if (display4 == 10) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 8);
	if (display4 == 11) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 3);
	if (display4 == 12) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 70);
	if (display4 == 13) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 33);
	if (display4 == 14) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 6);
	if (display4 == 15) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 14);
	if (display4 == 16) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 127);

	if (display5 == 0) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 64);
	if (display5 == 1) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 121);
	if (display5 == 2) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 36);
	if (display5 == 3) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 48);
	if (display5 == 4) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 25);
	if (display5 == 5) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 18);
	if (display5 == 6) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 2);
	if (display5 == 7) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 120);
	if (display5 == 8) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 0);
	if (display5 == 9) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 16);
	if (display5 == 10) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 8);
	if (display5 == 11) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 3);
	if (display5 == 12) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 70);
	if (display5 == 13) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 33);
	if (display5 == 14) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 6);
	if (display5 == 15) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 14);
	if (display5 == 16) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 127);

	if (display6 == 0) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 64);
	if (display6 == 1) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 121);
	if (display6 == 2) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 36);
	if (display6 == 3) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 48);
	if (display6 == 4) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 25);
	if (display6 == 5) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 18);
	if (display6 == 6) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 2);
	if (display6 == 7) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 120);
	if (display6 == 8) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 0);
	if (display6 == 9) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 16);
	if (display6 == 10) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 8);
	if (display6 == 11) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 3);
	if (display6 == 12) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 70);
	if (display6 == 13) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 33);
	if (display6 == 14) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 6);
	if (display6 == 15) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 14);
	if (display6 == 16) IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 127);

}

static void verify_reset(){
	if(reset0 == 0){
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY1_0_BASE, 127);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY2_0_BASE, 127);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY3_0_BASE, 127);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY4_0_BASE, 127);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY5_0_BASE, 127);
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_DISPLAY6_0_BASE, 127);
	}
}

static void verify_leds(){

	if(display1 == 16){
		display1 = 0;
	}

	if(display2 == 16){
		display2 = 0;
	}

	if(display3 == 16){
		display3 = 0;
	}

	if(display4 == 16){
		display4 = 0;
	}

	if(display5 == 16){
		display5 = 0;
	}

	if(display6 == 16){
		display6 = 0;
	}
}

void static plus_leds(){
	display1++;
	display2 = display1+1;
	display3 = display2+1;
	display4 = display3+1;
	display5 = display4+1;
	display6 = display5+1;

}

void static add_display_in_position(){
	if((display_selector == 0) && (display1 <= 14)){
		display1++;
	}else if((display_selector == 1) && (display2 <= 14)){
		display2++;
	}else if((display_selector == 2) && (display3 <= 14)){
		display3++;
	}else if((display_selector == 3) && (display4 <= 14)){
		display4++;
	}else if((display_selector == 4) && (display5 <= 14)){
		display5++;
	}else if((display_selector == 5) && (display6 <= 14)){
		display6++;
	}
}

void static sub_display_in_position(){
	if((display_selector == 0) && (display1 >= 1)){
		display1--;
	}else if((display_selector == 1) && (display2 >= 1)){
		display2--;
	}else if((display_selector == 2) && (display3 >= 1)){
		display3--;
	}else if((display_selector == 3) && (display4 >= 1)){
		display4--;
	}else if((display_selector == 4) && (display5 >= 1)){
		display5--;
	}else if((display_selector == 5) && (display6 >= 1)){
		display6--;
	}
}

void static handleleftrightbtn(){

	btnleftright = IORD_ALTERA_AVALON_PIO_DATA(PIO_LEFT_RIGHT_0_BASE);
	if((btnleftright != lastbtnleftright) && ((btnleftright == 2)|| (btnleftright == 1))){

		lastbtnleftright = btnleftright;

		if((btnleftright == 1) && (display_selector >= 1)){

			display_selector--;

		}else if((btnleftright == 2) && (display_selector <= 4)){

			display_selector++;

		}

	}if(btnleftright == 3){
		lastbtnleftright = 3;
	}
}

void static handleupdownbnt(){
	btnupdown = IORD_ALTERA_AVALON_PIO_DATA(PIO_UP_DOWN_0_BASE);
	if((btnupdown != lastbtnupdown) && ((btnupdown == 2)|| (btnupdown == 1))){

		lastbtnupdown = btnupdown;

		if(btnupdown == 1){
			sub_display_in_position();
		}else if(btnupdown == 2){
			add_display_in_position();
		}
	}if(btnupdown == 3){
		lastbtnupdown = 3;
	}
}

void static verify_set_value(){
	set_value = IORD_ALTERA_AVALON_PIO_DATA(PIO_SET_VALUE_0_BASE);
	if(set_value == 1){
		display4 = display1;
		display5 = display2;
		display6 = display3;

	}else{
		display4 = 0;
		display5 = 0;
		display6 = 0;

	}
}

void static show_current_display(){

	if(display_selector == 0){
		if(temp_display == 16){
			temp_display = display1;
			display1 = 16;
		}else{
			display1 = temp_display;
			temp_display = 16;
		}
	}else if(display_selector == 1){
		if(temp_display == 16){
			temp_display = display2;
			display2 = 16;
		}else{
			display2 = temp_display;
			temp_display = 16;
		}
	}else if(display_selector == 2){
		if(temp_display == 16){
			temp_display = display3;
			display3 = 16;
		}else{
			display3 = temp_display;
			temp_display = 16;
		}
	}else if(display_selector == 3){
		if(temp_display == 16){
			temp_display = display4;
			display4 = 16;
		}else{
			display4 = temp_display;
			temp_display = 16;
		}
	}else if(display_selector == 4){
		if(temp_display == 16){
			temp_display = display5;
			display5 = 16;
		}else{
			display5 = temp_display;
			temp_display = 16;
		}
	}else if(display_selector == 5){
		if(temp_display == 16){
			temp_display = display6;
			display6 = 16;
		}else{
			display6 = temp_display;
			temp_display = 16;
		}
	}

}



static void timer_isr(void *context)
{

	(void) context; //ignore
	IOWR_ALTERA_AVALON_PIO_DATA(PIO_READY_RSA_FILTER_0_BASE, 3);
	//plus_leds();
	//verify_leds();
	displaymap();
	handleleftrightbtn();
	handleupdownbnt();
	show_current_display();
	//verify_reset();

	// Clean timer status
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
}

/*static void timer_isr100ms(void *context){

	(void) context; //ignore



	//verify_set_value();

	// Clean timer status
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_100MS_0_BASE, 0);
}*/

int main()
{
	//Assign IRQ signal with ISR
	alt_ic_isr_register(
			TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID,
			TIMER_0_IRQ,
			timer_isr,
			NULL,
			NULL);

	//Enable periodic IRQS generated by timer
	IOWR_ALTERA_AVALON_TIMER_CONTROL(
			TIMER_0_BASE,
			  ALTERA_AVALON_TIMER_CONTROL_ITO_MSK
			| ALTERA_AVALON_TIMER_CONTROL_CONT_MSK);


	//Assign IRQ signal with ISR
/*		alt_ic_isr_register(
				TIMER_100MS_0_IRQ_INTERRUPT_CONTROLLER_ID,
				TIMER_100MS_0_IRQ,
				timer_isr100ms,
				NULL,
				NULL);

		//Enable periodic IRQS generated by timer
		IOWR_ALTERA_AVALON_TIMER_CONTROL(
				TIMER_100MS_0_BASE,
				  ALTERA_AVALON_TIMER_CONTROL_ITO_MSK
				| ALTERA_AVALON_TIMER_CONTROL_CONT_MSK);*/




	while (1);
}
