//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_CHOOSE_REFERENCE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_CHOOSE_REFERENCE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Selects a const or nonconst reference from a container type

If \a Container is const, the result is
<code>Container::const_reference</code>, otherwise it is
<code>Container::reference</code>.

\ingroup fcppttypetraits

\tparam Container Must be a container type with const_reference and reference
typedefs
*/
template<
	typename Container
>
using choose_reference
=
typename
std::conditional<
	std::is_const<
		Container
	>::value,
	typename Container::const_reference,
	typename Container::reference
>::type;

}
}

#endif
