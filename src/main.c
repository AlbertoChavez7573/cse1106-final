#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define PIN 17
int main(int argc, char* argv[])
{
   gpioInitialise();
   gpioSetMode(PIN, PI_OUTPUT);
   int max_capacity = 5; 
   int students = 0; //number of students
   printf("The current maximum capacity is %d. If this is incorrect, input the new capacity. ", max_capacity);
   scanf("%d", &max_capacity);
   while(max_capacity <= 0){
         printf("Invalid Number. Try again ");
         scanf("%d", &max_capacity);
   }
   while(students < max_capacity && students >= 0){
      gpioWrite(PIN, 0); //LED OFF
      printf("How many students are currently in the room? ");
      scanf("%d", &students);
      while(students < 0){
         printf("Invalid Number. Try again ");
         scanf("%d", &students);
      } 
      if(students < max_capacity){
         printf("%d/%d Room has space available\n", students, max_capacity);
      }
   }
   if(students > max_capacity){
         printf("%d/%d Room is already at capacity.\n", max_capacity, max_capacity);
   }
   if(students == max_capacity){
      gpioWrite(PIN, 1); //LED ON
      printf("%d/%d Room is full\n", students, max_capacity);
   }
   gpioTerminate();
   return 0;
}
