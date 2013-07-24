#include <16F877a.h>  // inclui arquivo de bibliotecas do dispositivo
#device adc=10      // essa diretiva precisa vir imediatamente abaixo do include do arquivo do processador
#use delay (clock = 20000000)
#fuses HS, NOWDT, NOPROTECT, NOPUT, NOBROWNOUT, NOLVP

#use rs232(baud=115200, xmit=PIN_C6, rcv=PIN_C7, parity = N, ERRORS)

#int_rda
void reception ()
{
   char temp;
   temp = getc();
   printf("Recebeu: %s", temp); //configura como mestre
}

void main(void)
{
    short int bt1;
    short int bt2;
    short int bt3;
    
    /* Habilita a interrupção serial */
   enable_interrupts(GLOBAL);
   enable_interrupts(int_rda);
   delay_ms(1000);
   
   printf("AT+ZV DefaultLocalName modBT2");
   putc(0x0d); //CR
   putc(0x0a); //new line
   
   while(true)
   {
      bt1 = input(pin_c1);
      bt2 = input(pin_c2);
      bt3 = input(pin_c3);
      
         if (!bt1)
         {
              delay_ms(1000);       
              output_high (pin_c0);
               printf("AT+ZV Bond 0011e0036ecc 1111"); //configura como mestre
               putc(0x0d); //CR
               putc(0x0a); //new line
         }
         if (!bt2)
         {
              delay_ms(1000);
                printf("Enviando Dados..."); //configura como mestre
               output_high (pin_c0);
         }
   }
}