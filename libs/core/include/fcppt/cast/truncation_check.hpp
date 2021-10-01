//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_TRUNCATION_CHECK_HPP_INCLUDED
#define FCPPT_CAST_TRUNCATION_CHECK_HPP_INCLUDED

#include <fcppt/cast/detail/truncation_check.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast
{
/**
\brief Cast between integral types, checking for truncation

\ingroup fcpptcasts

Casts \a _source of type \a Source to the type \a Dest. It returns the
converted value iff the conversion results in no truncation.

\tparam Dest Must be an integral type

\tparam Source Must be an integral type
*/
template <
    typename Dest,
    typename Source,
    typename =
        std::enable_if_t<std::conjunction_v<std::is_integral<Source>, std::is_integral<Dest>>>>
fcppt::optional::object<Dest> truncation_check(Source const _source)
{
  return fcppt::cast::detail::truncation_check<Dest>(_source);
}
}

#endif
