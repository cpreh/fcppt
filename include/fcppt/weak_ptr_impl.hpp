//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_WEAK_PTR_IMPL_HPP_INCLUDED
#define FCPPT_WEAK_PTR_IMPL_HPP_INCLUDED

#include <fcppt/optional_impl.hpp>
#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/weak_ptr_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Type,
	typename Deleter
>
fcppt::weak_ptr<
	Type,
	Deleter
>::weak_ptr()
:
	impl_()
{
}

template<
	typename Type,
	typename Deleter
>
template<
	typename Other
>
fcppt::weak_ptr<
	Type,
	Deleter
>::weak_ptr(
	fcppt::weak_ptr<
		Other,
		Deleter
	> const &_other
)
:
	impl_(
		_other.std_ptr()
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
fcppt::weak_ptr<
	Type,
	Deleter
>::weak_ptr(
	fcppt::shared_ptr<
		Other,
		Deleter
	> const &_other
)
:
	impl_(
		_other.std_ptr()
	)
{
}

template<
	typename Type,
	typename Deleter
>
fcppt::optional<
	typename
	fcppt::weak_ptr<
		Type,
		Deleter
	>::shared_ptr
>
fcppt::weak_ptr<
	Type,
	Deleter
>::lock() const
{
	typename
	shared_ptr::impl_type result(
		impl_.lock()
	);

	typedef
	fcppt::optional<
		shared_ptr
	>
	result_type;

       	return
		result
		?
			result_type(
				shared_ptr(
					std::move(
						result
					)
				)
			)
		:
			result_type()
		;
}

template<
	typename Type,
	typename Deleter
>
long
fcppt::weak_ptr<
	Type,
	Deleter
>::use_count() const
{
	return
		impl_.use_count();
}

template<
	typename Type,
	typename Deleter
>
bool
fcppt::weak_ptr<
	Type,
	Deleter
>::expired() const
{
	return
		impl_.expired();
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::weak_ptr<
	Type,
	Deleter
>::swap(
	weak_ptr &_other
)
{
	impl_.swap(
		_other.impl_
	);
}

template<
	typename Type,
	typename Deleter
>
typename fcppt::weak_ptr<
	Type,
	Deleter
>::impl_type
fcppt::weak_ptr<
	Type,
	Deleter
>::std_ptr() const
{
	return
		impl_;
}

template<
	typename Type1,
	typename Type2,
	typename Deleter
>
bool
fcppt::operator<(
	fcppt::weak_ptr<
		Type1,
		Deleter
	> const &_left,
	fcppt::weak_ptr<
		Type2,
		Deleter
	> const &_right
)
{
	return
		_left.std_ptr()
		<
		_right.std_ptr();
}

template<
	typename Type,
	typename Deleter
>
void
fcppt::swap(
	fcppt::weak_ptr<
		Type,
		Deleter
	> &_left,
	fcppt::weak_ptr<
		Type,
		Deleter
	> &_right
)
{
	_left.swap(
		_right
	);
}

#endif
