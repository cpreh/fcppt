//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_PTR_IMPL_HPP_INCLUDED
#define FCPPT_SCOPED_PTR_IMPL_HPP_INCLUDED

#include <fcppt/move.hpp>
#include <fcppt/scoped_ptr_decl.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::scoped_ptr<T, Deleter>::scoped_ptr(
	pointer const _ptr
)
:
	ptr_(
		_ptr
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
fcppt::scoped_ptr<T, Deleter>::scoped_ptr(
	unique_ptr<Y, Deleter> _ptr
)
:
	ptr_(
		_ptr.release()
	)
{
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::scoped_ptr<T, Deleter>::~scoped_ptr()
{
	Deleter<T>()(
		ptr_
	);
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::scoped_ptr<T, Deleter>::reset(
	pointer const _ptr
)
{
	scoped_ptr(
		_ptr
	).swap(
		*this
	);
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
	return *ptr_;
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
	return ptr_;
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
	return ptr_;
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
	return !ptr_;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::scoped_ptr<T, Deleter>::swap(
	scoped_ptr &_other
)
{
	std::swap(
		ptr_,
		_other.ptr_
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
	unique_ptr<Y, Deleter> _ptr
)
{
	reset();

	ptr_ = _ptr.release();
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
fcppt::unique_ptr<T, Deleter>
fcppt::scoped_ptr<T, Deleter>::release()
{
	fcppt::unique_ptr<
		T,
		Deleter
	> ret(
		ptr_
	);

	ptr_ = 0;

	return
		fcppt::move(
			ret
		);
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
	return ptr_ != 0;
}

template<
	typename T,
	template<
		typename
	> class Deleter
>
void
fcppt::swap(
	scoped_ptr<T, Deleter> &_a,
	scoped_ptr<T, Deleter> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
