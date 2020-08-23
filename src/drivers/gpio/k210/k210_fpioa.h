/**
 * @file fpioa.h
 * @brief
 * @author sksat <sksat@sksat.net>
 * @version 0.1
 * @date 2020-08-15
 */

#ifndef SRC_DRIVERS_GPIO_K210_FPIOA_H_
#define SRC_DRIVERS_GPIO_K210_FPIOA_H_

#define SYSCTL_BASE_ADDR	(0x50440000U)
#define FPIOA_BASE_ADDR		(0x502B0000U)

#define FPIOA_NUM_IO		48

typedef struct {
    uint32_t cpu      : 1;
    uint32_t sram0    : 1;
    uint32_t sram1    : 1;
    uint32_t apb0     : 1;
    uint32_t apb1     : 1;
    uint32_t apb2     : 1;
    uint32_t reserved : 26;
} __attribute__ ((packed, aligned(4))) sysctl_clock_enable_central;

typedef struct {
    uint32_t rom      : 1;
    uint32_t dma      : 1;
    uint32_t ai       : 1;
    uint32_t dvp      : 1;
    uint32_t fft      : 1;
    uint32_t gpio     : 1;
    uint32_t spi0     : 1;
    uint32_t spi1     : 1;
    uint32_t spi2     : 1;
    uint32_t spi3     : 1;
    uint32_t i2s0     : 1;
    uint32_t i2s1     : 1;
    uint32_t i2s2     : 1;
    uint32_t i2c0     : 1;
    uint32_t i2c1     : 1;
    uint32_t i2c2     : 1;
    uint32_t uart1    : 1;
    uint32_t uart2    : 1;
    uint32_t uart3    : 1;
    uint32_t aes      : 1;
    uint32_t fpioa    : 1;
    uint32_t timer0   : 1;
    uint32_t timer1   : 1;
    uint32_t timer2   : 1;
    uint32_t wdt0     : 1;
    uint32_t wdt1     : 1;
    uint32_t sha      : 1;
    uint32_t otp      : 1;
    uint32_t reserved0: 1;
    uint32_t rtc      : 1;
    uint32_t reserved1: 2;
} __attribute__((packed, aligned(4))) sysctl_clock_enable_peripheral;

typedef enum {
	FPIOA_PULL_NONE,
	FPIOA_PULL_DOWN,
	FPIOA_PULL_UP,
} k210_fpioa_pull_t;

typedef enum {
	FN_JTAG_TCLK, FN_JTAG_TDI, FN_JTAG_TMS, FN_JTAG_TDO,
	FN_SPI0_D0, FN_SPI0_D1, FN_SPI0_D2, FN_SPI0_D3, FN_SPI0_D4, FN_SPI0_D5, FN_SPI0_D6, FN_SPI0_D7,
	FN_SPI0_SS0, FN_SPI0_SS1, FN_SPI0_SS2, FN_SPI0_SS3, FN_SPI0_ARB, FN_SPI0_SCLK,
	FN_UARTHS_RX, FN_UARTHS_TX,
	FN_RESERVED6, FN_RESERVED7,
	FN_CLK_SPI1, FN_CLK_I2C1,
	FN_GPIOHS0, FN_GPIOHS1, FN_GPIOHS2, FN_GPIOHS3, FN_GPIOHS4,
	FN_GPIOHS5, FN_GPIOHS6, FN_GPIOHS7, FN_GPIOHS8, FN_GPIOHS9,
	FN_GPIOHS10, FN_GPIOHS11, FN_GPIOHS12, FN_GPIOHS13, FN_GPIOHS14,
	FN_GPIOHS15, FN_GPIOHS16, FN_GPIOHS17, FN_GPIOHS18, FN_GPIOHS19,
	FN_GPIOHS20, FN_GPIOHS21, FN_GPIOHS22, FN_GPIOHS23, FN_GPIOHS24,
	FN_GPIOHS25, FN_GPIOHS26, FN_GPIOHS27, FN_GPIOHS28, FN_GPIOHS29,
	FN_GPIOHS30, FN_GPIOHS31,
	FN_GPIO0, FN_GPIO1, FN_GPIO2, FN_GPIO3, FN_GPIO4,
	FN_GPIO5, FN_GPIO6, FN_GPIO7,
	FN_UART1_RX, FN_UART1_TX,
	FN_UART2_RX, FN_UART2_TX,
	FN_UART3_RX, FN_UART3_TX,
	FN_SPI1_D0, FN_SPI1_D1, FN_SPI1_D2, FN_SPI1_D3, FN_SPI1_D4,
	FN_SPI1_D5, FN_SPI1_D6, FN_SPI1_D7,
	FN_SPI1_SS0, FN_SPI1_SS1, FN_SPI1_SS2, FN_SPI1_SS3, FN_SPI1_ARB, FN_SPI1_SCLK,
	FN_SPI_SLAVE_D0, FN_SPI_SLAVE_SS, FN_SLAVE_SCLK,
	FN_I2S0_MCLK, FN_I2S0_SCLK, FN_I2S0_WS,
	FN_I2S0_IN_D0, FN_I2S0_IN_D1, FN_I2S0_IN_D2, FN_I2S0_IN_D3,
	FN_I2S0_OUT_D0, FN_I2S0_OUT_D1, FN_I2S0_OUT_D2, FN_I2S0_OUT_D3,
	FN_I2S1_MCLK, FN_I2S1_SCLK, FN_I2S1_WS,
	FN_I2S1_IN_D0, FN_I2S1_IN_D1, FN_I2S1_IN_D2, FN_I2S1_IN_D3,
	FN_I2S1_OUT_D0, FN_I2S1_OUT_D1, FN_I2S1_OUT_D2, FN_I2S1_OUT_D3,
	FN_I2S2_MCLK, FN_I2S2_SCLK, FN_I2S2_WS,
	FN_I2S2_IN_D0, FN_I2S2_IN_D1, FN_I2S2_IN_D2, FN_I2S2_IN_D3,
	FN_I2S2_OUT_D0, FN_I2S2_OUT_D1, FN_I2S2_OUT_D2, FN_I2S2_OUT_D3,
	FN_RESERVED0, FN_RESERVED1, FN_RESERVED2, FN_RESERVED3, FN_RESERVED4, FN_RESERVED5,
	FN_I2C0_SCLK, FN_I2C0_SDA,
	FN_I2C1_SCLK, FN_I2C1_SDA,
	FN_I2C2_SCLK, FN_I2C2_SDA,
	FN_CMOS_XCLK, FN_CMOS_RST, FN_CMOS_PWDN, FN_CMOS_VSYNC, FN_CMOS_HREF, FN_CMOS_PCLK,
	FN_CMOS_D0, FN_CMOS_D1, FN_CMOS_D2, FN_CMOS_D3, FN_CMOS_D4, FN_CMOS_D5, FN_CMOS_D6, FN_CMOS_D7,
	FN_SCCB_SCLK, FN_SCCB_SDA,
	FN_UART1_CTS, FN_UART1_DSR, FN_UART1_DCD, FN_UART1_RI, FN_UART1_SIR_IN, FN_UART1_DTR, FN_UART1_RTS,
	FN_UART1_OUT2, FN_UART1_OUT1, FN_UART1_SIR_OUT, FN_UART1_BAUD, FN_UART1_RE, FN_UART1_DE, FN_UART1_RS485_ENABLE,
	FN_UART2_CTS, FN_UART2_DSR, FN_UART2_DCD, FN_UART2_RI, FN_UART2_SIR_IN, FN_UART2_DTR, FN_UART2_RTS,
	FN_UART2_OUT2, FN_UART2_OUT1, FN_UART2_SIR_OUT, FN_UART2_BAUD, FN_UART2_RE, FN_UART2_DE, FN_UART2_RS485_ENABLE,
	FN_UART3_CTS, FN_UART3_DSR, FN_UART3_DCD, FN_UART3_RI, FN_UART3_SIR_IN, FN_UART3_DTR, FN_UART3_RTS,
	FN_UART3_OUT2, FN_UART3_OUT1, FN_UART3_SIR_OUT, FN_UART3_BAUD, FN_UART3_RE, FN_UART3_DE, FN_UART3_RS485_ENABLE,
	FN_TIMER0_TOGGLE1, FN_TIMER0_TOGGLE2, FN_TIMER0_TOGGLE3, FN_TIMER0_TOGGLE4,
	FN_TIMER1_TOGGLE1, FN_TIMER1_TOGGLE2, FN_TIMER1_TOGGLE3, FN_TIMER1_TOGGLE4,
	FN_TIMER2_TOGGLE1, FN_TIMER2_TOGGLE2, FN_TIMER2_TOGGLE3, FN_TIMER2_TOGGLE4,
	FN_CLK_SPI2, FN_CLK_I2C2,
	FN_INTERNAL0, FN_INTERNAL1, FN_INTERNAL2, FN_INTERNAL3, FN_INTERNAL4,
	FN_INTERNAL5, FN_INTERNAL6, FN_INTERNAL7, FN_INTERNAL8, FN_INTERNAL9,
	FN_INTERNAL10, FN_INTERNAL11, FN_INTERNAL12, FN_INTERNAL13, FN_INTERNAL14,
	FN_INTERNAL15, FN_INTERNAL16, FN_INTERNAL17,
	FN_CONST, FN_INTERNAL18,
	FN_DEBUG0, FN_DEBUG1, FN_DEBUG2, FN_DEBUG3, FN_DEBUG4,
	FN_DEBUG5, FN_DEBUG6, FN_DEBUG7, FN_DEBUG8, FN_DEBUG9,
	FN_DEBUG10, FN_DEBUG11, FN_DEBUG12, FN_DEBUG13, FN_DEBUG14,
	FN_DEBUG15, FN_DEBUG16, FN_DEBUG17, FN_DEBUG18, FN_DEBUG19,
	FN_DEBUG20, FN_DEBUG21, FN_DEBUG22, FN_DEBUG23, FN_DEBUG24,
	FN_DEBUG25, FN_DEBUG26, FN_DEBUG27, FN_DEBUG28, FN_DEBUG29,
	FN_DEBUG30, FN_DEBUG31,
	FN_MAX,
} k210_fpioa_func_t;
static_assert(FN_MAX == 256);

typedef struct {
	uint8_t channel;
	uint8_t div : 4;
	uint8_t out_enable : 1;
	uint8_t out_inv    : 1;
	uint8_t data_out   : 1;
	uint8_t data_inv   : 1;
	uint8_t pullup     : 1;
	uint8_t pulldown   : 1;
	uint8_t reserved   : 1;
	uint8_t slew       : 1;
	uint8_t in_enable  : 1;
	uint8_t in_inv     : 1;
	uint8_t data_in_inv: 1;
	uint8_t sch_trigger: 1;
	uint8_t reserved1  : 7;
	uint8_t pad_di     : 1;
} __attribute__((packed, aligned(4))) k210_fpioa_io_cfg_t;

typedef struct {
	k210_fpioa_io_cfg_t io[FPIOA_NUM_IO];
} __attribute__((packed, aligned(4))) fpioa_t;

extern volatile fpioa_t* const fpioa;

//int k210_fpioa_init(void);
void k210_fpioa_set_func(uint8_t num, k210_fpioa_func_t func);
void k210_fpioa_set_pull(uint8_t num, k210_fpioa_pull_t pull);

#endif