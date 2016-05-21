//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DYNAMIC_EXN_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_EXN_HPP_INCLUDED

#include <fcppt/cast/detail/dynamic_exn.hpp>
#include <fcppt/type_traits/is_base_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts between references of related types using
<code>dynamic_cast</code> and provides additional error information

\ingroup fcpptcasts

Tries to cast \a _src to \a Dest using <code>dynamic_cast</code>. Both
<code>Dest</code> and the type of \a _src must be reference types. If the
<code>dynamic_cast</code> fails an \link fcppt::cast::bad_dynamic \endlink will
be thrown that includes additional information about the types involved. To
catch more mistakes, \a Src must be a base class of \a Derived. In case you
need a cross cast, use \link fcppt::cast::dynamic_cross_exn \endlink.

The following example shows how this function can be used:

\snippet cast/dynamic.cpp dynamic_cast

\param _src The source reference to cast from

\tparam Dest Must be a reference type

\throws fcppt::cast::bad_dynamic on failure
*/
template<
	typename Dest,
	typename Src
>
inline
typename
std::enable_if<
	std::is_reference<
		Dest
	>::value,
	Dest
>::type
dynamic_exn(
	Src &_src
)
{
	static_assert(
		fcppt::type_traits::is_base_of<
			typename
			std::remove_cv<
				Src
			>::type,
			typename
			std::decay<
				Dest
			>::type
		>::value,
		"dynamic_exn can only cast from references to base classes to references to derived classes"
	);

	return
		fcppt::cast::detail::dynamic_exn<
			Dest
		>(
			_src
		);
}

}
}

#endif
