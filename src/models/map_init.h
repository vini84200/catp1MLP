//
// Created by vini84200 on 8/23/24.
//

#ifndef CATPPROJETO_MAP_INIT_H
#define CATPPROJETO_MAP_INIT_H

template<typename T> struct map_init_helper
{
    T& data;
    map_init_helper(T& d) : data(d) {}
    map_init_helper& operator() (typename T::key_type const& key, typename T::mapped_type const& value)
    {
        data[key] = value;
        return *this;
    }
};

template<typename T> map_init_helper<T> map_init(T& item);


#endif //CATPPROJETO_MAP_INIT_H
