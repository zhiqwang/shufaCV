#pragma once
#include <memory>
#include <vector>

namespace sfcv
{

class Mat
{
protected:
    int64_t data_size_ = 0;

    std::vector<int> dim_;

    //数据
    void* data_ = nullptr;
    //共享指针的意义是自动析构不被引用的数据，不可以直接使用
    std::shared_ptr<char> shared_data_;

    void* user_data_ = nullptr;

public:
    Mat(const std::vector<int>& dim);
    Mat(int m, int n) : Mat(std::vector<int>{ m, n }) {}
    Mat() {}
    //~Mat();
    Mat clone() const;
};

//运算符重载：+-*数乘
inline Mat operator+(const Mat& A, const Mat& B)
{
    Mat R;
    return R;
}

inline Mat operator-(const Mat& A, const Mat& B)
{
    Mat R;
    return R;
}

inline Mat operator*(const Mat& A, const Mat& B)
{
    Mat R;
    return R;
}

inline Mat operator*(double r, const Mat& A)
{
    Mat R;
    return R;
}

inline Mat operator*(const Mat& A, double r)
{
    Mat R;
    return R;
}

};    // namespace sfcv
