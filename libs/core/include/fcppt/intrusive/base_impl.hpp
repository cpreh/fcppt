//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_BASE_IMPL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_BASE_IMPL_HPP_INCLUDED

#include <fcppt/intrusive/base_decl.hpp>
#include <fcppt/intrusive/list_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

template<
	typename Type
>
inline
fcppt::intrusive::base<
	Type
>::base(
	list_type &_list
)
:
	prev_{
		_list.head_.prev_
	},
	next_{
		&_list.head_
	}
{
	_list.head_.prev_->next_ =
		this;

	_list.head_.prev_ =
		this;
}

template<
	typename Type
>
inline
fcppt::intrusive::base<
	Type
>::base(
	base &&_other
)
:
	prev_{
		_other.prev_
	},
	next_{
		_other.next_
	}
{
	prev_->next_ =
		this;

	next_->prev_ =
		this;

	_other.prev_ =
		&_other;

	_other.next_ =
		&_other;
}

FCPPT_PP_POP_WARNING

template<
	typename Type
>
inline
fcppt::intrusive::base<
	Type
> &
fcppt::intrusive::base<
	Type
>::operator=(
	base &&_other
)
{
	if(
		&_other
		==
		this
	)
		return
			*this;

	next_->prev_ =
		prev_;

	prev_->next_ =
		next_;

	prev_ =
		_other.prev_;

	next_ =
		_other.next_;

	prev_->next_ =
		this;

	next_->prev_ =
		this;

	_other.prev_ =
		&_other;

	_other.next_ =
		&_other;

	return
		*this;
}

template<
	typename Type
>
inline
fcppt::intrusive::base<
	Type
>::~base()
{
	next_->prev_ =
		prev_;

	prev_->next_ =
		next_;
}

template<
	typename Type
>
inline
void
fcppt::intrusive::base<
	Type
>::unlink()
{
	next_->prev_ =
		prev_;

	prev_->next_ =
		next_;

	next_ =
		this;

	prev_ =
		this;
}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

template<
	typename Type
>
inline
fcppt::intrusive::base<
	Type
>::base()
:
	prev_{
		this
	},
	next_{
		this
	}
{
}

FCPPT_PP_POP_WARNING

#endif
