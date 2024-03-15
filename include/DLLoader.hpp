/*
** EPITECH PROJECT, 2024
** B-OOP-400-PAR-4-1-arcade-thibaud.cathala
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
    #define DLLOADER_HPP_

    #include <string>
    #include <dlfcn.h>
    #include "my_tracked_exception.hpp"

namespace Arc
{
    template<typename T>
    class DLLoader
    {
    public:
        DLLoader() = default;
        DLLoader(const std::string &libName)
        {
            this->_handle = dlopen(libName.c_str(), RTLD_LAZY);
            if (!this->_handle) {
                throw my::tracked_exception(dlerror());
            }
        }

        ~DLLoader()
        {
            if (this->_handle == nullptr) {
                return;
            }
            dlclose(this->_handle);
        }

        void load(const std::string &libName)
        {
            this->_handle = dlopen(libName.c_str(), RTLD_LAZY);
            if (!this->_handle) {
                throw my::tracked_exception(dlerror());
            }
        }

        T *getInstance(const std::string &name)
        {
            auto func = reinterpret_cast<T *(*)(void)>(dlsym(this->_handle, name.c_str()));
            if (!func) {
                throw my::tracked_exception(dlerror());
            }
            return func();
        }

        const std::string &getName()
        {
            auto func = reinterpret_cast<const std::string &(*)(void)>(dlsym(this->_handle, "getName"));
            if (!func) {
                throw my::tracked_exception(dlerror());
            }
            return func();
        }

    private:
        void *_handle = nullptr;
    };
}

#endif /* !DLLOADER_HPP_ */
