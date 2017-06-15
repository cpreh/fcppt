//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_VARIADIC_FWD_HPP_INCLUDED
#define FCPPT_VARIANT_VARIADIC_FWD_HPP_INCLUDED

#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Declares a variant using a parameter pack

\ingroup fcpptvariant
*/
template<
	typename... Types
>
using
variadic
=
fcppt::variant::object<
	boost::mpl::vector<
		Types...
	>
>;

}
}

#endif
