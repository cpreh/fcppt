//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_DETAIL_LINK_IMPL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_DETAIL_LINK_IMPL_HPP_INCLUDED

#include <fcppt/intrusive/base_fwd.hpp>
#include <fcppt/intrusive/detail/link_decl.hpp>


inline
fcppt::intrusive::detail::link::link(
	fcppt::intrusive::base *const _prev,
	fcppt::intrusive::base *const _next
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

void
fcppt::intrusive::detail::link::unlink()
{
	if(
		next_
		==
		nullptr
	)
		return;

	next_->link_.prev_ =
		prev_;

	prev_->link_.next_ =
		next_;
}

fcppt::intrusive::detail::link
fcppt::intrusive::detail::link::move_to(
	fcppt::intrusive::base &_base
)
{
	next_->link_.prev_ =
		&_base;

	prev_->link_.next_ =
		&_base;

	fcppt::intrusive::detail::link const result{
		*this
	};

	next_ =
		nullptr;

	return
		result;
}

#endif
