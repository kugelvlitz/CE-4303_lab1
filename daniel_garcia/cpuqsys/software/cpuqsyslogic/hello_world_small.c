#include "sys/alt_irq.h"

#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"

#include "system.h"

static unsigned int current_width = 0;
static unsigned int current_height = 0;
static unsigned int width = 0;
static unsigned int height = 2;

static unsigned int readyrsafilter = 0;

static unsigned int display1 = 0;
static unsigned int display2 = 0;
static unsigned int display3 = 0;
static unsigned int display4 = 0;
static unsigned int display5 = 0;
static unsigned int display6 = 0;

static unsigned int totalkeys = 2;
static unsigned int private_key1 = 0;
static unsigned int private_key2 = 0;

static unsigned int set_val = 0;
static unsigned int last_set_val = 0;

static unsigned int continue0 = 0;
static unsigned int last_continue0 = 0;

static unsigned int reveal = 0;
static unsigned int last_reveal = 0;

static unsigned int current_pixel_d = 0;


static unsigned btnleftright = 3;
static unsigned lastbtnleftright = 3;
static unsigned int display_selector = 0;

static unsigned btnupdown = 3;
static unsigned lastbtnupdown = 3;

static unsigned pixel1 = 66;
static unsigned pixel2 = 3;
static unsigned current_pixel = 0;

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



// Función para descifrar un número cifrado usando la clave privada (d, n)
static long descifrar_rsa(long a, long b, long m) {

	    long long x = 1, y = a;
	    while (b > 0)
	    {
	        if (b % 2 == 1)
	        {
	            x = (x * y) % m;
	        }
	        y = (y * y) % m;
	        b /= 2;
	    }
	    return x % m;

}

// Función para aplicar el filtro Laplaciano a un valor de píxel
static int filtro_laplaciano(int valor_pixel) {
    // Coeficientes del filtro Laplaciano
    int coeficientes[3][3] = {
        {0, -1, 0},
        {-1, 4, -1},
        {0, -1, 0}
    };

    int resultado = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Comprobar los límites del píxel
            if (valor_pixel + i >= 0 && valor_pixel + i <= 255 &&
                valor_pixel + j >= 0 && valor_pixel + j <= 255) {
                resultado += coeficientes[i + 1][j + 1] * (valor_pixel + i);
            }
        }
    }

    // Asegurarse de que el valor resultante esté en el rango de 0 a 255
    resultado = (resultado < 0) ? 0 : (resultado > 255) ? 255 : resultado;

    return resultado;
}

static void clean_displays(){
	display1 = 0;
	display2 = 0;
	display3 = 0;
	display4 = 0;
	display5 = 0;
	display6 = 0;
}


void static handlesetvalue(){

	set_val = IORD_ALTERA_AVALON_PIO_DATA(PIO_SET_VALUE_0_BASE);


	if((set_val != last_set_val) && (set_val == 1)){
		last_set_val = set_val;

		unsigned int decimal = display1 + display2*16 + display3*16*16 + display4*16*16*16;

		if(totalkeys == 2){
				totalkeys--;
				private_key1 = decimal;

				clean_displays();

				IOWR_ALTERA_AVALON_PIO_DATA(PIO_CURRENT_KEY_0_BASE, totalkeys);

			}

		else if(totalkeys == 1){
				totalkeys++;
				private_key2 = decimal;

				clean_displays();

				IOWR_ALTERA_AVALON_PIO_DATA(PIO_CURRENT_KEY_0_BASE, totalkeys);
			}
	}if(set_val == 0){
		last_set_val = 0;

	}

}

void static handlecontinue0(){

	continue0 = IORD_ALTERA_AVALON_PIO_DATA(PIO_CONTINUE_0_BASE);
	readyrsafilter = IORD_ALTERA_AVALON_PIO_DATA(PIO_READY_RSA_FILTER_0_BASE);


	if((continue0 != last_continue0) && (continue0 == 1) && (readyrsafilter == 0)){
		last_continue0 = continue0;

		if(current_pixel == 0){
			pixel1 = descifrar_rsa(pixel1,private_key1,private_key2);
			current_pixel_d = pixel1;
			unsigned int divv = pixel1/16;
			display5 = pixel1-16*divv;
			display6 = divv;

		}else if(current_pixel == 1){
			pixel2 = descifrar_rsa(pixel2,private_key1,private_key2);
			current_pixel_d = pixel2;
			unsigned int divv = pixel2/16;
			display5 = pixel2-16*divv;
			display6 = divv;
		}

		current_pixel++;
		current_height++;

	}else if(continue0 == 0){
		last_continue0 = 0;

	}else if((continue0 != last_continue0) && (continue0 == 1) && (readyrsafilter == 1)){

		last_continue0 = continue0;

		if(current_pixel == 0){
			pixel1 = filtro_laplaciano(pixel1);
			current_pixel_d = pixel1;
			unsigned int divv = pixel1/16;
			display5 = pixel1-16*divv;
			display6 = divv;

		}else if(current_pixel == 1){
			pixel2 = filtro_laplaciano(pixel2);
			current_pixel_d = pixel2;
			unsigned int divv = pixel2/16;
			display5 = pixel2-16*divv;
			display6 = divv;
		}

		current_pixel++;
		current_height++;
	}

}

static void reveal_private_key1(){

	display1 = private_key1%10;
	display2 = private_key1/10%10;
	display3 = private_key1/100%10;
	display4 = private_key1/1000%10;
	display5 = private_key1/10000%10;
}

static void reveal_private_key2(){

	display1 = private_key2%10;
	display2 = private_key2/10%10;
	display3 = private_key2/100%10;
	display4 = private_key2/1000%10;
	display5 = private_key2/10000%10;
}


static void reveal_pixel(){

	display1 = current_pixel_d%10;
	display2 = current_pixel_d/10%10;
	display3 = current_pixel_d/100%10;
}

static void handlereveal(){

	reveal = IORD_ALTERA_AVALON_PIO_DATA(PIO_REVEAL_DECIMAL_0_BASE);

	if((reveal != last_reveal) && ((reveal == 1)|| (reveal == 2) || (reveal == 3) )){

			last_reveal = reveal;

			if(reveal == 1){
				reveal_private_key1();
			}else if(reveal == 2){
				reveal_pixel();
			}else if(reveal == 3){
				reveal_private_key2();
			}
		}else if((reveal != last_reveal) && (reveal == 0)){
			last_reveal = reveal;
			clean_displays();
		}


}

void static handle_ready_rsa_filter(){

	if((current_width == width)&&(current_height==height)){
		IOWR_ALTERA_AVALON_PIO_DATA(PIO_READY_RSA_FILTER_0_BASE, 1);
		current_height = 0;
		current_width = 0;
		current_pixel = 0;
	}
}

void static show_current_selection(){

	if(display_selector == 0) IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, 1);
	if(display_selector == 1) IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, 2);
	if(display_selector == 2) IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, 4);
	if(display_selector == 3) IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, 8);
	if(display_selector == 4) IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, 16);
	if(display_selector == 5) IOWR_ALTERA_AVALON_PIO_DATA(PIO_LEDS_0_BASE, 32);

}


static void timer_isr(void *context)
{
	// No usamos esto
	(void) context;



	displaymap();
	handleleftrightbtn();
	handleupdownbnt();
	handlesetvalue();
	handlecontinue0();
	handlereveal();
	handle_ready_rsa_filter();
	show_current_selection();
	displaymap();


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
