#include "Mat.h"

namespace sfcv
{
Mat::Mat(const std::vector<int>& dim)
{
    dim_ = dim;
    data_size_ = 1;
    for (auto d : dim_)
    {
        data_size_ *= d;
    }
    if (data_size_ > 0)
    {
        shared_data_->resize(data_size_);
        data_ = shared_data_->data();
    }
}
}

