#include <stdio.h>
#include "nuc980.h"
#include "sys.h"
#include "uart.h"
#include "etimer.h"
#define SYS_MIN_INT_SOURCE       1
#define SYS_MAX_INT_SOURCE       63
#define SYS_NUM_OF_AICREG        16

/* Global variables */
UINT32 volatile _sys_bIsAICInitial = 0x0;


void SYS_IRQ_Shell(void)
{
    //printf("ISR not found! ISNR=%d\n", inpw(REG_AIC_IRQNUM));
}

void SYS_FIQ_Shell(void)
{
    //printf("ISR not found! ISNR=%d\n", inpw(REG_AIC_FIQNUM));
}
sys_pvFunPtr sysIrqHandlerTable[] = { 0,           /* 0 */
                                      SYS_IRQ_Shell,   /* 1 */
                                      SYS_IRQ_Shell,   /* 2 */
                                      SYS_IRQ_Shell,   /* 3 */
                                      SYS_IRQ_Shell,   /* 4 */
                                      SYS_IRQ_Shell,   /* 5 */
                                      SYS_IRQ_Shell,   /* 6 */
                                      SYS_IRQ_Shell,   /* 7 */
                                      SYS_IRQ_Shell,   /* 8 */
                                      SYS_IRQ_Shell,   /* 9 */
                                      SYS_IRQ_Shell,   /* 10 */
                                      SYS_IRQ_Shell,   /* 11 */
                                      SYS_IRQ_Shell,   /* 12 */
                                      SYS_IRQ_Shell,   /* 13 */
                                      SYS_IRQ_Shell,   /* 14 */
                                      SYS_IRQ_Shell,   /* 15 */
                                      SYS_IRQ_Shell,   /* 16 */
                                      SYS_IRQ_Shell,   /* 17 */
                                      SYS_IRQ_Shell,   /* 18 */
                                      SYS_IRQ_Shell,   /* 19 */
                                      SYS_IRQ_Shell,   /* 20 */
                                      SYS_IRQ_Shell,   /* 21 */
                                      SYS_IRQ_Shell,   /* 22 */
                                      SYS_IRQ_Shell,   /* 23 */
                                      SYS_IRQ_Shell,   /* 24 */
                                      SYS_IRQ_Shell,   /* 25 */
                                      SYS_IRQ_Shell,   /* 26 */
                                      SYS_IRQ_Shell,   /* 27 */
                                      SYS_IRQ_Shell,   /* 28 */
                                      SYS_IRQ_Shell,   /* 29 */
                                      SYS_IRQ_Shell,   /* 30 */
                                      SYS_IRQ_Shell,   /* 31 */
                                      SYS_IRQ_Shell,   /* 32 */
                                      SYS_IRQ_Shell,   /* 33 */
                                      SYS_IRQ_Shell,   /* 34 */
                                      SYS_IRQ_Shell,   /* 35 */
                                      SYS_IRQ_Shell,   /* 36 */
                                      SYS_IRQ_Shell,   /* 37 */
                                      SYS_IRQ_Shell,   /* 38 */
                                      SYS_IRQ_Shell,   /* 39 */
                                      SYS_IRQ_Shell,   /* 40 */
                                      SYS_IRQ_Shell,   /* 41 */
                                      SYS_IRQ_Shell,   /* 42 */
                                      SYS_IRQ_Shell,   /* 43 */
                                      SYS_IRQ_Shell,   /* 44 */
                                      SYS_IRQ_Shell,   /* 45 */
                                      SYS_IRQ_Shell,   /* 46 */
                                      SYS_IRQ_Shell,   /* 47 */
                                      SYS_IRQ_Shell,   /* 48 */
                                      SYS_IRQ_Shell,   /* 49 */
                                      SYS_IRQ_Shell,   /* 50 */
                                      SYS_IRQ_Shell,   /* 51 */
                                      SYS_IRQ_Shell,   /* 52 */
                                      SYS_IRQ_Shell,   /* 53 */
                                      SYS_IRQ_Shell,   /* 54 */
                                      SYS_IRQ_Shell,   /* 55 */
                                      SYS_IRQ_Shell,   /* 56 */
                                      SYS_IRQ_Shell,   /* 57 */
                                      SYS_IRQ_Shell,   /* 58 */
                                      SYS_IRQ_Shell,   /* 59 */
                                      SYS_IRQ_Shell,   /* 60 */
                                      SYS_IRQ_Shell,   /* 61 */
                                      SYS_IRQ_Shell,   /* 62 */
                                      SYS_IRQ_Shell    /* 63 */
                                    };

sys_pvFunPtr sysFiqHandlerTable[] = { 0,
                                      SYS_FIQ_Shell,   /* 1 */
                                      SYS_FIQ_Shell,   /* 2 */
                                      SYS_FIQ_Shell,   /* 3 */
                                      SYS_FIQ_Shell,   /* 4 */
                                      SYS_FIQ_Shell,   /* 5 */
                                      SYS_FIQ_Shell,   /* 6 */
                                      SYS_FIQ_Shell,   /* 7 */
                                      SYS_FIQ_Shell,   /* 8 */
                                      SYS_FIQ_Shell,   /* 9 */
                                      SYS_FIQ_Shell,   /* 10 */
                                      SYS_FIQ_Shell,   /* 11 */
                                      SYS_FIQ_Shell,   /* 12 */
                                      SYS_FIQ_Shell,   /* 13 */
                                      SYS_FIQ_Shell,   /* 14 */
                                      SYS_FIQ_Shell,   /* 15 */
                                      SYS_FIQ_Shell,   /* 16 */
                                      SYS_FIQ_Shell,   /* 17 */
                                      SYS_FIQ_Shell,   /* 18 */
                                      SYS_FIQ_Shell,   /* 19 */
                                      SYS_FIQ_Shell,   /* 20 */
                                      SYS_FIQ_Shell,   /* 21 */
                                      SYS_FIQ_Shell,   /* 22 */
                                      SYS_FIQ_Shell,   /* 23 */
                                      SYS_FIQ_Shell,   /* 24 */
                                      SYS_FIQ_Shell,   /* 25 */
                                      SYS_FIQ_Shell,   /* 26 */
                                      SYS_FIQ_Shell,   /* 27 */
                                      SYS_FIQ_Shell,   /* 28 */
                                      SYS_FIQ_Shell,   /* 29 */
                                      SYS_FIQ_Shell,   /* 30 */
                                      SYS_FIQ_Shell,   /* 31 */
                                      SYS_FIQ_Shell,   /* 32 */
                                      SYS_FIQ_Shell,   /* 33 */
                                      SYS_FIQ_Shell,   /* 34 */
                                      SYS_FIQ_Shell,   /* 35 */
                                      SYS_FIQ_Shell,   /* 36 */
                                      SYS_FIQ_Shell,   /* 37 */
                                      SYS_FIQ_Shell,   /* 38 */
                                      SYS_FIQ_Shell,   /* 39 */
                                      SYS_FIQ_Shell,   /* 40 */
                                      SYS_FIQ_Shell,   /* 41 */
                                      SYS_FIQ_Shell,   /* 42 */
                                      SYS_FIQ_Shell,   /* 43 */
                                      SYS_FIQ_Shell,   /* 44 */
                                      SYS_FIQ_Shell,   /* 45 */
                                      SYS_FIQ_Shell,   /* 46 */
                                      SYS_FIQ_Shell,   /* 47 */
                                      SYS_FIQ_Shell,   /* 48 */
                                      SYS_FIQ_Shell,   /* 49 */
                                      SYS_FIQ_Shell,   /* 50 */
                                      SYS_FIQ_Shell,   /* 51 */
                                      SYS_FIQ_Shell,   /* 52 */
                                      SYS_FIQ_Shell,   /* 53 */
                                      SYS_FIQ_Shell,   /* 54 */
                                      SYS_FIQ_Shell,   /* 55 */
                                      SYS_FIQ_Shell,   /* 56 */
                                      SYS_FIQ_Shell,   /* 57 */
                                      SYS_FIQ_Shell,   /* 58 */
                                      SYS_FIQ_Shell,   /* 59 */
                                      SYS_FIQ_Shell,   /* 60 */
                                      SYS_FIQ_Shell,   /* 61 */
                                      SYS_FIQ_Shell,   /* 62 */
                                      SYS_FIQ_Shell    /* 63 */
                                    };



#if defined (__GNUC__) && !(__CC_ARM)
static void __attribute__ ((interrupt("IRQ"))) sysIrqHandler(void)
#else
__irq void sysIrqHandler()
#endif
{
    UINT32 volatile num;

    num = inpw(REG_AIC_IRQNUM);
    if (num != 0)
        (*sysIrqHandlerTable[num])();
    outpw(REG_AIC_EOIS, 1);
}

#if defined (__GNUC__) && !(__CC_ARM)
static void __attribute__ ((interrupt("FIQ"))) sysFiqHandler(void)
#else
__irq void sysFiqHandler()
#endif
{
    UINT32 volatile num;

    num = inpw(REG_AIC_FIQNUM);
    if (num != 0)
        (*sysFiqHandlerTable[num])();
    outpw(REG_AIC_EOFS, 1);
}

INT32 sysEnableInterrupt(IRQn_Type eIntNo)
{
    if ((eIntNo > SYS_MAX_INT_SOURCE) || (eIntNo < SYS_MIN_INT_SOURCE))
        return Fail;

    if (eIntNo < 32)
        outpw(REG_AIC_INTEN0, (1 << eIntNo));
    else
        outpw(REG_AIC_INTEN1, (1 << (eIntNo - 32)));

    return Successful;
}

void sysInitializeAIC()
{
    *(unsigned int volatile *)0x38 = (unsigned int)sysIrqHandler;

    *(unsigned int volatile *)0x3C = (unsigned int)sysFiqHandler;
}
void ETMR0_IRQHandler(void)
{
    static uint32_t sec = 1;
    //printf("%d sec\n", sec++);

    // clear timer interrupt flag
    ETIMER_ClearIntFlag(0);
}
INT32 sysSetLocalInterrupt(INT32 nIntState)
{
#if defined (__GNUC__) && !(__CC_ARM)

# else
    INT32 temp;
#endif

    switch (nIntState)
    {
    case ENABLE_IRQ:
    case ENABLE_FIQ:
    case ENABLE_FIQ_IRQ:
#if defined (__GNUC__) && !(__CC_ARM)
    asm
        (
            "mrs    r0, CPSR  \n"
            "bic    r0, r0, #0x80  \n"
            "msr    CPSR_c, r0  \n"
        );
#else
        __asm
        {
            MRS    temp, CPSR
            AND    temp, temp, nIntState
            MSR    CPSR_c, temp
        }
#endif
        break;

    case DISABLE_IRQ:
    case DISABLE_FIQ:
    case DISABLE_FIQ_IRQ:
#if defined ( __GNUC__ ) && !(__CC_ARM)
    asm
        (
            "MRS    r0, CPSR  \n"
            "ORR    r0, r0, #0x80  \n"
            "MSR    CPSR_c, r0  \n"
        );
#else
        __asm
        {
            MRS    temp, CPSR
            ORR    temp, temp, nIntState
            MSR    CPSR_c, temp
        }
#endif
        break;

    default:
        ;
    }
    return 0;
}

PVOID sysInstallISR(INT32 nIntTypeLevel, IRQn_Type eIntNo, PVOID pvNewISR)
{
    PVOID   _mOldVect;
    UINT32  _mRegAddr;//, _mRegValue;
    INT     shift;

    if (!_sys_bIsAICInitial)
    {
        sysInitializeAIC();
        _sys_bIsAICInitial = TRUE;
    }

    _mRegAddr = REG_AIC_SRCCTL0 + ((eIntNo / 4) * 4);
    shift = (eIntNo % 4) * 8;
    nIntTypeLevel &= 0xff;
    outpw(_mRegAddr, (inpw(_mRegAddr) & ~(0x0f << shift)) | (nIntTypeLevel << shift));

    if ((nIntTypeLevel & 0x7) == FIQ_LEVEL_0)
    {
        _mOldVect = (PVOID) sysFiqHandlerTable[eIntNo];
        sysFiqHandlerTable[eIntNo] = (sys_pvFunPtr)pvNewISR;
    }
    else
    {
        _mOldVect = (PVOID) sysIrqHandlerTable[eIntNo];
        sysIrqHandlerTable[eIntNo] = (sys_pvFunPtr)pvNewISR;
    }
    return _mOldVect;
}

INT32 sysGetPLL(UINT32 reg)
{
    UINT32 N,M,P;

    N =((inpw(reg) & 0x007F)>>0)+1;
    M =((inpw(reg) & 0x1F80)>>7)+1;
    P =((inpw(reg) & 0xE000)>>13)+1;

    return (12*N/(M*P));    /* 12MHz HXT */
}
/// @endcond HIDDEN_SYMBOLS

/**
 *  @brief  system Timer - install WDT interrupt handler
 *
 *  @param[in]  clk   clock source. \ref CLK_Type
 *
 *  @return   MHz
 */
UINT32 sysGetClock(CLK_Type clk)
{
    UINT32 src, divN, reg;

    switch(clk)
    {
    case SYS_UPLL:
        return sysGetPLL(REG_CLK_UPLLCON);

    case SYS_APLL:
        return sysGetPLL(REG_CLK_APLLCON);

    case SYS_SYSTEM:
    {
        reg = inpw(REG_CLK_DIVCTL0);
        switch (reg & 0x18)
        {
        case 0x0:
            src = 12;   /* HXT */
            break;
        case 0x10:
            src = sysGetPLL(REG_CLK_APLLCON);
            break;
        case 0x18:
            src = sysGetPLL(REG_CLK_UPLLCON);
            break;
        default:
            return 0;
        }
        divN = ((reg & 0x100) >> 8) + 1;
        return (src / divN);
    }

    case SYS_HCLK:
    {
        reg = inpw(REG_CLK_DIVCTL0);
        switch (reg & 0x18)
        {
        case 0x0:
            src = 12;   /* HXT */
            break;
        case 0x10:
            src = sysGetPLL(REG_CLK_APLLCON);
            break;
        case 0x18:
            src = sysGetPLL(REG_CLK_UPLLCON);
            break;
        default:
            return 0;
        }
        divN = ((reg & 0x100) >> 8) + 1;
        return (src / divN / 2);
    }

    case SYS_PCLK01:
    {
        reg = inpw(REG_CLK_DIVCTL0);
        switch (reg & 0x18)
        {
        case 0x0:
            src = 12;   /* HXT */
            break;
        case 0x10:
            src = sysGetPLL(REG_CLK_APLLCON);
            break;
        case 0x18:
            src = sysGetPLL(REG_CLK_UPLLCON);
            break;
        default:
            return 0;
        }
        divN = ((reg & 0x100) >> 8) + 1;
        return (src / divN / 2);
    }

    case SYS_CPU:
    {
        reg = inpw(REG_CLK_DIVCTL0);
        switch (reg & 0x18)
        {
        case 0x0:
            src = 12;   /* HXT */
            break;
        case 0x10:
            src = sysGetPLL(REG_CLK_APLLCON);
            break;
        case 0x18:
            src = sysGetPLL(REG_CLK_UPLLCON);
            break;
        default:
            return 0;
        }
        divN = ((reg & 0x10000) >> 16) + 1;
        return (src / divN);
    }

    case SYS_PCLK2:
    {
        reg = inpw(REG_CLK_DIVCTL0);
        switch (reg & 0x18)
        {
        case 0x0:
            src = 12;   /* HXT */
            break;
        case 0x10:
            src = sysGetPLL(REG_CLK_APLLCON);
            break;
        case 0x18:
            src = sysGetPLL(REG_CLK_UPLLCON);
            break;
        default:
            return 0;
        }
        divN = ((reg & 0x100) >> 8) + 1;
        return (src / divN / 2 / 2);
    }
    default:
        ;
    }
    return 0;   //write me!!
}




void UART_Init()
{
    /* enable UART0 clock */
    *(uint32_t*)REG_CLK_PCLKEN0 |= 0x10000;

    /* GPF11, GPF12 */
    *(uint32_t*)REG_SYS_GPF_MFPH = (*(uint32_t*)REG_SYS_GPF_MFPH&0xfff00fff) | 0x11000; // UART0 multi-function
    
    *(uint32_t*)REG_UART0_LCR |= 0x07;  /* UART0 line configuration for (115200,n,8,1) */
   
    *(uint32_t*)REG_UART0_BAUD |= 0x30000066;   /* 12MHz reference clock input, 115200 */
}

extern int _write (int fd, char *ptr, int len);
int main(){
    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);

 UART_Init();
	
   // Enable ETIMER0 engine clock
    outpw(REG_CLK_PCLKEN0, inpw(REG_CLK_PCLKEN0) | (1 << 8));

    // Set timer frequency to 1HZ
    ETIMER_Open(0, ETIMER_PERIODIC_MODE, 1);

    // Enable timer interrupt
    ETIMER_EnableInt(0);
    sysInstallISR(IRQ_LEVEL_1, IRQ_TIMER0, (PVOID)ETMR0_IRQHandler);
    sysSetLocalInterrupt(ENABLE_IRQ);
    sysEnableInterrupt(IRQ_TIMER0);

    // Start Timer 0
    ETIMER_Start(0);


  while(1){
  
  ;
  }

}
int sum(int x, int y)
{
  return x+y;
}

  
