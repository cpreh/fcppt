//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_LOG_DETAIL_CONTEXT_TREE_NODE_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_CONTEXT_TREE_NODE_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/log/name.hpp>
#include <fcppt/log/optional_level_fwd.hpp>
#include <fcppt/log/detail/active_level_int.hpp>
#include <fcppt/log/detail/context_tree_node_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <atomic>
#include <fcppt/config/external_end.hpp>

namespace fcppt::log::detail
{
class context_tree_node
{
  FCPPT_NONCOPYABLE(context_tree_node);

public:
  context_tree_node(fcppt::log::name, fcppt::log::optional_level const &);

  context_tree_node(context_tree_node &&) noexcept;

  context_tree_node &operator=(context_tree_node &&) noexcept;

  ~context_tree_node() noexcept;

  [[nodiscard]] fcppt::log::name const &name() const;

  [[nodiscard]] fcppt::log::optional_level level() const;

  void level(fcppt::log::optional_level const &);

private:
  fcppt::log::name name_;

  std::atomic<fcppt::log::detail::active_level_int> atomic_level_;
};

}

#endif
