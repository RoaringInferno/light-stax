#pragma once

#include <exception>

namespace lstax
{
    class data_structure_exception : public std::exception
    {
    public:
        virtual const char* what() const noexcept override
        {
            return "Stack exception";
        }
    };

    class data_structure_overflow : public data_structure_exception
    {
    public:
        const char* what() const noexcept override
        {
            return "Stack overflow";
        }
    };

    class data_structure_underflow : public data_structure_exception
    {
    public:
        const char* what() const noexcept override
        {
            return "Stack underflow";
        }
    };
}