//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_APPLY_FUNCTION_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_APPLY_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/at.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

// TODO: Remove this when we have polymorphic lambdas
template<
	typename Operation,
	typename Variant
>
class apply_function
{
	FCPPT_NONASSIGNABLE(
		apply_function
	);
public:
	apply_function(
		Operation &_operation,
		Variant &_variant
	)
	:
		operation_(
			_operation
		),
		variant_(
			_variant
		)
	{
	}

	typedef
	typename
	std::decay<
		Operation
	>::type::result_type
	result_type;

	template<
		typename Index
	>
	result_type
	operator()(
		Index
	) const
	{
		return
			operation_(
				variant_. template get_unchecked<
					typename
					boost::mpl::at<
						typename
						std::decay<
							Variant
						>::type::types,
						Index
					>::type
				>()
			);
	}
private:
	Operation &operation_;

	Variant &variant_;
};

}
}
}

#endif
