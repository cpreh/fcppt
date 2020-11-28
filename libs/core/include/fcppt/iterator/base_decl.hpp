//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_ITERATOR_BASE_DECL_HPP_INCLUDED
#define FCPPT_ITERATOR_BASE_DECL_HPP_INCLUDED

#include <fcppt/not.hpp>
#include <fcppt/iterator/base_fwd.hpp>
#include <fcppt/iterator/category_at_least.hpp>
#include <fcppt/iterator/is_types.hpp>
#include <fcppt/iterator/types.hpp>
#include <fcppt/type_traits/implication.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iterator>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace iterator
{
/**
\brief A template for implementing iterators.

\ingroup fcpptiterator

This class is meant to be derived from in order to implement an iterator. It
provides all functions to fulfil the iterator requirements of a specific
iterator category. The derived class <code>D</code> is expected to implement
certain public functions depending on what the category is:

<ul>
<li>Input iterator:
    <ul>
    <li><code>void increment()</code>: Increments the iterator.</li>
    <li><code>bool equal(D) const</code>: Compares two iterators for equality.</li>
    <li><code>Types::reference dereference() const</code>: Returns the current element.</li>
    </ul>
</li>
<li>Forward iterator:
    <ul>
    <li><code>Types::reference</code> must be <code>Types::value_type (const) &</code>.</li>
    <li><code>D</code> must have a default constructor.</li>
    </ul>
</li>
<li>Bidirectional iterator:
    <ul>
    <li><code>void decrement()</code>: Decrements the iterator.</li>
    </ul>
</li>
<li>Random Access iterator:
    <ul>
    <li><code>void advance(Types::difference_type)</code>: Moves the iterator
forwards/backwards.</li> <li><code>Types::difference_type distance_to(D) const</code>: The value to
advance <code>*this</code> with in order to be equal to the argument.</li>
    </ul>
</li>
</ul>

\tparam Types Must be an fcppt::iterator::types.
*/
template <typename Types>
class base
{
public:
  static_assert(fcppt::iterator::is_types<Types>::value, "Types must be fcppt::iterator::types");

  using derived = typename Types::derived;

  static_assert(fcppt::not_(std::is_const_v<derived>), "Derived can not be const");

  using value_type = typename Types::value_type;

  using reference = typename Types::reference;

  using difference_type = typename Types::difference_type;

  using pointer = std::add_pointer_t<reference>;

  using iterator_category = typename Types::iterator_category;

private:
  template <typename Category>
  using my_category_at_least = fcppt::iterator::category_at_least<iterator_category, Category>;

  static_assert(
      fcppt::type_traits::implication<
          my_category_at_least<std::forward_iterator_tag>,
          std::disjunction<
              std::is_same<reference, value_type &>,
              std::is_same<reference, value_type const &>>>::value,
      "Forward iterators need real reference types");

  static_assert(
      fcppt::type_traits::implication<
          my_category_at_least<std::random_access_iterator_tag>,
          std::is_signed<difference_type>>::value,
      "difference_type must be signed for random access iterators");

protected:
  base();

public:
  [[nodiscard]] reference operator*() const;

  derived &operator++();

  [[nodiscard]] bool operator==(base const &) const;

  [[nodiscard]] bool operator!=(base const &) const;

  [[nodiscard]] pointer operator->() const;

  [[nodiscard]] derived operator++(int);

  void swap(base &);

  // Bidirectional iterator
  derived &operator--();

  [[nodiscard]] derived operator--(int);

  // Random access iterator
  derived &operator+=(difference_type);

  [[nodiscard]] derived operator+(difference_type) const;

  derived &operator-=(difference_type);

  [[nodiscard]] derived operator-(difference_type) const;

  [[nodiscard]] reference operator[](difference_type) const;

  [[nodiscard]] difference_type operator-(base const &) const;

private:
  [[nodiscard]] derived &get();

  [[nodiscard]] derived const &get() const;
};

template <typename Types>
void swap(fcppt::iterator::base<Types> &, fcppt::iterator::base<Types> &);

// Random access iterator
template <typename Types>
typename fcppt::iterator::base<Types>::derived operator+(
    typename fcppt::iterator::base<Types>::difference_type, fcppt::iterator::base<Types> const &);

template <typename Types>
bool operator<(fcppt::iterator::base<Types> const &, fcppt::iterator::base<Types> const &);

template <typename Types>
bool operator>(fcppt::iterator::base<Types> const &, fcppt::iterator::base<Types> const &);

template <typename Types>
bool operator<=(fcppt::iterator::base<Types> const &, fcppt::iterator::base<Types> const &);

template <typename Types>
bool operator>=(fcppt::iterator::base<Types> const &, fcppt::iterator::base<Types> const &);

}
}

#endif
