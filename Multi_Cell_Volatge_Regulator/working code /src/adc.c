#include "stm32f4xx_hal.h"
#include "adc.h"

ADC_HandleTypeDef hadc1;


static void adc_pa0_continuous_conv_init(void);


uint32_t pa0_adc_read(void)
{
	return HAL_ADC_GetValue(&hadc1);
}

void adc_init_start(void)
{
	adc_pa0_continuous_conv_init();
	//HAL_ADC_Start(&hadc1);
}
void adc_pa0_continuous_conv_init(void)
{
	//configure pa0 as analog pin

	GPIO_InitTypeDef  GPIO_InitStruct = {0};
	ADC_ChannelConfTypeDef sConfig = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();


	GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


	//configure adc module for continuous conversion

	__HAL_RCC_ADC1_CLK_ENABLE();

	hadc1.Instance = ADC1;
	hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
    hadc1.Init.Resolution = ADC_RESOLUTION_12B;
    hadc1.Init.ScanConvMode = ENABLE;           // ⭐ multiple channels
	hadc1.Init.ContinuousConvMode  = DISABLE;
	hadc1.Init.DiscontinuousConvMode = DISABLE;
	hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	hadc1.Init.NbrOfConversion = 4;
	hadc1.Init.DMAContinuousRequests = DISABLE;
	hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

	HAL_ADC_Init(&hadc1);



	sConfig.Channel =  ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);

	sConfig.Channel =  ADC_CHANNEL_1;
	sConfig.Rank = 2;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);

	sConfig.Channel =  ADC_CHANNEL_2;
	sConfig.Rank = 3;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);

	sConfig.Channel =  ADC_CHANNEL_3;
	sConfig.Rank = 4;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&hadc1, &sConfig);


}

void ADC1_Read_4Channels(uint16_t *adc_values)
{
    HAL_ADC_Start(&hadc1);

    for(int i=0; i<4; i++)
    {
        HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
        adc_values[i] = HAL_ADC_GetValue(&hadc1);
    }

    HAL_ADC_Stop(&hadc1);
}

float ADC_to_CellVoltage(uint16_t adc)
{
	float Vadc = ((float)adc * VREF) / ADC_MAX;
	float Vcell = Vadc *DIV_FACTOR;
	return Vcell;
}

void BMS_Read_CellVolatge(float *cell)
{
	uint16_t adc_raw[4];

	ADC1_Read_4Channels(adc_raw);

	cell[0] = ADC_to_CellVoltage(adc_raw[0]);
	cell[1] = ADC_to_CellVoltage(adc_raw[1]);
	cell[2] = ADC_to_CellVoltage(adc_raw[2]);
	cell[3] = ADC_to_CellVoltage(adc_raw[3]);




}






