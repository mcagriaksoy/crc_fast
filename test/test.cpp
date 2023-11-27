// Mehmet Cagri Aksoy - github.com/mcagriaksoy

#include <gtest/gtest.h>
#include <string>

#include "../include/crc.hpp"
// Test fixture for crc_fast
TEST(MultithreadCrc8CalculationTest, ShouldCalculateCorrectCrc)
{
    std::string input = "Hello word!";
    uint8_t output;
    crc8_calc::crc8_t crc_type = crc8_calc::GENERAL;

    clock_t start = clock();
    multithread_crc_8_calculation(input, output, crc_type);
    clock_t end = clock();

    uint8_t expected_output = 53;
    EXPECT_EQ(output, expected_output);

    std::cout << "Multithreaded CRC-8 calculation took " << (end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;
}

TEST(SinglethreadCrc8CalculationTest, ShouldCalculateCorrectCrc)
{
    std::string input = "Hello word!";
    uint8_t output;
    crc8_calc::crc8_t crc_type = crc8_calc::GENERAL;

    clock_t start = clock();
    crc_8_calculation(input, output, crc_type);
    clock_t end = clock();

    uint8_t expected_output = 53;
    EXPECT_EQ(output, expected_output);

    std::cout << "Multithreaded CRC-8 calculation took " << (end - start) / CLOCKS_PER_SEC << " seconds." << std::endl;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    /*
    testing::internal::CaptureStdout();
    int retVal = RUN_ALL_TESTS();
    std::string output = testing::internal::GetCapturedStdout();
    std::cout << output;
    */
    return RUN_ALL_TESTS();
}