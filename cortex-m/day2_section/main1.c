const int g=0x1234;
int h;
int s = 0xabab;
__attribute__((section(".ramfunc"))) extern int multiple(int x, int y) ;
int main(void){
   int a=1,b=5;
   static int c;
   c =  multiple(1, 5);
}