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
        DLLoader(const std::string &libName)
        {
            this->handle = dlopen(libName.c_str(), RTLD_LAZY);
            if (!this->handle) {
                throw my::tracked_exception(dlerror());
            }
        }

        ~DLLoader()
        {
            dlclose(this->handle);
        }

        T *getInstance(const std::string &name)
        {
            auto func = reinterpret_cast<T *(*)(void)>(dlsym(this->handle, name.c_str()));
            if (!func) {
                throw my::tracked_exception(dlerror());
            }
            return func();
        }

    private:
        void *handle = nullptr;
    };
}

#endif /* !DLLOADER_HPP_ */
