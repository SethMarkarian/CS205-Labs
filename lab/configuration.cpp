#include "configuration.h"
#include <iostream>
#include <map>

Configuration::Configuration()
{

}

std::string get_key(std::string str) {
    return m.find(str);
}
std::string get_value(std::string str) {
    return m.at(str);
}
void set_key(std::string str) {

}
void set_value(std::string str) {

}


