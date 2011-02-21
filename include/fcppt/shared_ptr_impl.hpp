//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SHARED_PTR_IMPL_HPP_INCLUDED
#define FCPPT_SHARED_PTR_IMPL_HPP_INCLUDED

#include <fcppt/tr1/detail/use_boost_tr1.hpp> // workaround for boost's get_pointer
#include <fcppt/detail/make_shared_wrapper.hpp>
#include <fcppt/heap_deleter.hpp>
#include <fcppt/shared_ptr_decl.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>
#include <algorithm>

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::shared_ptr<T, Deleter>::shared_ptr()
:
	impl_()
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	Y *const _ptr
)
:
	impl_(
		_ptr,
		deleter()
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y,
	typename D,
	typename A
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	Y *const _ptr,
	A const &_alloc
)
:
	impl_(
		_ptr,
		deleter(),
		_alloc
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	weak_ptr<Y, Deleter> const &_other
)
:
	impl_(
		_other
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	shared_ptr<Y> const &_other
)
:
	impl_(
		_other.boost_ptr()
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	shared_ptr<Y> const & _other,
	boost::detail::static_cast_tag
)
:
	impl_(
		_other.boost_ptr(),
		boost::detail::static_cast_tag()
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	shared_ptr<Y> const &_other,
	boost::detail::const_cast_tag
)
:
	impl_(
		_other.boost_ptr(),
		boost::detail::const_cast_tag()
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	shared_ptr<Y> const &_other,
	boost::detail::dynamic_cast_tag
)
:
	impl_(
		_other.boost_ptr(),
		boost::detail::dynamic_cast_tag()
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	shared_ptr<Y> const &_other,
	boost::detail::polymorphic_cast_tag
)
:
	impl_(
		_other.boost_ptr(),
		boost::detail::polymorphic_cast_tag()
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	unique_ptr<Y, Deleter> _other
)
:
	impl_()
{
	impl_.reset(
		_other.release()
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter> &
fcppt::shared_ptr<T, Deleter>::operator=(
	shared_ptr<Y> const &_other
)
{
	impl_ = _other.impl;

	return *this;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::shared_ptr<T, Deleter> &
fcppt::shared_ptr<T, Deleter>::operator=(
	unique_ptr<Y, Deleter> _other
)
{
	impl_.reset(
		_other.release()
	);

	return *this;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::shared_ptr<T, Deleter>::~shared_ptr()
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::shared_ptr<T, Deleter>::reset()
{
	impl_.reset();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
void
fcppt::shared_ptr<T, Deleter>::reset(
	Y *const _ptr
)
{
       	impl_.reset(
		_ptr,
		deleter()
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y,
	typename A
>
void
fcppt::shared_ptr<T, Deleter>::reset(
	Y *const _ptr,
	A const &_alloc
)
{
	impl_.reset(
		_ptr,
		deleter(),
		_alloc
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::shared_ptr<T, Deleter>::reference
fcppt::shared_ptr<T, Deleter>::operator* () const
{
	return *impl_;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::shared_ptr<T, Deleter>::pointer
fcppt::shared_ptr<T, Deleter>::operator-> () const
{
	return impl_.operator->();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::shared_ptr<T, Deleter>::pointer
fcppt::shared_ptr<T, Deleter>::get() const
{
       	return impl_.get();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::shared_ptr<T, Deleter>::operator
typename fcppt::shared_ptr<T, Deleter>::unspecified_bool_type() const
{
	return impl_;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
bool
fcppt::shared_ptr<T, Deleter>::operator! () const
{
	return !impl_;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
bool
fcppt::shared_ptr<T, Deleter>::unique() const
{
	return impl_.unique();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
long
fcppt::shared_ptr<T, Deleter>::use_count() const
{
	return impl_.use_count();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::shared_ptr<T, Deleter>::swap(
	shared_ptr<T> &_other
)
{
	std::swap(
		impl_,
		_other.impl_
	);
 }

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::shared_ptr<T, Deleter>::impl_type const
fcppt::shared_ptr<T, Deleter>::boost_ptr() const
{
	return impl_;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename U
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	fcppt::detail::make_shared_wrapper<U> const _other
)
:
	impl_(
		_other.get()
	)
{
	BOOST_STATIC_ASSERT((
		boost::is_same<
			Deleter<T>,
			fcppt::heap_deleter<T>
		>::value
	));
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename U
>
fcppt::shared_ptr<T, Deleter>::shared_ptr(
	boost::shared_ptr<U> const _other
)
:
	impl_(
		_other
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
Deleter<T> const
fcppt::shared_ptr<T, Deleter>::deleter()
{
	return Deleter<T>();
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool
fcppt::operator==(
	shared_ptr<T, Deleter> const &_a,
	shared_ptr<U, Deleter> const &_b
)
{
	return
		_a.boost_ptr() == _b.boost_ptr();
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool
fcppt::operator!=(
	shared_ptr<T, Deleter> const &_a,
	shared_ptr<U, Deleter> const &_b
)
{
	return
		!(_a == _b);
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool
fcppt::operator<(
	shared_ptr<T, Deleter> const &_a,
	shared_ptr<U, Deleter> const &_b
)
{
	return
		_a.boost_ptr() < _b.boost_ptr();
}

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
void
fcppt::swap(
	shared_ptr<T, Deleter> &_a,
	shared_ptr<T, Deleter> &_b)
{
	_a.swap(
		_b
	);
}

template<
	typename Ch,
	typename Traits,
	typename T,
	template<
		typename
	> class Deleter
>
std::basic_ostream<Ch, Traits> &
fcppt::operator<< (
	std::basic_ostream<Ch, Traits> &_os,
	shared_ptr<T, Deleter> const &_ptr
)
{
	return 
		_os << _ptr.get();
}

#ifdef FCPPT_TR1_DETAIL_USE_BOOST_TR1
template<
	typename T,
	template<
		typename
	> class Deleter
>
T *
fcppt::get_pointer(
	fcppt::shared_ptr<
		T,
		Deleter
	> const _ptr
)
{
	return _ptr.get();
}

#endif

#endif
