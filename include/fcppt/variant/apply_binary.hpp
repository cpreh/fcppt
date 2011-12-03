//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_APPLY_BINARY_HPP_INCLUDED
#define FCPPT_VARIANT_APPLY_BINARY_HPP_INCLUDED

#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/detail/binary_unwrap.hpp>


namespace fcppt
{
namespace variant
{

/// Does a binary visitation with operation @a _op
/**
 * This will call @a _op::operator()(t1, t2)
 * where t1 and t2 are the objects held by @a _obj1 and @a _obj2 respectively
 * @return The result of @a _op::operator().
*/
template<
	typename Operation,
	typename Types1,
	typename Types2
>
typename Operation::result_type
apply_binary(
	Operation const &_op,
	fcppt::variant::object<
		Types1
	> const &_obj1,
	fcppt::variant::object<
		Types2
	> const &_obj2
)
{
	return
		variant::apply_unary(
			detail::binary_unwrap<
				Operation,
				fcppt::variant::object<
					Types1
				>
			>(
				_op,
				_obj1
			),
			_obj2
		);
}

}
}

#endif
