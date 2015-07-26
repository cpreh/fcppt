//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_DETAIL_INVOKE_ON_FUNCTION_HPP_INCLUDED
#define FCPPT_MPL_DETAIL_INVOKE_ON_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/at.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{
namespace detail
{

// TODO: Remove this when we have polymorphic lambdas
template<
	typename Sequence,
	typename Function
>
class invoke_on_function
{
	FCPPT_NONASSIGNABLE(
		invoke_on_function
	);
public:
	explicit
	invoke_on_function(
		Function const &_function
	)
	:
		function_(
			_function
		)
	{
	}

	typedef
	typename
	Function::result_type
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
			function_(
				fcppt::tag<
					typename
					boost::mpl::at<
						Sequence,
						Index
					>::type
				>()
			);
	}
private:
	Function const &function_;
};

}
}
}

#endif
