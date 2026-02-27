//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_BASIC_CHAR_SET_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_SET_IMPL_HPP_INCLUDED

#include <fcppt/const.hpp>
#include <fcppt/copy.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/parse/basic_char_set_decl.hpp> // IWYU pragma: export
#include <fcppt/parse/basic_char_set_error_impl.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/get_char.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/got_tag_fwd.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Ch>
fcppt::parse::basic_char_set<Ch>::basic_char_set(std::initializer_list<Ch> const &_inits)
    : basic_char_set(char_set_type{_inits})
{
}

template <typename Ch>
fcppt::parse::basic_char_set<Ch>::basic_char_set(char_set_type &&_chars) : chars_{std::move(_chars)}
{
}

template <typename Ch>
template <typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::basic_char_set<Ch>::result_type>
fcppt::parse::basic_char_set<Ch>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &) const
{
  fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

  fcppt::optional::object<Ch> const res{fcppt::parse::get_char(_state)};

  return fcppt::either::from_optional(
      fcppt::optional::bind(
          res,
          [this](Ch const _ch)
          { return fcppt::optional::make_if(this->chars_.contains(_ch), fcppt::const_(_ch)); }),
      [this, pos, res]
      {
        return fcppt::parse::error<Ch>{
            fcppt::parse::error_variant<Ch>{fcppt::parse::basic_char_set_error<Ch>{
                pos,
                fcppt::copy(this->chars_),
                fcppt::make_strong_typedef<fcppt::parse::got_tag>(res)}},
            fcppt::parse::is_fatal{false}};
      });
}

template <typename Ch>
fcppt::parse::basic_char_set<Ch>::char_set_type const &
fcppt::parse::basic_char_set<Ch>::chars() const
{
  return this->chars_;
}

#endif
