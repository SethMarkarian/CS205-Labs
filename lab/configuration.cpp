#include "configuration.h"


Configuration::Configuration(std::string fn)
{
    name = fn;
    reload();
}

~Configuration::Configuration()
{
    name = fn;
    reload();
}

std::string Configuration::get_value(std::string key) {
    return m.find(key) -> second;
}

void Configuration::set(std::string key, std::string value) {
    m.insert(std::pair<std::string, std::string> (key, value));
}

void Configuration::change_file_name(std::string fn) {
    const char *cfn = fn.c_str();
    const char *cname = name.c_str();
    std::rename(cname, cfn);
}

void Configuration::change_file_path(std::string fp) {
    try {
        std::ifstream src(name, std::ios::binary);
        std::ofstream dest(fp, std::ios::binary);

        dest << src.rdbuf();
        const char *cname = name.c_str();
        std::remove(cname);
    }
    catch (int e) {
        std::cout << "Exception: " << e;
    }

}

void Configuration::reload() {
    m.clear();
    try {
        std::ifstream src(name, std::ios::in);
        while(!src.eof()) {
            char * cline = " ";
            src >> cline;
            char aline[strlen(cline)];
            strcpy(aline, cline);
            char * key;
            char * val;
            key = strtok(aline, ":");
            val = strtok(NULL, ":");
            m[key] = val;
        }
    }
    catch (int e) {
        std::cout << "Exception: " << e;
    }

}

void Configuration::store_state() {
    Log l (name);
    l.close_fh();
    l.open_empty();
    for(std::map<std::string, std::string>::iterator it = m.begin(); it != m.end(); it++)
    {
        l << it -> first << ":" << it -> second << "\n";
    }
    l.flush_fh();
    l.close_fh();
}
