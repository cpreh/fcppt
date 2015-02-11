//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_RUNTIME_ENUM_FUNCTION_HPP_INCLUDED
#define FCPPT_DETAIL_RUNTIME_ENUM_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/cast/static_cast_fun.hpp>
#include <fcppt/mpl/integral_cast.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Enum,
	typename Function
>
class runtime_enum_function
{
	FCPPT_NONASSIGNABLE(
		runtime_enum_function
	);
public:
	typedef
	typename
	Function::result_type
	result_type;

	explicit
	runtime_enum_function(
		Function const &_function
	)
	:
		function_(
			_function
		)
	{
	}

	template<
		typename Index
	>
	typename
	Function::result_type
	operator()(
		Index
	) const
	{
		return
			function_(
				typename
				fcppt::mpl::integral_cast<
					Enum,
					fcppt::cast::static_cast_fun,
					Index
				>::type{}
			);
	}
private:
	Function const function_;
};

}
}

#endif
