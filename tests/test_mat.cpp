#include "Mat.h"
#include "gtest/gtest.h"

TEST(Mat, create)
{
    constexpr int rows = 3;
    constexpr int cols = 5;

    // Mat::Mat(int, int)
    sfcv::Mat mat1(rows, cols);
    EXPECT_TRUE(mat1.data() != nullptr);
    EXPECT_EQ(mat1.row(), rows);
    EXPECT_EQ(mat1.col(), cols);

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

    const sfcv::Mat mat1(rows, cols);
    EXPECT_TRUE(mat1.data() != nullptr);
    EXPECT_EQ(mat1.row(), rows);
    EXPECT_EQ(mat1.col(), cols);

    const sfcv::Mat mat2(std::vector<int>{rows, cols});
    EXPECT_TRUE(mat2.data() != nullptr);
    EXPECT_EQ(mat2.row(), rows);
    EXPECT_EQ(mat2.col(), cols);

    sfcv::Mat mat3({rows, cols});
    EXPECT_TRUE(mat3.data() != nullptr);
    EXPECT_EQ(mat3.row(), rows);
    EXPECT_EQ(mat3.col(), cols);
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

TEST(Mat, global_add_operator)
{
    constexpr int rows = 3;
    constexpr int cols = 5;

    const sfcv::Mat mat1(rows, cols);
    EXPECT_TRUE(mat1.data() != nullptr);
    EXPECT_EQ(mat1.row(), rows);
    EXPECT_EQ(mat1.col(), cols);

    const sfcv::Mat mat2(std::vector<int>{rows, cols});
    EXPECT_TRUE(mat2.data() != nullptr);
    EXPECT_EQ(mat2.row(), rows);
    EXPECT_EQ(mat2.col(), cols);

    char* data1 = mat1.data();
    char* data2 = mat2.data();
    for (int i = 0; i < rows * cols; i++)
    {
        data1[i] = 1;
        data2[i] = 2;
    }
    sfcv::Mat mat3 = mat1 + mat2;
    char* data3 = mat3.data();
    for (int i = 0; i < rows * cols; i++)
    {
        EXPECT_EQ(data3[i], 3);
    }
}
