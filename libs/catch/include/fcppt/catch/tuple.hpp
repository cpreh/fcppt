//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CATCH_TUPLE_HPP_INCLUDED
#define FCPPT_CATCH_TUPLE_HPP_INCLUDED

#include <fcppt/catch/convert.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_tostring.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace Catch
{
/**
\brief Output specialization for #fcppt::tuple::object.

\ingroup fcpptcatch
*/
template <typename... Types>
struct StringMaker<fcppt::tuple::object<Types...>>
{
  static std::string convert(fcppt::tuple::object<Types...> const &_value)
  {
    return fcppt::catch_::convert(_value.impl());
  }
};

}

#endif
