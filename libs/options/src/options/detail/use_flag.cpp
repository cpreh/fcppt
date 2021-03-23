//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/args_vector.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/string.hpp>
#include <fcppt/string_view.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/detail/flag_is_short.hpp>
#include <fcppt/options/detail/use_flag.hpp>
#include <fcppt/options/impl/flag_name.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

bool fcppt::options::detail::use_flag(
    fcppt::reference<fcppt::options::state> const _state,
    fcppt::string_view const &_name,
    fcppt::options::detail::flag_is_short const _is_short)
{
  fcppt::string const flag_name{fcppt::options::impl::flag_name(_name, _is_short)};

  fcppt::args_vector &args{_state.get().args()};

  fcppt::args_vector::iterator const pos{std::find(args.begin(), args.end(), flag_name)};

  if (pos != args.end())
  {
    args.erase(
        // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
        pos);

    return true;
  }

  return false;
}
