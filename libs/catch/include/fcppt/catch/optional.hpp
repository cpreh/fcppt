//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CATCH_OPTIONAL_HPP_INCLUDED
#define FCPPT_CATCH_OPTIONAL_HPP_INCLUDED

#include <fcppt/catch/convert.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace Catch
{
/**
\brief Output specialization for #fcppt::optional::object.

\ingroup fcpptcatch
*/
template <typename Type>
struct StringMaker<fcppt::optional::object<Type>>
{
  static std::string convert(fcppt::optional::object<Type> const &_value)
  {
    return fcppt::optional::maybe(
        _value,
        [] { return std::string{"N"}; },
        [](Type const &_inner) { return std::string{"J "} + fcppt::catch_::convert(_inner); });
  }
};

}

#endif
