//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_PTR_IMPL_HPP_INCLUDED
#define FCPPT_SCOPED_PTR_IMPL_HPP_INCLUDED

#include <fcppt/scoped_ptr_decl.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <algorithm>

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::scoped_ptr<T, Deleter>::scoped_ptr(
	pointer const p
)
:
	ptr(p)
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
fcppt::scoped_ptr<T, Deleter>::scoped_ptr(
	auto_ptr<Y> p
)
:
	ptr(p.release())
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
fcppt::scoped_ptr<T, Deleter>::scoped_ptr(
	unique_ptr<Y, Deleter> p
)
:
	ptr(p.release())
{}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::scoped_ptr<T, Deleter>::~scoped_ptr()
{
	Deleter<T>()(ptr);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::scoped_ptr<T, Deleter>::reset(
	pointer const p
)
{
	scoped_ptr(p).swap(*this);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::scoped_ptr<T, Deleter>::reference
fcppt::scoped_ptr<T, Deleter>::operator*() const
{
	return *ptr;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::scoped_ptr<T, Deleter>::pointer
fcppt::scoped_ptr<T, Deleter>::operator->() const
{
	return ptr;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
typename fcppt::scoped_ptr<T, Deleter>::pointer
fcppt::scoped_ptr<T, Deleter>::get() const
{
	return ptr;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
bool
fcppt::scoped_ptr<T, Deleter>::operator! () const
{
	return !ptr;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::scoped_ptr<T, Deleter>::swap(
	scoped_ptr &b
)
{
	std::swap(
		ptr,
		b.ptr
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
void
fcppt::scoped_ptr<T, Deleter>::take(
	auto_ptr<Y> p
)
{
	reset();

	ptr = p.release();
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
fcppt::scoped_ptr<T, Deleter>::take(
	unique_ptr<Y, Deleter> p
)
{
	reset();

	ptr = p.release();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
bool
fcppt::scoped_ptr<T, Deleter>::boolean_test() const
{
	return ptr != 0;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::swap(
	scoped_ptr<T, Deleter> &a,
	scoped_ptr<T, Deleter> &b
)
{
	a.swap(b);
}

#endif
