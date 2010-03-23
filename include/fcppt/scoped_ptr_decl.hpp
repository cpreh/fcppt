//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_PTR_DECL_HPP_INCLUDED
#define FCPPT_SCOPED_PTR_DECL_HPP_INCLUDED

#include <fcppt/scoped_ptr_fwd.hpp>
#include <fcppt/auto_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/safe_bool.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/type_traits/is_same.hpp>

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
	FCPPT_NONCOPYABLE(scoped_ptr)
	FCPPT_SAFE_BOOL(scoped_ptr)
private:
	struct dummy
	{};
public:
	typedef typename boost::mpl::if_<
		boost::is_same<
			T,
			void
		>,
		dummy,
		typename boost::add_reference<
			T
		>::type
	>::type reference;

	typedef typename boost::mpl::if_<
		boost::is_same<
			T,
			void
		>,
		dummy,
		std::auto_ptr<
			T
		>
	>::type auto_ptr;

	typedef T *pointer;

	explicit scoped_ptr(
		pointer = 0
	);

	explicit scoped_ptr(
		auto_ptr
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

	void
	take(
		auto_ptr p
	);
private:
	bool
	boolean_test() const;

	pointer ptr;
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
