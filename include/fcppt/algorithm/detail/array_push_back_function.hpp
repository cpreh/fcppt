//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_ARRAY_PUSH_BACK_FUNCTION_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_ARRAY_PUSH_BACK_FUNCTION_HPP_INCLUDED

#include <fcppt/nonassignable.hpp>
#include <fcppt/container/array_size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
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
		std::size_t Index
	>
	typename
	std::enable_if<
		Index
		!=
		fcppt::container::array_size<
			Source
		>::value,
		value_type
	>::type
	operator()() const
	{
		return
			source_[
				Index
			];
	}

	template<
		std::size_t Index
	>
	typename
	std::enable_if<
		Index
		==
		fcppt::container::array_size<
			Source
		>::value,
		value_type
	>::type
	operator()() const
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
