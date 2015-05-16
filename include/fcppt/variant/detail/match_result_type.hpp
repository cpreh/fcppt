//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_MATCH_RESULT_TYPE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_MATCH_RESULT_TYPE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/front.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Variant,
	typename Func,
	typename... Functions
>
struct match_result_type
{
	typedef
	typename
	std::result_of<
		Func(
			typename
			boost::mpl::front<
				typename
				std::decay<
					Variant
				>::type::types
			>::type
		)
	>::type
	type;
};

}
}
}

#endif
