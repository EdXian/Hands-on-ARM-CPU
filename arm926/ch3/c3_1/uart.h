#ifndef _UART_H_
#define _UART_H_


#define DR 0x00
#define FR 0x18

typedef struct uart{
  char *base;           // base address
  int  n;
}UART;

UART uart[4];          // 4 UART structs

int uart_init();


int uputc(UART *up, char c);

int ugetc(UART *up);

int ugets(UART *up, char *s);


int uputs(UART *up, char *s);


int uprints(UART *up, char *s);

int urpx(UART *up, int x);


int uprintx(UART *up, int x);


int urpu(UART *up, int x);


int uprintu(UART *up, int x);


int uprinti(UART *up, int x);


int ufprintf(UART *up, char *fmt,...);


int uprintf(char *fmt, ...);



#endif