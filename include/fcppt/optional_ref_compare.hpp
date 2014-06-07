//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_REF_COMPARE_HPP_INCLUDED
#define FCPPT_OPTIONAL_REF_COMPARE_HPP_INCLUDED

#include <fcppt/optional_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Compares two optional references for identity

\ingroup fcpptoptional

Compares \a _a and \a _b, which must be optional references, for identity. Two
optional references are equal if they both refer to the same object.

\param _a The first optional
\param _b The second optional
*/
template<
	typename T
>
typename boost::enable_if<
	std::is_reference<
		T
	>,
	bool
>::type
optional_ref_compare(
	fcppt::optional<
		T
	> const &_a,
	fcppt::optional<
		T
	> const &_b
)
{
	return
		_a.data() == _b.data();
}

}

#endif
