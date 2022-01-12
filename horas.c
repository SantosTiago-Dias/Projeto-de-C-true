#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Print the current date and time in C
int main(void)
{
    // variables to store the date and time components
    int hours, minutes, seconds, day, month, year;

    // `time_t` is an arithmetic time type
    time_t now;

    // Obtain current time
    // `time()` returns the current time of the system as a `time_t` value
    time(&now);
    hours = localtime(&now)->tm_hour;  // get hours since midnight (0-23)
    minutes = localtime(&now)->tm_min; // get minutes passed after the hour (0-59)
    seconds = localtime(&now)->tm_sec; // get seconds passed after a minute (0-59)

    day = localtime(&now)->tm_mday;      // get day of month (1 to 31)
    month = localtime(&now)->tm_mon + 1; // get month of year (0 to 11)
    year = localtime(&now)->tm_year;     // get year since 1900
    printf("Data de hoje%02d/%02d/%d\n", day, month, year);
    printf("Horas de hoje%02d/%02d/%d\n", hours, minutes, seconds);

    return 0;
}
