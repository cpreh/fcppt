//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_MAKE_SUCCESS_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_SUCCESS_HPP_INCLUDED

#include <fcppt/either/make_success.hpp>
#include <fcppt/options/error.hpp>
#include <fcppt/options/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace options
{
/**
\brief Creates a success value.

\ingroup fcpptoptions
*/
template <typename Type>
inline fcppt::options::result<std::remove_cvref_t<Type>> make_success(Type &&_value)
{
  return fcppt::either::make_success<fcppt::options::error>(std::forward<Type>(_value));
}

}
}

#endif
