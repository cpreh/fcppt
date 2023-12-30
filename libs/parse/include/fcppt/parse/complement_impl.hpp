//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_COMPLEMENT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_COMPLEMENT_IMPL_HPP_INCLUDED

#include <fcppt/const.hpp>
#include <fcppt/copy.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/not.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/complement_decl.hpp> // IWYU pragma: export
#include <fcppt/parse/complement_error_impl.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/get_char.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/got_tag_fwd.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Parser>
fcppt::parse::complement<Parser>::complement(Parser &&_parser) : parser_{std::move(_parser)}
{
}

template <typename Parser>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::complement<Parser>::result_type>
fcppt::parse::complement<Parser>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &) const
{
  fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

  fcppt::optional::object<Ch> const res{fcppt::parse::get_char(_state)};

  return fcppt::either::from_optional(
      fcppt::optional::bind(
          res,
          [this](Ch const _ch)
          {
            return fcppt::optional::make_if(
                fcppt ::not_(fcppt::parse::deref(this->parser_).chars().contains(_ch)),
                fcppt::const_(_ch));
          }),
      [this, pos, res]
      {
        return fcppt::parse::error<Ch>{
            fcppt::parse::error_variant<Ch>{fcppt::parse::complement_error<Ch>{
                pos,
                fcppt::copy(fcppt::parse::deref(this->parser_).chars()),
                fcppt::make_strong_typedef<fcppt::parse::got_tag>(res)}},
            fcppt::parse::is_fatal{false}};
      });
}

#endif
