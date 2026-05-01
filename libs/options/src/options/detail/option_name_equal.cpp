//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/string_view.hpp>
#include <fcppt/strong_typedef_comparison.hpp> // IWYU pragma: keep
#include <fcppt/options/is_short.hpp>
#include <fcppt/options/option_name.hpp>
#include <fcppt/options/detail/option_name_equal.hpp>
#include <fcppt/options/impl/option_name_view.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

bool fcppt::options::detail::option_name_equal::operator()(
    fcppt::options::option_name const &_left, fcppt::options::option_name const &_right)
{
  return fcppt::options::detail::option_name_equal::operator()(
      _left, fcppt::options::impl::option_name_view(_right));
}

bool fcppt::options::detail::option_name_equal::operator()(
    std::pair<fcppt::options::is_short, fcppt::string_view> const &_left,
    fcppt::options::option_name const &_right)
{
  return _left == fcppt::options::impl::option_name_view(_right);
}

bool fcppt::options::detail::option_name_equal::operator()(
    fcppt::options::option_name const &_left,
    std::pair<fcppt::options::is_short, fcppt::string_view> const &_right)
{
  return fcppt::options::impl::option_name_view(_left) == _right;
}
