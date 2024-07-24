#ifndef DATAHORA_HPP
#define DATAHORA_HPP
#include <ctime>
#include <ostream>

class DataHora
{

public:
    DataHora();
    DataHora(time_t);

    tm *getTm() const;

    bool isFuture() const;

private:
    time_t time_;
};

std::ostream &operator<<(std::ostream &, const DataHora &);

#endif