//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_GET_EXN_HPP_INCLUDED
#define FCPPT_VARIANT_GET_EXN_HPP_INCLUDED

#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/detail/get_exn_impl.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Free get function

\ingroup fcpptvariant

Equal to <code>%_object.get&lt;Type&gt;()</code>

\see fcppt::variant::object::get()
*/
template<
	typename Type,
	typename Elements
>
Type &
get_exn(
	fcppt::variant::object<
		Elements
	> &_object
)
{
	return
		fcppt::variant::detail::get_exn_impl<
			Type
		>(
			_object
		);
}

/**
\brief Free get function

\ingroup fcpptvariant

Equal to <code>%_object.get&lt;Type&gt;()</code>

\see fcppt::variant::object::get() const
*/
template<
	typename Type,
	typename Elements
>
Type const &
get_exn(
	fcppt::variant::object<
		Elements
	> const &_object
)
{
	return
		fcppt::variant::detail::get_exn_impl<
			Type const
		>(
			_object
		);
}

}
}

#endif
