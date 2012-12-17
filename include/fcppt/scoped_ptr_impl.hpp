//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SCOPED_PTR_IMPL_HPP_INCLUDED
#define FCPPT_SCOPED_PTR_IMPL_HPP_INCLUDED

#include <fcppt/scoped_ptr_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <memory>
#include <type_traits>
#include <utility>
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
		nullptr
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
	typename Other,
	typename OtherDeleter
>
fcppt::scoped_ptr<
	Type,
	Deleter
>::scoped_ptr(
	std::unique_ptr<
		Other,
		OtherDeleter
	> &&_ptr
)
:
	ptr_(
		_ptr.release()
	)
{
	static_assert(
		std::is_convertible<
			OtherDeleter,
			Deleter
		>::value,
		"The deleter of the unique_ptr must be compatible!"
	);
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
	typename Other,
	typename OtherDeleter
>
void
fcppt::scoped_ptr<
	Type,
	Deleter
>::take(
	std::unique_ptr<
		Other,
		OtherDeleter
	> &&_ptr
)
{
	static_assert(
		std::is_convertible<
			OtherDeleter,
			Deleter
		>::value,
		"The deleter of the unique_ptr must be compatible!"
	);

	this->reset();

	ptr_ = _ptr.release();
}

template<
	typename Type,
	typename Deleter
>
std::unique_ptr<
	Type,
	Deleter
>
fcppt::scoped_ptr<
	Type,
	Deleter
>::release()
{
	std::unique_ptr<
		Type,
		Deleter
	> ret(
		ptr_
	);

	ptr_ = nullptr;

	return
		std::move(
			ret
		);
}

template<
	typename Type,
	typename Deleter
>
fcppt::scoped_ptr<
	Type,
	Deleter
>::operator bool() const
{
	return
		ptr_
		!=
		nullptr;
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
