#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <map>
#include <iostream>
#include <fstream>
#include "log.h"
#include <cstring>
/*! The header file for the Configuration class */
/*!
  \class Configuration
  \brief The Configuration class loads, edits, and saves configuration data to files using a map

  The Configuration class reads configuration data saved in a file, and stores the data in a map.
  Data can be added to the map, and accessed based on the key value.
  */


class Configuration
{
    std::map<std::string, std::string> m; //! map of string keys and string values
    std::string path; //! file path
    std::string name; //! file name

public:
    Configuration();
    //! Constructor
    /*!
     * \brief Configuration constructor
     * \param fn file name
     */
    Configuration(std::string fn);
     //! Destructor
     /*!
      * \brief Configuration destructor
      */
    ~Configuration();
    //! Gets value based on key
    /*!
     * \brief get_value returns the value corresponding to the key
     * \param key key value of type std::string
     * \return value of type std::string
     */
    std::string get_value(std::string key);
    //! Sets a value and a key in the map
    /*!
     * \brief set sets a value and a key in the map
     * \param key the key of type std::string
     * \param value the value of type std::string
     */
    void set(std::string key, std::string value);
    //! Changes the name of the current file
    /*!
     * \brief change_file_name renames the current file
     * \param fn std::string the file name will be changed to
     */
    void change_file_name(std::string fn);
    //! Changes the path of the current file
    /*!
     * \brief change_file_path moves the file to a new path location
     * \param fp std::string new path location
     */
    void change_file_path(std::string fp);
    //! Clears the map and repopulates the map
    /*!
     * \brief reload clears the map and repopulates it based on the current file
     */
    void reload();
    //! Stores the current state of the map
    /*!
     * \brief store_state stores the map state in a file
     */
    void store_state();

    std::string get_filename();
};
#endif // CONFIGURATION_H
