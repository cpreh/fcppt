//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_INIT_HPP_INCLUDED
#define FCPPT_RECORD_INIT_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/vararg_map.hpp>
#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Initializes a record using a function

Let <code>element<L_1,T_1>, ..., element<L_n,T_n></code> be the elements of \a Result.
\a _function is then called as <code>(element<L_i,T_i>)</code> for <code>i = 1,..,n</code>.

\ingroup fcpptrecord

\tparam Result Must be an \link fcppt::record::object\endlink.

\tparam Function A polymorphic function callable as
<code>fcppt::record::label_value_type<Result, L> (fcppt::record::element<L,T>)</code>
for every <code>element<L,T></code> in \a Result.
*/
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
	static_assert(
		fcppt::record::is_object<
			Result
		>::value,
		"Result must be a record::object"
	);

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
