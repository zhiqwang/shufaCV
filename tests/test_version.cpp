#include "version.h"
#include "gtest/gtest.h"

TEST(version, macros)
{
    EXPECT_TRUE(SHUFACV_VERSION_MAJOR >= 0);
    EXPECT_TRUE(SHUFACV_VERSION_MINOR >= 0);
    EXPECT_TRUE(SHUFACV_VERSION_PATCH >= 0);
}




int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
