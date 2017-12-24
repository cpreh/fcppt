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
fcppt::intrusive::base<
	Type
>::base(
	list_type &_list
)
:
	link_{
		_list.push_back(
			*this
		)
	}
{
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
	link_{
		_other.move_to(
			*this
		)
	}
{
}

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
	link_ =
		_other.move_to(
			*this
		);

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
	this->unlink();
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
	link_.unlink();
}

template<
	typename Type
>
inline
fcppt::intrusive::base<
	Type
>::base()
:
	link_{
		this,
		this
	}
{
}

template<
	typename Type
>
inline
typename
fcppt::intrusive::base<
	Type
>::link_type
fcppt::intrusive::base<
	Type
>::move_to(
	base &_other
)
{
	// This may change link_ as well, in case it points to itself.
	link_.move_to(
		_other
	);

	link_type const temp{
		link_
	};

	link_.reset(
		*this
	);

	return
		temp;
}

#endif
