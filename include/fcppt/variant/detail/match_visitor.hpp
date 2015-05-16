//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_MATCH_VISITOR_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_MATCH_VISITOR_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/mpl/index_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Result,
	typename Variant,
	typename Tuple
>
class match_visitor
{
	FCPPT_NONASSIGNABLE(
		match_visitor
	);
public:
	explicit
	match_visitor(
		Tuple const &_tuple
	)
	:
		tuple_(
			_tuple
		)
	{
	}

	typedef
	Result
	result_type;

	template<
		typename Arg
	>
	result_type
	operator()(
		Arg &&_arg
	) const
	{
		return
			std::get<
				fcppt::mpl::index_of<
					typename
					std::decay<
						Variant
					>::type::types,
					typename
					std::decay<
						Arg
					>::type
				>::value
			>(
				tuple_
			)(
				std::forward<
					Arg
				>(
					_arg
				)
			);
	}
private:
	Tuple const &tuple_;
};

}
}
}

#endif
