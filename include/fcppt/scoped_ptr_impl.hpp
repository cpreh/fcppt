//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_PTR_IMPL_HPP_INCLUDED
#define FCPPT_SCOPED_PTR_IMPL_HPP_INCLUDED

#include <fcppt/heap_deleter.hpp>
#include <fcppt/move.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/scoped_ptr_decl.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


template<
	typename Type,
	typename Deleter
>
fcppt::scoped_ptr<
	Type,
	Deleter
>::scoped_ptr()
:
	ptr_(
		fcppt::null_ptr()
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
fcppt::scoped_ptr<
	Type,
	Deleter
>::scoped_ptr(
	Other *const _ptr
)
:
	ptr_(
		_ptr
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
fcppt::scoped_ptr<
	Type,
	Deleter
>::scoped_ptr(
	fcppt::unique_ptr<
		Other,
		Deleter
	> _ptr
)
:
	ptr_(
		_ptr.release()
	)
{
}

template<
	typename Type,
	typename Deleter
>
fcppt::scoped_ptr<
	Type,
	Deleter
>::~scoped_ptr()
{
	Deleter()(
		ptr_
	);
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::scoped_ptr<
	Type,
	Deleter
>::reset()
{
	scoped_ptr().swap(
		*this
	);
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
void
fcppt::scoped_ptr<
	Type,
	Deleter
>::reset(
	Other *const _ptr
)
{
	scoped_ptr(
		_ptr
	).swap(
		*this
	);
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::scoped_ptr<
	Type,
	Deleter
>::reference
fcppt::scoped_ptr<
	Type,
	Deleter
>::operator*() const
{
	return *ptr_;
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::scoped_ptr<
	Type,
	Deleter
>::pointer
fcppt::scoped_ptr<
	Type,
	Deleter
>::operator->() const
{
	return ptr_;
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::scoped_ptr<
	Type,
	Deleter
>::pointer
fcppt::scoped_ptr<
	Type,
	Deleter
>::get() const
{
	return ptr_;
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::scoped_ptr<
	Type,
	Deleter
>::swap(
	scoped_ptr &_other
)
{
	std::swap(
		ptr_,
		_other.ptr_
	);
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
void
fcppt::scoped_ptr<
	Type,
	Deleter
>::take(
	fcppt::unique_ptr<
		Other,
		Deleter
	> _ptr
)
{
	this->reset();

	ptr_ = _ptr.release();
}

template<
	typename Type,
	typename Deleter
>
fcppt::unique_ptr<
	Type,
	Deleter
>
fcppt::scoped_ptr<
	Type,
	Deleter
>::release()
{
	fcppt::unique_ptr<
		Type,
		Deleter
	> ret(
		ptr_
	);

	ptr_ = fcppt::null_ptr();

	return
		fcppt::move(
			ret
		);
}

template<
	typename Type,
	typename Deleter
>
bool
fcppt::scoped_ptr<
	Type,
	Deleter
>::boolean_test() const
{
	return
		ptr_
		!=
		fcppt::null_ptr();
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::swap(
	fcppt::scoped_ptr<
		Type,
		Deleter
	> &_a,
	fcppt::scoped_ptr<
		Type,
		Deleter
	> &_b
)
{
	_a.swap(
		_b
	);
}

#endif
