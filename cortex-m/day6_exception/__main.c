
extern int  _e_text ;
extern int  _s_data ;
extern int   _e_data ;
extern int    _s_bss ;
extern int    _e_bss ;
extern int main(void);

void __main(){

 char *p, *q;
 q = (char*)&_e_text;
 p = (char*)&_s_data;

 /* relocate initialized data section to ram */
 for(  ;  p!=(char*)&_e_data ;  ){
  *p++ = *q++ ;
 }

/* Initialize bss section */
 for( p=(char*)&_s_bss ;  p!=(char*)&_e_bss ;  ){
  *p++ = 0;
 }

/*jump to the main function*/
 main();
}