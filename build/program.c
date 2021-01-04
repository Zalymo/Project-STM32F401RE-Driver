#include "include/peripheral.h"

#define BUTTON_IDLE_STATE1 0
#define BUTTON_IDLE_STATE2 2
#define BUTTON_DOWN_STATE1 1
#define BUTTON_DOWN_STATE2 3

void INIT_Config();

void buttonClickInput(bool pressed, uint8_t* mode, bool* activated);

int main(void) {
    // Variables placed here for testing purposes
    RCC_TypeDef* RCCVar = RCC;
    TIM_TypeDef* TIM1Var = TIM1;
    GPIO_TypeDef* GPIOAV = GPIOA;
    GPIO_TypeDef* GPIOCV = GPIOC;

    INIT_Config();

    uint8_t dir = 1;
    uint32_t delayCount = MAX_COUNT;

    bool B2_Activated = true, C7_Activated = true;
    uint8_t B2_Mode = 0, C7_Mode = 0;

    while (1) {
        if (BIT_ON(TIM1->SR, TIM_SR_UIF) && B2_Activated) {
            BIT_CLEAR(TIM1->SR, TIM_SR_UIF);
            
            if (delayCount < MAX_COUNT) {
                delayCount += TIM1->ARR;
            } else {
                if (dir == 1) {
                    TIM1->CCR1++;
                } else {
                    TIM1->CCR1--;
                }

                if (TIM1->CCR1 == 0xF3) {
                    dir = 0;
                } else if (TIM1->CCR1 == 0) {
                    dir = 1;
                    delayCount = 0;
                }
            }
        }

        // User button (B1) on-off input (button click)
        buttonClickInput(!BIT_ON(GPIOC->IDR, GPIO_IDR_ID13), &B2_Mode, &B2_Activated);

        // Breadboard button (pin C7) on-off input (button click)
        buttonClickInput(BIT_ON(GPIOC->IDR, GPIO_IDR_ID7), &C7_Mode, &C7_Activated);

        // Turn on user LED (LD2) when the button has been pressed and activated is false
        // Turn it off otherwise (lights active)
        if (!B2_Activated) {
            GPIOA->BSRR |= GPIO_BSRR_BS5;
        } else {
            GPIOA->BSRR |= GPIO_BSRR_BR5;
        }

        if (C7_Activated) {
            TIM1->CCR3 = TIM1->CCR1;
        } else {
            TIM1->CCR3 = 0;
        }
    }
    
    return 0;
}

void INIT_Config() {
    RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN);
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    // Set GPIOA mode register modes to "Alternate Function"
    GPIOA->MODER |= (GPIO_MODER_MODER5_0 | GPIO_MODER_MODER8_1 | GPIO_MODER_MODER10_1);

    // Set both pin alternate functions to AF01
    GPIOA->AFR[1] |= (GPIO_AFRH_AFSEL8_0 | GPIO_AFRH_AFSEL10_0);

    //GPIOC->PUPDR |= GPIO_PUPDR_PUPD7_1;
    //GPIOC->OTYPER |= GPIO_OTYPER_OT7;
    
    // Enable timer counters
    TIM1->CR1 |= TIM_CR1_CEN;
    TIM1->ARR = 0x10D;
    TIM1->PSC = 0xF3;

    /* PWM Enable Process: TIM1_CH1 & TIM1_CH3 */
    TIM1->BDTR |= TIM_BDTR_MOE;

    TIM1->CCMR1 |= TIM_CCMR1_OC1PE;
    TIM1->CCMR2 |= TIM_CCMR2_OC3PE;

    TIM1->CCER |= (TIM_CCER_CC1E | TIM_CCER_CC3E);

    TIM1->CCMR1 |= CCMR1_OC1M_PWM_MODE1;
    TIM1->CCMR2 |= CCMR1_OC3M_PWM_MODE1;

    TIM1->EGR |= TIM_EGR_UG;
}

void buttonClickInput(bool pressed, uint8_t* mode, bool* activated) {
    uint8_t initialMode = *mode;

    if (pressed) {
        if (initialMode == BUTTON_IDLE_STATE1) {
            *mode = BUTTON_DOWN_STATE1;
        } else if (initialMode == BUTTON_IDLE_STATE2) {
            *mode = BUTTON_DOWN_STATE2;
        }
    } else {
        if (initialMode == BUTTON_DOWN_STATE1) {
            *mode = BUTTON_IDLE_STATE2;

            *activated = false;
        } else if (initialMode == BUTTON_DOWN_STATE2) {
            *mode = BUTTON_IDLE_STATE1;

            *activated = true;
        }
    }
}