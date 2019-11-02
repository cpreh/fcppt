//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DYNAMIC_CAST_TYPES_HPP_INCLUDED
#define FCPPT_VARIANT_DYNAMIC_CAST_TYPES_HPP_INCLUDED

#include <fcppt/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/transform.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief The variant element types used for #fcppt::variant::dynamic_cast_.

\ingroup fcpptvariant
*/
template<
	typename Types
>
using
dynamic_cast_types
=
::metal::transform<
	::metal::lambda<
		fcppt::reference
	>,
	Types
>;

}
}

#endif
