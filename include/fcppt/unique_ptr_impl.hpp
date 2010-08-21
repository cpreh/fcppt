// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED

#include <fcppt/unique_ptr_decl.hpp>
#include <fcppt/forward.hpp>
#include <fcppt/move.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/static_assert.hpp>

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::
operator detail_unique_ptr::rv<
	unique_ptr
>()
{
	return
		detail_unique_ptr::rv<
			unique_ptr
		>(
			*this
		);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::unique_ptr(
	detail_unique_ptr::rv<unique_ptr> r
)
:
	ptr_(
		r->release(),
		fcppt::forward<
			deleter_type
		>(
			r->get_deleter()
		)
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter> &
fcppt::unique_ptr<T, Deleter>::operator=(
	detail_unique_ptr::rv<unique_ptr> r
)
{
       	reset(r->release());

        ptr_.second() = fcppt::move(r->get_deleter());

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
	pointer const p
)
:
	ptr_(p)
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
	pointer const p,
	typename boost::mpl::if_<
		boost::is_reference<deleter_type>,
		volatile typename boost::remove_reference<
			deleter_type
		>::type &,
		deleter_type
	>::type const d
)
:
	ptr_(
		fcppt::move(
			p
		),
		fcppt::forward<
			deleter_type
		>(
			const_cast<
				typename boost::add_reference<
					deleter_type
				>::type
			>(
				d
			)
		)
	)
{}

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
	unique_ptr<U, Deleter> u,
	typename boost::enable_if_c<
                !boost::is_array<U>::value
		&&
		detail_unique_ptr::is_convertible<
			typename unique_ptr<U>::pointer,
			pointer
		>::value
	>::type *
)
:
	ptr_(
		u.release(),
		fcppt::forward<
			deleter_type
		>(
			u.get_deleter()
		)
	)
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::~unique_ptr()
{
	reset();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter> &
fcppt::unique_ptr<T, Deleter>::operator=(
	int nat::*
)
{
	reset();

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
	unique_ptr<U, Deleter> u
)
{
	reset(
		u.release()
	);

	ptr_.second() =
		fcppt::move(
			u.get_deleter()
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
	return *get();
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
	return get();
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

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>::
operator int nat::*() const
{
	return get() ? &nat::for_bool_ : 0;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::unique_ptr<T, Deleter>::reset(
	pointer const p
)
{
       	pointer const t = get();

	if (t != pointer())
		get_deleter()(t);

	ptr_.first() = p;
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
	pointer const tmp = get();

	ptr_.first() = pointer();

	return tmp;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::unique_ptr<T, Deleter>::swap(
	unique_ptr &u
)
{
	detail_unique_ptr::swap(
		ptr_,
		u.ptr_
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
	unique_ptr<T, D> &x,
	unique_ptr<T, D> &y
)
{
	x.swap(y);
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
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return x.get() == y.get();
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
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return !(x == y);
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
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return x.get() < y.get();
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
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return !(y < x);
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
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return y < x;
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
	unique_ptr<T1, D> const &x,
	unique_ptr<T2, D> const &y
)
{
	return !(x < y);
}

#endif
