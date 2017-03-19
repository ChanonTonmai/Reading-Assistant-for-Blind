/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */
#include <avr/delay.h> 
#include<string.h>
#include "pins_arduino.h"
//#include "SPI.h"
#include "SpeechSynthesis.h"

SpeechSynthesisClass SpeechSynthesis;


////////////////////////////////////////////////////////////////////


byte mm[]={ 0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x66,0x73,0x76,0x74,0x64,0x3D,0x7A,0x79,0x78,0x72,0x70,0x67,0x68,0x6E,0x6F,0x6D,0x6B,0x69,0x5B,0x5D};   


static byte aa[][5]={     
     /*0*/{mm[28],mm[25],mm[5],mm[1],mm[29]},
     /*1*/{mm[28],mm[25],mm[5],mm[2],mm[29]},
     /*2*/{mm[28],mm[25],mm[5],mm[3],mm[29]},
     /*3*/{mm[28],mm[25],mm[5],mm[4],mm[29]},
     /*4*/{mm[28],mm[25],mm[5],mm[5],mm[29]},
     /*5*/{mm[28],mm[25],mm[2],mm[3],mm[29]},
     /*6*/{mm[28],mm[25],mm[1],mm[7],mm[29]},
     /*7*/{mm[28],mm[25],mm[1],mm[9],mm[29]},
     /*8*/{mm[28],mm[25],mm[2],mm[0],mm[29]},
     /*9*/{mm[28],mm[25],mm[1],mm[1],mm[29]},
     /*10*/{mm[28],mm[25],mm[1],mm[4],mm[29]},
     /*11*/{mm[28],mm[25],mm[1],mm[5],mm[29]},
     /*12*/{mm[28],mm[25],mm[2],mm[2],mm[29]},
     /*13*/{mm[28],mm[25],mm[2],mm[4],mm[29]},
     /*14*/{mm[28],mm[25],mm[2],mm[5],mm[29]},
     /*15*/{mm[28],mm[25],mm[5],mm[6],mm[29]},
  };
static byte a[][4]={                            
       /*0*/{mm[28],mm[10],mm[0],mm[29]},
       /*1*/{mm[28],mm[10],mm[1],mm[29]},
       /*2*/{mm[28],mm[21],mm[0],mm[29]},
      /*3*/{mm[28],mm[21],mm[1],mm[29]},
      /*4*/{mm[28],mm[21],mm[2],mm[29]},
      /*5*/{mm[28],mm[22],mm[0],mm[29]},
      /*6*/{mm[28],mm[22],mm[1],mm[29]},
      /*7*/{mm[28],mm[22],mm[2],mm[29]},
      /*8*/{mm[28],mm[27],mm[0],mm[29]},
      /*9*/{mm[28],mm[22],mm[1],mm[29]},
      /*10*/{mm[28],mm[26],mm[0],mm[29]},
      /*11*/{mm[28],mm[26],mm[1],mm[29]},
      /*12*/{mm[28],mm[23],mm[0],mm[29]},
      /*13*/{mm[28],mm[23],mm[1],mm[29]},
      /*14*/{mm[28],mm[23],mm[2],mm[29]},
      /*15*/{mm[28],mm[19],mm[0],mm[29]},
      /*16*/{mm[28],mm[25],mm[3],mm[29]},
       /*17*/{mm[28],mm[25],mm[4],mm[29]},
       /*18*/{mm[28],mm[25],mm[7],mm[29]},
       /*19*/{mm[28],mm[25],mm[8],mm[29]},      
       /*20*/{mm[28],mm[19],mm[0],mm[29]},  
        /*20*/{mm[28],mm[18],mm[0],mm[29]},
       /*22*/{mm[28],mm[18],mm[1],mm[29]},
       /*23*/{mm[28],mm[17],mm[0],mm[29]},      
       /*24*/{mm[28],mm[17],mm[1],mm[29]},        
       /*25*/{mm[28],mm[16],mm[0],mm[29]},
       /*26*/{mm[28],mm[16],mm[0],mm[29]},   
        };  
 byte axa[][4]={
               /*1*/ {0xFD,0x00,0x01,0x02},//停止合成命令
               /*2*/ {0xFD,0x00,0x01,0x03},//暂停合成命令
               /*3*/ {0xFD,0x00,0x01,0x04},//恢复合成命令
               /*4*/ {0xFD,0x00,0x01,0x21},//状态查询命令
               /*5*/ {0xFD,0x00,0x01,0x88}//进入省电模式命令

              };

         /*0*/// char jin0[4]="[o";                  
         /*1*/ char jin1[4]="[p";              
         /*2*/ char jin2[4]="[s";                  ; 
         /*3*/ char jin3[4]="[t";                  ;
         /*4*/ char jin4[4]="[v";                  ;
         /*5*/ char jin5[4]="[d";                  ;
 
      

/////////////////////////////////////////////////////////////////////


void SpeechSynthesisClass::mvm(char sr[],byte cmd,char a[])
  { 
      

  char mu[2]="]"; 

       if(cmd<=5) 
      { 
      switch(cmd)
{
   // case 0:{  strcat(sr,jin0);break;}
    case 1:{  strcat(sr,jin1);break;}
    case 2:{  strcat(sr,jin2);break;}
    case 3:{  strcat(sr,jin3);break;}
    case 4:{  strcat(sr,jin4);break;}
    case 5:{  strcat(sr,jin5);break;}
    defualt:break;
}
     if(cmd!=5)
    {
      strcat(sr,a);
    }
      strcat(sr,mu);

      }
      else if(cmd==6)
      {
       strcat(sr,a);
      }
  
  }  



void SpeechSynthesisClass::Speaking(byte cmda ,byte cmdb,byte cmdc,byte c[])
     {
          
       byte i=0;
       byte xx[4]={0};
        if(cmda==0)
        {
        mking(cmdb,cmdc,c);
        }
        else if(cmda<=5)
        {
         // at(xx,d)
         for(i=0;i<4;i++);
          {
            xx[i]=axa[cmda][i];
          }
          Serial.write(xx,4);
        
        }
     }

void SpeechSynthesisClass::Espeaking(byte cmda ,byte cmdb,byte cmdc,byte c[])
     {
          
       byte i=0;
       byte xx[4]={0};
        if(cmda==0)
        {
        kxing(cmdb,cmdc,c);
        }
        else if(cmda<=5)
        {
         // at(xx,d)
         for(i=0;i<4;i++);
          {
            xx[i]=axa[cmda][i];
          }
          Serial.write(xx,4);
        
        }
     }

void SpeechSynthesisClass::kxing(byte a,byte b,byte c[])
{

byte bff[5]={0xFD,0x00,0x1F,0x01,0x00};
byte xm[5]={0},xxm[4]={0},xxmv[4]={0x5B,0x68,0x30,0x5D},kmg[]={0x5B,0x67,0x32,0x5D,0x5B,0x68,0x30,0x5D,0x5B,0x6E,0x31,0x5D,0x5B,0x6F,0x31,0x5D};
int x;

          if(b==4)
	  {
	    at(xxm,b); 
	 	if(a<=15)
           {

			 att(xm,a);
            // x=strlen(c)+4+5+2+4;

             x=c[0];
             x=c[1]|(x<<8);
             x=x-2+4+5+2+4;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xxmv,4);
             Serial.write(xm,5);
             Serial.write(xxm,4);
             Serial.write(&c[2],x-2);
             //Serial.println(c);
			   
			 

            }
       else if(a<=19)
           {

     
            at(xm,a);

             //x=strlen(c)+4+4+2+4;
             
             x=c[0];
             x=c[1]|(x<<8);
             x=x-2+4+4+2+4;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
			 Serial.write(xxmv,4);
             Serial.write(xm,4);
             Serial.write(xxm,4);
             Serial.write(&c[2],x-2);
             //Serial.println(c);
            }

	  }
	   else if(b==5)
	  {
	  at(xxm,b); 
	   if(a<=15)
           {


			 att(xm,a);
             x=c[0];
             x=c[1]|(x<<8);
             x=x-2+4+5+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,5);
             Serial.write(xxm,4);
             Serial.write(&c[2],x-2);
             //Serial.println(c);
			   
			 
            }
         else if(a<=19)
           {

            at(xm,a);

            // x=strlen(c)+4+4+2;
              x=c[0];
             x=c[1]|(x<<8);
             x=x-2+4+4+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,4);
             Serial.write(xxm,4);
            Serial.write(&c[2],x-2);
             //Serial.println(c);
            }
	  
	  }
	  else if(b==6)
	  {
	  at(xxm,b); 
	   if(a<=15)
           {
	     att(xm,a);
            // x=strlen(c)+4+5+2;
              x=c[0];
             x=c[1]|(x<<8);
             x=x-2+4+5+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,5);
             Serial.write(xxm,4);
            Serial.write(&c[2],x-2);
             //Serial.println(c);
			   
	   }

           // }
         else if(a<=19)
           {
            at(xm,a);
             x=c[0];
             x=c[1]|(x<<8);
             x=x-2+4+4+2;
            // x=strlen(c)+4+4+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,4);
             Serial.write(xxm,4);
          Serial.write(&c[2],x-2);
             //Serial.println(c);
            }
	  
	  }
         else if(b==7)
	  {
	  at(xxm,b); 
	   if(a<=15)
           {
	     att(xm,a);
            // x=strlen(c)+4+5+2;
              x=c[0];
             x=c[1]|(x<<8);
             x=x-2+4+5+2+12;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,5);
             //Serial.write(xxm,4);
             Serial.write(kmg,16);
            Serial.write(&c[2],x-2);
             //Serial.println(c);
			   
	   }

           // }
         else if(a<=19)
           {
            at(xm,a);
             x=c[0];
             x=c[1]|(x<<8);
             x=x-2+4+4+2+12;
            // x=strlen(c)+4+4+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,4);
            Serial.write(kmg,16);
          Serial.write(&c[2],x-2);
             //Serial.println(c);
            }
	  
	  }

/*
          if((b<=15))
             {
                at(xxm,b);
              }
          else if(b>15)
             {
               at(xxm,b+4);
               
             }


          if(a<=15)
           {
  
             att(xm,a);
             x=strlen(c)+4+5+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,5);
             Serial.write(xxm,4);
             Serial.println(c);
            }
         else if(a<=19)
           {
            at(xm,a);

             x=strlen(c)+4+4+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,4);
             Serial.write(xxm,4);
            Serial.println(c);

            }*/

}


void SpeechSynthesisClass::king(byte a,byte b,char c[])
{
byte bff[5]={0xFD,0x00,0x1F,0x01,0x00};
byte xm[5]={0},xxm[4]={0};
int x;
/**/
          if((b<=15))
             {
                at(xxm,b);
              }
          else if(b>15)
             {
               at(xxm,b+4);
               
             }


          if(a<=15)
           {
  
             att(xm,a);
             x=strlen(c)+4+5+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,5);
             Serial.write(xxm,4);
             Serial.println(c);
            }
         else if(a<=19)
           {
            at(xm,a);

             x=strlen(c)+4+4+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,4);
             Serial.write(xxm,4);
             Serial.println(c);

            }

}
void SpeechSynthesisClass::at(byte x[],byte n)
{
   static byte i=0;
 for(i=0;i<4;i++)
 {
   x[i]=a[n][i];
 }
}

void SpeechSynthesisClass::att(byte xx[],byte n)
{

   

  static byte i=0;
 for(i=0;i<5;i++)
 {
   xx[i]=aa[n][i];
 }
}


void SpeechSynthesisClass::mking(byte a,byte b,byte c[])
{
byte bff[5]={0xFD,0x00,0x1F,0x01,0x00};
byte xm[5]={0},xxm[4]={0},xxmv[4]={0x5B,0x68,0x30,0x5D};
int x;

          if((b<=15))
             {
                at(xxm,b);
              }
          else if(b>15)
             {
               at(xxm,b+4);
               
             }

 
          if(b==4)
           {
            if(a<=15)
           {
  
             att(xm,a);
             x=c[0];
             x=c[1]|(x<<8);
             x=x-2+4+5+2+4;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
            Serial.write(xxmv,4);
             Serial.write(xm,5);             
             Serial.write(xxm,4);
            
             x=c[0];
             x=c[1]|(x<<8);
             Serial.write(&c[2],x-2);
             
            // Serial.println(c);
            }
         else if(a<=19)
           {
            at(xm,a);
            x=c[0];
            x=c[1]|(x<<8);

             x=x-2+4+4+2+4;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
            Serial.write(xxmv,4);
             Serial.write(xm,4);         
             Serial.write(xxm,4);
             x=c[0];
             x=c[1]|(x<<8);
             Serial.write(&c[2],x-2);
            //Serial.println(c);

            }

           }
         else
         {
          if(a<=15)
           {
  
             att(xm,a);
             x=c[0];
             x=c[1]|(x<<8);
             x=x-2+4+5+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             
             Serial.write(xm,5);
             Serial.write(xxm,4);
            
            x=c[0];
            x=c[1]|(x<<8);
             Serial.write(&c[2],x-2);
             
            // Serial.println(c);
            }
         else if(a<=19)
           {
            at(xm,a);
            x=c[0];
             x=c[1]|(x<<8);

             x=x-2+4+4+2;
             bff[2]=x;
             bff[1]=x>>8;
             Serial.write(bff,5);
             Serial.write(xm,4);
             Serial.write(xxm,4);
            x=c[0];
            x=c[1]|(x<<8);
             Serial.write(&c[2],x-2);
            //Serial.println(c);

            }
         }

}


void SpeechSynthesisClass::English(byte ax[],byte cmd,char c[])
{
  int i=0;
  int v=0;
  char x[20]="jin";
  v=ax[0];
  v=((v<<8)|ax[1]);
 if(cmd==6)
{
 for(i=0;i< strlen(c);i++)
 {
  ax[i+v]=(byte)c[i];
 
 }
 v=v+strlen(c);
ax[1]=v;
ax[0]=v>>8;
}
else if(cmd<=5)
{
mvm(x,cmd,c);
 for(i=0;i< strlen(x);i++)
 {
  ax[i+v]=(byte)x[i+3];
 
 }
 v=v+strlen(x)-3;
ax[1]=v;
ax[0]=v>>8;
}

}














void SpeechSynthesisClass::Chinese_english(byte ax[],byte bm[],int n,byte cmd,char c[])
{
  int i=0;
  int v=0;
  char x[20]="jin";
  v=ax[0];
  v=((v<<8)|ax[1]);
if(cmd==6)
{
    for(i=0;i<n;i++)
 {
  ax[i+v]=bm[i];
 }
 //fs=sizeof(bm);
 v=v+n;
ax[1]=v;
ax[0]=v>>8;
}
else if(cmd==7)
{
 for(i=0;i< strlen(c);i++)
 {
  ax[i+v]=(byte)c[i];
 
 }
 v=v+strlen(c);
ax[1]=v;
ax[0]=v>>8;
}
else if(cmd<=5)
{
mvm(x,cmd,c);
 for(i=0;i< strlen(x);i++)
 {
  ax[i+v]=(byte)x[i+3];
 
 }
 v=v+strlen(x)-3;
ax[1]=v;
ax[0]=v>>8;
}

}


void SpeechSynthesisClass::buf_init(byte ay[])
{
  ay[0]=0x00;
  ay[1]=0x02;
  
}
void SpeechSynthesisClass::Em_init(char ay[])
{
  ay[0]=0x00;
  ay[1]=0x02;
  
}


