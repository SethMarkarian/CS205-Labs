#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <map>
#include <iostream>
#include <fstream>
#include "log.h"
#include <cstring>


class Configuration
{
    std::map<std::string, std::string> m;
    std::string path;
    std::string name;

public:
    Configuration(std::string fn);
    ~Configuration(std::string fn);
    std::string get_value(std::string key);
    void set(std::string key, std::string value);
    void change_file_name(std::string fn);
    void change_file_path(std::string fp);
    void reload();
    void store_state();
};
#endif // CONFIGURATION_H
