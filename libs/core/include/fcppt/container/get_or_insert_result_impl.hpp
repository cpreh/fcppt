//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GET_OR_INSERT_RESULT_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_GET_OR_INSERT_RESULT_IMPL_HPP_INCLUDED

#include <fcppt/container/get_or_insert_result_decl.hpp>


template<
	typename Reference
>
fcppt::container::get_or_insert_result<
	Reference
>::get_or_insert_result(
	Reference _reference,
	bool const _inserted
)
:
	reference_(
		_reference
	),
	inserted_{
		_inserted
	}
{
}

template<
	typename Reference
>
template<
	typename Other
>
fcppt::container::get_or_insert_result<
	Reference
>::get_or_insert_result(
	get_or_insert_result<
		Other
	> const &_other
)
:
	reference_(
		_other.element()
	),
	inserted_(
		_other.inserted()
	)
{
}

template<
	typename Reference
>
Reference
fcppt::container::get_or_insert_result<
	Reference
>::element() const
{
	return
		reference_.get();
}

template<
	typename Reference
>
bool
fcppt::container::get_or_insert_result<
	Reference
>::inserted() const
{
	return
		inserted_;
}

#endif
