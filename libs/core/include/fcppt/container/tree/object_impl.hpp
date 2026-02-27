//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_CONTAINER_TREE_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_TREE_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/maybe_back.hpp>
#include <fcppt/container/maybe_front.hpp>
#include <fcppt/container/pop_back.hpp>
#include <fcppt/container/pop_front.hpp>
#include <fcppt/container/tree/object_decl.hpp> // IWYU pragma: export
#include <fcppt/optional/from_pointer.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp> // IWYU pragma: keep
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename T>
fcppt::container::tree::object<T>::object(T const &_value)
    : value_{_value}, parent_{nullptr}, children_{}
{
}

template <typename T>
fcppt::container::tree::object<T>::object(T &&_value)
    : value_{std::move(_value)}, parent_{nullptr}, children_{}
{
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

template <typename T>
fcppt::container::tree::object<T>::object(T &&_value, child_list &&_children)
    : value_{std::move(_value)},
      parent_{nullptr},
      children_{this->move_children(std::move(_children))}
{
}

template <typename T>
fcppt::container::tree::object<T>::object(object const &_other)
    : value_{_other.value()}, parent_{nullptr}, children_{this->copy_children(_other.children_)}
{
}

template <typename T>
fcppt::container::tree::object<T>::object(object &&_other) noexcept(
    std::is_nothrow_move_constructible_v<T>) // NOLINT(cppcoreguidelines-noexcept-move-operations,hicpp-noexcept-move,performance-noexcept-move-constructor)
    : value_{std::move(_other.value())},
      parent_{nullptr},
      children_{this->move_children(std::move(_other.children_))}
{
}

FCPPT_PP_POP_WARNING

template <typename T>
fcppt::container::tree::object<T> &fcppt::container::tree::object<
    T>::operator=( // NOLINT(bugprone-unhandled-self-assignment,cert-oop54-cpp)
    object const &_other)
{
  if (this == &_other)
  {
    return *this;
  }

  this->value_ = _other.value_;

  this->parent_ = nullptr;

  this->children_ = this->copy_children(_other.children_);

  return *this;
}

template <typename T>
fcppt::container::tree::object<T> &fcppt::container::tree::object<T>::operator=(
    object &&_other) noexcept(std::is_nothrow_move_assignable_v<T>) // NOLINT(cppcoreguidelines-noexcept-move-operations,hicpp-noexcept-move,performance-noexcept-move-constructor)
{
  value_ = std::move(_other.value_);

  children_ = this->move_children(std::move(_other.children_));

  std::swap(parent_, _other.parent_);

  return *this;
}

namespace fcppt::container::tree
{
template <typename T>
object<T>::~object() = default;
}

template <typename T>
fcppt::container::tree::object<T>::child_list const &
fcppt::container::tree::object<T>::children() const
{
  return this->children_;
}

template <typename T>
fcppt::container::tree::object<T>::optional_ref fcppt::container::tree::object<T>::parent()
{
  return fcppt::optional::from_pointer(this->parent_);
}

template <typename T>
fcppt::container::tree::object<T>::const_optional_ref
fcppt::container::tree::object<T>::parent() const
{
  return fcppt::optional::map(
      fcppt::optional::from_pointer(this->parent_),
      [](fcppt::reference<object> const _val) { return fcppt::make_cref(_val.get()); });
}

template <typename T>
fcppt::container::tree::object<T> fcppt::container::tree::object<T>::release(iterator const _it)
{
  object ret(std::move(*_it));

  this->children_.erase(_it);

  ret.parent_ = nullptr;

  return ret;
}

template <typename T>
void fcppt::container::tree::object<T>::value(T const &_value)
{
  this->value_ = _value;
}

template <typename T>
void fcppt::container::tree::object<T>::value(T &&_value)
{
  this->value_ = std::move(_value);
}

template <typename T>
T &fcppt::container::tree::object<T>::value()
{
  return this->value_;
}

template <typename T>
T const &fcppt::container::tree::object<T>::value() const
{
  return this->value_;
}

template <typename T>
fcppt::container::tree::object<T>::reference
fcppt::container::tree::object<T>::push_back(object &&_tree)
{
  this->insert(this->end(), std::move(_tree));

  return fcppt::make_ref(this->children_.back());
}

template <typename T>
fcppt::container::tree::object<T>::reference
fcppt::container::tree::object<T>::push_back(T const &_value)
{
  this->insert(this->end(), _value);

  return fcppt::make_ref(this->children_.back());
}

template <typename T>
fcppt::container::tree::object<T>::reference
fcppt::container::tree::object<T>::push_back(T &&_value)
{
  this->insert(this->end(), std::move(_value));

  return fcppt::make_ref(this->children_.back());
}

template <typename T>
fcppt::container::tree::object<T>::optional_object
fcppt::container::tree::object<T>::pop_back()
{
  return fcppt::optional::map(fcppt::container::pop_back(this->children_), [](object &&_result) {
    _result.parent_ = nullptr;

    return std::move(_result);
  });
}

template <typename T>
fcppt::container::tree::object<T>::reference
fcppt::container::tree::object<T>::push_front(object &&_tree)
{
  this->insert(this->begin(), std::move(_tree));

  return fcppt::make_ref(this->children_.front());
}

template <typename T>
fcppt::container::tree::object<T>::reference
fcppt::container::tree::object<T>::push_front(T const &_value)
{
  this->insert(this->begin(), _value);

  return fcppt::make_ref(this->children_.front());
}

template <typename T>
fcppt::container::tree::object<T>::reference
fcppt::container::tree::object<T>::push_front(T &&_value)
{
  this->insert(this->begin(), std::move(_value));

  return fcppt::make_ref(this->children_.front());
}

template <typename T>
fcppt::container::tree::object<T>::optional_object
fcppt::container::tree::object<T>::pop_front()
{
  return fcppt::optional::map(fcppt::container::pop_front(this->children_), [](object &&_result) {
    _result.parent_ = nullptr;

    return std::move(_result);
  });
}

template <typename T>
void fcppt::container::tree::object<T>::clear()
{
  this->children_.clear();
}

template <typename T>
fcppt::container::tree::object<T>::optional_ref fcppt::container::tree::object<T>::back()
{
  return fcppt::container::maybe_back(this->children_);
}

template <typename T>
fcppt::container::tree::object<T>::const_optional_ref
fcppt::container::tree::object<T>::back() const
{
  return fcppt::container::maybe_back(this->children_);
}

template <typename T>
fcppt::container::tree::object<T>::optional_ref fcppt::container::tree::object<T>::front()
{
  return fcppt::container::maybe_front(this->children_);
}

template <typename T>
fcppt::container::tree::object<T>::const_optional_ref
fcppt::container::tree::object<T>::front() const
{
  return fcppt::container::maybe_front(this->children_);
}

template <typename T>
fcppt::container::tree::object<T>::iterator fcppt::container::tree::object<T>::begin()
{
  return this->children_.begin();
}

template <typename T>
fcppt::container::tree::object<T>::iterator fcppt::container::tree::object<T>::end()
{
  return this->children_.end();
}

template <typename T>
fcppt::container::tree::object<T>::const_iterator
fcppt::container::tree::object<T>::begin() const
{
  return this->children_.begin();
}

template <typename T>
fcppt::container::tree::object<T>::const_iterator
fcppt::container::tree::object<T>::end() const
{
  return this->children_.end();
}

template <typename T>
fcppt::container::tree::object<T>::reverse_iterator
fcppt::container::tree::object<T>::rbegin()
{
  return this->children_.rbegin();
}

template <typename T>
fcppt::container::tree::object<T>::reverse_iterator
fcppt::container::tree::object<T>::rend()
{
  return this->children_.rend();
}

template <typename T>
fcppt::container::tree::object<T>::const_reverse_iterator
fcppt::container::tree::object<T>::rbegin() const
{
  return this->children_.rbegin();
}

template <typename T>
fcppt::container::tree::object<T>::const_reverse_iterator
fcppt::container::tree::object<T>::rend() const
{
  return this->children_.rend();
}

template <typename T>
void fcppt::container::tree::object<T>::insert(iterator const _it, object &&_tree)
{
  this->children_.insert(_it, std::move(_tree))->parent_ = this;
}

template <typename T>
void fcppt::container::tree::object<T>::insert(iterator const _it, T const &_value)
{
  this->insert(_it, object(_value));
}

template <typename T>
void fcppt::container::tree::object<T>::insert(iterator const _it, T &&_value)
{
  this->insert(_it, object(std::move(_value)));
}

template <typename T>
void fcppt::container::tree::object<T>::erase(iterator const _it)
{
  this->children_.erase(_it);
}

template <typename T>
void fcppt::container::tree::object<T>::erase(iterator const _begin, iterator const _end)
{
  this->children_.erase(_begin, _end);
}

template <typename T>
fcppt::container::tree::object<T>::size_type
fcppt::container::tree::object<T>::size() const
{
  return this->children().size();
}

template <typename T>
bool fcppt::container::tree::object<T>::empty() const
{
  return this->children().empty();
}

template <typename T>
void fcppt::container::tree::object<T>::swap(object &_other) noexcept
{
  using std::swap;

  swap(this->value_, _other.value_);

  std::swap(this->parent_, _other.parent_);

  this->children_.swap(_other.children_);
}

template <typename T>
void fcppt::container::tree::object<T>::sort()
{
  this->children_.sort(
      [](object const &_left, object const &_right) { return _left.value() < _right.value(); });
}

template <typename T>
template <typename Predicate>
void fcppt::container::tree::object<T>::sort(Predicate const &_predicate)
{
  this->children_.sort([_predicate](object const &_left, object const &_right) {
    return _predicate(_left.value(), _right.value());
  });
}

template <typename T>
fcppt::container::tree::object<T>::child_list
fcppt::container::tree::object<T>::copy_children(child_list const &_children)
{
  child_list result{_children};

  for (auto &child : result)
  {
    child.parent_ = this;
  }

  return result;
}

template <typename T>
fcppt::container::tree::object<T>::child_list
fcppt::container::tree::object<T>::move_children(child_list &&_children)
{
  for (auto &child : _children)
  {
    child.parent_ = this;
  }

  return std::move(_children);
}

template <typename T>
void fcppt::container::tree::swap(
    fcppt::container::tree::object<T> &_a, fcppt::container::tree::object<T> &_b) noexcept
{
  _a.swap(_b);
}

#endif
