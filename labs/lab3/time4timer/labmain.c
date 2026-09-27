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

int mytime = 0x5957;
char textstring[] = "text, more text, and even more text!";
int hour_counter = 0;
volatile unsigned int* timer_address = (volatile int*) 0x04000020;

/* Below is the function that will be called when an interrupt is triggered. */
void handle_interrupt(unsigned cause) 
{}

/* Add your code here for initializing interrupts. */
void labinit(void)
{
  timer_address += 2; // periodl register
  *timer_address = 29999 // 100 ms

  timer_address--: // control register
  *timer_address = 0b0100; // start timer

  timer_address--; // cancel offset
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
int main() {
  // Call labinit()
  labinit();

  // start sequence
  for(int i = 0; i <= 15; i++) {
    if (*timer_address & 0b01){
      set_leds(i);
      *timer_address = 0;
    }
  }

  // Enter a forever loop
  while (1) {
    unsigned short button_pressed = get_btn();
    unsigned short toggle_status = get_sw();

    if (*timer_address & 0b01) {
      time2string( textstring, mytime ); // Converts mytime to string
      display_string( textstring ); //Print out the string 'textstring'
      tick( &mytime );     // Ticks the clock once
    
      if(mytime == 0){
        hour_counter++;
      }
      display_value(0, mytime & 0x0001)
      display_value(1, mytime & 0x0010)
      display_value(2, mytime & 0x0100)
      display_value(3, mytime & 0x1000)
      display_value(4, hour_counter % 10)
      display_value(5, hour_counter / 10)

      if(button_pressed) {
        int target_display = toggle_status >> 8;
        
        int display_value = toggle_status & 0b0000111111;

        switch(target_display) {
          case 1: // seconds-pair
            mytime = (mytime & 0x1110) & ((display_value % 10) & 0x0001)
            set_displays(0, display_value % 10);
            mytime = (mytime & 0x1101) & ((display_value / 10) & 0x0010)
            set_displays(1, display_value/10);
            break;
          case 2: // minutes-pair
            mytime = (mytime & 0x1011) & ((display_value % 10) & 0x0100)
            set_displays(2, display_value % 10);
            mytime = (mytime & 0x0111) & ((display_value / 10) & 0x1000)
            set_displays(3, display_value/10);
            break;
          case 3: // hours-pair
            hour_count = display_value;
            set_displays(4, display_value % 10);
            set_displays(5, display_value/10);
            break;  
        }
          
        if((toggle_status & 0b0010000000) == 0b0010000000){
          break;
        } 
      }

      *timer_address = 0;
    }
  }
}


