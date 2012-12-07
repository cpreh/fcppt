//          Copyright Carl Philipp Reh 2009 - 2012.
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
#include <functional>
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
		fcppt::variant::detail::apply<
			boost::mpl::empty<
				types
			>::value
		>:: template execute<
			boost::mpl::integral_c<
				fcppt::variant::size_type,
				0
			>,
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

template<
	typename Operation,
	typename Variant
>
typename Operation::result_type
apply_unary_internal(
	Operation const &_op,
	std::reference_wrapper<
		Variant
	> const &_obj
)
{
	return
		fcppt::variant::detail::apply_unary_internal(
			_op,
			_obj.get()
		);
}

}
}
}

#endif
