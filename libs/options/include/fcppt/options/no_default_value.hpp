//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_OPTIONS_NO_DEFAULT_VALUE_HPP_INCLUDED
#define FCPPT_OPTIONS_NO_DEFAULT_VALUE_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/default_value.hpp>

namespace fcppt::options
{
/**
\brief Creates an empty default value

\ingroup fcpptoptions
*/
template <typename Type>
inline fcppt::options::default_value<fcppt::optional::object<Type>> no_default_value()
{
  return fcppt::options::default_value<fcppt::optional::object<Type>>{
      fcppt::optional::object<Type>{}};
}

}

#endif
