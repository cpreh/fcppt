//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/is_short.hpp>
#include <fcppt/options/missing_option_argument_error.hpp>
#include <fcppt/options/name.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/use_option.hpp>
#include <fcppt/options/detail/use_option_result.hpp>
#include <fcppt/options/detail/use_option_success.hpp>
#include <fcppt/options/impl/flag_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <ranges>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::options::detail::use_option_result fcppt::options::detail::use_option(
    fcppt::reference<fcppt::options::state> const _state,
    fcppt::string_view const _name,
    fcppt::options::is_short const _is_short)
{
  fcppt::options::name flag_name{fcppt::options::impl::flag_name(_name, _is_short)};

  fcppt::args_vector &args{_state.get().args()};

  std::ranges::subrange const found{std::ranges::find(args, flag_name.get()), args.end()};

  if (std::ranges::empty(found))
  {
    return fcppt::options::detail::use_option_result{
        fcppt::optional::object<fcppt::options::detail::use_option_success>{}};
  }

  if (std::ranges::size(found) == 1)
  {
    return fcppt::options::detail::use_option_result{
        fcppt::options::missing_option_argument_error{std::move(flag_name)}};
  }

  std::ranges::subrange const pair{std::ranges::views::take(found, 2)};

  fcppt::string result{*std::ranges::begin(std::ranges::views::drop(pair, 1))};

  args.erase(std::ranges::begin(pair), std::ranges::end(pair));

  return fcppt::options::detail::use_option_result{fcppt::optional::make(
      fcppt::options::detail::use_option_success{std::move(flag_name), std::move(result)})};
}
