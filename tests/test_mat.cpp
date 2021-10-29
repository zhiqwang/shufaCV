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
