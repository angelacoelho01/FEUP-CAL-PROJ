#ifndef FEUP_CAL_PROJ_FILEEXCEPTION_H
#define FEUP_CAL_PROJ_FILEEXCEPTION_H

#include <stdexcept>

class FileNotFound : public std::logic_error {
public:
    explicit FileNotFound(const std::string& file);
};


#endif //FEUP_CAL_PROJ_FILEEXCEPTION_H
