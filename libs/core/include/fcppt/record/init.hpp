//          Copyright Carl Philipp Reh 2014 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_INIT_HPP_INCLUDED
#define FCPPT_RECORD_INIT_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

template<
	typename Result,
	typename Function
>
inline
Result
init(
	Function const &_function
)
{
	return
		fcppt::algorithm::vararg_map<
			typename
			Result::all_types
		>(
			[](
				auto &&... _args
			){
				return
					Result{
						std::forward<
							decltype(
								_args
							)
						>(
							_args
						)...
					};
			},
			[
				&_function
			](
				auto const _tag
			)
			{
				FCPPT_USE(
					_tag
				);

				typedef
				fcppt::tag_type<
					decltype(
						_tag
					)
				>
				element;

				return
					fcppt::record::element_to_label<
						element
					>{} =
						_function(
							element{}
						);
			}
		);
}

}
}

#endif
