#include "Mat.h"
#include "gtest/gtest.h"

TEST(Mat, create)
{
    constexpr int rows = 3;
    constexpr int cols = 5;

    // Mat::Mat(int, int)
    sfcv::Mat mat(rows, cols);
    EXPECT_TRUE(mat.data() != nullptr);
    EXPECT_EQ(mat.row(), rows);
    EXPECT_EQ(mat.col(), cols);

    // Mat::Mat(const std::vector<int>&)
    sfcv::Mat mat2(std::vector<int>{rows, cols});
    EXPECT_TRUE(mat2.data() != nullptr);
    EXPECT_EQ(mat2.row(), rows);
    EXPECT_EQ(mat2.col(), cols);

    // Mat::Mat(std::initializer_list<int>)
    sfcv::Mat mat3({rows, cols});
    EXPECT_TRUE(mat3.data() != nullptr);
    EXPECT_EQ(mat3.row(), rows);
    EXPECT_EQ(mat3.col(), cols);
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
