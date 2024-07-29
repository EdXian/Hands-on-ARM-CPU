const int g=0x1234;
int h;

/*extern add from assembly code*/
extern int add(int x, int y);

float add1(int x, int y){
 int a=1;
 int b =2;
 float c =3;
 float d  =4;

  return add(x, y)+a*b+d/c;
}

int main(void){
   int a=1,b=5;
   static float c;
   c = add1(a,b);
}