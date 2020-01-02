//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_SET_HPP_INCLUDED
#define FCPPT_RECORD_SET_HPP_INCLUDED

#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Sets an element in a record by copy

\ingroup fcpptrecord

Copies \a _value to the element identified by \a Label in \a _arg.
*/
template<
	typename Label,
	typename... Elements
>
inline
void
set(
	fcppt::record::object<
		Elements...
	> &_arg,
	fcppt::record::label_value_type<
		fcppt::record::object<
			Elements...
		>,
		Label
	> const &_value
)
{
	_arg. template set<
		Label
	>(
		_value
	);
}

/**
\brief Sets an element in a record by move

\ingroup fcpptrecord

Moves \a _value to the element identified by \a Label in \a _arg.
*/
template<
	typename Label,
	typename... Elements
>
inline
void
set(
	fcppt::record::object<
		Elements...
	> &_arg,
	fcppt::record::label_value_type<
		fcppt::record::object<
			Elements...
		>,
		Label
	> &&_value
)
{
	_arg. template set<
		Label
	>(
		std::move(
			_value
		)
	);
}

}
}

#endif
