#include<stdio.h>
#include<stdlib.h>
#include"xil_printf.h"
#include"xparameters.h"
#include"xmuladd.h"

#define SIZE 16

XMuladd Instance;
int main()
{
  int a[SIZE],b[SIZE];
  int i,temp = 0;
  if(XMuladd_Initialize(&Instance,XPAR_XMULADD_0_DEVICE_ID)!= XST_SUCCESS){
    xil_printf( "Init Error！\n");
      return XST_FAILURE;
    }
  for(i = 0; i <SIZE; i ++){
	  a [i] = rand() & 0xffff;
	  b [i] = rand() & 0xffff;
      temp += a [i] + b [i];
      xil_printf("a [％2d] =％04x b [％2d] =％04x temp =％08x \n",i,a [i],i,b [i],temp);
    }
  XMuladd_Write_a_Words(&Instance,0,a,SIZE);
  XMuladd_Write_b_Words(&Instance,0,b,SIZE);

  XMuladd_Start(&Instance);
  while(XMuladd_IsDone(&Instance)== 0);

  if(temp == XMuladd_Get_return(&Instance)){
    xil_printf(" 0K \n ");
    }
  else {
    xil_printf(" NG \n ");
  }
  return 0;
}
