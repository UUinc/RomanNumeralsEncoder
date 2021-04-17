#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char * RomanNumeralsEncoder(int n);

int main()
{
    int n;
    char *r;

    do
    {
        printf("Give a decimal number (max = 3999): ");
        scanf("%d",&n);

        if(n<1 || n>3999)
            printf("\nError : number < 1 or number > 3999\n");
    } while (n<1 || n>3999);
    
    r = RomanNumeralsEncoder(n);

    printf("\n%d = %s",n,r);

    return 0;
}
char * RomanNumeralsEncoder(int n) 
{
  int i,p=0,in,c=0;
  char romanNumber[7] = "IVXLCDM";
  char *romanEncoded;
  
  //allocate some memory for encoded roman number
  romanEncoded = (char *) malloc(100 * sizeof(char));
  //get the length of decimal number
  while(n/(int)pow(10,p) > 0)
    p++;p--;
  //get each individual number at a time
  for(;p>=0; p--)
  {
      in = n/(int)pow(10,p);
      n-=in * (int)pow(10,p);

      //work with each individual number in the input
      //encode the number from decimal to roman
      if(in <= 3)
          for(i=0; i<in; i++)
          {
              romanEncoded[c] = romanNumber[p*2];
              c++;
          }
      else if(in == 4)
      {
          romanEncoded[c] = romanNumber[p*2]; c++;
          romanEncoded[c] = romanNumber[p*2+1]; c++;
      }
      else if(in <= 8)
      {
          romanEncoded[c] = romanNumber[p*2+1]; c++;
          for(i=0; i<in-5; i++)
          {
              romanEncoded[c] = romanNumber[p*2]; c++;
          }
      }
      else
      {
          romanEncoded[c] = romanNumber[p*2]; c++;
          romanEncoded[c] = romanNumber[p*2+2]; c++;
      }
  }
  //the end character for the roman numeral
  romanEncoded[c] = '\0';
  
  return romanEncoded;
}