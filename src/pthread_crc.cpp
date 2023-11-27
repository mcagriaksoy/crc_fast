/**
 * @file crc.cpp
 * @brief CRC calculation source code.
 * @author Mehmet Cagri Aksoy - github.com/mcagriaksoy
 * @date 2023-09-11
 * @license MIT License
 * @details
 * This file contains the source code for the CRC calculation functions.
 * The functions are implemented using lookup tables.
 */

#include "../include/crc.hpp"
#include <pthread.h>
#include <string>

// Structure to hold the thread arguments
struct ThreadArgs
{
    std::string input;
    uint8_t *output;
    crc8_calc::crc8_t crc_type;
};

// Thread function for CRC-8 calculation
void *crc_8_calculation_thread(void *arg)
{
    ThreadArgs *args = static_cast<ThreadArgs *>(arg);
    crc_8_calculation(args->input, *(args->output), args->crc_type);
    pthread_exit(nullptr);
}

void multithread_crc_8_calculation(std::string &input, uint8_t &output, crc8_calc::crc8_t crc_type)
{
    // Create a thread and pass the arguments
    pthread_t thread;
    ThreadArgs args;
    args.input = input;
    args.output = &output;
    args.crc_type = crc_type;

    // Create the thread and wait for it to finish
    pthread_create(&thread, nullptr, crc_8_calculation_thread, &args);
    pthread_join(thread, nullptr);
}
