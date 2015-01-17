//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_UNARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_UNARY_HPP_INCLUDED

#include <fcppt/mpl/runtime_index.hpp>
#include <fcppt/variant/detail/apply_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/size.hpp>
#include <exception>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Does a unary visitation

\ingroup fcpptvariant

Visits \a _obj with the visitor \a _op. <code>_op.operator()(T)</code> will be
called where <code>T</code> is the type held \a _obj.

\tparam Operation The visitor type
\tparam Variant The variant type

\param _op The visitor to execute
\param _obj The variant to visit

\return The result of <code>_op.operator()(T)</code>
*/
template<
	typename Operation,
	typename Variant
>
typename
std::decay<
	Operation
>::type::result_type
apply_unary(
	Operation &&_op,
	Variant &&_obj
)
{
	return
		fcppt::mpl::runtime_index<
			typename
			boost::mpl::size<
				typename
				std::decay<
					Variant
				>::type::types
			>::type
		>(
			_obj.type_index(),
			fcppt::variant::detail::apply_function<
				Operation,
				Variant
			>(
				_op,
				_obj
			),
			[]()
			->
			typename
			std::decay<
				Operation
			>::type::result_type
			{
				std::terminate();
			}
		);
}

}
}

#endif
