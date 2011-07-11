#ifndef FCPPT_UTF8_FROM_STD_STRING_HPP_INCLUDED
#define FCPPT_UTF8_FROM_STD_STRING_HPP_INCLUDED

#include <fcppt/utf8/string.hpp>
#include <fcppt/symbol.hpp>
#include <string>

namespace fcppt
{
namespace utf8
{
FCPPT_SYMBOL utf8::string const
from_std_string(
	std::string const &);
}
}

#endif
