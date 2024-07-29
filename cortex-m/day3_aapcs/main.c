const int g=0x1234;
int h;

/*extern add from assembly code*/
extern int add(int x, int y);

int add1(int x, int y){
 int a=1;
 int b =2;
int c =3;
 int d  =4;

  return add(x, y)+a+b+c+d;
}

int main(void){
   int a=1,b=5;
   static int c;
   c = add1(a,b);
}