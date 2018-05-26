//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_DETAIL_LINK_IMPL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_DETAIL_LINK_IMPL_HPP_INCLUDED

#include <fcppt/intrusive/base_decl.hpp>
#include <fcppt/intrusive/detail/link_decl.hpp>


template<
	typename Type
>
inline
fcppt::intrusive::detail::link<
	Type
>::link(
	base_type *const _prev,
	base_type *const _next
)
:
	prev_{
		_prev
	},
	next_{
		_next
	}
{
}

template<
	typename Type
>
void
fcppt::intrusive::detail::link<
	Type
>::unlink()
{
	next_->link_.prev_ =
		prev_;

	prev_->link_.next_ =
		next_;
}

template<
	typename Type
>
void
fcppt::intrusive::detail::link<
	Type
>::reset(
	base_type &_self
)
{
	next_ =
		&_self;

	prev_ =
		&_self;
}

template<
	typename Type
>
void
fcppt::intrusive::detail::link<
	Type
>::move_to(
	base_type &_base
)
{
	next_->link_.prev_ =
		&_base;

	prev_->link_.next_ =
		&_base;
}

#endif
