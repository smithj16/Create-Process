#include <stdio.h>   // scanf(), fscanf(), fprintf(), fopen()
#include <stdlib.h>  // atoi(), getenv()

int main(int argc, char* argv[])
{
   
    int column = 3;
    int precision = 13;
    int num = 0;
    float number;
   
 // reading data from the config file
    FILE *fp;
    if ((fp = fopen("filter.cfg", "r")) != NULL) {
    fscanf(fp,"%d%d", &column, &precision);
   
  }
  
  //reading data from the env. variables
  char *op = getenv("CS302HW1COLUMNS");
  char *opp = getenv("CS302HW1PRECISION");
  if (op != NULL) {
      column = atoi(op);
      if(opp != NULL){
     
      precision = atoi(opp);
      }
  }
 
 //reading data from the cmd
  if (argc > 1) {
      column = atoi(argv[1]);
      precision = atoi(argv[2]);
  }

// printing data 
while (scanf("%f", &number) != EOF){
 
 printf("%*.*f",precision + 7, precision,  number);
 num++;
 
 if (num == column){
 printf("\n");
 num = 0;
 }
 
 }
 
 
  return 0;
}