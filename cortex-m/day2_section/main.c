const int g=0x1234;
int h;
int main(void){
   int a=1,b=5;
   static int c;
   c = a + b + g + h;
}