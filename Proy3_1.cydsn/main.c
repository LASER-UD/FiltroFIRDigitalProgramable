/* ========================================
 *
 * Copyriwht YOUR COMPANY, THE YEAR
 * All Riwhts Reserved
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


//const float h[]={0,0.0004,0.0004,-0.0007,-0.0028,-0.0051,-0.0055,-0.0026,0.0031,0.0085,0.0099,0.0061,0.0010,0.0012,0.0107,0.0254,0.0323,0.0174,-0.0229,-0.0747,-0.1100,-0.1021,-0.0433,0.0465,0.1271,0.1593,0.1271,0.0465,-0.0433,-0.1021,-0.1100,-0.0747,-0.0229,0.0174,0.0323,0.0254,0.0107,0.0012,0.0010,0.0061,0.0099,0.0085,0.0031,-0.0026,-0.0055,-0.0051,-0.0028,-0.0007,0.0004,0.0004,-0.0000};
const float h[]={0.0016,0.0019,0.0023,0.0026,0.0026,0.0020,0.0006,-0.0022,-0.0063,-0.0118,-0.0185,-0.0257,-0.0326,-0.0380,-0.0409,-0.0403,-0.0354,-0.0261,-0.0125,0.0045,0.0235,0.0428,0.0604,0.0746,0.0837,0.0869,0.0837,0.0746,0.0604,0.0428,0.0235,0.0045,-0.0125,-0.0261,-0.0354,-0.0403,-0.0409,-0.0380,-0.0326,-0.0257,-0.0185,-0.0118,-0.0063,-0.0022,0.0006,0.0020,0.0026,0.0026,0.0023,0.0019,0.0016};
const float g[]={-0.0010,-0.0017,-0.0021,-0.0018,-0.0004,0.0022,0.0052,0.0070,0.0064,0.0035,0.0003,-0.0002,0.0042,0.0125,0.0196,0.0179,0.0018,-0.0286,-0.0645,-0.0907,-0.0921,-0.0607,-0.0016,0.0676,0.1229,0.1440,0.1229,0.0676,-0.0016,-0.0607,-0.0921,-0.0907,-0.0645,-0.0286,0.0018,0.0179,0.0196,0.0125,0.0042,-0.0002,0.0003,0.0035,0.0064,0.0070,0.0052,0.0022,-0.0004,-0.0018,-0.0021,-0.0017,-0.0010};//8
const float w[]={0,-0.0001,0.0026,0.0005,   -0.0005,    0.0010,   -0.0063,   -0.0031,    0.0024,   -0.0035,    0.0130,    0.0119,   -0.0067,    0.0081,   -0.0209,   -0.0335,    0.0135,   -0.0137,    0.0273,    0.0850,   -0.0211,    0.0183,   -0.0297,   -0.3112,    0.0273,    0.4808,    0.0273,   -0.3112,   -0.0297,    0.0183,   -0.0211,    0.0850,    0.0273,   -0.0137,    0.0135,   -0.0335,   -0.0209,    0.0081,   -0.0067,    0.0119,    0.0130,   -0.0035,    0.0024,   -0.0031,   -0.0063,    0.0010,   -0.0005,    0.0005,0.0026,-0.0001,0};
volatile unsigned char cont=0;
uint16 x[51];


CY_ISR(INT_SW){
    LEDS_Write(~LEDS_Read());
    if(cont==3){
        cont=0;
    }else{
        cont++;
    }
    switch(cont){
        case 0:{
            LCD_ClearDisplay();
            LCD_PrintString("Muestreo");   
            break;
        }
        case 1:{
            LCD_ClearDisplay();
            LCD_PrintString("Alfa");
            break;
        }
        case 2:{
            LCD_ClearDisplay();
            LCD_PrintString("Beta");
            break;
        }
        case 3:{
            LCD_ClearDisplay();
            LCD_PrintString("Gamma");
            break;
        } 
        default:{
            break;
        }
    }
    SW_ClearInterrupt();  
}


CY_ISR(llegaMuestra)
{   unsigned char y=0;
    if(cont==0){
        ADC_StartConvert();
        ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
        y = ADC_GetResult16();
    }else if(cont==1){
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
}else if(cont==2){
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
    y = (x[0]*g[0]+x[1]*g[1]+x[2]*h[2]+x[3]*g[3]+x[4]*g[4]+x[5]*g[5]+x[6]*g[6]+x[7]*g[7]+x[8]*g[8]+x[9]*g[9]+x[10]*g[10]+x[11]*g[11]+x[12]*g[12]+x[13]*h[13]+x[14]*g[14]+x[15]*g[15]+x[16]*g[16]+x[17]*g[17]+x[18]*g[18]+x[19]*g[19]+x[20]*g[20]+x[21]*g[21]+x[22]*g[22]+x[23]*g[23]+x[24]*g[24]+x[25]*g[25]+x[26]*g[26]+x[27]*g[27]+x[28]*g[28]+x[29]*g[29]+x[30]*g[30]+x[31]*g[31]+x[32]*g[32]+x[33]*g[33]+x[34]*g[34]+x[35]*g[35]+x[36]*g[36]+x[37]*g[37]+x[38]*g[38]+x[39]*g[39]+x[40]*g[40]+x[41]*g[41]+x[42]*g[42]+x[43]*g[43]+x[44]*g[44]+x[45]*g[45]+x[46]*g[46]+x[47]*g[47]+x[48]*g[48]+x[49]*g[49]+x[50]*g[50])+108;
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
    y = (x[0]*w[0]+x[1]*w[1]+x[2]*h[2]+x[3]*w[3]+x[4]*w[4]+x[5]*w[5]+x[6]*w[6]+x[7]*w[7]+x[8]*w[8]+x[9]*w[9]+x[10]*w[10]+x[11]*w[11]+x[12]*w[12]+x[13]*h[13]+x[14]*w[14]+x[15]*w[15]+x[16]*w[16]+x[17]*w[17]+x[18]*w[18]+x[19]*w[19]+x[20]*w[20]+x[21]*w[21]+x[22]*w[22]+x[23]*w[23]+x[24]*w[24]+x[25]*w[25]+x[26]*w[26]+x[27]*w[27]+x[28]*w[28]+x[29]*w[29]+x[30]*w[30]+x[31]*w[31]+x[32]*w[32]+x[33]*w[33]+x[34]*w[34]+x[35]*w[35]+x[36]*w[36]+x[37]*w[37]+x[38]*w[38]+x[39]*w[39]+x[40]*w[40]+x[41]*w[41]+x[42]*w[42]+x[43]*w[43]+x[44]*w[44]+x[45]*w[45]+x[46]*w[46]+x[47]*w[47]+x[48]*w[48]+x[49]*w[49]+x[50]*w[50]);
    
}
PWM_1_WriteCompare(y);
DAC_SetValue(y+108);


}

int main(void)
{
    CyGlobalIntEnable; /* Enable wlobal interrupts. */    
    /* Place your initialization/startup code here (e.w. MyInst_Start()) */
    //Inicializamos los componentes
    LCD_Start();
    ADC_Start();
    DAC_Start();
    Timer_Start();
    ISR_StartEx(llegaMuestra);
    LEDS_Write(1);
    PWM_1_Start();
    ISR_1_StartEx(INT_SW);
    //Fin inicialización variables
    LCD_Position(0,0);
    LCD_PrintString("Muestreo");
    for(;;)
    {
    }
}

/* [] END OF FILE */