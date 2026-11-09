#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define PIN 17
#define MAX_CAPACITY 5 //max capacity of students

int main(int argc, char* argv[])
{
   int students = 0; //number of students
   while(students < MAX_CAPACITY){
      printf("How many students are currently in the room? ");
      scanf("%d", &students);
   }
   gpioInitialise();
   gpioSetMode(PIN, PI_OUTPUT);
   gpioWrite(PIN, 1); //LED ON
   getchar();  //waits for Enter key
   gpioWrite(PIN, 0); //LED OFF
   getchar(); //waits for Enter key
   gpioTerminate();
   return 0;
}
