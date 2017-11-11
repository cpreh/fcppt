//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/container/tree/map.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_tree_map
)
{
FCPPT_PP_POP_WARNING

	typedef
	fcppt::container::tree::object<
		int
	>
	int_tree;

	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::container::tree::object<
		int_unique_ptr
	>
	int_unique_ptr_tree;

	int_tree test(
		42
	);

	test.push_back(
		13
	);

	int_unique_ptr_tree const result(
		fcppt::container::tree::map<
			int_unique_ptr_tree
		>(
			test,
			[](
				int const _value
			)
			{
				return
					fcppt::make_unique_ptr<
						int
					>(
						_value
					);
			}
		)
	);

	BOOST_CHECK_EQUAL(
		*result.value(),
		42
	);

	fcppt::optional::maybe(
		result.back(),
		[]{
			BOOST_CHECK(
				false
			);
		},
		[](
			fcppt::reference<
				int_unique_ptr_tree const
			> const _ref
		)
		{
			BOOST_CHECK_EQUAL(
				13,
				*_ref.get().value()
			);
		}
	);
}
