//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_PTR_DECL_HPP_INCLUDED
#define FCPPT_SCOPED_PTR_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/safe_bool.hpp>
#include <fcppt/scoped_ptr_fwd.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename T,
	template<
		typename
	> class Deleter
>
class scoped_ptr
{
	FCPPT_NONCOPYABLE(
		scoped_ptr
	);

	FCPPT_SAFE_BOOL(scoped_ptr)
public:
	typedef typename boost::add_reference<
		T
	>::type reference;

	typedef T *pointer;

	explicit scoped_ptr(
		pointer = 0
	);

	template<
		typename Y
	>
	explicit scoped_ptr(
		unique_ptr<Y, Deleter>
	);

	~scoped_ptr();

	void
	reset(
		pointer = 0
	);

	reference
	operator*() const;

	pointer
	operator->() const;

	pointer
	get() const;

	bool
	operator! () const;

	void
	swap(
		scoped_ptr &
	);

	template<
		typename Y
	>
	void
	take(
		unique_ptr<Y, Deleter>
	);

	unique_ptr<T, Deleter>
	release();
private:
	bool
	boolean_test() const;

	pointer ptr_;
};

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
swap(
	scoped_ptr<T, Deleter> &,
	scoped_ptr<T, Deleter> &
);

}

#endif
