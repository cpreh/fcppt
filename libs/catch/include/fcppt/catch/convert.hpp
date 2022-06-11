//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CATCH_CONVERT_HPP_INCLUDED
#define FCPPT_CATCH_CONVERT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_tostring.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace fcppt::catch_
{
/**
\brief Calls Catch's StringMaker

\ingroup fcpptcatch
*/
template <typename Type>
std::string convert(Type const &_value)
{
  return Catch::StringMaker<Type>::convert(_value);
}

}

#endif
