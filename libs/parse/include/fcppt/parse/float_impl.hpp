//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_PARSE_FLOAT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_FLOAT_IMPL_HPP_INCLUDED

#include <fcppt/char_literal.hpp>
#include <fcppt/extract_from_string.hpp>
#include <fcppt/output_to_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string_literal.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/parse/basic_stream_fwd.hpp>
#include <fcppt/parse/digits.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/float_decl.hpp>
#include <fcppt/parse/int_impl.hpp>
#include <fcppt/parse/make_lexeme.hpp>
#include <fcppt/parse/make_literal.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

template <typename Type>
fcppt::parse::float_<Type>::float_() = default;

template <typename Type>
template <typename Ch, typename Skipper>
fcppt::parse::result<Ch, typename fcppt::parse::float_<Type>::result_type>
fcppt::parse::float_<Type>::parse(
    fcppt::reference<fcppt::parse::basic_stream<Ch>> const _state, Skipper const &_skipper) const
{
  auto const parser{
      fcppt::parse::int_<std::int64_t>{} >>
      fcppt::parse::make_lexeme(
          fcppt::parse::make_literal(FCPPT_CHAR_LITERAL(Ch, '.')) >> +fcppt::parse::digits<Ch>())};

  return fcppt::either::bind(
      parser.parse(_state, _skipper), [](fcppt::parse::result_of<decltype(parser)> const &_result) {
        std::basic_string<Ch> const float_string{
            fcppt::output_to_string<std::basic_string<Ch>>(fcppt::tuple::get<0>(_result)) +
            std::basic_string<Ch>{'.'} + fcppt::tuple::get<1>(_result)};

        return fcppt::either::from_optional(
            fcppt::extract_from_string<Type>(float_string), [&float_string] {
              return fcppt::parse::error<Ch>{
                  std::basic_string<Ch>{FCPPT_STRING_LITERAL(Ch, "Expected float, got ")} +
                  float_string};
            });
      });
}

#endif
