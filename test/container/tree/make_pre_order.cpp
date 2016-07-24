//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/tree/make_pre_order.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/pre_order.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	fcppt::container::tree::object<
		int
	>
	i_tree;

	i_tree tree{
		1
	};

	static_assert(
		std::is_same<
			decltype(
				fcppt::container::tree::make_pre_order(
					tree
				)
			),
			fcppt::container::tree::pre_order<
				i_tree
			>
		>::value,
		""
	);

	i_tree const c_tree{
		1
	};

	static_assert(
		std::is_same<
			decltype(
				fcppt::container::tree::make_pre_order(
					c_tree
				)
			),
			fcppt::container::tree::pre_order<
				i_tree const
			>
		>::value,
		""
	);
}
