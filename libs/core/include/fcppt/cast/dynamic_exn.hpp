//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DYNAMIC_EXN_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_EXN_HPP_INCLUDED

#include <fcppt/cast/detail/dynamic_exn.hpp>
#include <fcppt/type_traits/is_base_of.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
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

Tries to cast \a _src to \a Derived using <code>dynamic_cast</code>. On failure,
an #fcppt::cast::bad_dynamic  is thrown that includes additional
information about the types involved. To catch more mistakes, \a Base must be a
base class of \a Derived. In case you need a cross cast, use #fcppt::cast::dynamic_cross_exn.

Here is an example:

\snippet cast/dynamic_exn.cpp dynamic_exn

\tparam Derived The type to cast to. Must be a reference type. Must inherit from \a Base.

\tparam Base A cv-qualified non-reference type.

\throws fcppt::cast::bad_dynamic on failure
*/
template<
	typename Derived,
	typename Base
>
inline
std::enable_if_t<
	std::is_reference<
		Derived
	>::value,
	Derived
>
dynamic_exn(
	Base &_src
)
{
	static_assert(
		fcppt::type_traits::is_base_of<
			std::remove_cv_t<
				Base
			>,
			fcppt::type_traits::remove_cv_ref_t<
				Derived
			>
		>::value,
		"dynamic_exn can only cast from references to base classes to references to derived classes"
	);

	return
		fcppt::cast::detail::dynamic_exn<
			Derived
		>(
			_src
		);
}

}
}

#endif
