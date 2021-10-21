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
        shared_data_ = std::make_shared<char>(new char[data_size_]);
        data_ = shared_data_.get();
    }
}
    
Mat Mat::clone()
{
    Mat _copy(dim_);
    if(data_ && _copy.data_)
        memcpy(_copy.data_, data_, data_size_);
    return _copy;
}
}

