//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_LIST_IMPL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_LIST_IMPL_HPP_INCLUDED

#include <fcppt/intrusive/base_impl.hpp>
#include <fcppt/intrusive/iterator_impl.hpp>
#include <fcppt/intrusive/list_decl.hpp>
#include <fcppt/intrusive/detail/link_impl.hpp>


template<
	typename Type
>
fcppt::intrusive::list<
	Type
>::list()
:
	head_{}
{
}

template<
	typename Type
>
fcppt::intrusive::list<
	Type
>::list(
	list &&
)
= default;

template<
	typename Type
>
fcppt::intrusive::list<
	Type
> &
fcppt::intrusive::list<
	Type
>::operator=(
	list &&
)
= default;

template<
	typename Type
>
fcppt::intrusive::list<
	Type
>::~list()
{
}

template<
	typename Type
>
typename
fcppt::intrusive::list<
	Type
>::iterator
fcppt::intrusive::list<
	Type
>::begin()
{
	return
		iterator{
			head_.link_.next_
		};
}

template<
	typename Type
>
typename
fcppt::intrusive::list<
	Type
>::iterator
fcppt::intrusive::list<
	Type
>::end()
{
	return
		iterator{
			&head_
		};
}

template<
	typename Type
>
typename
fcppt::intrusive::list<
	Type
>::const_iterator
fcppt::intrusive::list<
	Type
>::begin() const
{
	return
		const_iterator{
			head_.link_.next_
		};
}

template<
	typename Type
>
typename
fcppt::intrusive::list<
	Type
>::const_iterator
fcppt::intrusive::list<
	Type
>::end() const
{
	return
		const_iterator{
			&head_
		};
}

template<
	typename Type
>
bool
fcppt::intrusive::list<
	Type
>::empty() const
{
	return
		this->begin()
		==
		this->end();
}

template<
	typename Type
>
typename
fcppt::intrusive::list<
	Type
>::link_type
fcppt::intrusive::list<
	Type
>::push_back(
	base_type &_base
)
noexcept
{
	link_type const result{
		head_.link_.prev_,
		&head_
	};

	head_.link_.prev_->link_.next_ =
		&_base;

	head_.link_.prev_ =
		&_base;

	return
		result;
}

#endif
