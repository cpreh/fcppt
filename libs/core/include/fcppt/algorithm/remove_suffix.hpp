//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ALGORITHM_REMOVE_SUFFIX_HPP_INCLUDED
#define FCPPT_ALGORITHM_REMOVE_SUFFIX_HPP_INCLUDED

#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/type_traits/size_type.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string_view>
#include <fcppt/config/external_end.hpp>

namespace fcppt::algorithm
{

/**
\brief Removes a suffix of a string.

\ingroup fcpptalgorithm

If the input string \a _string has at least \a _length characters, then the suffix of size \a _length is removed.
Otherwise, the empty optional is returned.
*/
template <typename String>
[[nodiscard]]
fcppt::optional::object<String>
remove_suffix(String const &_string, fcppt::type_traits::size_type<String> const _length)
  requires(fcppt::type_traits::is_string<String>::value)
{
  return fcppt::optional::make_if(
      _string.size() >= _length,
      [&_string, _length]
      {
        std::basic_string_view<fcppt::type_traits::value_type<String>> ret_view{_string};
        ret_view.remove_suffix(_length);
        return String{ret_view};
      });
}
}

#endif
