//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/const.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/options/is_short.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/impl/is_flag.hpp>
#include <fcppt/options/impl/next_arg.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ranges>
#include <utility>
#include <fcppt/config/external_end.hpp>

fcppt::optional::object<fcppt::args_vector::const_iterator> fcppt::options::impl::next_arg(
    fcppt::args_vector const &_args, fcppt::options::option_name_set const &_option_names)
{
  using result_type = fcppt::optional::object<fcppt::args_vector::const_iterator>;

  for(std::ranges::subrange range{_args.begin(), _args.end()}; !std::ranges::empty(range);)
  {
    if (fcppt::optional::maybe(
            fcppt::options::impl::is_flag(*std::ranges::begin(range)),
            fcppt::const_(false),
            [&_option_names, &range](
                std::pair<fcppt::options::is_short, fcppt::string_view> const &_flag)
            {
              range = std::ranges::views::drop(range, 1);

              if (!std::ranges::empty(range) && _option_names.contains(_flag))
              {
                range = std::ranges::views::drop(range, 1);
              }

              return true;
            }))
    {
      continue;
    }

    return result_type{std::ranges::begin(range)};
  }

  return result_type{};
}
