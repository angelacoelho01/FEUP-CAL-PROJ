#include "FileException.h"

FileNotFound::FileNotFound(const std::string& file) :
        std::logic_error("File "+ file + " not found!"){
}
