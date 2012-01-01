//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_OPTIONAL_DYNAMIC_CAST_HPP_INCLUDED

#include <fcppt/optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
/**
\brief Tries a <code>dynamic_cast</code>, returning an empty optional value if it failed
\ingroup fcpptcasts
\tparam Derived The type do cast into. This has to be a reference type (see the example below)
\tparam The type which is to be cast (must not be a reference)

The logic of this cast is basically the <code>dynamic_cast</code> with
pointers, but with optional references. Note that you can only cast to a
reference type (be that const or nonconst). Here's a usage example:

\snippet optional_dynamic_cast.cpp optional_dynamic_cast
*/
template<typename Derived,typename Base>
typename
boost::enable_if
<
	boost::is_reference<Derived>,
	fcppt::optional<Derived> const
>::type
optional_dynamic_cast(
	Base &_base)
{
	typedef typename
	boost::remove_reference<Derived>::type
	derived_no_reference;

	derived_no_reference * const derived_ptr =
		dynamic_cast<derived_no_reference *>(
			&_base);

	if(!derived_ptr)
		return fcppt::optional<Derived>();

	return
		fcppt::optional<Derived>(
			*derived_ptr);
}
}

#endif
