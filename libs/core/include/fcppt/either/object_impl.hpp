//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_EITHER_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_EITHER_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/either/object_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <expected>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Failure, typename Success>
fcppt::either::object<Failure, Success>::object(Success &&_object) : impl_{std::move(_object)}
{
}

template <typename Failure, typename Success>
fcppt::either::object<Failure, Success>::object(Success const &_object) : impl_{_object}
{
}

template <typename Failure, typename Success>
fcppt::either::object<Failure, Success>::object(Failure &&_object)
    : impl_{std::unexpected{std::move(_object)}}
{
}

template <typename Failure, typename Success>
fcppt::either::object<Failure, Success>::object(Failure const &_object)
    : impl_{std::unexpected{_object}}
{
}

template <typename Failure, typename Success>
bool fcppt::either::object<Failure, Success>::has_success() const
{
  return this->impl_.has_value();
}

template <typename Failure, typename Success>
bool fcppt::either::object<Failure, Success>::has_failure() const
{
  return !this->has_success();
}

template <typename Failure, typename Success>
Success &fcppt::either::object<Failure, Success>::get_success_unsafe()
{
  return this->impl_.value();
}

template <typename Failure, typename Success>
Success const &fcppt::either::object<Failure, Success>::get_success_unsafe() const
{
  return this->impl_.value();
}

template <typename Failure, typename Success>
Failure &fcppt::either::object<Failure, Success>::get_failure_unsafe()
{
  return this->impl_.error();
}

template <typename Failure, typename Success>
Failure const &fcppt::either::object<Failure, Success>::get_failure_unsafe() const
{
  return this->impl_.error();
}

template <typename Failure, typename Success>
typename fcppt::either::object<Failure, Success>::std_type &
fcppt::either::object<Failure, Success>::impl()
{
  return this->impl_;
}

template <typename Failure, typename Success>
typename fcppt::either::object<Failure, Success>::std_type const &
fcppt::either::object<Failure, Success>::impl() const
{
  return this->impl_;
}

#endif
