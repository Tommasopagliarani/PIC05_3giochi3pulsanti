/*
  Cognome Nome: Pagliarani Tommaso      
  classe: 4A
  data: 30/03/2023
  
  Descrizione: Utilizzando il pulsante 1 si hanno tre effetti: Ogni volta che si preme viene incrementata 
 * la variabile c e viene eseguito il gioco assegnato al numero contenuto dalla variabile. Premendo il pulsante due 
 * i led si spengono. Con il tre si ha un altro effetto.
		
		
 */

#include "mcc_generated_files/mcc.h"
#define Display LATB

void PalleR();  
void Supercar();
void PariDispari();
void LampSfas (); 

char s; 
char c=0;

void main(void)
{
    Display=0b00000000;

    SYSTEM_Initialize();

    while (1)
    {
        //premendo il pulsante RA3 si spengono i led e c va a zero
        if(IO_RA3_GetValue()==1)
        {
            c=0;
            Display=0b00000000;
            
        }
        // Ogni volta che il pulsante RA2 viene premuto C incrementa, per ogni valore di c è assegnata la funzione di un gioco
        if(IO_RA2_GetValue()==1)
        {
            c++;  
        }
        if(c==1)
        {
            Supercar();  
        }
        if(c==2)
        {
            PalleR();  
        }
        if(c==3)
        {
            PariDispari();  
        }
        if(c==4)
        {
            c=0;  
        }
        // alla pressionde di RA4 si avvia un altro gioco e c va a 5
        if(IO_RA4_GetValue()==1)
        {
            c=5;
        }
        if(c==5)
        {
             LampSfas();
        }
    }
}
void Supercar()
{
    char i=0;  
    Display=0b00000001; 
    for(i=0;i<7;i++) 
    {
        Display=Display<<1;  
        __delay_ms(100); 
    }
    for(i=0;i<7;i++)  
    {
        Display=Display>>1;  
        __delay_ms(100);  
    }
}
void PalleR()
{
    char a=0b00010000;  
    char b=0b00001000;  
    char i=0;  
    for(i=0;i<3;i++)  
       {
            Display=a|b;  
            a=a<<1;  
            b=b>>1;  
            __delay_ms(50);  
       }
      for(i=0;i<3;i++)  
      {
            Display=a|b;  
            a=a>>1;  
            b=b<<1;  
            __delay_ms(50);  
      }  
}
void PariDispari()
{
    char i=0;  
        Display=0b00000010;  
        __delay_ms(200);  
        for(i=0;i<3;i++)  
        {
            Display=Display<<2;  
            __delay_ms(200); 
        }
        Display=0b01000000;  
        __delay_ms(200);  
        for(i=0;i<3;i++)  
        {
            Display=Display>>2;  
            __delay_ms(200);  
        }
}
//questa funzione non usa shift ma vengono inseriti direttamente i bit
void LampSfas ()  
{
    Display=0b01010101; 
    __delay_ms(200);
    Display=0b10101010;  
    __delay_ms(200);
}
/**
 End of File
**/