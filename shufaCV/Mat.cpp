#include "Mat.h"

namespace sfcv {
Mat::Mat(const std::vector<int>& dim)
    : data_size_(1), dim_(dim)
{
    create();
}

Mat::Mat(const std::initializer_list<int> dim)
    : data_size_(1), dim_(dim)
{
    create();
}

void Mat::create()
{
    for (const auto d : dim_)
    {
        data_size_ *= d;
    }
    if (data_size_ > 0)
    {
        shared_data_ = std::make_shared<std::vector<char> >();
        shared_data_->resize(data_size_);
        data_ = shared_data_->data();
    }
}

} // namespace sfcv
