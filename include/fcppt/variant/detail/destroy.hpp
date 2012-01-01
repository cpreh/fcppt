//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_DESTROY_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_DESTROY_HPP_INCLUDED

#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

struct destroy
{
	typedef void result_type;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4100)
	template<
		typename T
	>
	result_type
	operator()(
		T const &_t
	) const
	{
		_t.~T();
	}
FCPPT_PP_POP_WARNING
};

}
}
}

#endif
