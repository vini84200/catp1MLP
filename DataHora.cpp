#include "DataHora.hpp"

DataHora::DataHora()
    : time_(time(0))
{
}

DataHora::DataHora(time_t time)
    : time_(time)
{
}

tm *DataHora::getTm() const
{
    return localtime(&time_);
}

bool DataHora::isFuture() const
{
    return time_ > time(0);
}

std::ostream &operator<<(std::ostream &os, const DataHora &time)
{
    tm *ltm = time.getTm();
    os << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year;
    return os;
}
