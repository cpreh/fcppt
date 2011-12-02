//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_APPLY_UNARY_INTERNAL_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_APPLY_UNARY_INTERNAL_HPP_INCLUDED

#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/apply.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/integral_c.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Operation,
	typename Variant
>
typename Operation::result_type
apply_unary_internal(
	Operation const &_op,
	Variant &_obj
)
{
	typedef typename Variant::types types;

	return
		detail::apply<
			boost::mpl::integral_c<
				size_type,
				0
			>,
			boost::mpl::empty<
				types
			>::value
		>:: template execute<
			typename boost::mpl::begin<
				types
			>::type,
			typename boost::mpl::end<
				types
			>::type
		>(
			_op,
			_obj
		);
}

}
}
}

#endif
