///////////////////////////////////////////////////////////////////////////////
//          University of Hawaii, College of Engineering
/// @brief  Lab 06c - countdown - EE 205 - Spr 2022
//
// Usage:  countdown
//
// Result:
//   Counts down (or towards) a significant date
//
// @author Brayden Suzuki <braydens@hawaii.edu>
// @date   Feb 21 2022
///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void delay(int seconds) {

   int milli_seconds = 1000 * seconds;

   clock_t start_time = clock();

   while (clock() < start_time + milli_seconds)
      ;
}

int main() {
   time_t ref_time;
   struct tm reference;
   char ref_array[80];

   reference.tm_year = 2022- 1900; //setting reference time
   reference.tm_mon = 2 - 1;
   reference.tm_mday = 21;
   reference.tm_hour = 19;
   reference.tm_min = 27;
   reference.tm_sec = 0;
   reference.tm_isdst = -1;

   ref_time = mktime(&reference);

   strftime(ref_array, sizeof(ref_array), "%a %b %d %l:%M:%S %p %Z %Y", &reference); //formatting reference time

   printf("Reference time: %s\n", ref_array);

   time_t curr_time; 
   curr_time = time( NULL ); //creating current time in seconds in reference to Unix epoch

   time_t diff_time = ref_time - curr_time ;
   time_t i = diff_time;

   if (diff_time > 0) {
      while (i >= 0) {
         time_t years = floor( i / 31536000);
         time_t days = floor((i % 31536000) / 86400);
         time_t hours = floor(((i % 31536000) % 86400) / 3600);
         time_t minutes = floor((((i % 31536000) % 86400) % 3600) / 60);
         time_t seconds = (((i % 31536000) % 86400) % 3600) % 60;
         printf("Years: %ld Days: %ld Hours: %ld Minutes: %ld Seconds: %ld\n", years, days, hours, minutes, seconds);
         delay(1000);
         i = i - 1;
         if (i == 0) {
            printf("Time reached!\n");
         }
      }
   }
   else {
      i = i * -1;
      while (i >= 0) {
         time_t years = floor( i / 31536000);
         time_t days = floor((i % 31536000) / 86400);
         time_t hours = floor(((i % 31536000) % 86400) / 3600);
         time_t minutes = floor((((i % 31536000) % 86400) % 3600) / 60);
         time_t seconds = (((i % 31536000) % 86400) % 3600) % 60;
         printf("Years: %ld Days: %ld Hours: %ld Minutes: %ld Seconds: %ld\n", years, days, hours, minutes, seconds);
         delay(1000);
         i = i + 1;
      }
   }

   return 0;
}
