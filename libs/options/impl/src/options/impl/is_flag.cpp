//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/char_type.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/text.hpp>
#include <fcppt/container/uncons_string_view.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>
#include <fcppt/options/impl/is_flag.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/tuple/get.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

fcppt::optional::object<std::pair<fcppt::options::detail::flag_is_short, fcppt::string_view>>
fcppt::options::impl::is_flag(fcppt::string_view const _value)
{
  using result_type =
      fcppt::optional::object<std::pair<fcppt::options::detail::flag_is_short, fcppt::string_view>>;

  auto const is_dash{[](fcppt::char_type const _ch) { return _ch == FCPPT_TEXT('-'); }};

  return fcppt::optional::bind(
      fcppt::container::uncons_string_view(_value),
      [is_dash](fcppt::tuple::object<fcppt::char_type, fcppt::string_view> const _pos1)
      {
        fcppt::string_view const rest_view{fcppt::tuple::get<1>(_pos1)};

        return is_dash(fcppt::tuple::get<0>(_pos1))
                   ? fcppt::optional::map(
                         fcppt::container::uncons_string_view(rest_view),
                         [is_dash, rest_view](
                             fcppt::tuple::object<fcppt::char_type, fcppt::string_view> const _pos2)
                         {
                           bool const dash_here{is_dash(fcppt::tuple::get<0>(_pos2))};

                           return std::make_pair(
                               fcppt::options::detail::flag_is_short{!dash_here},
                               dash_here ? fcppt::tuple::get<1>(_pos2) : rest_view);
                         })
                   : result_type{};
      });
}

FCPPT_PP_POP_WARNING
