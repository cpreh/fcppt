//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_INIT_CTOR_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_INIT_CTOR_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/container/tuple/vararg_map.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/detail/label_is_same.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/always.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/trait.hpp>
#include <metal/list/find_if.hpp>
#include <metal/list/list.hpp>
#include <tuple>
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
		fcppt::type_traits::remove_cv_ref_t<
			Args
		>...
	> arguments(
		std::move(
			_args
		)...
	);

	typedef
	::metal::list<
		fcppt::type_traits::remove_cv_ref_t<
			Args
		>...
	>
	args_list;

	return
		fcppt::container::tuple::vararg_map(
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
				::metal::find_if<
					args_list,
					::metal::bind<
						::metal::trait<
							fcppt::record::detail::label_is_same
						>,
						::metal::always<
							fcppt::record::element_to_label<
								fcppt::tag_type<
									decltype(
										_fcppt_element
									)
								>
							>
						>,
						::metal::_1
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
