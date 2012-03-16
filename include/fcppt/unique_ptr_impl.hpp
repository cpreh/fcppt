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
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::
operator fcppt::detail_unique_ptr::rv<
	fcppt::unique_ptr<
		Type,
		Deleter
	>
>()
{
	return
		fcppt::detail_unique_ptr::rv<
			unique_ptr
		>(
			*this
		);
}
/// \endcond

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr(
	fcppt::detail_unique_ptr::rv<
		unique_ptr
	> _other
)
:
	ptr_(
		_other->release(),
		fcppt::forward<
			Deleter
		>(
			_other->get_deleter()
		)
	)
{
}

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
> &
fcppt::unique_ptr<
	Type,
	Deleter
>::operator=(
	fcppt::detail_unique_ptr::rv<
		unique_ptr
	> _other
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
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr()
{
	BOOST_STATIC_ASSERT(
		!boost::is_reference<
			Deleter
		>::value
	);

	BOOST_STATIC_ASSERT(
		!boost::is_pointer<
			Deleter
		>::value
	);
}

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr(
	pointer const _ptr
)
:
	ptr_(
		_ptr
	)
{
	BOOST_STATIC_ASSERT(
		!boost::is_reference<
			Deleter
		>::value
	);

	BOOST_STATIC_ASSERT(
		!boost::is_pointer<
			Deleter
		>::value
	);
}

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr(
	pointer const _ptr,
	typename boost::mpl::if_<
		boost::is_reference<Deleter>,
		volatile typename boost::remove_reference<
			Deleter
		>::type &,
		Deleter
	>::type const _deleter
)
:
	ptr_(
		fcppt::move(
			_ptr
		),
		fcppt::forward<
			Deleter
		>(
			const_cast<
				typename boost::add_reference<
					Deleter
				>::type
			>(
				_deleter
			)
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
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr(
	fcppt::unique_ptr<
		Other,
		Deleter
	> _other,
	typename boost::enable_if<
		boost::is_convertible<
			typename fcppt::unique_ptr<
				Other
			>::pointer,
			pointer
		>
	>::type *
)
:
	ptr_(
		_other.release(),
		fcppt::forward<
			Deleter
		>(
			_other.get_deleter()
		)
	)
{
}

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::~unique_ptr()
{
	this->reset();
}

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
> &
fcppt::unique_ptr<
	Type,
	Deleter
>::operator=(
	bool_type
)
{
	this->reset();

	return *this;
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::unique_ptr<
	Type,
	Deleter
> &
fcppt::unique_ptr<
	Type,
	Deleter
>::operator=(
	fcppt::unique_ptr<
		Other,
		Deleter
	> _other
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
	typename Type,
	typename Deleter
>
typename boost::add_reference<
	Type
>::type
fcppt::unique_ptr<
	Type,
	Deleter
>::operator*() const
{
	return *this->get();
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::unique_ptr<
	Type,
	Deleter
>::pointer
fcppt::unique_ptr<
	Type,
	Deleter
>::operator->() const
{
	return this->get();
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::unique_ptr<
	Type,
	Deleter
>::pointer
fcppt::unique_ptr<
	Type,
	Deleter
>::get() const
{
	return ptr_.first();
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::unique_ptr<
	Type,
	Deleter
>::deleter_reference
fcppt::unique_ptr<
	Type,
	Deleter
>::get_deleter()
{
	return ptr_.second();
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::unique_ptr<
	Type,
	Deleter
>::deleter_const_reference
fcppt::unique_ptr<
	Type,
	Deleter
>::get_deleter() const
{
	return ptr_.second();
}

// Doxygen says: warning: member `operator int fcppt::unique_ptr' of class `unique_ptr' cannot be found
/// \cond FCPPT_DOXYGEN_DEBUG
template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>::
operator int fcppt::unique_ptr<
	Type,
	Deleter
>::nat::*() const
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
	typename Type,
	typename Deleter
>
void
fcppt::unique_ptr<
	Type,
	Deleter
>::reset(
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
	typename Type,
	typename Deleter
>
typename fcppt::unique_ptr<
	Type,
	Deleter
>::pointer
fcppt::unique_ptr<
	Type,
	Deleter
>::release()
{
	pointer const this_ptr(
		this->get()
	);

	ptr_.first() = fcppt::null_ptr();

	return this_ptr;
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::unique_ptr<
	Type,
	Deleter
>::swap(
	unique_ptr &_other
)
{
	fcppt::detail_unique_ptr::swap(
		ptr_,
		_other.ptr_
	);
}

template<
	typename Type,
	typename Deleter
>
inline
void
fcppt::swap(
	fcppt::unique_ptr<
		Type,
		Deleter
	> &_left,
	fcppt::unique_ptr<
		Type,
		Deleter
	> &_right
)
{
	_left.swap(
		_right
	);
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
inline
bool
fcppt::operator==(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &_left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &_right
)
{
	return
		_left.get()
		==
		_right.get();
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
inline
bool
fcppt::operator!=(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &_left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &_right
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
	typename Type1,
	typename Type2,
	typename Deleter
>
inline
bool
fcppt::operator<(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &_left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &_right
)
{
	return
		_left.get()
		<
		_right.get();
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
inline
bool
fcppt::operator<=(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &_left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &_right
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
	typename Type1,
	typename Type2,
	typename Deleter
>
inline
bool
fcppt::operator>(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &_left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &_right
)
{
	return
		_right
		<
		_left;
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
inline
bool
fcppt::operator>=(
	fcppt::unique_ptr<
		Type1,
		Deleter
	> const &_left,
	fcppt::unique_ptr<
		Type2,
		Deleter
	> const &_right
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
