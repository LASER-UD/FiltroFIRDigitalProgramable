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

volatile double h[51];
uint16 x[51];
uint16 frec_final;
volatile uint8 i,cont_char,u_frec,d_frec,c_frec,um_frec;
volatile char fila, tecla, columna,paso,filtro;
volatile char frec[4];

CY_ISR(llegaMuestra)
{    
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
    x[0] = ADC_GetResult16();    
    
      
    if(filtro == 2 || filtro == 3)
    {
        double y = (double)x[0]*h[0]+(double)x[1]*h[1]+(double)x[2]*h[2]+(double)x[3]*h[3]+(double)x[4]*h[4]+(double)x[5]*h[5]+(double)x[6]*h[6]+(double)x[7]*h[7]+(double)x[8]*h[8]+(double)x[9]*h[9]+(double)x[10]*h[10]+(double)x[11]*h[11]+(double)x[12]*h[12]+(double)x[13]*h[13]+(double)x[14]*h[14]+(double)x[15]*h[15]+(double)x[16]*h[16]+(double)x[17]*h[17]+(double)x[18]*h[18]+(double)x[19]*h[19]+(double)x[20]*h[20]+(double)x[21]*h[21]+(double)x[22]*h[22]+(double)x[23]*h[23]+(double)x[24]*h[24]+(double)x[25]*h[25]+(double)x[26]*h[26]+(double)x[27]*h[27]+(double)x[28]*h[28]+(double)x[29]*h[29]+(double)x[30]*h[30]+(double)x[31]*h[31]+(double)x[32]*h[32]+(double)x[33]*h[33]+(double)x[34]*h[34]+(double)x[35]*h[35]+(double)x[36]*h[36]+(double)x[37]*h[37]+(double)x[38]*h[38]+(double)x[39]*h[39]+(double)x[40]*h[40]+(double)x[41]*h[41]+(double)x[42]*h[42]+(double)x[43]*h[43]+(double)x[44]*h[44]+(double)x[45]*h[45]+(double)x[46]*h[46]+(double)x[47]*h[47]+(double)x[48]*h[48]+(double)x[49]*h[49]+(double)x[50]*h[50];
        y+=512;
        DAC_SetValue((int)trunc(y));
    }
    else
    {
        int y = (double)x[0]*h[0]+(double)x[1]*h[1]+(double)x[2]*h[2]+(double)x[3]*h[3]+(double)x[4]*h[4]+(double)x[5]*h[5]+(double)x[6]*h[6]+(double)x[7]*h[7]+(double)x[8]*h[8]+(double)x[9]*h[9]+(double)x[10]*h[10]+(double)x[11]*h[11]+(double)x[12]*h[12]+(double)x[13]*h[13]+(double)x[14]*h[14]+(double)x[15]*h[15]+(double)x[16]*h[16]+(double)x[17]*h[17]+(double)x[18]*h[18]+(double)x[19]*h[19]+(double)x[20]*h[20]+(double)x[21]*h[21]+(double)x[22]*h[22]+(double)x[23]*h[23]+(double)x[24]*h[24]+(double)x[25]*h[25]+(double)x[26]*h[26]+(double)x[27]*h[27]+(double)x[28]*h[28]+(double)x[29]*h[29]+(double)x[30]*h[30]+(double)x[31]*h[31]+(double)x[32]*h[32]+(double)x[33]*h[33]+(double)x[34]*h[34]+(double)x[35]*h[35]+(double)x[36]*h[36]+(double)x[37]*h[37]+(double)x[38]*h[38]+(double)x[39]*h[39]+(double)x[40]*h[40]+(double)x[41]*h[41]+(double)x[42]*h[42]+(double)x[43]*h[43]+(double)x[44]*h[44]+(double)x[45]*h[45]+(double)x[46]*h[46]+(double)x[47]*h[47]+(double)x[48]*h[48]+(double)x[49]*h[49]+(double)x[50]*h[50];
        DAC_SetValue(trunc(y));
    }
//    x[0] = ADC_GetResult16();
//    y = x[0];    
}

void Calc_coef()
{
    //Por estandar de C, el valor decimal de los dígitos en ASCII es el dígito en ASCII - '0', entonces eso es lo que hacemos
    um_frec = frec[0] - '0';
    c_frec = frec[1] - '0';
    d_frec = frec[2] - '0';
    u_frec = frec[3] - '0';
    //Ahora acá procedemos a volver estos un número en frec_final
    frec_final = (um_frec)*1000+(c_frec)*100+(d_frec)*10+u_frec;
    //miramos si frec_final está dentro del rango
    if(frec_final>1000 || frec_final == 0)
    {
        //Si no, le decimos al usuario que resetee el sistema
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString("Fuera de Rango");
        LCD_Position(1,0);
        LCD_PrintString("Presione Reset");
    }
    else
    {
        //Si sí viene la tarea engorrosa de calcular los coeficientes
        volatile double wc = 2*3.14159265*(double)frec_final/3000;
        if(filtro == 1)
        {
            for(i = 0; i < 51; i++)
            {
                if(i != 25)
                {
                    double temp = wc*(i-25);
                    h[i] = (sin(temp));
                    h[i] /= (3.14159265*(i-25));
                }
                else
                {
                    h[i] = wc/3.14159265;
                }
            }
        }
        if(filtro == 2)
        {
            for(i = 0; i < 51; i++)
            {
                if(i != 25)
                {
                    double temp = wc*(i-25);
                    h[i] = -(sin(temp));
                    h[i] /= (3.14159265*(i-25));
                }
                else
                {
                    h[i] = 1 - wc/3.14159265;
                }
            }
        }
        if(filtro == 3)
        {
            double wc2 = ((double)frec_final+100)*3.14159265/1500;
            double wc1 = ((double)frec_final-100)*3.14159265/1500;
            for(i = 0; i < 51; i++)
            {
                if(i != 25)
                {
                    double temp2 = wc2*(i-25);
                    double temp1 = wc1*(i-25);
                    h[i] = (sin(temp2));
                    h[i] /= (3.14159265*(i-25));
                    double temp3 = (sin(temp1));
                    temp3 /= (3.14159265*(i-25));
                    h[i] -= temp3;
                }
                else
                {
                    h[i] = wc2/3.14159265 - wc1/3.14159265;
                }
            }
        }
        //Ahora después de calculados notificamos al usuario que fueron calculados para esa frecuencia
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString("Coef Calculados");
        LCD_Position(1,0);
        LCD_PrintString("Para F:");
        LCD_PutChar(frec[0]);
        LCD_PutChar(frec[1]);
        LCD_PutChar(frec[2]);
        LCD_PutChar(frec[3]);
        CyDelay(3000);
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString("Inicia");
        LCD_Position(1,0);
        LCD_PrintString("Filtrado");
        ADC_Start();
        DAC_Start();
        Muestreo_Start();
        Recorre_Uno_Stop();
        int_EndOfConv_StartEx(llegaMuestra);
        int_CambioUno_Stop();
        int_TeclaOprimida_Stop();
    }
}

//Esta función se ejecutará cada que se termine una conversión del ADC;

//Con este método identificaremos la tecla oprimida del teclado matricial
CY_ISR(identificarTecla)
{
    columna = Columnas_Read();
    if(fila == 1)
    {
        switch(columna)
        {
            case 0b00000001:
                tecla = '1';
                break;
            case 0b00000010:
                tecla = '2';
                break;
            case 0b00000100:
                tecla = '3';
                break;
        }
    }
    if(fila == 2)
    {
        switch(columna)
        {
            case 0b00000001:
                tecla = '4';
                break;
            case 0b00000010:
                tecla = '5';
                break;
            case 0b00000100:
                tecla = '6';
                break;
        }
    }
    if(fila == 4)
    {
        switch(columna)
        {
            case 0b00000001:
                tecla = '7';
                break;
            case 0b00000010:
                tecla = '8';
                break;
            case 0b00000100:
                tecla = '9';
                break;
        }
    }
    if(fila == 8)
    {
        switch(columna)
        {
            case 0b00000001:
                tecla = '*';
                break;
            case 0b00000010:
                tecla = '0';
                break;
            case 0b00000100:
                tecla = '#';
                break;
        }
    }    
    //Empezamos a mirar la lógica del algoritmo de visualización    
    if(paso == 3)
    {
        //Procedemos a calcular los coeficientes luego de colocar *
        if(tecla == '*')
        {
            LCD_Position(0,0);
            LCD_PrintString("                ");
            LCD_Position(0,0);
            LCD_PrintString("Calculando Coef");
            LCD_Position(1,0);
            LCD_PrintString("                ");
            LCD_Position(1,0);
            LCD_PrintString("...");
            Calc_coef();
        }
    }
    if(paso == 2)
    {
        //Digitamos cada uno de los valores de unidades de mil de frecuencia, centenas de frecuencia, decenas de frecuencia y unidades de frecuencia
        if((tecla - '0') != filtro)
        {
            frec[cont_char] = tecla;
            LCD_PutChar(tecla);
            cont_char++;
            if(cont_char == 4)
            {
                LCD_Position(0,0);
                LCD_PrintString("                ");
                LCD_Position(0,0);
                LCD_PrintString("Presione *");
                CyDelay(2000);
                paso = 3;
            }
        }
        else
        {
            tecla = filtro + '0';
            frec[cont_char] = tecla;
            LCD_PutChar(tecla);
            cont_char++;
            if(cont_char == 4)
            {
                LCD_Position(0,0);
                LCD_PrintString("                ");
                LCD_Position(0,0);
                LCD_PrintString("Presione *");
                CyDelay(2000);
                paso = 3;
            }
        }       
    }
    if(paso == 1)
    {   
        //Miramos qué tipo de filtro digita
        switch(tecla)
        {
            case '1':
                filtro = 1;                
                paso = 2;
                break;
            case '2':
                filtro = 2;                
                paso = 2;
                break;
            case '3':                
                filtro = 3;
                paso = 2;
                break;
        }        
    }    
    CyDelay(250);
    Columnas_ClearInterrupt();
}
//Con este método hacemos que el uno recorra las filas para recibirlo en las columnas
CY_ISR(cambiarUno)
{
    switch(fila)
    {
        case 1:
            fila = 2;
            break;
        case 2:
            fila = 4;
            break;
        case 4:
            fila = 8;
            break;
        case 8:
            fila = 1;
            break;
    }
    Filas_Write(fila);    
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    //Inicializamos los componentes    
    LCD_Start();
    Recorre_Uno_Start();    
    //Fin inicialización componentes
    //Inicializamos las interrupciones    
    int_TeclaOprimida_StartEx(identificarTecla);
    int_CambioUno_StartEx(cambiarUno);
    //Fin inicialización de interrupciones
    //Inicializamos variables
    fila = 1;
    paso = 1;
    cont_char = 0;
    u_frec = 0;
    d_frec = 0;
    c_frec = 0;
    um_frec = 0;
    frec_final = 0;
    //Fin inicialización variables      
    for(;;)
    {    
        //En el for infinito vamos a lidiar con la visualización
        if(paso == 1)
        {
            //Preguntamos por el tipo de filtro
            LCD_PrintString("Filtro: 1)P.Bajas");
            LCD_Position(1,0);
            LCD_PrintString("2)P.Alta 3)P.Banda");
        }
        if(paso == 2)
        {
            //Pedimos la frecuencia del filtro intermitentemente
            if(cont_char == 0)
            {
                LCD_ClearDisplay();
                int_TeclaOprimida_Stop();
                LCD_PrintString("Digite una frec");                  
                LCD_Position(1,0);
                LCD_PrintString("de 4 digitos");
                CyDelay(2500);                
                LCD_Position(0,0);
                LCD_PrintString("                ");
                LCD_Position(0,0);
                switch(filtro)
                {
                    case 1:                
                        LCD_PrintString("Digite F corte");
                        break;
                    case 2:                
                        LCD_PrintString("Digite F corte");
                        break;
                    case 3:                
                        LCD_PrintString("Digite F central");
                        break;
                }
                LCD_Position(1,0);
                LCD_PrintString("                ");
                LCD_Position(1,0);        
                LCD_PrintString("Frec:");
                int_TeclaOprimida_StartEx(identificarTecla);
            }
        }        
        CyDelay(2500);
    }
}

/* [] END OF FILE */