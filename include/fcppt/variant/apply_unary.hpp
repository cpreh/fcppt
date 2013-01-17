//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_UNARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_UNARY_HPP_INCLUDED

#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/apply.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/integral_c.hpp>
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
typename std::remove_reference<
	Operation
>::type::result_type
apply_unary(
	Operation &&_op,
	Variant &&_obj
)
{
	typedef typename std::remove_reference<
		Variant
	>::type::types types;

	return
		fcppt::variant::detail::apply<
			boost::mpl::empty<
				types
			>::value
		>:: template execute<
			boost::mpl::integral_c<
				fcppt::variant::size_type,
				0
			>,
			typename boost::mpl::begin<
				types
			>::type,
			typename boost::mpl::end<
				types
			>::type
		>(
			_op,
			_obj
		);
}

}
}

#endif
