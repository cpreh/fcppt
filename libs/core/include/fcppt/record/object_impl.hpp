//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_RECORD_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_RECORD_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/no_init_fwd.hpp>
#include <fcppt/mpl/list/empty.hpp>
#include <fcppt/mpl/list/object_fwd.hpp>
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/record/element_tag_tuple.hpp>
#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/object_decl.hpp> // IWYU pragma: export
#include <fcppt/record/detail/all_initializers.hpp>
#include <fcppt/record/detail/element_at.hpp>
#include <fcppt/record/detail/init_ctor.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename... Elements>
fcppt::record::object<Elements...>::object() : elements_{}
{
  static_assert(fcppt::mpl::list::empty<all_types>::value, "record not empty");
}

template <typename... Elements>
fcppt::record::object<Elements...>::object(fcppt::no_init const &)
{
}

template <typename... Elements>
template <typename... Args, typename>
fcppt::record::object<Elements...>::object(Args &&..._args)
    : elements_{fcppt::record::detail::
                    init_ctor<tuple, fcppt::record::element_tag_tuple<this_type>, Args...>(
                        std::forward<Args>(_args)...)}
{
  static_assert(
      fcppt::mpl::list::size<all_types>::value == sizeof...(Args),
      "You have to provide the right amount of parameters");

  static_assert(
      fcppt::record::detail::all_initializers<all_types, fcppt::mpl::list::object<Args...>>::value,
      "You have to initialize every element");
}

template <typename... Elements>
template <typename Label>
void fcppt::record::object<Elements...>::set(
    fcppt::record::label_value_type<this_type, Label> const &_value)
{
  fcppt::record::detail::element_at<all_types, Label>(this->elements_) = _value;
}

template <typename... Elements>
template <typename Label>
void fcppt::record::object<Elements...>::set(
    fcppt::record::label_value_type<this_type, Label> &&_value)
{
  fcppt::record::detail::element_at<all_types, Label>(this->elements_) = std::move(_value);
}

template <typename... Elements>
template <typename Label>
fcppt::record::label_value_type<fcppt::record::object<Elements...>, Label> const &
fcppt::record::object<Elements...>::get() const
{
  return fcppt::record::detail::element_at<all_types, Label>(this->elements_);
}

template <typename... Elements>
template <typename Label>
fcppt::record::label_value_type<fcppt::record::object<Elements...>, Label> &
fcppt::record::object<Elements...>::get()
{
  return fcppt::record::detail::element_at<all_types, Label>(this->elements_);
}

template <typename... Elements>
typename fcppt::record::object<Elements...>::tuple &
fcppt::record::object<Elements...>::impl()
{
  return this->elements_;
}

template <typename... Elements>
typename fcppt::record::object<Elements...>::tuple const &
fcppt::record::object<Elements...>::impl() const
{
  return this->elements_;
}

#endif
