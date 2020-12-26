//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CATCH_ARRAY_HPP_INCLUDED
#define FCPPT_CATCH_ARRAY_HPP_INCLUDED

#include <fcppt/array/object_impl.hpp>
#include <fcppt/catch/convert.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstddef>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace Catch
{
/**
\brief Output specialization for #fcppt::array::object.

\ingroup fcpptcatch
*/
template <typename T, std::size_t Size>
struct StringMaker<fcppt::array::object<T, Size>>
{
  static std::string convert(fcppt::array::object<T, Size> const &_value)
  {
    return fcppt::catch_::convert(_value.impl());
  }
};

}

#endif
