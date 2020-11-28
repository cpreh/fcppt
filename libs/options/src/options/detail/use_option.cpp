//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>
#include <fcppt/options/detail/missing_option_argument.hpp>
#include <fcppt/options/detail/use_option.hpp>
#include <fcppt/options/detail/use_option_result.hpp>
#include <fcppt/options/impl/flag_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::detail::use_option_result fcppt::options::detail::use_option(
    fcppt::reference<fcppt::options::state> const _state,
    fcppt::string_view const &_name,
    fcppt::options::detail::flag_is_short const _is_short)
{
  fcppt::string const flag_name{fcppt::options::impl::flag_name(_name, _is_short)};

  // TODO(philipp): This is terrible
  fcppt::args_vector &args{_state.get().args()};

  fcppt::args_vector::iterator const end{args.end()};

  fcppt::args_vector::iterator pos{std::find(args.begin(), end, flag_name)};

  if (pos == end)
  {
    return fcppt::options::detail::use_option_result{fcppt::optional_string{}};
  }

  if (
      // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
      std::next(pos) == end)
  {
    return fcppt::options::detail::use_option_result{
        fcppt::options::detail::missing_option_argument{flag_name}};
  }

  fcppt::string result{// NOLINTNEXTLINE(fuchsia-default-arguments-calls)
                       *std::next(pos)};

  args.erase(
      // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
      pos,
      // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
      std::next(pos, 2));

  return fcppt::options::detail::use_option_result{fcppt::optional_string{std::move(result)}};
}
