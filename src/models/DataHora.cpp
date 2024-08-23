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

bool DataHora::isBefore(const DataHora &other)
{
    return time_ < other.time_;
}

bool DataHora::isAfter(const DataHora &other)
{
    return time_ > other.time_;
}

bool DataHora::isBetween(const DataHora &start, const DataHora &end)
{
    return !isBefore(start) && !isAfter(end);
}

DataHora::DataHora(unsigned int dia, unsigned int mes, unsigned int ano) {
    tm ltm = {};
    ltm.tm_mday = dia;
    ltm.tm_mon = mes - 1;
    ltm.tm_year = ano - 1900;
    ltm.tm_hour = 0;
    ltm.tm_min = 0;
    ltm.tm_sec = 0;
    ltm.tm_isdst = -1;
    time_ = mktime(&ltm);
}

std::ostream &operator<<(std::ostream &os, const DataHora &time)
{
    tm *ltm = time.getTm();
    os << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year;
    return os;
}
