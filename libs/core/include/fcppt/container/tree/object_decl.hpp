//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/container/tree/object_fwd.hpp> // IWYU pragma: keep
#include <fcppt/optional/object_decl.hpp>
#include <fcppt/optional/reference_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <list>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace fcppt::container::tree
{
/**
\brief A tree data structure

\ingroup fcpptcontainertree
*/
template <typename T>
class object
{
public:
  using child_list = std::list<object>;

  using value_type = T;

  using size_type = child_list::size_type;

  using difference_type = child_list::difference_type;

  using iterator = child_list::iterator;

  using const_iterator = child_list::const_iterator;

  using reverse_iterator = child_list::reverse_iterator;

  using const_reverse_iterator = child_list::const_reverse_iterator;

  using optional_ref = fcppt::optional::reference<object>;

  using const_optional_ref = fcppt::optional::reference<object const>;

  using optional_object = fcppt::optional::object<object>;

  using reference = fcppt::reference<object>;

  explicit object(T const &);

  explicit object(T &&);

  /**
  \brief Constructs a tree, including its children, by moving
  */
  object(T &&, child_list &&);

  /**
  \brief Deeply copies a tree

  \see tree_copying
  */
  object(object const &);

  // TODO(philipp): There is a problem with fcppt::log::detail::context_tree_node
  // NOLINTNEXTLINE(cppcoreguidelines-noexcept-move-operations,hicpp-noexcept-move,performance-noexcept-move-constructor)
  object(object &&) noexcept(std::is_nothrow_move_constructible_v<T>);

  /**
  \brief Deeply assigns a tree

  \see tree_copying
  */
  object &operator=(object const &);

  // NOLINTNEXTLINE(cppcoreguidelines-noexcept-move-operations,hicpp-noexcept-move,performance-noexcept-move-constructor)
  object &operator=(object &&) noexcept(std::is_nothrow_move_assignable_v<T>);

  ~object();

  [[nodiscard]] child_list const &children() const;

  /**
  \brief Returns a reference to the parent of this tree.
  */
  [[nodiscard]] optional_ref parent();

  /**
  \brief Returns a reference to the parent of this tree.
  */
  [[nodiscard]] const_optional_ref parent() const;

  /**
  \brief Detaches the given child from the parent and returns it.
  */
  [[nodiscard]] object release(iterator);

  /**
  \brief Sets a new value
  */
  void value(T const &);

  void value(T &&);

  /**
  \brief Retrieves the tree's value
  */
  [[nodiscard]] T &value();

  /**
  \brief Retrieves the tree's value
  */
  [[nodiscard]] T const &value() const;

  /**
  \brief Inserts a new child at the end of the child list
  */
  reference push_back(object &&);

  /**
  \brief Inserts a new child at the end of the child list
  */
  reference push_back(T const &);

  reference push_back(T &&);

  /**
  \brief Removes a child from the end of the child list
  */
  [[nodiscard]] optional_object pop_back();

  /**
  \brief Adds a child in front of the child list
  */
  reference push_front(object &&);

  /**
  \brief Adds a child in front of the child list
  */
  reference push_front(T const &);

  reference push_front(T &&);

  /**
  \brief Removes a child from the front of the children list and returns it.
  */
  [[nodiscard]] optional_object pop_front();

  /**
  \brief Removes all children
  */
  void clear();

  [[nodiscard]] optional_ref back();

  [[nodiscard]] const_optional_ref back() const;

  [[nodiscard]] optional_ref front();

  [[nodiscard]] const_optional_ref front() const;

  [[nodiscard]] iterator begin();

  [[nodiscard]] iterator end();

  [[nodiscard]] const_iterator begin() const;

  [[nodiscard]] const_iterator end() const;

  [[nodiscard]] reverse_iterator rbegin();

  [[nodiscard]] reverse_iterator rend();

  [[nodiscard]] const_reverse_iterator rbegin() const;

  [[nodiscard]] const_reverse_iterator rend() const;

  /**
  \brief Inserts an element before the given iterator
  */
  void insert(iterator, object &&);

  /**
  \brief Inserts an element before the given iterator
  */
  void insert(iterator, T const &);

  void insert(iterator, T &&);

  /**
  \brief Erases a single element
  */
  void erase(iterator);

  /**
  \brief Erases a range
  */
  void erase(iterator, iterator);

  /**
  \brief Returns the number of children
  */
  [[nodiscard]] size_type size() const;

  /**
  \brief Returns if the container is empty
  */
  [[nodiscard]] bool empty() const;

  /**
  \brief Swaps with another tree
  */
  void swap(object &) noexcept;

  /**
  \brief Sorts the children using operator< on T
  */
  void sort();

  /**
  \brief Sorts the children using a predicate on two Ts
  */
  template <typename Predicate>
  void sort(Predicate const &);

private:
  [[nodiscard]] child_list copy_children(child_list const &);

  [[nodiscard]] child_list move_children(child_list &&);

  T value_;

  object *parent_;

  child_list children_;
};

/**
\brief Swaps two trees
*/
template <typename T>
void swap(fcppt::container::tree::object<T> &, fcppt::container::tree::object<T> &) noexcept;

}

#endif
