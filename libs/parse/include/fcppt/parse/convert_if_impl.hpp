//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_CONVERT_IF_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_CONVERT_IF_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/map_failure.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/convert_if_decl.hpp> // IWYU pragma: export
#include <fcppt/parse/custom_error.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch, typename Parser, typename Result>
fcppt::parse::convert_if<Ch, Parser, Result>::convert_if(Parser &&_parser, function_type &&_convert)
    : parser_{std::move(_parser)}, convert_{std::move(_convert)}
{
}

template <typename Ch, typename Parser, typename Result>
template <typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::convert_if<Ch, Parser, Result>::result_type>
fcppt::parse::convert_if<Ch, Parser, Result>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
 fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

 return fcppt::either::bind(
     fcppt::parse::deref(this->parser_).parse(_state, _skipper),
     [pos, this](fcppt::parse::result_of<Parser> &&_result)
     {
       return fcppt::either::map_failure(
           this->convert_(pos, std::move(_result)),
           [](fcppt::parse::custom_error<Ch> &&_error)
           {
             return fcppt::parse::error<Ch>{
                 fcppt::parse::error_variant<Ch>{std::move(_error)}, fcppt::parse::is_fatal{false}};
           });
     });
}

#endif
