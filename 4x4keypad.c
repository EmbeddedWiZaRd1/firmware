#include <stdint.h>
#include<stdio.h>

void delay(void)
{
	for(uint32_t i =0 ; i < 300000 ; i++);

}

int main(void)
{
	uint32_t volatile *const pClkCntrlreg = (uint32_t*)0x40023830; //RCC register
	uint32_t volatile *const pPortDMode = (uint32_t*)0x40020C00; //GPIOD mode registers
	uint32_t volatile *const pInPutDataReg=(uint32_t*)(0x40020C00+0x10);
	uint32_t volatile *const pOutPutDataReg=(uint32_t*)(0x40020C00+0x14);
	uint32_t volatile *const pPullupdownReg=(uint32_t*)(0x40020C00+0x0C);


	//Enable peripheral clock of GPIOD
	*pClkCntrlreg |=(1<<3);

	//COnfiguring PD0,PD1,PD2,PD3 as output
	*pPortDMode &= ~(0xFF); //cleared all the fields
	*pPortDMode |=0x55;  //mode 0 1 2 3 set to 01010101=0x55-set

	//COnfiguring PD8,PD9,PD10,PD11 as input
	*pPortDMode &= ~(0xFF <<16);

	////COnfiguring internal pullup registors for PD8,PD9,PD10,PD11 as input
	*pPullupdownReg	&= ~(0xFF<<16);
	*pPullupdownReg |=(0x55<<16);


	while(1)
	{
	//make all rows high
	*pOutPutDataReg |=(0x0F);

	//make r0 low i.e pD0 low
	*pOutPutDataReg &= ~(1<<0);

	//scan columns
	if(!(*pInPutDataReg & ( 1 << 8))){
	    	//key is pressed
	    	delay();
	    	printf("1\n");
	    }

	    //check C2(PD9) low or high
	    if(!(*pInPutDataReg & ( 1 << 9))){
	    	//key is pressed
	    	delay();
	    	printf("2\n");
	    }

	    //check C3(PD10) low or high
	    if(!(*pInPutDataReg & ( 1 << 10))){
	    	//key is pressed
	    	delay();
	    	printf("3\n");
	    }

	    //check C4(PD11) low or high
	    if(!(*pInPutDataReg & ( 1 << 11))){
	    	//key is pressed
	    	delay();
	    	printf("A\n");
	    }

	    //make all rows HIGH
	        *pOutPutDataReg |= 0x0f;
	       //make R2 LOW(PD1)
	       *pOutPutDataReg &= ~( 1 << 1);

	       //scan the columns
	       //check C1(PD8) low or high
	       if(!(*pInPutDataReg & ( 1 << 8))){
	       	//key is pressed
	       	delay();
	       	printf("4\n");
	       }

	       //check C2(PD9) low or high
	       if(!(*pInPutDataReg & ( 1 << 9))){
	       	//key is pressed
	       	delay();
	       	printf("5\n");
	       }

	       //check C3(PD10) low or high
	       if(!(*pInPutDataReg & ( 1 << 10))){
	       	//key is pressed
	       	delay();
	       	printf("6\n");
	       }

	       //check C4(PD11) low or high
	       if(!(*pInPutDataReg & ( 1 << 11))){
	       	//key is pressed
	       	delay();
	       	printf("B\n");
	       }

	       //make all rows HIGH
	        *pOutPutDataReg |= 0x0f;
	       //make R3 LOW(PD2)
	       *pOutPutDataReg &= ~( 1 << 2);

	       //scan the columns
	       //check C1(PD8) low or high
	       if(!(*pInPutDataReg & ( 1 << 8))){
	       	//key is pressed
	       	delay();
	       	printf("7\n");
	       }

	       //check C2(PD9) low or high
	       if(!(*pInPutDataReg & ( 1 << 9))){
	       	//key is pressed
	       	delay();
	       	printf("8\n");
	       }

	       //check C3(PD10) low or high
	       if(!(*pInPutDataReg & ( 1 << 10))){
	       	//key is pressed
	       	delay();
	       	printf("9\n");
	       }

	       //check C4(PD11) low or high
	       if(!(*pInPutDataReg & ( 1 << 11))){
	       	//key is pressed
	       	delay();
	       	printf("C\n");
	       }

	       //make all rows HIGH
	        *pOutPutDataReg |= 0x0f;
	       //make R4 LOW(PD2)
	       *pOutPutDataReg &= ~( 1 << 3);

	       //scan the columns
	       //check C1(PD8) low or high
	       if(!(*pInPutDataReg & ( 1 << 8))){
	       	//key is pressed
	       	delay();
	       	printf("*\n");
	       }

	       //check C2(PD9) low or high
	       if(!(*pInPutDataReg & ( 1 << 9))){
	       	//key is pressed
	       	delay();
	       	printf("0\n");
	       }

	       //check C3(PD10) low or high
	       if(!(*pInPutDataReg & ( 1 << 10))){
	       	//key is pressed
	       	delay();
	       	printf("#\n");
	       }

	       //check C4(PD11) low or high
	       if(!(*pInPutDataReg & ( 1 << 11))){
	       	//key is pressed
	       	delay();
	       	printf("D\n");
	       }

	   }//while end
}