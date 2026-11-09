#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>


#define PIN 17

void test_t1(int max_capacity){
      int students = 0;
      if(students == max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }

      if (students < 0){
         printf("Invalid Number. Try again ");
      }
      if(students < max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }
      if(students == max_capacity){
        gpioWrite(PIN, 1); //LED ON
        printf("%d/%d Room is full.\n", students, max_capacity); 
      }
      if(students > max_capacity){
         gpioWrite(PIN, 1); //LED ON
         printf("%d/%d Room is already at capacity.\n", max_capacity, max_capacity);
   }
}

int main(int argc, char* argv[])
{
   FILE *log = fopen("student_log.csv", "w+");
   if(log == NULL){
      printf("Invalid file");
      return 1;
   }
   gpioInitialise();
   gpioSetMode(PIN, PI_OUTPUT);
   gpioWrite(PIN, 0); //LED OFF
   int max_capacity = 5;
   int students = 0; //number of students
   printf("The current maximum capacity is %d. If this is incorrect, input the new capacity. ", max_capacity);
   scanf("%d", &max_capacity);
   while(max_capacity <= 0){
         printf("Invalid Number. Try again ");
         scanf("%d", &max_capacity);
   }

   //Test Cases
   printf("Test Cases: \n");
   printf("T1 (0): ");
   test_t1(max_capacity);
   printf("T2 (Max Capacity): ");
  // test_t2(max_capacity);
   printf("T3 (Max Capacity - 1): ");
  // test_t3(max_capacity);
   printf("T4 (Max Capacity + 1): ");
  // test_t4(max_capacity);
   printf("T5 (-1): ");
  // test_t5(max_capacity);
   
   while(students >= 0){
      printf("How many students are currently in the room? ");
      scanf("%d", &students);
      while(students < 0){
         printf("Invalid Number. Try again ");
         scanf("%d", &students);
      } 
      if(students < max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }
     if(students == max_capacity){
        gpioWrite(PIN, 1); //LED ON
        printf("%d/%d Room is full.\n", students, max_capacity); 
      }
      if(students > max_capacity){
         gpioWrite(PIN, 1); //LED ON
         printf("%d/%d Room is already at capacity.\n", max_capacity, max_capacity);
       }
      fprintf(log, "%d\n", students);
   }  
   gpioTerminate();
   fclose(log);
   return 0;
}
/*
void test_t1(int max_capacity){
      int students = 0;
      if(students == max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }

      if (students < 0){
         printf("Invalid Number. Try again ");
      }
      if(students < max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }
      if(students == max_capacity){
        gpioWrite(PIN, 1); //LED ON
        printf("%d/%d Room is full.\n", students, max_capacity); 
      }
      if(students > max_capacity){
         gpioWrite(PIN, 1); //LED ON
         printf("%d/%d Room is already at capacity.\n", max_capacity, max_capacity);
   }
}
void test_t2(int max_capacity){
      int students = max_capacity;
      if(students == max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }

      if (students < 0){
         printf("Invalid Number. Try again ");
      }
      if(students < max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }
      if(students == max_capacity){
        gpioWrite(PIN, 1); //LED ON
        printf("%d/%d Room is full.\n", students, max_capacity); 
      }
      if(students > max_capacity){
         gpioWrite(PIN, 1); //LED ON
         printf("%d/%d Room is already at capacity.\n", max_capacity, max_capacity);
      }

   }
void test_t3(int max_capacity){
      int students = max_capacity+1;
      if(students == max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }

      if (students < 0){
         printf("Invalid Number. Try again ");
      }
      if(students < max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }
      if(students == max_capacity){
        gpioWrite(PIN, 1); //LED ON
        printf("%d/%d Room is full.\n", students, max_capacity); 
      }
      if(students > max_capacity){
         gpioWrite(PIN, 1); //LED ON
         printf("%d/%d Room is already at capacity.\n", max_capacity, max_capacity);
      }
   }
void test_t4(int max_capacity){
      int students = max_capacity-1;
      if(students == max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }

      if (students < 0){
         printf("Invalid Number. Try again ");
      }
      if(students < max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }
      if(students == max_capacity){
        gpioWrite(PIN, 1); //LED ON
        printf("%d/%d Room is full.\n", students, max_capacity); 
      }
      if(students > max_capacity){
         gpioWrite(PIN, 1); //LED ON
         printf("%d/%d Room is already at capacity.\n", max_capacity, max_capacity);
      }
   }
void test_t5(int max_capacity){
      int students = -1;
      if(students == max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }

      if (students < 0){
         printf("Invalid Number. Try again ");
      }
      if(students < max_capacity){
         gpioWrite(PIN, 0); //LED OFF
         printf("%d/%d Room has space available\n", students, max_capacity);
      }
      if(students == max_capacity){
        gpioWrite(PIN, 1); //LED ON
        printf("%d/%d Room is full.\n", students, max_capacity); 
      }
      if(students > max_capacity){
         gpioWrite(PIN, 1); //LED ON
         printf("%d/%d Room is already at capacity.\n", max_capacity, max_capacity);
      }
   }
*/
