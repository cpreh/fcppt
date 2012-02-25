// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED

#include <fcppt/forward.hpp>
#include <fcppt/move.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/unique_ptr_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <fcppt/config/external_end.hpp>


// doxygen says: warning: member `operator fcppt::detail_rv' of class `unique_ptr' cannot be found
/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::
operator fcppt::detail_unique_ptr::rv<
	fcppt::unique_ptr<T, Deleter>
>()
{
	return
		detail_unique_ptr::rv<
			unique_ptr
		>(
			*this
		);
}
/// \endcond

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::unique_ptr(
	detail_unique_ptr::rv<unique_ptr> _other
)
:
	ptr_(
		_other->release(),
		fcppt::forward<
			deleter_type
		>(
			_other->get_deleter()
		)
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter> &
fcppt::unique_ptr<T, Deleter>::operator=(
	detail_unique_ptr::rv<unique_ptr> _other
)
{
	this->reset(
		_other->release()
	);

	ptr_.second() =
		fcppt::move(
			_other->get_deleter()
		);

        return *this;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::unique_ptr()
{
	BOOST_STATIC_ASSERT(
		!boost::is_reference<
			deleter_type
		>::value
	);

	BOOST_STATIC_ASSERT(
		!boost::is_pointer<
			deleter_type
		>::value
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::unique_ptr(
	pointer const _ptr
)
:
	ptr_(
		_ptr
	)
{
	BOOST_STATIC_ASSERT(
		!boost::is_reference<
			deleter_type
		>::value
	);

	BOOST_STATIC_ASSERT(
		!boost::is_pointer<
			deleter_type
		>::value
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::unique_ptr(
	pointer const _ptr,
	typename boost::mpl::if_<
		boost::is_reference<deleter_type>,
		volatile typename boost::remove_reference<
			deleter_type
		>::type &,
		deleter_type
	>::type const _deleter
)
:
	ptr_(
		fcppt::move(
			_ptr
		),
		fcppt::forward<
			deleter_type
		>(
			const_cast<
				typename boost::add_reference<
					deleter_type
				>::type
			>(
				_deleter
			)
		)
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
	typename U
>
fcppt::unique_ptr<T, Deleter>::unique_ptr(
	unique_ptr<U, Deleter> _other,
	typename boost::enable_if<
		boost::is_convertible<
			typename unique_ptr<U>::pointer,
			pointer
		>
	>::type *
)
:
	ptr_(
		_other.release(),
		fcppt::forward<
			deleter_type
		>(
			_other.get_deleter()
		)
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::~unique_ptr()
{
	this->reset();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter> &
fcppt::unique_ptr<T, Deleter>::operator=(
	bool_type
)
{
	this->reset();

	return *this;
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
fcppt::unique_ptr<T, Deleter> &
fcppt::unique_ptr<T, Deleter>::operator=(
	unique_ptr<U, Deleter> _other
)
{
	this->reset(
		_other.release()
	);

	ptr_.second() =
		fcppt::move(
			_other.get_deleter()
		);

	return *this;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename boost::add_reference<T>::type
fcppt::unique_ptr<T, Deleter>::operator*() const
{
	return *this->get();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::unique_ptr<T, Deleter>::pointer
fcppt::unique_ptr<T, Deleter>::operator->() const
{
	return this->get();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::unique_ptr<T, Deleter>::pointer
fcppt::unique_ptr<T, Deleter>::get() const
{
	return ptr_.first();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::unique_ptr<T, Deleter>::deleter_reference
fcppt::unique_ptr<T, Deleter>::get_deleter()
{
	return ptr_.second();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::unique_ptr<T, Deleter>::deleter_const_reference
fcppt::unique_ptr<T, Deleter>::get_deleter() const
{
	return ptr_.second();
}

// Doxygen says: warning: member `operator int fcppt::unique_ptr' of class `unique_ptr' cannot be found
/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::
operator int fcppt::unique_ptr<T, Deleter>::nat::*() const
{
	return
		this->get()
		?
			&nat::for_bool_
		:
			bool_type()
		;
}
/// \endcond

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::unique_ptr<T, Deleter>::reset(
	pointer const _ptr
)
{
	pointer const this_ptr(
		this->get()
	);

	if(
		this_ptr != fcppt::null_ptr()
	)
		this->get_deleter()(
			this_ptr
		);

	ptr_.first() = _ptr;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::unique_ptr<T, Deleter>::pointer
fcppt::unique_ptr<T, Deleter>::release()
{
	pointer const this_ptr(
		this->get()
	);

	ptr_.first() = fcppt::null_ptr();

	return this_ptr;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::unique_ptr<T, Deleter>::swap(
	unique_ptr &_other
)
{
	detail_unique_ptr::swap(
		ptr_,
		_other.ptr_
	);
}

template<
	typename T,
	template<
		typename
	> class D
>
inline
void
fcppt::swap(
	unique_ptr<T, D> &_left,
	unique_ptr<T, D> &_right
)
{
	_left.swap(
		_right
	);
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator==(
	unique_ptr<T1, D> const &_left,
	unique_ptr<T2, D> const &_right
)
{
	return
		_left.get()
		==
		_right.get();
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator!=(
	unique_ptr<T1, D> const &_left,
	unique_ptr<T2, D> const &_right
)
{
	return
		!(
			_left
			==
			_right
		);
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator<(
	unique_ptr<T1, D> const &_left,
	unique_ptr<T2, D> const &_right
)
{
	return
		_left.get()
		<
		_right.get();
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator<=(
	unique_ptr<T1, D> const &_left,
	unique_ptr<T2, D> const &_right
)
{
	return
		!(
			_right
			<
			_left
		);
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator>(
	unique_ptr<T1, D> const &_left,
	unique_ptr<T2, D> const &_right
)
{
	return
		_right
		<
		_left;
}

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
inline
bool
fcppt::operator>=(
	unique_ptr<T1, D> const &_left,
	unique_ptr<T2, D> const &_right
)
{
	return
		!(
			_left
			<
			_right
		);
}

#endif
