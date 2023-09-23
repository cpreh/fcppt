//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_EITHER_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/either/object_decl.hpp> // IWYU pragma: export
#include <fcppt/variant/get_unsafe.hpp>
#include <fcppt/variant/holds_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Failure, typename Success>
fcppt::either::object<Failure, Success>::object(Success &&_object) : impl_(std::move(_object))
{
}

template <typename Failure, typename Success>
fcppt::either::object<Failure, Success>::object(Success const &_object) : impl_(_object)
{
}

template <typename Failure, typename Success>
fcppt::either::object<Failure, Success>::object(Failure &&_object) : impl_(std::move(_object))
{
}

template <typename Failure, typename Success>
fcppt::either::object<Failure, Success>::object(Failure const &_object) : impl_(_object)
{
}

template <typename Failure, typename Success>
bool fcppt::either::object<Failure, Success>::has_success() const
{
  return fcppt::variant::holds_type<Success>(impl_);
}

template <typename Failure, typename Success>
bool fcppt::either::object<Failure, Success>::has_failure() const
{
  return fcppt::variant::holds_type<Failure>(impl_);
}

template <typename Failure, typename Success>
Success &fcppt::either::object<Failure, Success>::get_success_unsafe()
{
  return fcppt::variant::get_unsafe<Success>(impl_);
}

template <typename Failure, typename Success>
Success const &fcppt::either::object<Failure, Success>::get_success_unsafe() const
{
  return fcppt::variant::get_unsafe<Success>(impl_);
}

template <typename Failure, typename Success>
Failure &fcppt::either::object<Failure, Success>::get_failure_unsafe()
{
  return fcppt::variant::get_unsafe<Failure>(impl_);
}

template <typename Failure, typename Success>
Failure const &fcppt::either::object<Failure, Success>::get_failure_unsafe() const
{
  return fcppt::variant::get_unsafe<Failure>(impl_);
}

#endif
