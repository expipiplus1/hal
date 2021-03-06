////
//
//        STM32F7x7 vectors
//
////

template<> void handler<interrupt::NMI>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::HARDFAULT>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::MEMMANAGE>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::BUSFAULT>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::USAGEFAULT>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SVCALL>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DEBUG>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::PENDSV>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SYSTICK>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::WWDG>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::PVD>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TAMP_STAMP>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::RTC_WKUP>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::FLASH>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::RCC>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::EXTI0>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::EXTI1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::EXTI2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::EXTI3>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::EXTI4>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA1_STREAM0>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA1_STREAM1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA1_STREAM2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA1_STREAM3>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA1_STREAM4>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA1_STREAM5>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA1_STREAM6>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::ADC>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN1_TX>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN1_RX0>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN1_RX1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN1_SCE>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::EXTI9_5>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM1_BRK_TIM9>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM1_UP_TIM10>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM1_TRG_COM_TIM11>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM1_CC>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM3>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM4>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::I2C1_EV>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::I2C1_ER>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::I2C2_EV>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::I2C2_ER>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SPI1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SPI2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::USART1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::USART2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::USART3>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::EXTI15_10>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::RTC_ALARM>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::OTG_FS_WKUP>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM8_BRK_TIM12>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM8_UP_TIM13>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM8_TRG_COM_TIM14>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM8_CC>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA1_STREAM7>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::FMC>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SDMMC1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM5>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SPI3>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::UART4>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::UART5>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM6_DAC>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::TIM7>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA2_STREAM0>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA2_STREAM1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA2_STREAM2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA2_STREAM3>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA2_STREAM4>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::ETH>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::ETH_WKUP>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN2_TX>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN2_RX0>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN2_RX1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN2_SCE>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::OTG_FS>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA2_STREAM5>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA2_STREAM6>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA2_STREAM7>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::USART6>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::I2C3_EV>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::I2C3_ER>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::OTG_HS_EP1_OUT>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::OTG_HS_EP1_IN>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::OTG_HS_WKUP>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::OTG_HS>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DCMI>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CRYP>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::HASH_RNG>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::FPU>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::UART7>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::UART8>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SPI4>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SPI5>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SPI6>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SAI1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::LCD_TFT>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::LCD_TFT_ERR>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DMA2D>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SAI2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::QUADSPI>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::LP_TIMER1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::I2C4_EV>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::I2C4_ER>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SPDIFRX>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DSIHOST>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DFSDM1_FLT0>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DFSDM1_FLT1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DFSDM1_FLT2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::DFSDM1_FLT3>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::SDMMC2>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN3_TX>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN3_RX0>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN3_RX1>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::CAN3_SCE>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::JPEG>() __attribute__ ((weak, alias("_Z17__default_handlerv")));
template<> void handler<interrupt::MDIOS>() __attribute__ ((weak, alias("_Z17__default_handlerv")));

void (*vectors[])(void) __attribute__ ((section(".vectors"))) =
    { (void(*)(void)) &__estack                     // -16: Initial stack pointer
    , handler<interrupt::RESET>                     // -15: Reset [fixed]
    , handler<interrupt::NMI>                       // -14: Non maskable interrupt [fixed]
    , handler<interrupt::HARDFAULT>                 // -13: All class of fault [fixed]
    , handler<interrupt::MEMMANAGE>                 // -12: Memory management [settable]
    , handler<interrupt::BUSFAULT>                  // -11: Pre-fetch fault, memory access fault [settable]
    , handler<interrupt::USAGEFAULT>                // -10: Undefined instruction or illegal state [settable]
    , 0x0
    , 0x0
    , 0x0
    , 0x0
    , handler<interrupt::SVCALL>                    // -5: System service call via SWI instruction [settable]
    , handler<interrupt::DEBUG>                     // -4: Monitor Debug Monitor [settable]
    , 0x0
    , handler<interrupt::PENDSV>                    // -2: Pendable request for system service [settable]
    , handler<interrupt::SYSTICK>                   // -1: System tick timer [settable]
    , handler<interrupt::WWDG>                      // 0: Window Watchdog interrupt
    , handler<interrupt::PVD>                       // 1: PVD through EXTI line detection
    , handler<interrupt::TAMP_STAMP>                // 2: Tamper and TimeStamp interrupts through the EXTI line
    , handler<interrupt::RTC_WKUP>                  // 3: RTC Tamper or TimeStamp /CSS on LSE through EXTI line 19 interrupts
    , handler<interrupt::FLASH>                     // 4: Flash global interrupt
    , handler<interrupt::RCC>                       // 5: RCC global interrupt
    , handler<interrupt::EXTI0>                     // 6: EXTI Line0 interrupt
    , handler<interrupt::EXTI1>                     // 7: EXTI Line1 interrupt
    , handler<interrupt::EXTI2>                     // 8: EXTI Line2 interrupt
    , handler<interrupt::EXTI3>                     // 9: EXTI Line3 interrupt
    , handler<interrupt::EXTI4>                     // 10: EXTI Line4 interrupt
    , handler<interrupt::DMA1_STREAM0>              // 11: DMA1 Stream0 global interrupt
    , handler<interrupt::DMA1_STREAM1>              // 12: DMA1 Stream1 global interrupt
    , handler<interrupt::DMA1_STREAM2>              // 13: DMA1 Stream2 global interrupt
    , handler<interrupt::DMA1_STREAM3>              // 14: DMA1 Stream3 global interrupt
    , handler<interrupt::DMA1_STREAM4>              // 15: DMA1 Stream4 global interrupt
    , handler<interrupt::DMA1_STREAM5>              // 16: DMA1 Stream5 global interrupt
    , handler<interrupt::DMA1_STREAM6>              // 17: DMA1 Stream6 global interrupt
    , handler<interrupt::ADC>                       // 18: ADC1 global interrupt
    , handler<interrupt::CAN1_TX>                   // 19: CAN1 TX interrupts
    , handler<interrupt::CAN1_RX0>                  // 20: CAN1 RX0 interrupts
    , handler<interrupt::CAN1_RX1>                  // 21: CAN1 RX1 interrupts
    , handler<interrupt::CAN1_SCE>                  // 22: CAN1 SCE interrupt
    , handler<interrupt::EXTI9_5>                   // 23: EXTI Line[9:5] interrupts
    , handler<interrupt::TIM1_BRK_TIM9>             // 24: TIM1 Break interrupt and TIM9 global interrupt
    , handler<interrupt::TIM1_UP_TIM10>             // 25: TIM1 Update interrupt and TIM10
    , handler<interrupt::TIM1_TRG_COM_TIM11>        // 26: TIM1 Trigger and Commutation interrupts and TIM11 global interrupt
    , handler<interrupt::TIM1_CC>                   // 27: TIM1 Capture Compare interrupt
    , handler<interrupt::TIM2>                      // 28: TIM2 global interrupt
    , handler<interrupt::TIM3>                      // 29: TIM3 global interrupt
    , handler<interrupt::TIM4>                      // 30: TIM4 global interrupt
    , handler<interrupt::I2C1_EV>                   // 31: I2C1 event interrupt
    , handler<interrupt::I2C1_ER>                   // 32: I2C1 error interrupt
    , handler<interrupt::I2C2_EV>                   // 33: I2C2 event interrupt
    , handler<interrupt::I2C2_ER>                   // 34: I2C2 error interrupt
    , handler<interrupt::SPI1>                      // 35: SPI1 global interrupt
    , handler<interrupt::SPI2>                      // 36: SPI2 global interrupt
    , handler<interrupt::USART1>                    // 37: USART1 global interrupt
    , handler<interrupt::USART2>                    // 38: USART2 global interrupt
    , handler<interrupt::USART3>                    // 39: USART3 global interrupt
    , handler<interrupt::EXTI15_10>                 // 40: EXTI Line[15:10] interrupts
    , handler<interrupt::RTC_ALARM>                 // 41: RTC alarms through EXTI line 18 interrupts
    , handler<interrupt::OTG_FS_WKUP>               // 42: USB On-The-Go FS Wakeup through EXTI line interrupt
    , handler<interrupt::TIM8_BRK_TIM12>            // 43: TIM8 Break interrupt and TIM12 global interrupt
    , handler<interrupt::TIM8_UP_TIM13>             // 44: TIM8 Update interrupt and TIM13 global interrupt
    , handler<interrupt::TIM8_TRG_COM_TIM14>        // 45: TIM8 Trigger and Commutation interrupts and TIM14 global interrupt
    , handler<interrupt::TIM8_CC>                   // 46: TIM8 Capture Compare interrupt
    , handler<interrupt::DMA1_STREAM7>              // 47: DMA1 Stream7 global interrupt
    , handler<interrupt::FMC>                       // 48: FMC global interrupt
    , handler<interrupt::SDMMC1>                    // 49: SDMMC1 global interrupt
    , handler<interrupt::TIM5>                      // 50: TIM5 global interrupt
    , handler<interrupt::SPI3>                      // 51: SPI3 global interrupt
    , handler<interrupt::UART4>                     // 52: UART4 global interrupt
    , handler<interrupt::UART5>                     // 53: UART5 global interrupt
    , handler<interrupt::TIM6_DAC>                  // 54: TIM6 global interrupt, DAC1 and DAC2 underrun error interrupt
    , handler<interrupt::TIM7>                      // 55: TIM7 global interrupt
    , handler<interrupt::DMA2_STREAM0>              // 56: DMA2 Stream0 global interrupt
    , handler<interrupt::DMA2_STREAM1>              // 57: DMA2 Stream1 global interrupt
    , handler<interrupt::DMA2_STREAM2>              // 58: DMA2 Stream2 global interrupt
    , handler<interrupt::DMA2_STREAM3>              // 59: DMA2 Stream3 global interrupt
    , handler<interrupt::DMA2_STREAM4>              // 60: DMA2 Stream4 global interrupt
    , handler<interrupt::ETH>                       // 61: Ethernet global interrupt
    , handler<interrupt::ETH_WKUP>                  // 62: Ethernet Wakeup through EXTI line
    , handler<interrupt::CAN2_TX>                   // 63: CAN2 TX interrupts
    , handler<interrupt::CAN2_RX0>                  // 64: CAN2 RX0 interrupts
    , handler<interrupt::CAN2_RX1>                  // 65: CAN2 RX1 interrupts
    , handler<interrupt::CAN2_SCE>                  // 66: CAN2 SCE interrupt
    , handler<interrupt::OTG_FS>                    // 67: USB On The Go FS global interrupt
    , handler<interrupt::DMA2_STREAM5>              // 68: DMA2 Stream5 global interrupt
    , handler<interrupt::DMA2_STREAM6>              // 69: DMA2 Stream6 global interrupt
    , handler<interrupt::DMA2_STREAM7>              // 70: DMA2 Stream7 global interrupt
    , handler<interrupt::USART6>                    // 71: USART6 global interrupt
    , handler<interrupt::I2C3_EV>                   // 72: I2C3 event interrupt
    , handler<interrupt::I2C3_ER>                   // 73: I2C3 error interrupt
    , handler<interrupt::OTG_HS_EP1_OUT>            // 74: USB On The Go HS End Point 1 Out global interrupt
    , handler<interrupt::OTG_HS_EP1_IN>             // 75: USB On The Go HS End Point 1 In global interrupt
    , handler<interrupt::OTG_HS_WKUP>               // 76: USB On The Go HS Wakeup through EXTI interrupt
    , handler<interrupt::OTG_HS>                    // 77: USB On The Go HS global interrupt
    , handler<interrupt::DCMI>                      // 78: DCMI global interrupt
    , handler<interrupt::CRYP>                      // 79: CRYP crypto global interrupt
    , handler<interrupt::HASH_RNG>                  // 80: Hash and Rng global interrupt
    , handler<interrupt::FPU>                       // 81: Floating point unit interrupt
    , handler<interrupt::UART7>                     // 82: UART7 global interrupt
    , handler<interrupt::UART8>                     // 83: UART 8 global interrupt
    , handler<interrupt::SPI4>                      // 84: SPI 4 global interrupt
    , handler<interrupt::SPI5>                      // 85: SPI 5 global interrupt
    , handler<interrupt::SPI6>                      // 86: SPI 6 global interrupt
    , handler<interrupt::SAI1>                      // 87: SAI1 global interrupt
    , handler<interrupt::LCD_TFT>                   // 88: LTDC global interrupt
    , handler<interrupt::LCD_TFT_ERR>               // 89: LCD-TFT global Error interrupt
    , handler<interrupt::DMA2D>                     // 90: DMA2D global interrupt
    , handler<interrupt::SAI2>                      // 91: SAI2 global interrupt
    , handler<interrupt::QUADSPI>                   // 92: QuadSPI global interrupt
    , handler<interrupt::LP_TIMER1>                 // 93: LP Timer1 global interrupt
    , 0x0
    , handler<interrupt::I2C4_EV>                   // 95: I2C4 event interrupt
    , handler<interrupt::I2C4_ER>                   // 96: I2C4 Error interrupt
    , handler<interrupt::SPDIFRX>                   // 97: SPDIFRX global interrupt
    , handler<interrupt::DSIHOST>                   // 98: DSI host global interrupt
    , handler<interrupt::DFSDM1_FLT0>               // 99: DFSDM1 Filter 0 global interrupt
    , handler<interrupt::DFSDM1_FLT1>               // 100: DFSDM1 Filter 1 global interrupt
    , handler<interrupt::DFSDM1_FLT2>               // 101: DFSDM1 Filter 2 global interrupt
    , handler<interrupt::DFSDM1_FLT3>               // 102: DFSDM1 Filter 3 global interrupt
    , handler<interrupt::SDMMC2>                    // 103: SDMMC2 global interrupt
    , handler<interrupt::CAN3_TX>                   // 104: CAN3 TX interrupt
    , handler<interrupt::CAN3_RX0>                  // 105: CAN3 RX0 interrupt
    , handler<interrupt::CAN3_RX1>                  // 106: CAN3 RX1 interrupt
    , handler<interrupt::CAN3_SCE>                  // 107: CAN3 SCE interrupt
    , handler<interrupt::JPEG>                      // 108: JPEG global interrupt
    , handler<interrupt::MDIOS>                     // 109: MDIO slave global interrupt
    };

