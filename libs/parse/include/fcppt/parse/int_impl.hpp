//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_INT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_INT_IMPL_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/extract_from_string.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/digits.hpp>
#include <fcppt/parse/error_impl.hpp>
#include <fcppt/parse/error_variant_impl.hpp>
#include <fcppt/parse/get_position.hpp>
#include <fcppt/parse/got_tag_fwd.hpp>
#include <fcppt/parse/int_decl.hpp>
#include <fcppt/parse/is_fatal.hpp>
#include <fcppt/parse/make_lexeme.hpp>
#include <fcppt/parse/make_literal.hpp>
#include <fcppt/parse/position.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/type_name_tag_fwd.hpp>
#include <fcppt/parse/typed_error_impl.hpp>
#include <fcppt/parse/operators/optional.hpp>
#include <fcppt/parse/operators/repetition_plus.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Type>
fcppt::parse::int_<Type>::int_() = default;

template <typename Type>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::int_<Type>::result_type>
fcppt::parse::int_<Type>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  auto const parser{fcppt::parse::make_lexeme(
      -fcppt::parse::make_literal(FCPPT_CHAR_LITERAL(Ch, '-')) >>
      +fcppt::parse::digits<Ch>())};

  fcppt::parse::position<Ch> const pos{fcppt::parse::get_position(_state)};

  return fcppt::either::bind(
      parser.parse(_state, _skipper),
      [pos](fcppt::tuple::object<fcppt::optional::object<fcppt::unit>, std::basic_string<Ch>>
                &&_result)
      {
        return fcppt::either::map(
            fcppt::either::from_optional(
                fcppt::extract_from_string<Type>(fcppt::tuple::get<1>(_result)),
                [&_result, pos]
                {
                  return fcppt::parse::error<Ch>{
                      fcppt::parse::error_variant<Ch>{fcppt::parse::typed_error<Ch>{
                          pos,
                          // TODO(philipp): Take the type into account here!
                          fcppt::make_strong_typedef<fcppt::parse::type_name_tag>(
                              std::basic_string<Ch>{FCPPT_STRING_LITERAL(Ch, "int")}),
                          fcppt::make_strong_typedef<fcppt::parse::got_tag>(
                              std::move(fcppt::tuple::get<1>(_result)))}},
                      fcppt::parse::is_fatal{false}};
                }),
            [&_result](result_type const _value)
            { return fcppt::tuple::get<0>(_result).has_value() ? -_value : _value; });
      });
}

#endif
