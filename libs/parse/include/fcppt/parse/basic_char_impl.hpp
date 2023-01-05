//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_CHAR_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/parse/basic_char_decl.hpp>
#include <fcppt/parse/basic_char_error_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/get_char.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/result.hpp>

template <typename Ch>
fcppt::parse::basic_char<Ch>::basic_char() = default;

template <typename Ch>
template <typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::basic_char<Ch>::result_type>
fcppt::parse::basic_char<Ch>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &) const
{
 fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

 return fcppt::either::from_optional(
     fcppt::parse::get_char(_state),
     [pos]
     {
       return fcppt::parse::error<Ch>{
           fcppt::parse::error_variant<Ch>{fcppt::parse::basic_char_error<Ch>{pos}},
           fcppt::parse::is_fatal{false}};
     });
}

#endif
