#pragma once

#include <exception>

namespace lstax
{
    class stack_exception : public std::exception
    {
    public:
        virtual const char* what() const noexcept override
        {
            return "Stack exception";
        }
    };

    class stack_overflow : public stack_exception
    {
    public:
        const char* what() const noexcept override
        {
            return "Stack overflow";
        }
    };

    class stack_underflow : public stack_exception
    {
    public:
        const char* what() const noexcept override
        {
            return "Stack underflow";
        }
    };
}