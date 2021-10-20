#pragma once
#include <memory>
#include <vector>

namespace sfcv
{

class Mat
{
protected:
    int64_t data_size_ = 0;
    int width_ = 0, height_ = 0, channel_ = 0, number_ = 0;
    int row_ = 0;

    std::vector<int> dim_;

    //数据
    void* data_ = nullptr;
    //共享指针的意义是自动析构不被引用的数据，不可以直接使用
    std::shared_ptr<char> shared_data_;

    void* user_data_ = nullptr;

public:
    Mat(const std::vector<int>& dim);
    Mat(int w, int h, int c, int n);
    Mat(int m, int n);
    Mat(const std::vector<int>& dim, char* data);
    Mat();
    //~Matrix();
    Mat clone() const;
};

//运算符重载：+-*数乘
inline Mat operator+(const Mat& A, const Mat& B)
{
    Mat R(A.getDim());
    Mat::add(A, B, R);
    return A;
}

inline Mat operator-(const Mat& A, const Mat& B)
{
    Mat R(A.getDim(), A.getDeviceType());
    Mat::add(A, B, R, 1, -1);
    return R;
}

inline Mat operator*(const Mat& A, const Mat& B)
{
    Mat R(A.getRow(), B.getNumber(), A.getDeviceType());
    Mat::mul(A, B, R);
    return R;
}

inline Mat operator*(real r, const Mat& A)
{
    Mat R(A.getDim());
    Mat::scale(A, R, r);
    return R;
}

inline Mat operator*(const Mat& A, real r)
{
    Mat R(A.getDim());
    Mat::scale(A, R, r);
    return R;
}

};    // namespace sfcv