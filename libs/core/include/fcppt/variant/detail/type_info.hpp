//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_TYPE_INFO_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_TYPE_INFO_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

struct type_info
{
	typedef std::type_info const &result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &
	) const
	{
		return typeid(T);
	}
};

}
}
}

#endif
