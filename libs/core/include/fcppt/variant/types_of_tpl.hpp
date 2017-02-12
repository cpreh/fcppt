//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_TYPES_OF_TPL_HPP_INCLUDED
#define FCPPT_VARIANT_TYPES_OF_TPL_HPP_INCLUDED

#include <fcppt/variant/object_fwd.hpp>


namespace fcppt
{
namespace variant
{

template<
	typename Type
>
struct types_of_tpl;

/**
\brief A metafunction returning the types of a variant

\ingroup fcpptvariant
*/
template<
	typename Types
>
struct types_of_tpl<
	fcppt::variant::object<
		Types
	>
>
{
	typedef
	Types
	type;
};

}
}

#endif
