#include "configuration.h"

//! Constructor for Configuration Class
Configuration::Configuration(std::string fn)
{
    name = fn; //! assigns file name
    // std::cout << 1; // testing
    reload(); //! loads data from file
    // std::cout << 2; //testing
}

//! Destructor for Configuration Class
Configuration::~Configuration()
{
    store_state(); //! save the data
}

//! Get value based on key
std::string Configuration::get_value(std::string key) {
    return m.find(key) -> second; //! finds the iterator for key, returns the value assosciated with the iterator
}

//! Set a key and value
void Configuration::set(std::string key, std::string value) {
    std::cout << "setting ";
    m.insert(std::pair<std::string, std::string> (key, value)); //! inserts into map a string pair of key, value
}

//! Changes the name of the current file
void Configuration::change_file_name(std::string fn) {
    //! converts fn and name to char * to be used in std::rename
    const char *cfn = fn.c_str();
    const char *cname = name.c_str();
    std::rename(cname, cfn); //! renames the name file to fn
}

//! Changes the path of the current file
void Configuration::change_file_path(std::string fp) {
    try {
        std::ifstream src(name, std::ios::binary); //! ifstream of current file
        std::ofstream dest(fp, std::ios::binary); //! ofstream opens a file in new path

        dest << src.rdbuf(); //! sends source's file buffer to destination file
        const char *cname = name.c_str(); //! converts name to char * to delete it
        std::remove(cname); //! removes file at old location
        name = fp; //! reassigns file name
    }
    catch (int e) {
        std::cout << "Exception: " << e;
    }

}

//! Reloads the configuration data
void Configuration::reload() {
    m.clear(); //! clears the current map
    try {
        std::ifstream src(name, std::ios::in); //! ifstream of name file
        while(!src.eof()) { //! while not at end of name file
            char * cline; //! declares and instatiates
            src >> cline; //! sends line in name file to cline
            char aline[256]; //! declares aline to length 256
            strcpy(aline, cline); //! copies contents of cline to aline
            char * key; //! declares a char * for key
            char * val; //! declares a char * for val
            key = strtok(aline, ":"); //! assigns key value
            val = strtok(NULL, ":"); //! assigns val value
            m[key] = val; //! maps key to val in m
        }
    }
    catch (int e) {
        std::cout << "Exception: " << e;
    }
    // std::cout << "t "; // testing
}

//! Stores state of current map
void Configuration::store_state() {
    std::cout << "starting ";
    Log l (name); //! declaring a Log object for the name file
    l.close_fh(); //! closes the default ofstream of Log
    l.open_empty(); //! opens to rewrite the file
    std::cout << "to the loop ";
    for(std::map<std::string, std::string>::iterator it = m.begin(); it != m.end(); it++) //! iterates through the map
    {
        l << it -> first << ":" << it -> second << "\n"; //! writes to file in format key:value
        std::cout << "storing ";
    }
    l.flush_fh(); //! flushes the Log
    l.close_fh(); //! closes the Log
}
