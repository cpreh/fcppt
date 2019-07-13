//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_VARIANT_DYNAMIC_CAST_HPP_INCLUDED

#include <fcppt/loop.hpp>
#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/fold_break.hpp>
#include <fcppt/algorithm/loop_break_brigand.hpp>
#include <fcppt/cast/apply.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/variant/dynamic_cast_types.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Tries several dynamic casts

\ingroup fcpptvariant

Let <code>Types=(T_1,...,T_n)</code>. The function tries to cast \a _base
to <code>T_1</code> first. If this fails, it tries to cast \a _base to <code>T_2</code>, and so on.
The result of the first cast that succeeds is returned.

\return An optional variant of types <code>fcppt::reference<T_1>,...,fcppt::reference<T_n></code>.

\tparam Types An MPL sequence.

\tparam Cast A dynamic cast function from \ref fcpptcasts, e.g. #fcppt::cast::dynamic_fun.

\tparam Base The base class type to cast from.
*/
template<
	typename Types,
	typename Cast,
	typename Base
>
fcppt::optional::object<
	fcppt::variant::object<
		fcppt::variant::dynamic_cast_types<
			Types
		>
	>
>
dynamic_cast_(
	Base &_base
)
{
	typedef
	fcppt::variant::object<
		fcppt::variant::dynamic_cast_types<
			Types
		>
	>
	variant_type;

	typedef
	fcppt::optional::object<
		variant_type
	>
	result_type;

	return
		fcppt::algorithm::fold_break(
			Types{},
			result_type{},
			[
				&_base
			](
				auto const _type,
				result_type const &_result
			)
			{
				FCPPT_USE(
					_type
				);

				return
					_result.has_value()
					?
						std::make_pair(
							fcppt::loop::break_,
							_result
						)
					:
						std::make_pair(
							fcppt::loop::continue_,
							fcppt::optional::map(
								fcppt::cast::apply<
									Cast,
									fcppt::tag_type<
										decltype(
											_type
										)
									>
								>(
									_base
								),
								[](
									auto const _ref
								)
								{
									return
										variant_type{
											_ref
										};
								}
							)
						)
					;
			}
		);
}

}
}

#endif
