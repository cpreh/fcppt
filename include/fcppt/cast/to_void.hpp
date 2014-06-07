//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_TO_VOID_HPP_INCLUDED
#define FCPPT_CAST_TO_VOID_HPP_INCLUDED


namespace fcppt
{
namespace cast
{

/**
\brief Casts and expression to void

\ingroup fcpptcasts

Casts \a _value to void, ignoring the expression. This is useful if you want to
avoid using an expression, for example if an expression is used to do static
type checking (e.g. for completeness).

\tparam Type Can be any object type

\param _value The value to cast to void
*/
template<
	typename Type
>
inline
void
to_void(
	Type const &_value
)
{
	static_cast<
		void
	>(
		_value
	);
}

}
}

#endif
