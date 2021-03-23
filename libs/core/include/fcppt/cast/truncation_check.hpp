//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_TRUNCATION_CHECK_HPP_INCLUDED
#define FCPPT_CAST_TRUNCATION_CHECK_HPP_INCLUDED

#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/cast/bad_truncation_check.hpp>
#include <fcppt/cast/detail/truncation_check.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace cast
{
/**
\brief Cast between integral types, checking for truncation

\ingroup fcpptcasts

Casts \a _source of type \a Source to the type \a Dest. It returns the
converted value iff the conversion results in no truncation, otherwise
#fcppt::cast::bad_truncation_check  is thrown.

\tparam Dest Must be an integral type

\tparam Source Must be an integral type

\throw fcppt::cast::bad_truncation_check if truncation occurs
*/
template <typename Dest, typename Source>
Dest truncation_check(Source const _source)
{
  static_assert(
      std::is_integral<Source>::value && std::is_integral<Dest>::value,
      "truncation_check_cast can only cast from integral to integral types");

  return fcppt::optional::to_exception(
      fcppt::cast::detail::truncation_check<Dest>(_source), [_source] {
        return fcppt::cast::bad_truncation_check(
            fcppt::output_to_fcppt_string(_source),
            std::type_index(typeid(Source)),
            std::type_index(typeid(Dest)));
      });
}

}
}

#endif
