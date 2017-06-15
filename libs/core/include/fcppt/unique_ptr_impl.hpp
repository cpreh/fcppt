//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_IMPL_HPP_INCLUDED

#include <fcppt/unique_ptr_decl.hpp>


template<
	typename Type,
	typename Deleter
>
inline
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr(
	pointer const _ptr
)
noexcept
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
inline
fcppt::unique_ptr<
	Type,
	Deleter
>::unique_ptr(
	unique_ptr &&_other
)
noexcept
:
	ptr_(
		_other.release_ownership()
	)
{
}

template<
	typename Type,
	typename Deleter
>
inline
fcppt::unique_ptr<
	Type,
	Deleter
> &
fcppt::unique_ptr<
	Type,
	Deleter
>::operator=(
	unique_ptr &&_other
)
noexcept
{
	ptr_ =
		_other.release_ownership();

	return
		*this;
}

template<
	typename Type,
	typename Deleter
>
inline
fcppt::unique_ptr<
	Type,
	Deleter
>::~unique_ptr()
{
	if(
		this->get_pointer()
		!=
		nullptr
	)
		Deleter()(
			this->get_pointer()
		);
}

template<
	typename Type,
	typename Deleter
>
inline
typename
std::add_lvalue_reference<
	Type
>::type
fcppt::unique_ptr<
	Type,
	Deleter
>::operator*() const
noexcept
{
	return
		*this->get_pointer();
}

template<
	typename Type,
	typename Deleter
>
inline
typename
fcppt::unique_ptr<
	Type,
	Deleter
>::pointer
fcppt::unique_ptr<
	Type,
	Deleter
>::operator->() const
noexcept
{
	return
		this->get_pointer();
}

template<
	typename Type,
	typename Deleter
>
inline
typename
fcppt::unique_ptr<
	Type,
	Deleter
>::pointer
fcppt::unique_ptr<
	Type,
	Deleter
>::get_pointer() const
noexcept
{
	return
		ptr_;
}

template<
	typename Type,
	typename Deleter
>
inline
typename
fcppt::unique_ptr<
	Type,
	Deleter
>::pointer
fcppt::unique_ptr<
	Type,
	Deleter
>::release_ownership()
noexcept
{
	pointer const result(
		ptr_
	);

	ptr_ =
		nullptr;
	return
		result;
}

#endif
