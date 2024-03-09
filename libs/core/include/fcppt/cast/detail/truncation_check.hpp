//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CAST_DETAIL_TRUNCATION_CHECK_HPP_INCLUDED
#define FCPPT_CAST_DETAIL_TRUNCATION_CHECK_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::cast::detail
{
template <typename Dest, typename Source>
fcppt::optional::object<Dest> truncation_check(Source const _source)
  requires(std::is_signed_v<Dest> == std::is_signed_v<Source> && sizeof(Dest) >= sizeof(Source))
{
  return fcppt::optional::object<Dest>(_source);
}

template <typename Dest, typename Source>
fcppt::optional::object<Dest> truncation_check(Source const _source)
  requires(std::is_unsigned_v<Dest> && std::is_unsigned_v<Source> && sizeof(Dest) < sizeof(Source))
{
  using dest_type = fcppt::optional::object<Dest>;

  return fcppt::cast::size<Source>(std::numeric_limits<Dest>::max()) < _source
             ? dest_type()
             : dest_type(fcppt::cast::size<Dest>(_source));
}

template <typename Dest, typename Source>
fcppt::optional::object<Dest> truncation_check(Source const _source)
  requires(std::is_signed_v<Dest> && std::is_signed_v<Source> && sizeof(Dest) < sizeof(Source))
{
  using dest_type = fcppt::optional::object<Dest>;

  return fcppt::cast::size<Source>(std::numeric_limits<Dest>::max()) < _source ||
                 fcppt::cast::size<Source>(std::numeric_limits<Dest>::min()) > _source
             ? dest_type()
             : dest_type(fcppt::cast::size<Dest>(_source));
}

template <typename Dest, typename Source>
fcppt::optional::object<Dest> truncation_check(Source const _source)
  requires(std::is_unsigned_v<Dest> && std::is_signed_v<Source>)
{
  using dest_type = fcppt::optional::object<Dest>;

  return _source < fcppt::literal<Source>(0)
             ? dest_type()
             : fcppt::cast::detail::truncation_check<Dest>(fcppt::cast::to_unsigned(_source));
}

template <typename Dest, typename Source>
fcppt::optional::object<Dest> truncation_check(Source const _source)
  requires(std::is_signed_v<Dest> && std::is_unsigned_v<Source>)
{
  using dest_type = fcppt::optional::object<Dest>;

  using intermediate_type = std::make_unsigned_t<Dest>;

  using intermediate_dest = fcppt::optional::object<intermediate_type>;

  intermediate_dest const dest(fcppt::cast::detail::truncation_check<intermediate_type>(_source));

  return fcppt::optional::bind(dest, [_source](intermediate_type const _dest) {
    return fcppt::cast::to_unsigned(std::numeric_limits<Dest>::max()) < _dest
               ? dest_type()
               : dest_type(fcppt::cast::size<Dest>(fcppt::cast::to_signed(_source)));
  });
}

}

#endif
