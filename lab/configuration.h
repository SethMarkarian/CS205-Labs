#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <map>
#include <iostream>


class Configuration
{

public:
    std::map<std::string, std::string> m;
    Configuration();
    std::string get_key(std::string str);
    std::string get_value(std::string str);
    void set_key(std::string str);
    void set_value(std::string str);
};

#endif // CONFIGURATION_H
