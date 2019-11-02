//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_TO_NUMBER_LIST_HPP_INCLUDED
#define FCPPT_METAL_TO_NUMBER_LIST_HPP_INCLUDED

#include <fcppt/metal/to_number.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/list/transform.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{

template<
	typename List
>
using
to_number_list
=
::metal::transform<
	::metal::lambda<
		fcppt::metal::to_number
	>,
	List
>;

}
}

#endif
