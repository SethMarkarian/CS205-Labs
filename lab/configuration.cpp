#include "configuration.h"

Configuration::Configuration()
{
    name = "shortened_words.txt";
}

//! Constructor for Configuration Class
Configuration::Configuration(std::string fn)
{
    name = fn; //! assigns file name
    //std::cout << 1; // testing
    reload(); //! loads data from file
    //std::cout << 2; //testing
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
void Configuration::reload()
{
    m.clear();
    try {
        std::ifstream src(name, std::ios::in);
        while(!src.eof())
        {
            char aline[256];
            src >> aline;
            char * checker;
            checker = strchr(aline, ':');
            if(checker == NULL)
            {
                continue;
            }
            char * key;
            char * val;
            key = strtok(aline, ":");
            val = strtok(NULL, ":");
            m[key] = val;
            contin:;
        }
    }
    catch (int e) {
        std::cout << "Exception: " << e;
    }
}

//! Stores state of current map
void Configuration::store_state() {
    Log l (name); //! declaring a Log object for the name file
    l.close_fh(); //! closes the default ofstream of Log
    l.open_empty(); //! opens to rewrite the file
    for(std::map<std::string, std::string>::iterator it = m.begin(); it != m.end(); it++) //! iterates through the map
    {
        l << it -> first << ":" << it -> second << "\n"; //! writes to file in format key:value
    }
    l.flush_fh(); //! flushes the Log
    l.close_fh(); //! closes the Log
}
