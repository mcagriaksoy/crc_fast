/**
 * @file crc.hpp
 * @brief CRC calculation header file
 * @author Mehmet Cagri Aksoy - github.com/mcagriaksoy
 * @date 2023-09-11
 * @license MIT License
 * @details
 * This file contains the header file for the CRC calculation functions.
 * The functions are implemented using lookup tables.
 */

#ifndef CRC_HPP
#define CRC_HPP

#include "crc_lookup_table.hpp"
#include <string>

namespace crc8_calc // CRC-8 calculation namespace
{
    typedef enum
    {
        GENERAL,
        CDMA_2000,
        DARC,
        DVB_S2,
        EBU,
        I_CODE,
        ITU,
        MAXIM,
        ROHC,
        WCDMA
    } crc8_t;

    typedef enum
    {
        GENERAL_POLY = 0x07,
        CDMA_2000_POLY = 0x9B,
        DARC_POLY = 0x39,
        DVB_S2_POLY = 0xD5,
        EBU_POLY = 0x1D,
        I_CODE_POLY = 0x1D,
        ITU_POLY = 0x07,
        MAXIM_POLY = 0x31,
        ROHC_POLY = 0x07,
        WCDMA_POLY = 0x9B
    } crc8_poly_t;
}

namespace crc16_calc
{
    typedef enum
    {
        GENERAL
    } crc16_t;
}

namespace crc32_calc
{
    typedef enum
    {
        GENERAL
    } crc32_t;
}

/**
 * @brief Calculates the CRC-8 checksum of the given input string using the specified CRC-8 type.
 *
 * @param input The input string to calculate the checksum for.
 * @param output The output variable to store the calculated checksum.
 * @param crc_type The type of CRC-8 to use for the calculation.
 */
void crc_8_calculation(std::string &input, uint8_t &output, crc8_calc::crc8_t crc_type);

/**
 * @brief Calculates the CRC-16 checksum of the given input string using the specified CRC type.
 *
 * @param input The input string to calculate the checksum for.
 * @param output The output variable to store the calculated checksum.
 * @param crc_type The type of CRC-16 algorithm to use for the calculation.
 */
void crc_16_calculation(std::string &input, uint16_t &output, crc16_calc::crc16_t crc_type);

/**
 * @brief Calculates the CRC-32 checksum of the given input string using the specified CRC type.
 *
 * @param input The input string to calculate the checksum for.
 * @param output The output variable to store the calculated checksum.
 * @param crc_type The type of CRC algorithm to use for the calculation.
 */
void crc_32_calculation(std::string &input, uint32_t &output, crc32_calc::crc32_t crc_type);

#endif // CRC_HPP
