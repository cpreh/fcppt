//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_EPSILON_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_EPSILON_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/epsilon_decl.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/result.hpp>

inline fcppt::parse::epsilon::epsilon() = default;

template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, fcppt::parse::epsilon::result_type> fcppt::parse::epsilon::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>>, Skipper const &) const
{
  return fcppt::parse::make_success<Ch>(fcppt::unit{});
}

#endif
