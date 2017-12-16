//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_INTRUSIVE_BASE_IMPL_HPP_INCLUDED
#define FCPPT_INTRUSIVE_BASE_IMPL_HPP_INCLUDED

#include <fcppt/intrusive/base_decl.hpp>
#include <fcppt/intrusive/list_fwd.hpp>
#include <fcppt/intrusive/detail/link_impl.hpp>


template<
	typename Type
>
inline
fcppt::intrusive::base::base(
	fcppt::intrusive::list<
		Type
	> &_list
)
:
	link_{
		_list.push_back(
			*this
		)
	}
{
}

inline
fcppt::intrusive::base::base(
	base &&_other
)
:
	link_{
		_other.link_.move_to(
			*this
		)
	}
{
	_other.link_.unlink();
}

inline
fcppt::intrusive::base &
fcppt::intrusive::base::operator=(
	base &&_other
)
{
	link_ =
		_other.link_.move_to(
			*this
		);

	return
		*this;
}

inline
fcppt::intrusive::base::~base()
{
	link_.unlink();
}

inline
fcppt::intrusive::base::base()
:
	link_{
		this,
		this
	}
{
}

#endif
