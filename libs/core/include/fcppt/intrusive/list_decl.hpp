//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INTRUSIVE_LIST_DECL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_LIST_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/base_decl.hpp>
#include <fcppt/intrusive/iterator_fwd.hpp>
#include <fcppt/intrusive/list_fwd.hpp>

namespace fcppt::intrusive
{
/**
\brief An intrusive list.

\ingroup fcpptintrusive

Elements that are going to be part of a list must derive from
<code>fcppt::intrusive::base<Type></code>. They get a list as a constructor
parameter and as long as they are not destroyed or moved from, they are part of
the list.
*/
template <typename Type>
class list
{
  FCPPT_NONCOPYABLE(list);

public:
  list();

  list(list &&) noexcept;

  list &operator=(list &&) noexcept;

  ~list();

  using iterator = fcppt::intrusive::iterator<Type>;

  using const_iterator = fcppt::intrusive::iterator<Type const>;

  [[nodiscard]] iterator begin();

  [[nodiscard]] iterator end();

  [[nodiscard]] const_iterator begin() const;

  [[nodiscard]] const_iterator end() const;

  [[nodiscard]] bool empty() const;

private:
  using base_type = fcppt::intrusive::base<Type>;

  template <typename T>
  friend class fcppt::intrusive::base;

  base_type head_; // NOLINT(cppcoreguidelines-use-default-member-init,modernize-use-default-member-init)
};

}

#endif
