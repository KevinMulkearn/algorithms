/**
 * Simple struct to help measure sort time durartion
 */

#if !defined(TIMING_H)
#define TIMING_H

#include <chrono>
#include <iostream>
#include <thread>

typedef std::chrono::high_resolution_clock Clock;

struct Timer
{
    Clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer ()
    {
        start = Clock::now();
    }

    ~Timer ()
    {
        end = Clock::now();
        duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

        std::cout << "Exection time: " << duration.count() << " seconds" << std::endl;
    }
};

#endif // TIMING_H