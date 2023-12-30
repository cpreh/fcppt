//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_IMPL_FIND_CHILD_TPL_HPP_INCLUDED
#define FCPPT_LOG_IMPL_FIND_CHILD_TPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/strong_typedef_comparison.hpp> // IWYU pragma: keep
#include <fcppt/algorithm/find_if_opt.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/optional/deref.hpp>
#include <fcppt/optional/reference.hpp>

namespace fcppt::log::impl
{
template <typename Tree>
fcppt::optional::reference<Tree>
find_child_tpl(fcppt::reference<Tree> const _tree, fcppt::log::name const &_name)
{
  return fcppt::optional::deref(fcppt::algorithm::find_if_opt(
      _tree.get(), [&_name](Tree &_child) { return _child.value().name() == _name; }));
}

}

#endif
