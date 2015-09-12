//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SHARED_PTR_IMPL_HPP_INCLUDED
#define FCPPT_SHARED_PTR_IMPL_HPP_INCLUDED

#include <fcppt/default_deleter.hpp>
#include <fcppt/shared_ptr_decl.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/weak_ptr_fwd.hpp>
#include <fcppt/detail/make_shared_wrapper.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	Other *const _ptr
)
:
	impl_(
		_ptr,
		Deleter()
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other,
	typename Alloc
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	Other *const _ptr,
	Alloc const &_alloc
)
:
	impl_(
		_ptr,
		Deleter(),
		_alloc
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::weak_ptr<
		Other,
		Deleter
	> const &_other
)
:
	impl_(
		_other
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::shared_ptr<
		Other,
		Deleter
	> const &_other
)
:
	impl_(
		_other.std_ptr()
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::shared_ptr<
		Other
	> const & _other,
	pointer const _data
)
:
	impl_(
		_other.std_ptr(),
		_data
	)
{
	static_assert(
		std::is_same<
			Deleter,
			fcppt::default_deleter
		>::value,
		"storing a different pointer in a shared_ptr only works with default_deleter"
	);
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	std::unique_ptr<
		Other,
		Deleter
	> &&_other
)
:
	impl_(
		std::move(
			_other
		)
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::unique_ptr<
		Other,
		Deleter
	> &&_other
)
:
	impl_(
		_other.release_ownership()
	)
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
> &
fcppt::shared_ptr<
	Type,
	Deleter
>::operator=(
	fcppt::shared_ptr<
		Other,
		Deleter
	> const &_other
)
{
	impl_ =
		_other.impl;

	return
		*this;
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
> &
fcppt::shared_ptr<
	Type,
	Deleter
>::operator=(
	fcppt::unique_ptr<
		Other,
		Deleter
	> &&_other
)
{
	impl_.reset(
		_other.release_ownership()
	);

	return
		*this;
}

template<
	typename Type,
	typename Deleter
>
fcppt::shared_ptr<
	Type,
	Deleter
>::~shared_ptr()
{
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::shared_ptr<
	Type,
	Deleter
>::reference
fcppt::shared_ptr<
	Type,
	Deleter
>::operator* () const
{
	return
		*impl_;
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::shared_ptr<
	Type,
	Deleter
>::pointer
fcppt::shared_ptr<
	Type,
	Deleter
>::operator-> () const
{
	return
		impl_.operator->();
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::shared_ptr<
	Type,
	Deleter
>::pointer
fcppt::shared_ptr<
	Type,
	Deleter
>::get_pointer() const
{
	return
		impl_.get();
}

template<
	typename Type,
	typename Deleter
>
bool
fcppt::shared_ptr<
	Type,
	Deleter
>::unique() const
{
	return
		impl_.unique();
}

template<
	typename Type,
	typename Deleter
>
long
fcppt::shared_ptr<
	Type,
	Deleter
>::use_count() const
{
	return
		impl_.use_count();
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::shared_ptr<
	Type,
	Deleter
>::swap(
	fcppt::shared_ptr<
		Type,
		Deleter
	> &_other
)
{
	std::swap(
		impl_,
		_other.impl_
	);
 }

template<
	typename Type,
	typename Deleter
>
typename fcppt::shared_ptr<
	Type,
	Deleter
>::impl_type
fcppt::shared_ptr<
	Type,
	Deleter
>::std_ptr() const
{
	return
		impl_;
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	fcppt::detail::make_shared_wrapper<
		Other
	> &&_other
)
:
	impl_(
		_other.release()
	)
{
	static_assert(
		std::is_same<
			Deleter,
			fcppt::default_deleter
		>::value,
		"make_shared_ptr only works with default_deleter"
	);
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::shared_ptr<
	Type,
	Deleter
>::shared_ptr(
	std::shared_ptr<
		Other
	> const _other
)
:
	impl_(
		_other
	)
{
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
bool
fcppt::operator==(
	fcppt::shared_ptr<
		Type1,
		Deleter
	> const &_a,
	fcppt::shared_ptr<
		Type2,
		Deleter
	> const &_b
)
{
	return
		_a.std_ptr()
		==
		_b.std_ptr();
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
bool
fcppt::operator!=(
	fcppt::shared_ptr<
		Type1,
		Deleter
	> const &_a,
	fcppt::shared_ptr<
		Type2,
		Deleter
	> const &_b
)
{
	return
		_a.std_ptr()
		!=
		_b.std_ptr();
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
bool
fcppt::operator<(
	fcppt::shared_ptr<
		Type1,
		Deleter
	> const &_a,
	fcppt::shared_ptr<
		Type2,
		Deleter
	> const &_b
)
{
	return
		_a.std_ptr()
		<
		_b.std_ptr();
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::swap(
	fcppt::shared_ptr<
		Type,
		Deleter
	> &_a,
	fcppt::shared_ptr<
		Type,
		Deleter
	> &_b)
{
	_a.swap(
		_b
	);
}

template<
	typename Ch,
	typename Traits,
	typename Type,
	typename Deleter
>
std::basic_ostream<
	Ch,
	Traits
> &
fcppt::operator<< (
	std::basic_ostream<
		Ch,
		Traits
	> &_os,
	fcppt::shared_ptr<
		Type,
		Deleter
	> const &_ptr
)
{
	return
		_os << _ptr.get();
}

#endif
