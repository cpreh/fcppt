//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_HOLDS_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_HOLDS_TYPE_HPP_INCLUDED

#include <fcppt/variant/object_impl.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/index_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Checks if a type is held by a variant

\ingroup fcpptvariant

The <em>currently held</em> type of a variant is the type passed to its
constructor or assignment operator. A type T <em>can be held</em> by a
<code>variant<Set></code> if T is a member of Set.

This function checks if \a Type is held by \a _variant.

\tparam Type The type to check for which must be a possible type for the
variant

\tparam Elements The types of the variant

\param _variant The variant to check

\return If the type is held by the variant
*/
template<
	typename Type,
	typename Elements
>
typename boost::enable_if<
	boost::mpl::contains<
		Elements,
		Type
	>,
	bool
>::type
holds_type(
	fcppt::variant::object<
		Elements
	> const &_variant
)
{
	return
		_variant.type_index()
		==
		fcppt::variant::detail::index_of<
			Elements,
			Type
		>::value;
}

}
}

#endif
