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

#include "crc.hpp"
#include <string>

void crc_8_calculation(std::string &input, uint8_t &output, crc8_calc::crc8_t crc_type)
{
    // Initialize the output variable for the specified CRC type.
    switch (crc_type)
    {
    case crc8_calc::crc8_t::I_CODE:
        output = 0xFD;
        break;
    case crc8_calc::crc8_t::CDMA_2000:
    case crc8_calc::crc8_t::EBU:
    case crc8_calc::crc8_t::ROHC:
        output = 0xFF;
        break;
    case crc8_calc::crc8_t::DVB_S2:
    case crc8_calc::crc8_t::ITU:
    case crc8_calc::crc8_t::MAXIM:
    case crc8_calc::crc8_t::DARC:
    case crc8_calc::crc8_t::WCDMA:
    case crc8_calc::crc8_t::GENERAL:
    default:
        output = 0x00;
    }

    // Calculate the CRC-8 checksum of the given input string using the specified CRC-8 type.
    for (auto element : input)
    {
        switch (crc_type)
        {
        case crc8_calc::crc8_t::CDMA_2000:
            output = crc8_calc::crc8_cdma2000_table[output ^ element];
            break;
        case crc8_calc::crc8_t::DARC:
            output = crc8_calc::crc8_darc_table[output ^ element];
            break;
        case crc8_calc::crc8_t::EBU:
            output = crc8_calc::crc8_ebu_table[output ^ element];
            break;
        case crc8_calc::crc8_t::DVB_S2:
            output = crc8_calc::crc8_dvb_s2_table[output ^ element];
            break;
        case crc8_calc::crc8_t::I_CODE:
            output = crc8_calc::crc8_i_code_table[output ^ element];
            break;
        case crc8_calc::crc8_t::ITU:
            output = crc8_calc::crc8_itu_table[output ^ element];
            break;
        case crc8_calc::crc8_t::MAXIM:
            output = crc8_calc::crc8_maxim_table[output ^ element];
            break;
        case crc8_calc::crc8_t::ROHC:
            output = crc8_calc::crc8_rohc_table[output ^ element];
            break;
        case crc8_calc::crc8_t::WCDMA:
            output = crc8_calc::crc8_wcdma_table[output ^ element];
            break;
        case crc8_calc::crc8_t::GENERAL:
        default:
            output = crc8_calc::crc8_general_table[output ^ element];
        }
    }

    // Special handling for the ITU CRC-8 type.
    if (crc_type == crc8_calc::crc8_t::ITU)
    {
        output ^= 0x55;
    }
}

void crc_16_calculation(std::string &input, uint16_t &output, crc16_calc::crc16_t crc_type)
{
}

void crc_32_calculation(std::string &input, uint32_t &output, crc32_calc::crc32_t crc_type)
{
}