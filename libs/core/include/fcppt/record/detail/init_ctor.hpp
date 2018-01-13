//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_INIT_CTOR_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_INIT_CTOR_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/detail/label_is_same.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/find.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/sequences/list.hpp>
#include <brigand/types/args.hpp>
#include <tuple>
#include <type_traits>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Result,
	typename TagTuple,
	typename... Args
>
Result
init_ctor(
	Args &&... _args
)
{
	std::tuple<
		typename
		std::decay<
			Args
		>::type...
	> arguments(
		std::move(
			_args
		)...
	);

	typedef
	::brigand::list<
		typename
		std::decay<
			Args
		>::type...
	>
	args_list;

	return
		fcppt::algorithm::vararg_map(
			TagTuple{},
			[](
				auto &&... _args_inner
			)
			-> Result
			{
				return
					Result{
						std::forward<
							decltype(
								_args_inner
							)
						>(
							_args_inner
						)...
				};
			},
			[
				&arguments
			](
				auto const _fcppt_element
			)
			{
				FCPPT_USE(
					_fcppt_element
				);

				typedef
					::brigand::index_if<
						args_list,
						::brigand::bind<
							fcppt::record::detail::label_is_same,
							::brigand::pin<
								fcppt::record::element_to_label<
									fcppt::tag_type<
										decltype(
											_fcppt_element
										)
									>
								>
							>,
							::brigand::_1
						>
					>
				index_type;

			return
				std::move(
					std::get<
						index_type::value
					>(
						arguments
					).value()
				);
		}
	);
}

}
}
}

#endif
