/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <math.h>

//Creación de variables h para los coeficientes del filtro, x para las muestras, y para la salida, i como variable de conteo
//tecla para guardar lo recibido del teclado

const double g[]={5.7797,-15.6072,25.4760,-27.4067,19.8718,-9.4955,2.7433,-0.3708};//8
//const float h[]={0,0.0004,0.0004,-0.0007,-0.0028,-0.0051,-0.0055,-0.0026,0.0031,0.0085,0.0099,0.0061,0.0010,0.0012,0.0107,0.0254,0.0323,0.0174,-0.0229,-0.0747,-0.1100,-0.1021,-0.0433,0.0465,0.1271,0.1593,0.1271,0.0465,-0.0433,-0.1021,-0.1100,-0.0747,-0.0229,0.0174,0.0323,0.0254,0.0107,0.0012,0.0010,0.0061,0.0099,0.0085,0.0031,-0.0026,-0.0055,-0.0051,-0.0028,-0.0007,0.0004,0.0004,-0.0000};
const float h[]={0.0016,0.0019,0.0023,0.0026,0.0026,0.0020,0.0006,-0.0022,-0.0063,-0.0118,-0.0185,-0.0257,-0.0326,-0.0380,-0.0409,-0.0403,-0.0354,-0.0261,-0.0125,0.0045,0.0235,0.0428,0.0604,0.0746,0.0837,0.0869,0.0837,0.0746,0.0604,0.0428,0.0235,0.0045,-0.0125,-0.0261,-0.0354,-0.0403,-0.0409,-0.0380,-0.0326,-0.0257,-0.0185,-0.0118,-0.0063,-0.0022,0.0006,0.0020,0.0026,0.0026,0.0023,0.0019,0.0016};
volatile uint8 cont=0;
uint16 x[51];


CY_ISR(INT_SW){
    if(cont==1){
        cont=0;
    }else{
        cont=1;
    }
    LEDS_Write(cont);
    SW_ClearInterrupt();  
}


CY_ISR(llegaMuestra)
{   unsigned char y;
    if(cont==0){
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        y = ADC_GetResult16();
    }else{
    x[50] = x[49];
    x[49] = x[48];
    x[48] = x[47];
    x[47] = x[46];
    x[46] = x[45];
    x[45] = x[44];
    x[44] = x[43];
    x[43] = x[42];
    x[42] = x[41];
    x[41] = x[40];
    x[40] = x[39];
    x[39] = x[38];
    x[38] = x[37];
    x[37] = x[36];
    x[36] = x[35];
    x[35] = x[34];
    x[34] = x[33];
    x[33] = x[32];
    x[32] = x[31];
    x[31] = x[30];
    x[30] = x[29];
    x[29] = x[28];
    x[28] = x[27];
    x[27] = x[26];
    x[26] = x[25];
    x[25] = x[24];
    x[24] = x[23];
    x[23] = x[22];
    x[22] = x[21];
    x[21] = x[20];
    x[20] = x[19];
    x[19] = x[18];
    x[18] = x[17];
    x[17] = x[16];
    x[16] = x[15];
    x[15] = x[14];
    x[14] = x[13];
    x[13] = x[12];
    x[12] = x[11];
    x[11] = x[10];
    x[10] = x[9];
    x[9] = x[8];
    x[8] = x[7];
    x[7] = x[6];
    x[6] = x[5];
    x[5] = x[4];
    x[4] = x[3];
    x[3] = x[2];
    x[2] = x[1];
    x[1] = x[0];  
    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    x[0] = ADC_GetResult16();
    y = (x[0]*h[0]+x[1]*h[1]+x[2]*h[2]+x[3]*h[3]+x[4]*h[4]+x[5]*h[5]+x[6]*h[6]+x[7]*h[7]+x[8]*h[8]+x[9]*h[9]+x[10]*h[10]+x[11]*h[11]+x[12]*h[12]+x[13]*h[13]+x[14]*h[14]+x[15]*h[15]+x[16]*h[16]+x[17]*h[17]+x[18]*h[18]+x[19]*h[19]+x[20]*h[20]+x[21]*h[21]+x[22]*h[22]+x[23]*h[23]+x[24]*h[24]+x[25]*h[25]+x[26]*h[26]+x[27]*h[27]+x[28]*h[28]+x[29]*h[29]+x[30]*h[30]+x[31]*h[31]+x[32]*h[32]+x[33]*h[33]+x[34]*h[34]+x[35]*h[35]+x[36]*h[36]+x[37]*h[37]+x[38]*h[38]+x[39]*h[39]+x[40]*h[40]+x[41]*h[41]+x[42]*h[42]+x[43]*h[43]+x[44]*h[44]+x[45]*h[45]+x[46]*h[46]+x[47]*h[47]+x[48]*h[48]+x[49]*h[49]+x[50]*h[50])+108;
}
    DAC_SetValue(y);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    //Inicializamos los componentes
    ADC_Start();
    DAC_Start();
    Timer_Start();
    ISR_StartEx(llegaMuestra);
    LEDS_Write(0);
    ISR_1_StartEx(INT_SW);
    //Fin inicialización variables      
    for(;;)
    {
               
    }
}

/* [] END OF FILE */