/* main.c

   This file written 2024 by Artur Podobas and Pedro Antunes

   For copyright and licensing, see file COPYING */


/* Below functions are external and found in other files. */
extern void print(const char*);
extern void print_dec(unsigned int);
extern void display_string(char*);
extern void time2string(char*,int);
extern void tick(int*);
extern void delay(int);
extern int nextprime( int );
extern void enable_interrupt(void); 

int mytime = 0x5957;
char textstring[] = "text, more text, and even more text!";
int hour_counter = 23;
volatile unsigned int* timer_address = (volatile unsigned int*) 0x04000020;
int timeoutcount = 0;
int prime = 1234567;

void set_displays(int display_number, int value);

void restart_timer(void){
  timer_address += 2; // periodl register
  *timer_address = 0b1100011010111111;
  timer_address += 1; // periodh register
  *timer_address = 0b101101; // 100 ms combined

  timer_address-=2; // control register
  *timer_address = 0b0101; // start timer and enable ITO

  timer_address--; // cancel offset
}

/* Below is the function that will be called when an interrupt is triggered. */
void handle_interrupt(unsigned cause) 
{
  if(timeoutcount == 10) {
    if((mytime & 0xFFFF) == 0){
      hour_counter++;
    }
    set_displays(0, mytime & 0x000F);
    set_displays(1, (mytime & 0x00F0) >> 4);
    set_displays(2, (mytime & 0x0F00) >> 8);
    set_displays(3, (mytime & 0xF000) >> 12);
    set_displays(4, hour_counter % 10);
    set_displays(5, hour_counter / 10);
    
    tick( &mytime );

    timeoutcount = 0;
  }
  timeoutcount++;
  *timer_address = 0b00;
  restart_timer();
}

/* Add your code here for initializing interrupts. */
void labinit(void)
{
  restart_timer();
  enable_interrupt();
}

void set_leds(int led_mask) {
  volatile int* led_address = (volatile int*) 0x04000000;

  *led_address = led_mask;
}

void set_displays(int display_number, int value) {
  volatile int* display_address = (volatile int*) (0x04000050 + 0x10*display_number);

  switch (value) {
    case 1: // display 1
      *display_address = 0b11111001;
      break;
    case 2: // display 2
      *display_address = 0b10100100;
      break;
    case 3: // display 3
      *display_address = 0b10110000;
      break;
    case 4: //display 4
      *display_address = 0b10011001;
      break;
    case 5: // display 5
      *display_address = 0b10010010;
      break;
    case 6: // display 6
      *display_address = 0b10000010;
      break;
    case 7: // display 7
      *display_address = 0b11111000;
      break;
    case 8: // display 8
      *display_address = 0b10000000;
      break;
    case 9: // display 9
      *display_address = 0b10010000;
      break;
    case 0: // display 0
      *display_address = 0b11000000;
      break;
    default:
      *display_address = 0b01111111;
      break;
  }
}

int get_sw(void) {
  volatile int* switch_address = (volatile int*) 0x04000010;
  int switch_status = *switch_address & 0b1111111111;
  return switch_status;
}

int get_btn(void) {
  volatile int* btn2_address = (volatile int*) 0x040000d0;
  int btn2_status = *btn2_address & 1;
  return btn2_status;
}

/* Your code goes into main as well as any needed functions. */
int main ( void ) {
labinit();
  while (1) {
    print("Prime: ");
    prime = nextprime( prime );
    print_dec( prime );
    print("\n");
  }
}



