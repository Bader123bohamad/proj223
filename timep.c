#include "header.h"
void timep(int seconds) {
    time_t start_time, current_time;
    double elapsed_time;

    time(&start_time); // Get the current time

    do {
        time(&current_time); // Get the current time again
        elapsed_time = difftime(current_time, start_time); // Calculate elapsed time
    } while (elapsed_time < seconds); // Wait until elapsed time reaches the desired duration
}
