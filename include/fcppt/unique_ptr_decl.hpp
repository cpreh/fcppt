// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_UNIQUE_PTR_DECL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_DECL_HPP_INCLUDED

#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/detail_unique_ptr/pointer_type.hpp>
#include <fcppt/detail_unique_ptr/rv.hpp>
#include <fcppt/detail_unique_ptr/storage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename T,
	template<
		typename
	> class Deleter
>
class unique_ptr
{
public:
	typedef T element_type;

	typedef Deleter<T> deleter_type;

	typedef typename detail_unique_ptr::pointer_type<
    		element_type,
		deleter_type
	>::type pointer;

private:
	detail_unique_ptr::storage<
		pointer,
		deleter_type
	> ptr_;

	typedef typename boost::add_reference<
		deleter_type
	>::type deleter_reference;

	typedef typename boost::add_reference<
		deleter_type const
	>::type deleter_const_reference;

	struct nat
	{
		int for_bool_;
	};

	unique_ptr(
		unique_ptr &
	);

	unique_ptr &
	operator=(
		unique_ptr &
	);
public:
	operator detail_unique_ptr::rv<
		unique_ptr
	>();

	unique_ptr(
		detail_unique_ptr::rv<unique_ptr>
	);

	unique_ptr &
	operator=(
		detail_unique_ptr::rv<unique_ptr>
	);

	unique_ptr();

	explicit unique_ptr(
		pointer
	);

	unique_ptr(
		pointer,
		typename boost::mpl::if_<
			boost::is_reference<
				deleter_type
			>,
			volatile typename boost::remove_reference<
				deleter_type
			>::type &,
			deleter_type
		>::type
	);

	template<
		typename U
	>
	unique_ptr(
		unique_ptr<U, Deleter> u,
		typename boost::enable_if<
			boost::is_convertible<
				typename unique_ptr<U>::pointer,
				pointer
			>
		>::type* = 0
	);

	~unique_ptr();

	unique_ptr &
	operator=(
		int nat::*
	);

	template<
		typename U
	>
	unique_ptr &
	operator=(
		unique_ptr<U, Deleter>
	);

	typename boost::add_reference<T>::type
	operator*() const;

	pointer
	operator->() const;

	pointer
	get() const;

	deleter_reference
	get_deleter();

	deleter_const_reference
	get_deleter() const;

	operator int nat::*() const;

	void
	reset(
		pointer = pointer()
	);

	pointer
	release();

	void
	swap(
		unique_ptr &
	);
};

template<
	typename T,
	template<
		typename
	> class D
>
void
swap(
	unique_ptr<T, D> &,
	unique_ptr<T, D> &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator==(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator!=(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator<(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator<=(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator>(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

template<
	typename T1,
	typename T2,
	template<
		typename
	> class D
>
bool
operator>=(
	unique_ptr<T1, D> const &,
	unique_ptr<T2, D> const &
);

}

#endif
