#include "Mat.h"
#include "gtest/gtest.h"

TEST(Mat, create)
{
    constexpr int rows = 3;
    constexpr int cols = 5;

    sfcv::Mat mat(rows, cols);
    EXPECT_TRUE(mat.data() != nullptr);
    EXPECT_EQ(mat.row(), rows);
    EXPECT_EQ(mat.col(), cols);

    sfcv::Mat mat2(std::vector<int>{rows, cols});
    EXPECT_TRUE(mat.data() != nullptr);
    EXPECT_EQ(mat2.row(), rows);
    EXPECT_EQ(mat2.col(), cols);
}

TEST(Mat, create_const)
{
    constexpr int rows = 3;
    constexpr int cols = 5;

    const sfcv::Mat mat(rows, cols);
    EXPECT_TRUE(mat.data() != nullptr);
    EXPECT_EQ(mat.row(), rows);
    EXPECT_EQ(mat.col(), cols);

    const sfcv::Mat mat2(std::vector<int>{rows, cols});
    EXPECT_TRUE(mat.data() != nullptr);
    EXPECT_EQ(mat2.row(), rows);
    EXPECT_EQ(mat2.col(), cols);
}

TEST(Mat, pixel_value_conformance)
{
    constexpr int rows = 1;
    constexpr int cols = 4;
    sfcv::Mat mat(rows, cols);

    char* data = mat.data();
    data[0] = -1;
    EXPECT_EQ(data[0], -1);
}

int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    // Run a specific test only
    //testing::GTEST_FLAG(filter) = "OpenCV.read_image";

    // Exclude a specific test
    //testing::GTEST_FLAG(filter) = "-cvtColorTwoPlane.yuv420sp_to_rgb:-cvtColorTwoPlane.rgb_to_yuv420sp"; // The writing test is broken, so skip it

    return RUN_ALL_TESTS();
}
