/*
 * adc.h
 *
 *  Created on: Jan 24, 2026
 *      Author: raj43
 */

#ifndef ADC_H_
#define ADC_H


#define VREF             5.00f
#define ADC_MAX          4095.0f
#define DIV_FACTOR       0.6666f

uint32_t pa0_adc_read(void);
void adc_init_start(void);
void ADC1_Read_4Channels(uint16_t *adc_values);
float ADC_to_CellVoltage(uint16_t adc);
void BMS_Read_CellVolatge(float *Vcell);





#endif /* ADC_H_ */
