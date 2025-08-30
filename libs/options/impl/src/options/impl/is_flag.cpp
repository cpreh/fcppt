//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/char_type.hpp>
#include <fcppt/not.hpp>
#include <fcppt/string.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>
#include <fcppt/options/impl/is_flag.hpp>
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

fcppt::optional::object<std::pair<fcppt::options::detail::flag_is_short, fcppt::string>>
fcppt::options::impl::is_flag(fcppt::string_view const _value)
{
  // TODO(philipp): This is terrible
  fcppt::string_view::const_iterator pos{_value.begin()};

  using result_type =
      fcppt::optional::object<std::pair<fcppt::options::detail::flag_is_short, fcppt::string>>;

  auto const is_dash{[](fcppt::char_type const _ch) { return _ch == FCPPT_TEXT('-'); }};

  if (pos == _value.end() || fcppt::not_(is_dash(*pos)))
  {
    return result_type{};
  }

  ++pos; // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)

  return result_type{
      is_dash(*pos)
          ? std::make_pair(
                fcppt::options::detail::flag_is_short{false},
                fcppt::string{std::next(pos), _value.end()})
          : std::make_pair(
                fcppt::options::detail::flag_is_short{true}, fcppt::string{pos, _value.end()})};
}

FCPPT_PP_POP_WARNING
