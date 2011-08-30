//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WEAK_PTR_DECL_HPP_INCLUDED
#define FCPPT_WEAK_PTR_DECL_HPP_INCLUDED

#include <fcppt/weak_ptr_fwd.hpp>
#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/weak_ptr.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{

template<
	typename T,
	template<
		typename
	> class Deleter
>
class weak_ptr
{
public:
	typedef boost::weak_ptr<
		T
	> impl_type;

	typedef fcppt::shared_ptr<
		T,
		Deleter
	> shared_ptr;

	typedef T element_type;

	weak_ptr();

	template<
		typename Y
	>
	weak_ptr(
		weak_ptr<Y, Deleter> const &
	);

	template<
		typename Y
	>
	weak_ptr(
		fcppt::shared_ptr<Y, Deleter> const &
	);

	shared_ptr const
	lock() const;

	long
	use_count() const;

	bool
	expired() const;

	void
	reset();

	void
	swap(
		weak_ptr &
	);

	impl_type const
	boost_ptr() const;
private:
	impl_type impl;
};

template<
	typename T,
	typename U,
	template<
		typename
	> class Deleter
>
bool
operator<(
	weak_ptr<T, Deleter> const & a,
	weak_ptr<U, Deleter> const & b
);

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
swap(
	weak_ptr<T, Deleter> &a,
	weak_ptr<T, Deleter> &b
);

}

#endif
