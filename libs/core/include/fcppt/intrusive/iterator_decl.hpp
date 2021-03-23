//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_INTRUSIVE_ITERATOR_DECL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_ITERATOR_DECL_HPP_INCLUDED

#include <fcppt/intrusive/base_fwd.hpp>
#include <fcppt/intrusive/iterator_fwd.hpp>
#include <fcppt/intrusive/detail/iterator_base.hpp>
#include <fcppt/iterator/base_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace intrusive
{
/**
\brief The iterator type of an intrusive list.

\ingroup fcpptintrusive

This is a bidirectional iterator.
*/
template <typename Type>
class iterator : public fcppt::intrusive::detail::iterator_base<Type>
{
public:
  using iterator_base = fcppt::intrusive::detail::iterator_base<Type>;

  using reference = typename iterator_base::reference;

  using base_type = fcppt::intrusive::base<std::remove_const_t<Type>>;

  using pointer_type = std::conditional_t<std::is_const_v<Type>, base_type const, base_type> *;

  iterator();

  explicit iterator(pointer_type);

  void increment();

  void decrement();

  [[nodiscard]] reference dereference() const;

  [[nodiscard]] bool equal(iterator const &) const;

private:
  pointer_type cur_;
};

}
}

#endif
