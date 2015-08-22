//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_comparison.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/optional_output.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/container/find_opt.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	container_find_opt
)
{
FCPPT_PP_POP_WARNING

	FCPPT_MAKE_STRONG_TYPEDEF(
		int,
		strong_int
	);

	struct comp
	{
		bool
		operator()(
			int const _left,
			int const _right
		) const
		{
			return
				_left
				<
				_right;
		}

		bool
		operator()(
			int const _value,
			strong_int const _comp
		) const
		{
			return
				_value
				<
				_comp.get();
		}

		bool
		operator()(
			strong_int const _comp,
			int const _value
		) const
		{
			return
				_comp.get()
				<
				_value;
		}

	FCPPT_PP_PUSH_WARNING
	FCPPT_PP_DISABLE_GCC_WARNING(-Wunused-local-typedefs)
		typedef
		void
		is_transparent;
	FCPPT_PP_POP_WARNING
	};

	typedef
	std::set<
		int,
		comp
	>
	int_set;

	int_set const set{
		1,2,3
	};

	typedef
	fcppt::optional<
		int
	>
	optional_int;

	BOOST_CHECK_EQUAL(
		optional_int{
			fcppt::container::find_opt(
				set,
				strong_int(
					3
				)
			)
		},
		optional_int(
			3
		)
	);

	BOOST_CHECK(
		!fcppt::container::find_opt(
			set,
			strong_int(
				4
			)
		).has_value()
	);
}
