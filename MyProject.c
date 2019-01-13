
  unsigned char *arr[9]; int i=0;

  void newline()
{

  Uart1_write ('\r');
  Uart1_write ('\n');
}
  void ReadStatue()
  {
  if(portb.f0==1)
   arr[0]="SW1:ON & ";
  else if(portb.f0==0)
   arr[0]="SW1:OFF & ";
  if(portb.f1==1)
   arr[1]="SW2:ON & ";
  else  if(portb.f1==0)
   arr[1]="SW2:OFF & ";
  if(portb.f2==1)
   arr[2]="SW3:ON & ";
  else  if(portb.f2==0)
   arr[2]="SW3:OFF & ";
  if(portb.f3==1)
   arr[3]="SW4:ON & ";
  else  if(portb.f3==0)
   arr[3]="SW4:OFF & ";
  if(portb.f4==1)
   arr[4]="SW5:ON & ";
  else if(portb.f4==0)
   arr[4]="SW5:OFF & ";
  if(portb.f5==1)
   arr[5]="SW6:ON & ";
  else  if(portb.f5==0)
   arr[5]="SW6:OFF & ";
  if(portb.f6==1)
   arr[6]="SW7:ON & ";
  else if(portb.f6==0)
   arr[6]="SW7:OFF & ";
  if(portb.f7==1)
   arr[7]="SW8:ON & ";
  else  if(portb.f7==0)
   arr[7]="SW8:OFF  ";
  }


void main() {


trisb=0xff; 
trisc=0x01;
portc=0;

Uart1_Init(9600);
delay_ms(50);
while(1){
  while(portc.f0==1)
  {
   ReadStatue();
   uart1_write_text("AT+CMGS=\"01068965228\"");
  Uart1_write (10);
   for(i=0;i<8;i++)
   {
    uart1_write_text (arr[i]);
    }
   uart1_write(0X1A);

   while(portc.f0==1);
  }
  }
}