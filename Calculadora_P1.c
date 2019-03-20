#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, /*NOMCLR,*/ STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)
long  valor1 = 0, valor2 = 0, resultado = 0;

void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_a(0xcf);
   set_tris_b(0xff);
   set_tris_c(0x00);
   set_tris_d(0x80);
   set_tris_e(0xf);
   int op=0;
   while(1){
       valor1 = input_a();
       valor2 = input_b();
   
        if(input(PIN_E0) ==1)
           op=1;
        if(input(PIN_E1) ==1)
           op=2;
        if(input(PIN_E2) ==1)
           op=3;
        if(input(PIN_D7) ==1)
           op=4;
        
        if(input(PIN_E0)==1 && op==1){
           resultado = valor1 + valor2; 
           op=0;
      }
        if(input(PIN_E1)==1 && op==2){
           resultado = valor1 - valor2;
           op=0;
     }
        if(input(PIN_E2)==1 && op==3){
           resultado = valor1 * valor2;
           op=0;
   }
          if(input(PIN_D7)==1 && op==4){
       if(input_b()!=0){
          resultado= valor1/ valor2;
          op=0;
       }
           
           
   }
   output_c(resultado);
   output_d(resultado>>8);
   }
   
}
