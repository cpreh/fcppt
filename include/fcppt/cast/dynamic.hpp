//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DYNAMIC_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_HPP_INCLUDED

#include <fcppt/cast/bad_dynamic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <stdexcept>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts between references using <code>dynamic_cast</code> and provides
additional error information

\ingroup fcpptcasts

Tries to cast \a _src to \a Dest using <code>dynamic_cast</code>. Both
<code>Dest</code> and the type of \a _src are reference types. If the
<code>dynamic_cast</code> fails an \link fcppt::cast::bad_dynamic \endlink will
be thrown that includes additional information about the types involved.

The following example shows how this function can be used:

\snippet dynamic_cast.cpp dynamic_cast

\param _src The source reference to cast from

\return The casted result as if in <code>dynamic_cast<Dest>(_src)</code> if the
casts succeeds.

\throws fcppt::cast::bad_dynamic on failure
*/
template<
	typename Dest,
	typename Src
>
typename
std::enable_if<
	std::is_reference<
		Dest
	>::value,
	Dest
>::type
dynamic(
	Src &_src
)
{
	try
	{
		return
			dynamic_cast<
				Dest
			>(
				_src
			);
	}
	catch(
		std::bad_cast const &
	)
	{
		throw
			fcppt::cast::bad_dynamic(
				std::type_index(
					typeid(
						_src
					)
				),
				std::type_index(
					typeid(
						Dest
					)
				)
			);
	}
}

/**
\brief Converts between pointers using <code>dynamic_cast</code>

\ingroup fcpptcasts

This function is the complement to the version of
<code>fcppt::cast::dynamic</code> taking references. It doesn't do anything
special, which is to convert \a _src to \a Dest using <code>dynamic_cast</code>.
Both \a Dest and the type of \a _src are pointer types.

\param _src The source pointer to cast from

\return <code>dynamic_cast<Dest>(_src)</code>
*/
template<
	typename Dest,
	typename Src
>
typename
std::enable_if<
	std::is_pointer<
		Dest
	>::value,
	Dest
>::type
dynamic(
	Src *const _src
)
{
	return
		dynamic_cast<
			Dest
		>(
			_src
		);
}

}
}

#endif
