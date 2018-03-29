//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_DETAIL_ARRAY_PUSH_BACK_FUNCTION_HPP_INCLUDED
#define FCPPT_CONTAINER_DETAIL_ARRAY_PUSH_BACK_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/array_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace detail
{

template<
	typename Source
>
class array_push_back_function
{
	FCPPT_NONASSIGNABLE(
		array_push_back_function
	);
public:
	typedef
	typename
	Source::value_type
	value_type;

	array_push_back_function(
		Source const &_source,
		value_type const &_back
	)
	:
		source_(
			_source
		),
		back_(
			_back
		)
	{
	}

	template<
		typename Index
	>
	std::enable_if_t<
		Index::value
		!=
		fcppt::container::array_size<
			Source
		>::value,
		value_type
	>
	operator()(
		Index
	) const
	{
		return
			source_[
				Index::value
			];
	}

	template<
		typename Index
	>
	std::enable_if_t<
		Index::value
		==
		fcppt::container::array_size<
			Source
		>::value,
		value_type
	>
	operator()(
		Index
	) const
	{
		return
			back_;
	}
private:
	Source const &source_;

	value_type const &back_;
};

}
}
}

#endif
