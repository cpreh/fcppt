//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WEAK_PTR_IMPL_HPP_INCLUDED
#define FCPPT_WEAK_PTR_IMPL_HPP_INCLUDED

#include <fcppt/weak_ptr_decl.hpp>

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::weak_ptr<T, Deleter>::weak_ptr()
:
	impl()
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::weak_ptr<T, Deleter>::weak_ptr(
	weak_ptr<Y, Deleter> const &r
)
:
	impl(r.boost_ptr())
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
template<
	typename Y
>
fcppt::weak_ptr<T, Deleter>::weak_ptr(
	shared_ptr<Y, Deleter> const &r
)
:
	impl(r.boost_ptr())
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::shared_ptr<T, Deleter> const
fcppt::weak_ptr<T, Deleter>::lock() const
{
       	return shared_ptr<T, Deleter>(
		impl.lock()
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
long
fcppt::weak_ptr<T, Deleter>::use_count() const
{
	return impl.use_count();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
bool
fcppt::weak_ptr<T, Deleter>::expired() const
{
	return impl.expired();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::weak_ptr<T, Deleter>::reset()
{
	impl.reset();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::weak_ptr<T, Deleter>::swap(
	weak_ptr &other
)
{
	impl.swap(
		other.impl
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::weak_ptr<T, Deleter>::impl_type const
fcppt::weak_ptr<T, Deleter>::boost_ptr() const
{
	return impl;
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
	weak_ptr<T, Deleter> const & a,
	weak_ptr<U, Deleter> const & b
)
{
	return a.boost_ptr() < b.boost_ptr();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::swap(
	weak_ptr<T, Deleter> &a,
	weak_ptr<T, Deleter> &b
)
{
	a.swap(b);
}

#endif
