//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DYNAMIC_CAST_HPP_INCLUDED
#define FCPPT_VARIANT_DYNAMIC_CAST_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>
#include <fcppt/cast/apply.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/variant/object_impl.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Tries several dynamic casts

Let <code>Types=(reference<T_1>,...,reference<T_n>)</code>. The function tries to cast \a _base
to <code>T_1</code> first. If this fails, it tries to cast \a _base to <code>T_2</code>, and so on.
The result of the first cast that succeeds is returned.

\tparam Types An MPL sequence of \link fcppt::reference\endlink types.

\tparam Cast A dynamic cast function from \ref fcpptcasts, e.g. \link fcppt::cast::dynamic_fun\endlink.

\tparam Base The base class type to cast from.
*/
template<
	typename Types,
	typename Cast,
	typename Base
>
fcppt::optional::object<
	fcppt::variant::object<
		Types
	>
>
dynamic_cast_(
	Base &_base
)
{
	typedef
	fcppt::variant::object<
		Types
	>
	variant_type;

	typedef
	fcppt::optional::object<
		variant_type
	>
	result_type;

	return
		fcppt::algorithm::fold(
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
						_result
					:
						fcppt::optional::map(
							fcppt::cast::apply<
								Cast,
								typename
								fcppt::tag_type<
									decltype(
										_type
									)
								>::type
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
						);
			}
		);
}

}
}

#endif
