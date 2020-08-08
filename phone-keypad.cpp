//Phone Keypad Problem
#include<iostream>
using namespace std;
char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"}; 
void generate_names(char *in, char* out, int i, int j)
{
   //base case
   if(in[i]=='\0')
   {
      out[j]='\0';
      cout<< out <<endl;
      return;
   }
   //rec case
   int digit = in[i]-'0';      //Gives integer value
   if(digit==0 || digit==1)
      generate_names(in,out,i+1,j);
   for(int k=0; keypad[digit][k]!='\0';k++)
   {
      out[j]=keypad[digit][k];
      //fill the remaining part
      generate_names(in,out,i+1,j+1);
   }
   return;
}
int main()
{
   char input[100];
   cin>>input;
   char output[100];
   generate_names(input,output,0,0);
   return 0;
}